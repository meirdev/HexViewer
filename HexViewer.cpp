#include "HexViewer.h"
#include "Style/Hexyl/Hexyl.h"
#include "Style/HexDump/HexDump.h"
#include "Printer/DefaultPrinter/DefaultPrinter.h"
#include "FileStream/LocalFile/LocalFile.h"
#include "DataProcessing/DataProcessing.h"

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

void HexViewer::setStyle(const std::string& _style, bool _colors)
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

void HexViewer::setPrinter(const std::string& _printer)
{
    m_printer = new DefaultPrinter;
}

void HexViewer::setFile(const std::string& _file)
{
    m_file = new LocalFile(_file);
}

void HexViewer::print(int _offset, size_t _length)
{
    DataProcessing dataProcessing(*m_printer, *m_style, *m_file);

    if (_offset)
    {
        dataProcessing.setOffset(_offset);
    }

    if (_length)
    {
        dataProcessing.setLength(_length);
    }

    dataProcessing.process();
}