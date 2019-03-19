#include <iostream>
#include <string>
#include <unistd.h> // isatty

#include "CLI11.hpp"
#include "Style/Hexyl/Hexyl.h"
#include "Style/HexDump/HexDump.h"
#include "Printer/DefaultPrinter/DefaultPrinter.h"
#include "FileStream/LocalFile/LocalFile.h"

int main(int argc, char** argv)
{
    CLI::App app("HexViewer");

    std::string fileName;
    app.add_option("filename", fileName, "Filename")->required();

    std::string theme;
    app.add_option("-t", theme, "Theme");

    int length = 0;
    app.add_option("-l", length, "Length");

    int offset = 0;
    app.add_option("-s", offset, "Offset");

    CLI11_PARSE(app, argc, argv);

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