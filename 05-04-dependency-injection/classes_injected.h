#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <stdexcept>

class LineStreamer {
public:
    ~LineStreamer() {}

    virtual std::string get_line() = 0;
};

class FileReader: public LineStreamer {
public:
    FileReader(const std::string & file_name) {
        m_file.open(file_name, std::fstream::in);
        if (!m_file.is_open())
        {
            throw std::runtime_error("Unable to open file");
        }
    }

    std::string get_line() {
        std::string line;
        std::getline(m_file, line);
        return line;
    }

protected:
    std::ifstream m_file;
};

// C stands for TAB
class CSVParser {
public:
    using Row = std::vector<float>;

    CSVParser(LineStreamer & source): m_source{source} {}


    void parse() {
        std::string line;
        while ((line = m_source.get_line()) != "")
        {
            std::vector<std::string> cells;
            cells = get_cells(line);

            Row new_row;

            for (const auto & cell : cells)
            {
                new_row.push_back(to_float(cell));
            }

            m_document.emplace_back(new_row);
        }
    }

    float get_value(unsigned row, unsigned col) {
        if (row >= m_document.size() || col >= m_document[row].size())
        {
            throw std::range_error("Coordinates out of range!");
        }

        return m_document[row][col];
    }

protected:

    std::vector<std::string> get_cells(const std::string & line) {
        std::vector<std::string> out;
        std::istringstream stream;
        stream.str(line);
        for (std::string cell; std::getline(stream, cell, '\t');)
        {
            out.push_back(cell);
        }

        return out;
    }

    float to_float(const std::string & str) {
        return std::stof(str);
    }

protected:
    LineStreamer & m_source;
    std::vector<Row> m_document;
};
