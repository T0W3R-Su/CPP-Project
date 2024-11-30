#include "ExecutorImpl.hpp"

#include <memory>
#include <unordered_map>

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
    // 指令映射，表驱动提升可拓展性
    std::unordered_map<char, std::unique_ptr<ICommand>> instructionMap;
    instructionMap.emplace('M', std::make_unique<MoveInstruction>());
    instructionMap.emplace('L', std::make_unique<TurnLeftInstruction>());
    instructionMap.emplace('R', std::make_unique<TurnRightInstruction>());
    instructionMap.emplace('F', std::make_unique<FastMoveInstruction>());

    for (const auto& ins : instruction) {
        const auto& iter = instructionMap.find(ins);

        if (iter != instructionMap.end()) {
            iter->second->DoOperate(poseHandler);
        }
    }
}

const Pose ExecutorImpl::Query(void) const noexcept
{
    return poseHandler.Query();
}
}  // namespace adas