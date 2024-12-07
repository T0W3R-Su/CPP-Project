#include "InstructionFactory.hpp"

namespace adas
{
InstructionList InstructionFactory::GetInstructions(const std::string& instruction) const noexcept
{
    InstructionList instructions;

    for (const auto& ins : instruction) {
        const auto& iter = instructionMap.find(ins);

        if (iter != instructionMap.end()) {
            instructions.push_back(iter->second);
        }
    }

    return instructions;
}

}  // namespace adas