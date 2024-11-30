#include "ExecutorImpl.hpp"

#include <memory>

#include "Instruction.hpp"

namespace adas
{
Executor* Executor::NewExecutor(const Pose& initialPose) noexcept
{
    return new ExecutorImpl(initialPose);
}

ExecutorImpl::ExecutorImpl(const Pose& initialPose) noexcept : poseHandler(initialPose)
{
}

void ExecutorImpl::Execute(const std::string& instruction) noexcept
{
    for (const auto ins : instruction) {
        // 使用继承和虚函数的方式，实现了多态

        std::unique_ptr<ICommand> inst;

        switch (ins) {
        case 'M':
            inst = std::make_unique<MoveInstruction>();
            break;
        case 'L':
            inst = std::make_unique<TurnLeftInstruction>();
            break;
        case 'R':
            inst = std::make_unique<TurnRightInstruction>();
            break;
        case 'F':
            inst = std::make_unique<FastMoveInstruction>();
            break;
        default:
            break;
        }

        if (inst) {
            inst->DoOperate(poseHandler);
        }
    }
}

const Pose ExecutorImpl::Query(void) const noexcept
{
    return poseHandler.Query();
}
}  // namespace adas