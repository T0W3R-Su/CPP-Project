#pragma once
#include "ActionGroup.hpp"
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
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept
    {
        ActionGroup actionGroup;

        const auto action =
            poseHandler.IsReverseMove() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;

        if (poseHandler.IsFastMove()) {
            actionGroup.PushAction(action);
        }

        actionGroup.PushAction(action);
        return actionGroup;
    }
};

// 左转类
class TurnLeftInstruction final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept
    {
        ActionGroup actionGroup;

        if (poseHandler.IsFastMove()) {
            const auto action =
                poseHandler.IsReverseMove() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
            actionGroup.PushAction(action);
        }

        const auto action =
            poseHandler.IsReverseMove() ? ActionType::REVERSE_TURN_LEFT_ACTION : ActionType::TURN_LEFT_ACTION;

        actionGroup.PushAction(action);

        return actionGroup;
    }
};

// 右转类
class TurnRightInstruction final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept
    {
        ActionGroup actionGroup;

        if (poseHandler.IsFastMove()) {
            const auto action =
                poseHandler.IsReverseMove() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
            actionGroup.PushAction(action);
        }

        const auto action =
            poseHandler.IsReverseMove() ? ActionType::REVERSE_TURN_RIGHT_ACTION : ActionType::TURN_RIGHT_ACTION;

        actionGroup.PushAction(action);

        return actionGroup;
    }
};

// 快速移动类
class FastMoveInstruction final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept
    {
        ActionGroup actionGroup;
        actionGroup.PushAction(ActionType::BE_FAST_ACTION);
        return actionGroup;
    };
};

// 倒车类
class ReverseInstruction final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept
    {
        ActionGroup actionGroup;
        actionGroup.PushAction(ActionType::BE_REVERSE_ACTION);
        return actionGroup;
    };
};

}  // namespace adas
