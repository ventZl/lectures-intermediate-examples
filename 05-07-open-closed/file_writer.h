#pragma once

#include <string>
#include <fstream>

class Buffer {
public:
    char * data() { return m_data; }
    size_t length() { return m_length; }

protected:
    char * m_data;
    size_t m_length;
};

class FileWriter {
public:
    FileWriter();

    bool open() { m_file.open(m_name, std::fstream::in | std::fstream::out); return m_file.is_open(); }
    bool read(Buffer & buf) { m_file.read(buf.data(), buf.length()); return true; }
    bool write(Buffer & buf) { m_file.write(buf.data(), buf.length()); return true; }
    void close() { m_file.close(); }

    void set_file_name(const std::string & name) { m_name = name; }
    const std::string & get_file_name() const { return m_name; }

    bool disk_is_full() const { return false; }
    /* ... */

protected:
    std::string m_name;
    std::fstream m_file;
};
