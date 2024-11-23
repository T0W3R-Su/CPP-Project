#include <gtest/gtest.h>

#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas
{
// F: fast move 快速移动测试
TEST(ExecutorTest, should_return_x_plus_2_when_status_is_fast_move_and_instruction_is_M_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // Act
    executor->Execute("FM");

    // Assert
    const Pose target{2, 0, 'E'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorTest, should_return_N_and_x_plus_1_when_status_is_fast_move_and_instruction_is_L_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // Act
    executor->Execute("FL");

    // Assert
    const Pose target{1, 0, 'N'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorTest, should_return_S_and_x_plus_1_when_status_is_fast_move_and_instruction_is_R_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // Act
    executor->Execute("FR");

    // Assert
    const Pose target{1, 0, 'S'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorTest, should_return_y_plus_1_when_instruction_is_FFM_and_heading_is_N)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));

    // Act
    executor->Execute("FFM");

    // Assert
    const Pose target{0, 1, 'N'};
    ASSERT_EQ(executor->Query(), target);
}
}  // namespace adas