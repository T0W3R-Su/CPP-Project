#include <gtest/gtest.h>

#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas
{
// Normal
TEST(SportsCarTest, should_return_x_plus_2_when_instruction_is_M_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, CarType::SportsCar));

    // Act
    executor->Execute("M");

    // Assert
    const Pose target{2, 0, 'E'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(SportsCarTest, should_return_N_and_y_plus_1_when_instruction_is_L_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, CarType::SportsCar));

    // Act
    executor->Execute("L");

    // Assert
    const Pose target{0, 1, 'N'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(SportsCarTest, should_return_S_and_y_minus_1_when_instruction_is_R_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, CarType::SportsCar));

    // Act
    executor->Execute("R");

    // Assert
    const Pose target{0, -1, 'S'};
    ASSERT_EQ(executor->Query(), target);
}

// Fast
TEST(SportsCarTest, should_return_x_plus_4_when_instruction_is_FM_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, CarType::SportsCar));

    // Act
    executor->Execute("FM");

    // Assert
    const Pose target{4, 0, 'E'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(SportsCarTest, should_return_N_and_x_plus_1_and_y_plus_1_when_instruction_is_FL_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, CarType::SportsCar));

    // Act
    executor->Execute("FL");

    // Assert
    const Pose target{1, 1, 'N'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(SportsCarTest, should_return_S_and_x_plus_1_and_y_minus_1_when_instruction_is_FR_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, CarType::SportsCar));

    // Act
    executor->Execute("FR");

    // Assert
    const Pose target{1, -1, 'S'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(SportsCarTest, SportsCarTest_should_return_x_plus_2_when_instruction_is_FFM_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, CarType::SportsCar));

    // Act
    executor->Execute("FFM");

    // Assert
    const Pose target{2, 0, 'E'};
    ASSERT_EQ(executor->Query(), target);
}

// Back
TEST(SportsCarTest, should_return_x_minus_2_when_instruction_is_BM_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, CarType::SportsCar));

    // Act
    executor->Execute("BM");

    // Assert
    const Pose target{-2, 0, 'E'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(SportsCarTest, should_return_S_and_y_plus_1_when_instruction_is_BL_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, CarType::SportsCar));

    // Act
    executor->Execute("BL");

    // Assert
    const Pose target{0, 1, 'S'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(SportsCarTest, should_return_N_and_y_minus_1_when_instruction_is_BR_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, CarType::SportsCar));

    // Act
    executor->Execute("BR");

    // Assert
    const Pose target{0, -1, 'N'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(SportsCarTest, should_return_x_plus_2_when_instruction_is_BBM_and_heading_is_N)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}, CarType::SportsCar));

    // Act
    executor->Execute("BBM");

    // Assert
    const Pose target{0, 2, 'N'};
    ASSERT_EQ(executor->Query(), target);
}

// Fast and Back
TEST(SportsCarTest, should_return_x_minus_4_when_instruction_is_FBM_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, CarType::SportsCar));

    // Act
    executor->Execute("FBM");

    // Assert
    const Pose target{-4, 0, 'E'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(SportsCarTest, should_return_S_and_x_minus_1_and_y_plus_1_when_instruction_is_FBL_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, CarType::SportsCar));

    // Act
    executor->Execute("FBL");

    // Assert
    const Pose target{-1, 1, 'S'};
    ASSERT_EQ(executor->Query(), target);
}

TEST(SportsCarTest, should_return_N_and_x_minus_1_and_y_minus_1_when_instruction_is_FBR_and_heading_is_E)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, CarType::SportsCar));

    // Act
    executor->Execute("FBR");

    // Assert
    const Pose target{-1, -1, 'N'};
    ASSERT_EQ(executor->Query(), target);
}

}  // namespace adas