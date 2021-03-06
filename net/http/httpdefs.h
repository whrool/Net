// The MIT License (MIT)
//
// Copyright(c) 2015-2016 huan.wang
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

#pragma once

#include <unordered_map>

#include "net/base/strings/string_utils.h"

namespace net {
namespace http {
    struct HashCaseInsensitive
    {
        std::size_t operator() (const std::string& key) const
        {
            return std::hash<std::string>{}(base::strings::ToLower(key));
        }
    };

    struct KeyEqualCaseInsensitive
    {
        bool operator() (const std::string& lhs, const std::string& rhs) const
        {
            return base::strings::Equal(lhs, rhs, true);
        }
    };
    typedef std::unordered_multimap<std::string, std::string, HashCaseInsensitive, KeyEqualCaseInsensitive> Header;
    typedef std::unordered_multimap<std::string, std::string> Values;
} // !namespace http
} // !namespace net