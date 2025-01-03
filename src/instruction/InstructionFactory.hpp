#pragma once

#include <functional>
#include <list>
#include <unordered_map>

#include "Instruction.hpp"

namespace adas
{
using Instruction = std::function<ActionGroup(PoseHandler &poseHandler, CarType carType)>;
using InstructionList = std::list<Instruction>;

class InstructionFactory final
{
    // 指令映射
private:
    const std::unordered_map<char, Instruction> instructionMap{
        {'M',
         [](PoseHandler &poseHandler, CarType carType) -> ActionGroup {
             MoveInstruction moveInstruction;
             return moveInstruction(poseHandler, carType);
         }},
        {'L',
         [](PoseHandler &poseHandler, CarType carType) -> ActionGroup {
             TurnLeftInstruction turnLeftInstruction;
             return turnLeftInstruction(poseHandler, carType);
         }},
        {'R',
         [](PoseHandler &poseHandler, CarType carType) -> ActionGroup {
             TurnRightInstruction turnRightInstruction;
             return turnRightInstruction(poseHandler, carType);
         }},
        {'F',
         [](PoseHandler &poseHandler, CarType carType) -> ActionGroup {
             FastMoveInstruction fastMoveInstruction;
             return fastMoveInstruction(poseHandler, carType);
         }},
        {'B',
         [](PoseHandler &poseHandler, CarType carType) -> ActionGroup {
             ReverseInstruction reverseInstruction;
             return reverseInstruction(poseHandler, carType);
         }},
        {'Z',
         [](PoseHandler &poseHandler, CarType carType) -> ActionGroup {
             TurnRoundInstruction turnRoundInstruction;
             return turnRoundInstruction(poseHandler, carType);
         }}

    };  // 表驱动提升可拓展性

    // 解析指令
private:
    std::string ParseInstructionString(std::string_view instructions) const noexcept;
    void ReplaceAll(std::string &inout, std::string_view what, std::string_view with) const noexcept;

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