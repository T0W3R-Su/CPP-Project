#include "PoseHandler.hpp"

namespace adas
{
PoseHandler::PoseHandler(const Pose& pose) noexcept : pose(pose)
{
}

PoseHandler::~PoseHandler()
{
}

void PoseHandler::Move() noexcept
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

void PoseHandler::TurnLeft() noexcept
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

void PoseHandler::TurnRight() noexcept
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

void PoseHandler::FastMove() noexcept
{
    fastMoveFlag = !fastMoveFlag;
}

bool PoseHandler::IsFastMove() const noexcept
{
    return fastMoveFlag;
}

const Pose PoseHandler::Query() const noexcept
{
    return pose;
}

}  // namespace adas