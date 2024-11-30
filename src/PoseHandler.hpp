#pragma once
#include "Executor.hpp"

namespace adas
{
class PoseHandler final
{
    // 必须值
private:
    Pose pose;
    bool fastMoveFlag = false;

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
    const Pose Query(void) const noexcept;
};
}  // namespace adas