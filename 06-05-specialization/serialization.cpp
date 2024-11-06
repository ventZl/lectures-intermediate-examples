#include "serializable.h"

class Text: public Serializable {
public:
    Text() {}
    Text(int line_no): m_line_no{line_no} {}

    void on_serialize(std::ostream & output)
    {
        m_line_no >> output;
    }

    void on_deserialize(std::istream & input)
    {
        m_line_no << input;
    }

protected:
    int m_line_no;
};

class Page: public Serializable {
public:
    void on_serialize(std::ostream & output)
    {
        size_t num_lines = m_lines.size();
        num_lines >> output;
        for (auto & line : m_lines) {
            line >> output;
        }
    }

    void on_deserialize(std::istream & input)
    {
        size_t num_lines;
        num_lines << input;
        for (int q = 0; q < num_lines; ++q) {
            Text line;
            line << input;
            m_lines.emplace_back(line);
        }
    }

    void add_line(Text line)
    {
        m_lines.push_back(line);
    }

    Text & get_line(unsigned no)
    {
        if (no < m_lines.size()) {
            return m_lines[no];
        }

        throw std::range_error("Line out of range");
    }

    unsigned lines() const
    {
        return m_lines.size();
    }

protected:
    std::vector<Text> m_lines;
};

class Document: public Serializable {
public:
    void on_serialize(std::ostream & output)
    {
        size_t num_pages = m_pages.size();
        num_pages >> output;
        for (auto & page : m_pages) {
            page >> output;
        }
    }

    void on_deserialize(std::istream & input)
    {
        size_t num_pages;
        num_pages << input;
        for (int q = 0; q < num_pages; ++q) {
            Page page;
            page << input;
            m_pages.emplace_back(page);
        }
    }

    void add_page(Page page)
    {
        m_pages.push_back(page);
    }

    Page & get_page(unsigned no)
    {
        if (no < m_pages.size()) {
            return m_pages[no];
        }

        throw std::range_error("Line out of range");
    }

    unsigned pages() const
    {
        return m_pages.size();
    }



public:
    std::vector<Page> m_pages;
};

int main(int argc, char ** argv)
{

    std::fstream file;
    file.open("serialized.bin", std::fstream::out | std::fstream::trunc);
    {
        Text line_1(1);

        Page page_1;
        page_1.add_line(line_1);

        Document document;
        document.add_page(page_1);

        document >> file;
        file.close();
    }

    file.open("serialized.bin", std::fstream::in);
    {
        Document document;
        document << file;
        std::cout << "Document has " << document.pages() << " pages" << std::endl;
        Page & page = document.get_page(0);
        std::cout << "Page has " << page.lines() << " lines" << std::endl;

    }
    file.close();
}
