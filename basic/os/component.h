#include <cstdint>
#include <array>
#include <vector>

enum operation {
    ADD, SUBTRACT, MULTIPLY, DIVIDE,
    AND, OR, NOT, 
};

class Core {
    std::array<uint16_t, 16> registers;
    uint8_t pc;
    uint8_t ir;
    uint8_t alu(operation op, uint8_t op1, uint8_t op2 = 0x00);
};