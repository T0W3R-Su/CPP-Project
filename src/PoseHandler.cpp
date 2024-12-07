#include "PoseHandler.hpp"

namespace adas
{
// PoseHandler
PoseHandler::PoseHandler(const Pose& pose) noexcept
    : point(pose.x, pose.y), facing(&Direction::GetDirection(pose.heading))
{
}

PoseHandler::~PoseHandler()
{
}

void PoseHandler::Move() noexcept
{
    if (reverseMoveFlag) {
        point -= facing->Move();
    } else {
        point += facing->Move();
    }
}

void PoseHandler::TurnLeft() noexcept
{
    facing = &(facing->TurnLeft());
}

void PoseHandler::TurnRight() noexcept
{
    facing = &(facing->TurnRight());
}

void PoseHandler::FastMove() noexcept
{
    fastMoveFlag = !fastMoveFlag;
}

bool PoseHandler::IsFastMove() const noexcept
{
    return fastMoveFlag;
}

void PoseHandler::ReverseMove(void) noexcept
{
    reverseMoveFlag = !reverseMoveFlag;
}

bool PoseHandler::IsReverseMove(void) const noexcept
{
    return reverseMoveFlag;
}

const Pose PoseHandler::Query(void) const noexcept
{
    return {point.GetX(), point.GetY(), facing->GetHeading()};
}

// Direction
static const Direction directions[4] = {{0, 'E'}, {1, 'S'}, {2, 'W'}, {3, 'N'}};

Direction::Direction(const unsigned index, const char heading) noexcept
{
    this->index = index;
    this->heading = heading;
}

const Direction& Direction::GetDirection(const char heading) noexcept
{
    for (const auto& direction : directions) {
        if (direction.heading == heading) {
            return direction;
        }
    }
    return directions[3];
}

const char Direction::GetHeading(void) const noexcept
{
    return heading;
}

const Point& Direction::Move(void) const noexcept
{
    // ESWN
    static const Point point[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    return point[index];
}

const Direction& Direction::TurnLeft(void) const noexcept
{
    return directions[(index + 3) % 4];
}

const Direction& Direction::TurnRight(void) const noexcept
{
    return directions[(index + 1) % 4];
}

// Point
Point::Point(const int x, const int y) noexcept : x(x), y(y)
{
}

Point::Point(const Point& rhs) noexcept : x(rhs.x), y(rhs.y)
{
}

Point& Point::operator=(const Point& rhs) noexcept
{
    x = rhs.x;
    y = rhs.y;
    return *this;
}

Point& Point::operator+=(const Point& rhs) noexcept
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Point& Point::operator-=(const Point& rhs) noexcept
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

int Point::GetX(void) const noexcept
{
    return x;
}

int Point::GetY(void) const noexcept
{
    return y;
}

}  // namespace adas