#include "ExecutorImpl.hpp"

namespace adas
{
Executor* Executor::NewExecutor(const Pose& initialPose) noexcept
{
    return new ExecutorImpl(initialPose);
}

ExecutorImpl::ExecutorImpl(const Pose& initialPose) noexcept : pose(initialPose)
{
}

void ExecutorImpl::Execute(const std::string& instruction) noexcept
{
    for (const auto ins : instruction) {
        switch (ins) {
        case 'M':
            switch (pose.heading) {
            case 'N':
                pose.y++;
                break;
            case 'E':
                pose.x++;
                break;
            case 'S':
                pose.y--;
                break;
            case 'W':
                pose.x--;
                break;
            }
        }
    }
}

const Pose ExecutorImpl::Query(void) const noexcept
{
    return pose;
}

}  // namespace adas