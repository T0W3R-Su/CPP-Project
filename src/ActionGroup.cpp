#include "ActionGroup.hpp"

#include <algorithm>
#include <vector>

#include "InstructionFactory.hpp"

namespace adas
{
ActionGroup::ActionGroup(const std::list<ActionType>& actions) noexcept : actions(actions)
{
}

void ActionGroup::PushAction(const ActionType action) noexcept
{
    actions.push_back(action);
}

class ForwardAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Forward();
    }
};

class BackwardAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Backward();
    }
};

class TurnLeftAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.TurnLeft();
    }
};

class ReverseTurnLeftAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.ReverseTurnLeft();
    }
};

class TurnRightAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.TurnRight();
    }
};

class ReverseTurnRightAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.ReverseTurnRight();
    }
};

class BeFastAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.BeFast();
    }
};

class BeReverseAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.BeReverse();
    }
};

void ActionGroup::DoOperation(PoseHandler& poseHandler) const noexcept
{
    static std::vector<std::function<void(PoseHandler &poseHandler)>> actionVector = {
        ForwardAction(),   BackwardAction(),         TurnLeftAction(), ReverseTurnLeftAction(),
        TurnRightAction(), ReverseTurnRightAction(), BeFastAction(),   BeReverseAction(),
    };

    std::for_each(actions.begin(), actions.end(), [&poseHandler](const ActionType& action) mutable {
        actionVector[static_cast<uint16_t>(action)](poseHandler);
    });
}

}  // namespace adas
