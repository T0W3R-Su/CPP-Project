#include "ExecutorImpl.hpp"

#include <memory>

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
        default:
            break;
        }

        if (inst) {
            inst->DoOperate(*this);
        }
    }
}

const Pose ExecutorImpl::Query(void) const noexcept
{
    return pose;
}

}  // namespace adas