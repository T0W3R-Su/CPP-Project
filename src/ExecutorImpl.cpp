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

void ExecutorImpl::Move(void) noexcept
{
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
}

void ExecutorImpl::TurnLeft(void) noexcept
{
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
}

void ExecutorImpl::TurnRight(void) noexcept
{
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
}

void ExecutorImpl::Execute(const std::string& instruction) noexcept
{
    for (const auto ins : instruction) {
        switch (ins) {
        case 'M':
            Move();
            break;
        case 'L':
            TurnLeft();
            break;
        case 'R':
            TurnRight();
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