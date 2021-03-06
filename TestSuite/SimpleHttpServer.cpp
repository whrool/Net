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

#include "stdafx.h"
#include "SimpleHttpServer.h"

#include "net/http/context.h"
#include "net/http/handler.h"

using namespace net::http;

class SimpleHandler : public Handler
{
public:
    virtual void ServeHTTP(std::shared_ptr<Context> ctx) override
    {
        ctx->Write("Hello World");
    }
};

SimpleHttpServer::~SimpleHttpServer()
{
    m_thread.detach();
}

void SimpleHttpServer::Start(uint16_t port /*= 8080*/)
{
    m_server = Server::Create(port);
    m_server->SetHandler(std::make_shared<SimpleHandler>());

    m_thread = std::thread(&Server::ListenAndServe, m_server.get());
}
