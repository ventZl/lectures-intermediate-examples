#include "socket.h"
#include "tcp_socket.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("", "[example]")
{
    char buffer[64];
    Socket * sock = TCPSocket::open("127.0.0.1", 22);
    REQUIRE(sock->write(buffer, sizeof(buffer)) == sizeof(buffer));
}
