#pragma once

#include <list>

#include "PoseHandler.hpp"

namespace adas
{
enum class ActionType : uint16_t {
    FORWARD_1_STEP_ACTION = 0,
    BACKWARD_1_STEP_ACTION,
    TURN_LEFT_ACTION,
    REVERSE_TURN_LEFT_ACTION,
    TURN_RIGHT_ACTION,
    REVERSE_TURN_RIGHT_ACTION,
    BE_FAST_ACTION,
    BE_REVERSE_ACTION,
};

class ActionGroup final
{
    // 操作列表
private:
    std::list<ActionType> actions;

    // 初始化和销毁
public:
    ActionGroup(void) = default;
    explicit ActionGroup(const std::list<ActionType>& actions) noexcept;
    ~ActionGroup() = default;

    // 添加操作和执行操作列表
public:
    void PushAction(const ActionType action) noexcept;
    void DoOperation(PoseHandler& poseHandler) const noexcept;
};

}  // namespace adas