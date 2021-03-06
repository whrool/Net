// The MIT License (MIT)
//
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

#include <cassert>
#include <thread>
#include "net/socket/StreamSocketImpl.h"

namespace net {
StreamSocketImpl::StreamSocketImpl()
{
}

StreamSocketImpl::StreamSocketImpl(NativeHandle sockfd)
    : SocketImpl(sockfd)
{
}

StreamSocketImpl::~StreamSocketImpl()
{
}

int StreamSocketImpl::Send(const char* buffer, int length, int flags /*= 0*/)
{
    const char* p = buffer;
    int remaining = length;
    int sent = 0;
    bool bBlocking = GetBlocking();
    while (remaining > 0)
    {
        int n = SocketImpl::Send(p, remaining, flags);
        assert(n >= 0);
        p += n;
        sent += n;
        remaining -= n;
        if (bBlocking && remaining > 0)
            std::this_thread::yield();
        else
            break;
    } //!while
    return sent;
}

int StreamSocketImpl::Receive(char * buffer, int length, int flags /*= 0*/)
{
    int len = -1;
    while (true)
    {
        len = SocketImpl::Receive(buffer, length, flags);
        int err = WSAGetLastError();
        if (len < 0 && (WSAEWOULDBLOCK == err || WSAEINPROGRESS == err))
            std::this_thread::yield();
        else
            break;
    }
    return len;
}

} //!net