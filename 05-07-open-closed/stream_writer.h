#pragma once

#include "file_writer.h"
#include <string>

enum Status {};

class StreamWriter : public FileWriter {
public:
    Status read(Buffer & buf);
    Status write(const Buffer & buf);
    Status close();
    void set_file_name(const std::string & /* name */) { /* ??? */ }
    bool disk_is_full() const { /* ??? */ return false; }
    /* ... */

protected:
    /* what to do with m_file? */
};
