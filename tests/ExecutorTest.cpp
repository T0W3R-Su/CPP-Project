#include <gtest/gtest.h>

#include "Executor.hpp"

namespace adas
{
bool operator==(const Pose& lhs, const Pose& rhs)
{
    // 为 Pose 重载 ==，测试时可以直接比较两个 Pose 对象
    return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
}

TEST(ExecutorTest, should_return_initial_pose_when_no_instruction)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // Act

    // Assert
    const Pose target{0, 0, 'E'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorTest, should_return_default_pose_when_no_init_and_no_instruction)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({}));

    // Act

    // Assert
    const Pose target{0, 0, 'N'};
    ASSERT_EQ(executor->Query(), target);
}
}  // namespace adas