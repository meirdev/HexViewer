#include <string>
#include <getopt.h>
#include <unistd.h> // isatty

#include "Style/Hexyl/Hexyl.h"
#include "Style/HexDump/HexDump.h"
#include "Printer/DefaultPrinter/DefaultPrinter.h"
#include "FileStream/LocalFile/LocalFile.h"

int main(int argc, char** argv)
{
    std::string fileName = argv[1];

    int option, length = 0, offset = 0;
    std::string theme;

    while ((option = getopt(argc, argv, "t:l:s:")) != -1)
    {
        switch (option)
        {
            case 't': // theme
                theme = optarg;
                break;
            case 'l': // length
                length = std::stoi(optarg);
                break;
            case 's': // offset
                offset = std::stoi(optarg);
                break;
        }
    }

    IStyle* style = nullptr;

    if (theme == "hexyl")
    {
        style = new Hexyl(bool(isatty(STDOUT_FILENO)));
    }
    else if (theme == "hexdump")
    {
        style = new HexDump;
    }
    else
    {
        style = new Hexyl;
    }

    IPrinter* printer = new DefaultPrinter(*style);

    IFile* file = new LocalFile(*printer, fileName);

    if (offset)
    {
        file->setOffset(static_cast<size_t>(offset));
    }

    if (length)
    {
        file->setLength(static_cast<size_t>(length));
    }

    file->print();

    delete file;
    delete printer;
    delete style;

    return 0;
}