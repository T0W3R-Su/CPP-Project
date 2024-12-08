#include "ExecutorImpl.hpp"

#include <algorithm>
#include <memory>
#include <unordered_map>

#include "Instruction.hpp"
#include "InstructionFactory.hpp"
#include "Singleton.hpp"
#include "functional"

namespace adas
{
Executor* Executor::NewExecutor(const Pose& initialPose) noexcept
{
    return new ExecutorImpl(initialPose);
}

ExecutorImpl::ExecutorImpl(const Pose& initialPose) noexcept : poseHandler(initialPose)
{
}

void ExecutorImpl::Execute(const std::string& ins) noexcept
{
    const auto instructions = Singleton<InstructionFactory>::Instance().GetInstructions(ins);

    std::for_each(instructions.begin(), instructions.end(),
                  [this](const Instruction& instruction) { instruction(poseHandler).DoOperation(poseHandler); });
}

const Pose ExecutorImpl::Query(void) const noexcept
{
    return poseHandler.Query();
}
}  // namespace adas