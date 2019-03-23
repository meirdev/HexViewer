#include "HexViewer.h"
#include "Style/Hexyl/Hexyl.h"
#include "Style/HexDump/HexDump.h"
#include "Printer/DefaultPrinter/DefaultPrinter.h"
#include "FileStream/LocalFile/LocalFile.h"

HexViewer::HexViewer()
: m_style(nullptr)
, m_printer(nullptr)
, m_file(nullptr)
{
}

HexViewer::~HexViewer()
{
    delete m_style;
    delete m_printer;
    delete m_file;
}

void HexViewer::setStyle(std::string _style, bool _colors)
{
    if (_style == "hexyl")
    {
        m_style = new Hexyl(_colors);
    }
    else if (_style == "hexdump")
    {
        m_style = new HexDump;
    }
    else
    {
        throw std::runtime_error("Can't load theme");
    }
}

void HexViewer::setPrinter(std::string _printer)
{
    m_printer = new DefaultPrinter(*m_style);
}

void HexViewer::setFile(std::string _file, std::string _fileName, size_t _offset, size_t _length)
{
    m_file = new LocalFile(*m_printer, _fileName);

    if (_offset)
    {
        m_file->setOffset(static_cast<size_t>(_offset));
    }

    if (_length)
    {
        m_file->setLength(static_cast<size_t>(_length));
    }
}

void HexViewer::print()
{
    m_printer->header();

    m_file->read();

    m_printer->footer();
}