#include <gtest/gtest.h>

#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas
{
TEST(ExecutorTurnRoundTest, should_normal_tr_build_left_forward_left_forward)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // Act
    executor->Execute("TR");

    // Assert
    const Pose target{0, 1, 'W'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTurnRoundTest, should_fast_tr_build_forward_left_forward_left)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // Act
    executor->Execute("FTR");

    // Assert
    const Pose target{1, 1, 'W'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTurnRoundTest, in_the_B_state_the_reverse_instruction_is_invalid)
{
    // Arrange
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // Act
    executor->Execute("BTR");

    // Assert
    const Pose target{0, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}
}  // namespace adas