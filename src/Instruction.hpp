#pragma once
#include "PoseHandler.hpp"

namespace adas
{
// 虚基类，定义了所有的指令
class ICommand
{
public:
    virtual ~ICommand(void) noexcept = default;
    virtual void DoOperate(PoseHandler& poseHandler) const noexcept = 0;
};

// 移动类
class MoveInstruction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFastMove()) {
            poseHandler.Move();
        }

        poseHandler.Move();
    };
};

// 左转类
class TurnLeftInstruction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFastMove()) {
            poseHandler.Move();
        }

        if (poseHandler.IsReverseMove()) {
            poseHandler.TurnRight();
        } else {
            poseHandler.TurnLeft();
        }
    };
};

// 右转类
class TurnRightInstruction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFastMove()) {
            poseHandler.Move();
        }

        if (poseHandler.IsReverseMove()) {
            poseHandler.TurnLeft();
        } else {
            poseHandler.TurnRight();
        }
    };
};

// 快速移动类
class FastMoveInstruction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.FastMove();
    };
};

// 倒车类
class ReverseInstruction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.ReverseMove();
    };
};

}  // namespace adas
