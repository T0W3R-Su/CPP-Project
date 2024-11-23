#pragma once
#include "Executor.hpp"

namespace adas
{
class ExecutorImpl final : public Executor
{
public:
    explicit ExecutorImpl(const Pose& initialPose) noexcept;
    ~ExecutorImpl(void) noexcept = default;
    ExecutorImpl(const ExecutorImpl&) = delete;
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;

public:
    const Pose Query(void) const noexcept override;
    void Execute(const std::string& instruction) noexcept override;

private:
    Pose pose;
    bool fastMoveFlag = false;

private:
    // 虚基类，定义了所有的指令
    class ICommand
    {
    public:
        virtual ~ICommand(void) noexcept = default;
        virtual void DoOperate(ExecutorImpl& executor) const noexcept = 0;
    };

    // 移动类
    class MoveInstruction final : public ICommand
    {
    public:
        void DoOperate(ExecutorImpl& executor) const noexcept
        {
            if (executor.IsFastMove()) {
                executor.Move();
            }

            executor.Move();
        }
    };

    // 左转类
    class TurnLeftInstruction final : public ICommand
    {
    public:
        void DoOperate(ExecutorImpl& executor) const noexcept
        {
            if (executor.IsFastMove()) {
                executor.Move();
            }

            executor.TurnLeft();
        }
    };

    // 右转类
    class TurnRightInstruction final : public ICommand
    {
    public:
        void DoOperate(ExecutorImpl& executor) const noexcept
        {
            if (executor.IsFastMove()) {
                executor.Move();
            }

            executor.TurnRight();
        }
    };

    // 快速移动类
    class FastMoveInstruction final : public ICommand
    {
    public:
        void DoOperate(ExecutorImpl& executor) const noexcept
        {
            executor.FastMove();
        }
    };

private:
    void Move(void) noexcept;
    void TurnLeft(void) noexcept;
    void TurnRight(void) noexcept;
    void FastMove(void) noexcept;
    bool IsFastMove(void) const noexcept;
};
}  // namespace adas
