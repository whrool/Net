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

#include "stdafx.h"
#include "CppUnitTest.h"
#include "net/base/zip.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSuite
{
    TEST_CLASS(ZipTest)
    {
    public:

        TEST_METHOD(TestCompress)
        {
            std::string data("hello world!, hello hello hello hello hello hello hello hello world");
            std::string strCompressData = base::zip::Compress(data);
            Assert::IsTrue(strCompressData.length() > 8);
            Assert::IsTrue(data.length() == std::stoul(strCompressData.substr(0, 8)));
        }

        TEST_METHOD(TestDecompress)
        {
            std::string data("hello world ! I am ZipTest.");
            std::string strCompressData = base::zip::Compress(data);
            std::string strDecompressData = base::zip::Decompress(strCompressData);
            Assert::IsTrue(strDecompressData == data);
            Assert::IsTrue(base::zip::Decompress(data).empty());
        }
    };
}