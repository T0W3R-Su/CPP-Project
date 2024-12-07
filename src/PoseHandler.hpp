#pragma once
#include "Executor.hpp"

namespace adas
{
class Point final
{
private:
    int x;
    int y;

public:
    Point(const int x, const int y) noexcept;
    Point(const Point &rhs) noexcept;
    Point &operator=(const Point &rhs) noexcept;
    Point &operator+=(const Point &rhs) noexcept;
    Point &operator-=(const Point &rhs) noexcept;

public:
    int GetX(void) const noexcept;
    int GetY(void) const noexcept;
};

class Direction final
{
private:
    char heading;
    unsigned index;

public:
    Direction(const unsigned index, const char heading) noexcept;

public:
    static const Direction &GetDirection(const char heading) noexcept;

public:
    const char GetHeading(void) const noexcept;

public:
    const Point &Move(void) const noexcept;
    const Direction &TurnLeft(void) const noexcept;
    const Direction &TurnRight(void) const noexcept;
};

class PoseHandler final
{
    // 必须值
private:
    Point point;
    bool fastMoveFlag = false;
    bool reverseMoveFlag = false;
    const Direction *facing;

    // 初始化和销毁
public:
    PoseHandler(const Pose &pose) noexcept;
    ~PoseHandler();
    PoseHandler(const PoseHandler &) = delete;
    PoseHandler &operator=(const PoseHandler &) = delete;

    // 指令函数
public:
    void Move(void) noexcept;
    void TurnLeft(void) noexcept;
    void TurnRight(void) noexcept;
    void FastMove(void) noexcept;
    bool IsFastMove(void) const noexcept;
    void ReverseMove(void) noexcept;
    bool IsReverseMove(void) const noexcept;
    const Pose Query(void) const noexcept;
};

}  // namespace adas