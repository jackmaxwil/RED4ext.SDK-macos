#pragma once

#include <RED4ext/Detail/Views/BufferIterator.hpp>

namespace RED4ext
{
template<typename T>
struct BufferView
{
    using Iterator = Detail::BufferIterator<T>;

    BufferView(void* aData, size_t aDataSize, size_t aElementSize = 0)
        : m_data(reinterpret_cast<uintptr_t>(aData))
        , m_dataSize(aDataSize)
        , m_elementSize(aElementSize > 0 ? aElementSize : sizeof(T))
    {
#ifdef __APPLE__
        // macOS: the cooked world node headers take the buffer and element size from native members the RTTI dump
        // cannot confirm. An implausible combination means the layout is wrong, so the view is empty (fail closed).
        if ((m_dataSize && !m_data) || m_elementSize < sizeof(T) || m_elementSize > 0x1000 ||
            m_dataSize % m_elementSize != 0)
        {
            m_data = 0;
            m_dataSize = 0;
            m_elementSize = sizeof(T);
        }
#endif
    }

    T& operator*()
    {
        return Front();
    }

    T& operator->()
    {
        return Front();
    }

    T& operator[](uint32_t aIndex)
    {
        return At(aIndex);
    }

    [[nodiscard]] T& At(uint32_t aIndex) const
    {
        return *reinterpret_cast<T*>(m_data + aIndex * m_elementSize);
    }

    [[nodiscard]] uint32_t Size() const
    {
        return m_dataSize / m_elementSize;
    }

    [[nodiscard]] bool IsEmpty() const
    {
        return m_dataSize == 0;
    }

    [[nodiscard]] T& Front() const
    {
        return At(0);
    }

    [[nodiscard]] T& Back() const
    {
        return At(Size() - 1);
    }

    [[nodiscard]] Iterator Begin() const
    {
        return {m_data, m_elementSize};
    }

    [[nodiscard]] Iterator End() const
    {
        return {m_data, m_elementSize};
    }

#pragma region STL
    [[nodiscard]] inline Iterator begin() const
    {
        return Begin();
    }

    [[nodiscard]] inline Iterator end() const
    {
        return End();
    }
#pragma endregion

private:
    uintptr_t m_data;
    size_t m_dataSize;
    size_t m_elementSize;
};
} // namespace RED4ext
