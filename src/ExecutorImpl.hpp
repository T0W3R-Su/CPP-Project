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
};
}  // namespace adas
