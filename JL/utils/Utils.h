#pragma once

#define UTILS_API

namespace jl
{
    UTILS_API void WriteAssertionError(const char* expression, const char* file, int lineNumber);
    UTILS_API void ThrowAssertionError(const char* expression, const char* file, int lineNumber);
} // namespace jl

#ifdef WIN32
    #define ALWAYS_ASSERT(expr) (void) (!!(expr) || (jl::WriteAssertionError(#expr, __FILE__, __LINE__),0) || (__debugbreak(),0) )
#else
    #define ALWAYS_ASSERT(expr) (void) (!!(expr) || (jl::ThrowAssertionError(#expr, __FILE__, __LINE__),0) )
#endif

#if NDEBUG
    #define ASSERT(f)          ((void)0)
    #define VERIFY(f)          ((void)(f))
#else
    #define ASSERT(expr) ALWAYS_ASSERT(expr)
    #define VERIFY(expr) ALWAYS_ASSERT(expr)
#endif