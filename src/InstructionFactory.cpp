#include "InstructionFactory.hpp"

namespace adas
{
// 解析指令
std::string InstructionFactory::ParseInstructionString(std::string_view instructions) const noexcept
{
    std::string result(instructions);

    ReplaceAll(result, "TR", "Z");

    return result;
}

// 替换所有的指令
void InstructionFactory::ReplaceAll(std::string& inout, std::string_view what, std::string_view with) const noexcept
{
    for (std::string::size_type pos{}; inout.npos != (pos = inout.find(what.data(), pos, what.length()));
         pos += with.length()) {
        inout.replace(pos, what.length(), with.data(), with.length());
    }
}

InstructionList InstructionFactory::GetInstructions(const std::string& instruction) const noexcept
{
    InstructionList instructions;

    for (const auto ins : ParseInstructionString(instruction)) {
        const auto& iter = instructionMap.find(ins);

        if (iter != instructionMap.end()) {
            instructions.push_back(iter->second);
        }
    }

    return instructions;
}

}  // namespace adas