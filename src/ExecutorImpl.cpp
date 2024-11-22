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
            default:
                break;
            }
            break;
        case 'L':
            switch (pose.heading) {
            case 'N':
                pose.heading = 'W';
                break;
            case 'E':
                pose.heading = 'N';
                break;
            case 'S':
                pose.heading = 'E';
                break;
            case 'W':
                pose.heading = 'S';
                break;
            default:
                break;
            }
            break;
        case 'R':
            switch (pose.heading) {
            case 'N':
                pose.heading = 'E';
                break;
            case 'E':
                pose.heading = 'S';
                break;
            case 'S':
                pose.heading = 'W';
                break;
            case 'W':
                pose.heading = 'N';
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

const Pose ExecutorImpl::Query(void) const noexcept
{
    return pose;
}

}  // namespace adas