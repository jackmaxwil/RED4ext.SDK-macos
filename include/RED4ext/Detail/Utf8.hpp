#pragma once

#include <string>
#include <string_view>

#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#else
#include <cstdint>
#endif

namespace RED4ext::Detail
{
inline std::string WideToUtf8(std::wstring_view aValue)
{
    if (aValue.empty())
    {
        return {};
    }

#if defined(_WIN32) || defined(_WIN64)
    const int size = WideCharToMultiByte(CP_UTF8, 0, aValue.data(), static_cast<int>(aValue.size()), nullptr, 0,
                                         nullptr, nullptr);
    if (size <= 0)
    {
        return {};
    }

    std::string result(static_cast<size_t>(size), '\0');
    const int written = WideCharToMultiByte(CP_UTF8, 0, aValue.data(), static_cast<int>(aValue.size()), result.data(),
                                            static_cast<int>(result.size()), nullptr, nullptr);
    if (written <= 0)
    {
        return {};
    }
    return result;
#else
    // macOS wchar_t is UTF-32 code units.
    std::string result;
    result.reserve(aValue.size());

    for (wchar_t wc : aValue)
    {
        const std::uint32_t cp = static_cast<std::uint32_t>(wc);
        if (cp <= 0x7F)
        {
            result.push_back(static_cast<char>(cp));
        }
        else if (cp <= 0x7FF)
        {
            result.push_back(static_cast<char>(0xC0 | ((cp >> 6) & 0x1F)));
            result.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
        }
        else if (cp <= 0xFFFF)
        {
            result.push_back(static_cast<char>(0xE0 | ((cp >> 12) & 0x0F)));
            result.push_back(static_cast<char>(0x80 | ((cp >> 6) & 0x3F)));
            result.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
        }
        else if (cp <= 0x10FFFF)
        {
            result.push_back(static_cast<char>(0xF0 | ((cp >> 18) & 0x07)));
            result.push_back(static_cast<char>(0x80 | ((cp >> 12) & 0x3F)));
            result.push_back(static_cast<char>(0x80 | ((cp >> 6) & 0x3F)));
            result.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
        }
        else
        {
            result.push_back('?');
        }
    }

    return result;
#endif
}

inline std::wstring Utf8ToWide(std::string_view aValue)
{
    if (aValue.empty())
    {
        return {};
    }

#if defined(_WIN32) || defined(_WIN64)
    const int size = MultiByteToWideChar(CP_UTF8, 0, aValue.data(), static_cast<int>(aValue.size()), nullptr, 0);
    if (size <= 0)
    {
        return {};
    }

    std::wstring result(static_cast<size_t>(size), L'\0');
    const int written = MultiByteToWideChar(CP_UTF8, 0, aValue.data(), static_cast<int>(aValue.size()), result.data(),
                                            static_cast<int>(result.size()));
    if (written <= 0)
    {
        return {};
    }
    return result;
#else
    std::wstring result;
    result.reserve(aValue.size());

    const unsigned char* ptr = reinterpret_cast<const unsigned char*>(aValue.data());
    const unsigned char* end = ptr + aValue.size();

    while (ptr < end)
    {
        std::uint32_t cp = 0;
        const unsigned char c0 = *ptr++;

        if ((c0 & 0x80) == 0)
        {
            cp = c0;
        }
        else if ((c0 & 0xE0) == 0xC0 && ptr < end)
        {
            cp = static_cast<std::uint32_t>(c0 & 0x1F) << 6;
            cp |= static_cast<std::uint32_t>(*ptr++ & 0x3F);
        }
        else if ((c0 & 0xF0) == 0xE0 && (end - ptr) >= 2)
        {
            cp = static_cast<std::uint32_t>(c0 & 0x0F) << 12;
            cp |= static_cast<std::uint32_t>(*ptr++ & 0x3F) << 6;
            cp |= static_cast<std::uint32_t>(*ptr++ & 0x3F);
        }
        else if ((c0 & 0xF8) == 0xF0 && (end - ptr) >= 3)
        {
            cp = static_cast<std::uint32_t>(c0 & 0x07) << 18;
            cp |= static_cast<std::uint32_t>(*ptr++ & 0x3F) << 12;
            cp |= static_cast<std::uint32_t>(*ptr++ & 0x3F) << 6;
            cp |= static_cast<std::uint32_t>(*ptr++ & 0x3F);
        }
        else
        {
            cp = static_cast<std::uint32_t>('?');
        }

        result.push_back(static_cast<wchar_t>(cp));
    }

    return result;
#endif
}
} // namespace RED4ext::Detail
