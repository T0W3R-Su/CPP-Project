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
    std::unordered_map<char, std::function<void(PoseHandler & poseHandler)>> instructionMap;

    MoveInstruction moveInstruction;
    instructionMap.emplace('M', moveInstruction.operate);

    TurnLeftInstruction turnLeftInstruction;
    instructionMap.emplace('L', turnLeftInstruction.operate);

    TurnRightInstruction turnRightInstruction;
    instructionMap.emplace('R', turnRightInstruction.operate);

    FastMoveInstruction fastMoveInstruction;
    instructionMap.emplace('F', fastMoveInstruction.operate);

    for (const auto& ins : instruction) {
        const auto& iter = instructionMap.find(ins);

        if (iter != instructionMap.end()) {
            iter->second(poseHandler);
        }
    }
}

const Pose ExecutorImpl::Query(void) const noexcept
{
    return poseHandler.Query();
}
}  // namespace adas