// The MIT License (MIT)
//
// Copyright(c) 2016 huan.wang
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
// 

#include "net/http/response.h"
#include "net/http/status.h"

namespace net {
namespace http {

std::shared_ptr<Response> Response::Create()
{
    return std::shared_ptr<Response>(new Response());
}

int Response::GetStatusCode() const
{
    return m_statusCode;
}

void Response::SetStatusCode(int code)
{
    m_statusCode = code;
}

void Response::SetStatus(const std::string & status)
{
    if (!base::strings::TrimSpace(status).empty())
        m_status = status;
}

std::string Response::GetStatus() const
{
    if (!m_status.empty())
        return m_status;
    else
        return StatusText((Status)m_statusCode);
}

std::shared_ptr<Request> Response::GetRequest() const
{
    return m_request;
}

void Response::SetRequest(std::shared_ptr<Request> request)
{
    m_request = request;
}

} // !namespace http
} // !namespace net