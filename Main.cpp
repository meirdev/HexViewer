#include <string>

#include "HexViewer.h"
#include "CLI11.hpp"

int main(int argc, char** argv)
{
    CLI::App app("HexViewer");

    std::string fileName;
    app.add_option("filename", fileName, "Filename")->required();

    std::string theme = "hexyl";
    app.add_option("-t,--theme", theme, "Theme");

    int offset = 0;
    app.add_option("-s,--offset", offset, "Offset");

    size_t length = 0;
    app.add_option("-l,--length", length, "Length");

    bool noColor = false;
    app.add_flag("-n,--no-colors", noColor, "No colors");

    CLI11_PARSE(app, argc, argv);

    HexViewer hexViewer;

    hexViewer.setStyle(theme, !noColor);
    hexViewer.setPrinter("default");
    hexViewer.setFile(fileName);

    hexViewer.print(offset, length);

    return 0;
}