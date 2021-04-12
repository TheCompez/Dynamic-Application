/*!
 * MIT License
 *
 * @author     : Kambiz Asadzadeh
 * @file       : This file is a part of the project.
 * @version    : 1.0
 * @copyright  : Copyright (c) 2020 Kambiz Asadzadeh
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef COMMON_HPP
#define COMMON_HPP

#include <string>
#include <string_view>
#include <memory>

constexpr std::string_view __project_full_version = "0.5";
constexpr std::string_view __project_release_mode = "alpha";
constexpr std::string_view __project_release_mode_number = "2";

#define STLLIB_STANDARD             0x0
#define STLLIB_TECHNICAL_REPORT     0x1
#define STLLIB_EXPERIMENTAL         0x2
#define STLLIB_BOOST                0x3
#define STLLIB_NETWORKING_ERROR "We don't even have access to networking TS."
#define STLLIB_SYSTEM_ERROR "We don't even have access to system TS."
#define BOOST_ASIO_NO_DEPRECATED

#undef PROJECT_COPYRIGHT
#define PROJECT_COPYRIGHT 1

//! Compiler Predefined Variables.

#define __project_null_str ""
#define __project_zero 0
#define __project_newline "\n"
#define __project_compiler_counter __COUNTER__
#define __project_compiler_line __LINE__
#define __project_compiler_file __FILE__
#define __project_compiler_function __FUNCTION__
#define __project_compiler_pretty_function __PRETTY_FUNCTION__
#define __project_compiled_date __DATE__
#define __project_compiler_time __TIME__

#define __project_has_include __has_include

#define PROJECT_BRACE_BEGIN {
#define PROJECT_BRACE_END }
#define PROJECT_USING_NAMESPACE using namespace
#define PROJECT_NAMESPACE_BEGIN(x) namespace x {
#define PROJECT_ANONYMOUS_NAMESPACE_BEGIN namespace {
#define PROJECT_NAMESPACE_END }
#define PROJECT_USING using
#define PROJECT_NAMESPACE namespace

/*
 * C++11 keywords and expressions
 */
#ifdef PROJECT_COMPILER_NULLPTR
# define __project_nullptr         nullptr
#else
# define __project_nullptr         NULL
#endif

# define __project_override override
# define __project_final final

# define __project_noexcept noexcept
# define __project_noexcept_expr(x) noexcept(x)

#define __project_no_discard [[nodiscard]]
#define __project_no_discard_message(x) [[nodiscard(x)]]

#define PROJECT_HAS_INCLUDE __has_include
#define PROJECT_ENABLE_SHARED_FROM(x) std::enable_shared_from_this<x>

#define PROJECT_MOVE(x) std::move(x)

#define PROJECT_DEFAULT_OCTORS(Class) \
    Class();\
    ~Class();

#define PROJECT_DEFAULT_OCTORS_IMPL(Class) \
    Class::Class()\
    {\
    }\
    Class::~Class()\
    {\
    }\

#define PointerToObject(object, name)\
typedef object* (*name)();

#define PointerToFunction void(*)()

#define __project_enum enum class

#define __project_shared_ptr(Class) \
std::shared_ptr<Class>

#define PROJECT_DISABLE_COPY(Class) \
    Class(const Class &) = delete;\
    Class &operator=(const Class &) = delete;

#define PROJECT_DISABLE_MOVE(Class) \
    Class(Class &&) = delete; \
    Class &operator=(Class &&) = delete;

#define PROJECT_DISABLE_COPY_MOVE(Class) \
    PROJECT_DISABLE_COPY(Class) \
    PROJECT_DISABLE_MOVE(Class)

#if defined(__WINNT) || defined(__WINNT__) || defined(WIN32) ||                \
    defined(_WIN32) || defined(__WIN32) || defined(__WIN32__) ||               \
    defined(WIN64) || defined(_WIN64) || defined(__WIN64) ||                   \
    defined(__WIN64__)
//! Microsoft Windows
#define __project_export __declspec(dllexport)
#define __project_import __declspec(dllimport)
#elif defined(__GNUC__)
//! Define for Unix base OS such as: Linux, macOS, FreeBSD, etc...
#define __project_export __attribute__((visibility("default")))
#define __project_import __attribute__((visibility("default")))
#define __project_hidden __attribute__((visibility("hidden")))
#else
//  do nothing and hope for the best?
#define __project_export
#define __project_import
#pragma warning Unknown dynamic link import / export semantics.
#endif

#if defined(__APPLE__) && defined(__MACH__)
/* macOS */
#define __PLATFORM_OS "macOS"
#define __PLATFORM_MAC "Unix-macOS (X11)"
#define __PLATFORM_TYPE "Macintosh"
#elif defined(__linux__) && defined(linux) && !defined(__ANDROID__) &&         \
    !defined(ANDROID)
/* Linux. --------------------------------------------------- */
#define __PLATFORM_OS "Linux"
#define __PLATFORM_LINUX "Linux"
#define __PLATFORM_DEVICE "Desktop"
#define __PLATFORM_TYPE "Unix (Linux)"
#elif defined(X64_64bit) && defined(__linux) && defined(__linux__) &&          \
    defined(linux) && !defined(__ANDROID__) && !defined(ANDROID)
/* Linux. --------------------------------------------------- */
#define __PLATFORM_OS "Linux"
#define __PLATFORM_LINUX "Linux"
#define __PLATFORM_DEVICE "Desktop"
#define __PLATFORM_TYPE "Unix (Linux)"
#elif defined(_WIN32) || defined(_WIN32_WINNT) && !defined(_WIN64) &&          \
                             !defined(WINAPI_FAMILY_phone_APP) &&              \
                             !defined(WINAPI_FAMILY) &&                        \
                             (WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP)
/* Microsoft Windows (32-bit). ------------------------------ */
#define __PLATFORM_OS "Windows"
#define __PLATFORM_WINDOWS_x86 "Microsoft Windows (32-Bit)"
#define __PLATFORM_WINDOWS "Microsoft Windows (32-Bit)"
#define __PLATFORM_DEVICE "Desktop"
#define __PLATFORM_TYPE "PC (Windows)"
#elif defined(_WIN64) && !defined(_WIN32) && !defined(_WIN32_WINNT) &&         \
    !defined(WINAPI_FAMILY_phone_APP) &&                                       \
    (WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP)
/* Microsoft Windows (64-bit). ------------------------------ */
#define __PLATFORM_OS "Windows "
#define __PLATFORM_ARCH "x64 (64-Bit)"
#define __PLATFORM_WINDOWS_X64 "Microsoft Windows"
#define __PLATFORM_DEVICE "Desktop"
#define __PLATFORM_WINDOWS "Microsoft Windows"
#define __PLATFORM_TYPE "PC (Windows)"
/* Microsoft Phone ------------------------------ */
#elif defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_APP)
/* Microsoft Windows Store or Universal Windows Platform - (32-bit).
 * ------------------------------ */
#define __PLATFORM_OS "Windows"
#define __PLATFORM_WINDOWS_x86 "Microsoft Windows (32-Bit)"
#define __PLATFORM_WINDOWS_UWP "Microsoft Windows UWP (32-Bit)"
#define __PLATFORM_DEVICE "Desktop"
#define __PLATFORM_TYPE "PC (Windows)"
#elif defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_APP) &&        \
    defined(_WIN64) && !defined(_WIN32) && !defined(_WIN32_WINNT)
/* Microsoft Windows (64-bit). ------------------------------ */
#define __PLATFORM_OS "Windows "
#define __PLATFORM_WINDOWS_X64 "Microsoft Windows x64"
#define __PLATFORM_WINDOWS_UWP "Microsoft Windows UWP"
#define __PLATFORM_DEVICE "Desktop"
#define __PLATFORM_WINDOWS "Microsoft Windows"
#define __PLATFORM_TYPE "PC (Windows)"
/* Microsoft Phone ------------------------------ */
#elif defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_phone_APP)
/* Microsoft Windows (Phone). ------------------------------ */
#define __PLATFORM_OS "WindowsRT"
#define __PLATFORM_WINDOWS_phone "Windows Phone"
#define __PLATFORM_DEVICE "Mobile"
#define __PLATFORM_TYPE "Mobile (Windows Phone)"
#elif defined(_WIN64) && defined(WINAPI_FAMILY_phone_APP)
/* Microsoft Windows (Phone). ------------------------------ */
#define __PLATFORM_OS "WindowsRT"
#define __PLATFORM_DEVICE "Mobile"
#define __PLATFORM_WINDOWS_phone "Windows Phone"
#define __PLATFORM_TYPE "Mobile (Windows Phone)"
#endif

#if defined(__clang__)
/* Clang/LLVM. ---------------------------------------------- */
#undef __PLATFORM_COMPILER
#define __PLATFORM_COMPILER "Clang/LLVM"
#undef __PLATFORM_COMPILER_ver
#define __PLATFORM_COMPILER_ver __clang_version__
#elif defined(__ICC) || defined(__INTEL_COMPILER)
/* Intel ICC/ICPC. ------------------------------------------ */
#define __PLATFORM_COMPILER "Intel ICC/ICPC"
#define __PLATFORM_COMPILER_ver __INTEL_COMPILER_BUILD_DATE
#elif defined(__MINGW32__) && !defined(__amd64__) && !defined(__amd64) &&      \
    !defined(__ia64__)
/* __MINGW32__. ------------------------------------------------- */
#undef __PLATFORM_COMPILER
#define __PLATFORM_COMPILER "MinGW-w86 (x86) 32 Bit"
#undef __PLATFORM_COMPILER_ver
#define __PLATFORM_COMPILER_ver                                                 \
  __MINGW32_MAJOR_VERSION << '.' << __MINGW32_MINOR_VERSION
#elif defined(__MINGW32__)
/* __MINGW32__. ------------------------------------------------- */
#undef __PLATFORM_COMPILER
#define __PLATFORM_COMPILER "MinGW-w64 (x86_64) 32-64 Bit"
#undef __PLATFORM_COMPILER_ver
#define __PLATFORM_COMPILER_ver                                                 \
  __MINGW32_MAJOR_VERSION << '.' << __MINGW32_MINOR_VERSION
#elif defined(__MINGW64__)
/* __MINGW64__. ------------------------------------------------- */
#undef __PLATFORM_COMPILER
#define __PLATFORM_COMPILER "MinGW-w64 (x64) 64 Bit"
#undef __PLATFORM_COMPILER_ver
#define __PLATFORM_COMPILER_ver                                                 \
  __MINGW64_MAJOR_VERSION << '.' << __MINGW64_MINOR_VERSION
#elif defined(__GNUC__) || defined(__GNUG__) && !defined(__clang__)
/* GNU GCC/G++. --------------------------------------------- */
#undef __PLATFORM_COMPILER
#define __PLATFORM_COMPILER "GNU GCC/G++"
#undef __PLATFORM_COMPILER_ver
#define __PLATFORM_COMPILER_ver __GNUC__
#elif defined(__HPPP_cc) || defined(__HPPP_aCC)
/* Hewlett-Packard C/aC++. ---------------------------------- */
#define __PLATFORM_COMPILER "Hewlett-Packard C/aC++"
#define __PLATFORM_COMPILER_ver __HPPP_aCC
#elif defined(__IBMC__) || defined(__IBMCPP__)
/* IBM XL C/C++. -------------------------------------------- */
#define __PLATFORM_COMPILER "IBM XL C/C++"
#define __PLATFORM_COMPILER_ver __xlC_veR
#elif defined(_MSC_VER)
/* Microsoft Visual Studio. --------------------------------- */
#undef __PLATFORM_COMPILER
#define __PLATFORM_COMPILER "MSVC++ "
#undef __PLATFORM_COMPILER_MSVC
#define __PLATFORM_COMPILER_MSVC
#undef __PLATFORM_COMPILER_ver_
#define __PLATFORM_COMPILER_ver _MSC_VER
#elif defined(__PGI)
/* Portland Group PGCC/PGCPP. ------------------------------- */
#define __PLATFORM_COMPILER "PGCC/PGCPP"
#define __PLATFORM_COMPILER_ver __VERSION__
#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
/* Oracle Solaris Studio. ----------------------------------- */
#define __PLATFORM_COMPILER "Oracle Solaris"
#define __PLATFORM_COMPILER_ver __SUNPRO_CC
#endif

#endif // COMMON_HPP
