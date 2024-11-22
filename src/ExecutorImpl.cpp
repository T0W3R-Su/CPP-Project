#include "ExecutorImpl.hpp"

namespace adas
{
Executor* Executor::NewExecutor(const Pose& initialPose) noexcept
{
    return new ExecutorImpl(initialPose);
}

ExecutorImpl::ExecutorImpl(const Pose& initialPose) noexcept
{
}

void ExecutorImpl::Execute(const std::string& instruction) noexcept
{
}

const Pose ExecutorImpl::Query(void) const noexcept
{
    return pose;
}

}  // namespace adas