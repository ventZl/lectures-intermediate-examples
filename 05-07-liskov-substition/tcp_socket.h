#pragma once

#include "socket.h"
#include <sys/socket.h>

class TCPSocket: public Socket, public Buffer {
    TCPSocket(int socket): m_socket{socket} {}
public:
    static TCPSocket * open(const char * ip, unsigned short port) { /* .... */ return new TCPSocket(42 /* socket fd goes here */); }
    int write(const char * buffer, size_t len) override { return send(m_socket, buffer, len, 0); }
    int read(char * buffer, size_t len) override { return recv(m_socket, buffer, len, 0); }

protected:
    int m_socket;
};
