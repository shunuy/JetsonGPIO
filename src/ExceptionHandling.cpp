/*
Copyright (c) 2019-2023, Jueon Park(pjueon) <bluegbgb@gmail.com>.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include "private/ExceptionHandling.h"
#include "private/PythonFunctions.h"
#include <stdexcept>
#include <string>

namespace GPIO
{
    // for exception handling
    std::string _error_message(const std::exception& e, const std::string& from)
    {
        return format("[Exception] %s (catched from: %s)\n", e.what(), from.c_str());
    }

    std::runtime_error _error(const std::exception& e, const std::string& from)
    {
        return std::runtime_error(_error_message(e, from));
    }
} // namespace GPIO
