#pragma once
#include "Executor.hpp"
#include "PoseHandler.hpp"

namespace adas
{
class ExecutorImpl final : public Executor
{
private:
    PoseHandler poseHandler;
    CarType carType;
    // 初始化和销毁
public:
    explicit ExecutorImpl(const Pose& initialPose, const CarType carType) noexcept;
    ~ExecutorImpl(void) noexcept = default;
    ExecutorImpl(const ExecutorImpl&) = delete;
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;

public:
    void Execute(const std::string& instruction) noexcept override;

    const Pose Query(void) const noexcept override;
};
}  // namespace adas
