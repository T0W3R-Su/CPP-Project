#pragma once

namespace adas
{
template <typename T>
class Singleton final
{
private:
    Singleton(void) noexcept = default;
    ~Singleton(void) noexcept = default;

public:
    Singleton(const Singleton&) noexcept = delete;
    Singleton& operator=(const Singleton&) noexcept = delete;

public:
    static T& Instance(void) noexcept
    {
        static T instance;
        return instance;
    }
};
}  // namespace adas