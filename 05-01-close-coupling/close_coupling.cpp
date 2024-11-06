#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <stdexcept>

// C stands for TAB
class CSVParser {
public:
    using Row = std::vector<float>;

    CSVParser(const std::string & file_name) {
        m_file.open(file_name, std::fstream::in);
        if (!m_file.is_open())
        {
            throw std::runtime_error("Unable to open file");
        }
    }

    void parse() {
        for (std::string line; std::getline(m_file, line);)
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
    std::string get_line() {
        std::string line;
        std::getline(m_file, line);
        return line;
    }

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
    std::ifstream m_file;
    std::vector<Row> m_document;
};

int main(int argc, char **)
{
    auto csv_file = new CSVParser("data.csv");
    csv_file->parse();
    std::cout << "[0, 0] = " << csv_file->get_value(0, 0) << std::endl;
    delete csv_file;
}
