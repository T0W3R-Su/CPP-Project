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
    std::unique_ptr<Executor> executor(Executor::NewExecutor());

    // Act

    // Assert
    const Pose target{0, 0, 'N'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorTest, should_return_x_plus_1_when_instruction_is_M_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // Act
    executor->Execute("M");

    // Assert
    const Pose target{1, 0, 'E'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorTest, should_return_x_minus_1_when_instruction_is_M_and_heading_is_W)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));

    // Act
    executor->Execute("M");

    // Assert
    const Pose target{-1, 0, 'W'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorTest, should_return_y_plus_1_when_instruction_is_M_and_heading_is_N)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));

    // Act
    executor->Execute("M");

    // Assert
    const Pose target{0, 1, 'N'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorTest, should_return_y_minus_1_when_instruction_is_M_and_heading_is_S)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));

    // Act
    executor->Execute("M");

    // Assert
    const Pose target{0, -1, 'S'};
    ASSERT_EQ(executor->Query(), target);
}

}  // namespace adas