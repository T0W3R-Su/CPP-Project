#pragma once

#include <functional>
#include <list>
#include <unordered_map>

#include "Instruction.hpp"

namespace adas
{
using Instruction = std::function<void(PoseHandler &poseHandler)>;
using InstructionList = std::list<Instruction>;

class InstructionFactory final
{
    // 指令映射
private:
    const std::unordered_map<char, std::function<void(PoseHandler &poseHandler)>> instructionMap{
        {'M', MoveInstruction()},
        {'L', TurnLeftInstruction()},
        {'R', TurnRightInstruction()},
        {'F', FastMoveInstruction()},
        {'B', ReverseInstruction()}};  // 表驱动提升可拓展性

    // 初始化和销毁
public:
    InstructionFactory(void) = default;
    ~InstructionFactory(void) noexcept = default;
    InstructionFactory(const InstructionFactory &) noexcept = delete;
    InstructionFactory &operator=(const InstructionFactory &) noexcept = delete;

    // 通过指令获取对应的操作
public:
    InstructionList GetInstructions(const std::string &instruction) const noexcept;
};
}  // namespace adas