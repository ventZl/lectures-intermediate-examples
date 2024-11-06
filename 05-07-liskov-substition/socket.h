#pragma once

#include <stddef.h>

class Socket {
public:
    virtual int write(const char * buf, size_t len) { return len; }
    virtual int read(char * buf, size_t len) { return len; }
};
