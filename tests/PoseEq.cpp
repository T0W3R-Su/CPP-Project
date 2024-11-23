#include "PoseEq.hpp"

#include <tuple>

namespace adas
{
bool operator==(const Pose& lhs, const Pose& rhs)
{
    // 为 Pose 重载 ==，测试时可以直接比较两个 Pose 对象
    return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
}
}  // namespace adas