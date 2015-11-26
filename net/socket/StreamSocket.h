// Copyright(c) 2015 huan.wang
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files(the "Software"),
// to deal in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell copies of the Software,
// and to permit persons to whom the Software is furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#pragma once
#include "net/socket/Socket.h"

namespace net {

class StreamSocketImpl;

class StreamSocket :
    public Socket
{
public:
    StreamSocket();
    StreamSocket(const SocketAddress& address);
    StreamSocket(const Socket& socket);
    StreamSocket(std::shared_ptr<SocketImpl> pImpl);
    virtual ~StreamSocket();

    bool Connect(const SocketAddress& address, const std::chrono::seconds& timeout = std::chrono::seconds(0));
    bool ShutdownReceive();
    bool ShutdownSend();
    bool Shutdown();
    int Send(const void* buffer, int length, int flags = 0);
    int Receive(void* buffer, int length, int flags = 0);
    int SendUrgent(unsigned char data);
};

} //!net