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

// L: turn left
TEST(ExecutorTest, should_return_heading_W_when_instruction_is_L_and_heading_is_N)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));

    // Act
    executor->Execute("L");

    // Assert
    const Pose target{0, 0, 'W'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorTest, should_return_heading_N_when_instruction_is_L_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // Act
    executor->Execute("L");

    // Assert
    const Pose target{0, 0, 'N'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorTest, should_return_heading_E_when_instruction_is_L_and_heading_is_S)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));

    // Act
    executor->Execute("L");

    // Assert
    const Pose target{0, 0, 'E'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorTest, should_return_heading_S_when_instruction_is_L_and_heading_is_W)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));

    // Act
    executor->Execute("L");

    // Assert
    const Pose target{0, 0, 'S'};
    ASSERT_EQ(executor->Query(), target);
}

// R: turn right
TEST(ExecutorTest, should_return_heading_E_when_instruction_is_R_and_heading_is_N)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));

    // Act
    executor->Execute("R");

    // Assert
    const Pose target{0, 0, 'E'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorTest, should_return_heading_S_when_instruction_is_R_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // Act
    executor->Execute("R");

    // Assert
    const Pose target{0, 0, 'S'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorTest, should_return_heading_W_when_instruction_is_R_and_heading_is_S)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));

    // Act
    executor->Execute("R");

    // Assert
    const Pose target{0, 0, 'W'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorTest, should_return_heading_N_when_instruction_is_R_and_heading_is_W)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));

    // Act
    executor->Execute("R");

    // Assert
    const Pose target{0, 0, 'N'};
    ASSERT_EQ(executor->Query(), target);
}

// F: fast move
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