#include <gtest/gtest.h>

#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas
{
// F: fast move 快速移动测试
TEST(ExecutorFastTest, should_return_x_plus_2_when_instruction_is_FM_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // Act
    executor->Execute("FM");

    // Assert
    const Pose target{2, 0, 'E'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorFastTest, should_return_N_and_x_plus_1_when_instruction_is_FL_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // Act
    executor->Execute("FL");

    // Assert
    const Pose target{1, 0, 'N'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorFastTest, should_return_S_and_x_plus_1_when_instruction_is_FR_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // Act
    executor->Execute("FR");

    // Assert
    const Pose target{1, 0, 'S'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorFastTest, should_return_y_plus_1_when_instruction_is_FFM_and_heading_is_N)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));

    // Act
    executor->Execute("FFM");

    // Assert
    const Pose target{0, 1, 'N'};
    ASSERT_EQ(executor->Query(), target);
}

// B: back move 后退测试
TEST(ExecutorBackTest, should_return_x_minus_1_when_instruction_is_BM_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // Act
    executor->Execute("BM");

    // Assert
    const Pose target{-1, 0, 'E'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorBackTest, should_return_S_when_instruction_is_BL_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // Act
    executor->Execute("BL");

    // Assert
    const Pose target{0, 0, 'S'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorBackTest, should_return_N_when_instruction_is_BR_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // Act
    executor->Execute("BR");

    // Assert
    const Pose target{0, 0, 'N'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorBackTest, should_return_y_plus_1_when_instruction_is_BBM_and_heading_is_N)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));

    // Act
    executor->Execute("BBM");

    // Assert
    const Pose target{0, 1, 'N'};
    ASSERT_EQ(executor->Query(), target);
}

// BF: back and fast move 后退和快速移动测试
TEST(ExecutorBackFastTest, should_return_x_minus_2_when_instruction_is_BFM_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // Act
    executor->Execute("BFM");

    // Assert
    const Pose target{-2, 0, 'E'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorBackFastTest, should_return_S_and_x_minus_1_when_instruction_is_BFL_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // Act
    executor->Execute("BFL");

    // Assert
    const Pose target{-1, 0, 'S'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(ExecutorBackFastTest, should_return_N_and_x_minus_1_when_instruction_is_BFR_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // Act
    executor->Execute("BFR");

    // Assert
    const Pose target{-1, 0, 'N'};
    ASSERT_EQ(executor->Query(), target);
}
}  // namespace adas