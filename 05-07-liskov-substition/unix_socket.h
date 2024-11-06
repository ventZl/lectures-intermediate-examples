#pragma once

#include "socket.h"

class TCPSocket: public Socket {
public:
    TCPSocket(int socket): m_socket{socket} {}
    int write(const char * buffer, size_t len) override { return send(m_socket, buffer, len, 0); }
    int read(char * buffer, size_t len) override { return recv(m_socket, buffer, len, 0); }

protected:
    int m_socket;
};
