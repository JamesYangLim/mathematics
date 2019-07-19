#include "JL/utils/Utils.h"
#include <iostream>

namespace jl
{
    UTILS_API void WriteAssertionError(const char* expression, const char* file, int lineNumber)
    {
        std::cerr << "Assertion error : " << expression << " in file " << file << " line " << lineNumber << '\n';
    }

    UTILS_API void ThrowAssertionError(const char* expression, const char* file, int lineNumber)
    {
        WriteAssertionError(expression, file, lineNumber);
        throw std::bad_exception();
    }
} // namespace jl