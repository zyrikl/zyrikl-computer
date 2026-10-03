#include "component.h"

uint8_t Core::alu(operation op, uint8_t op1, uint8_t op2) {
    switch (op) {
        case ADD:
            return op1+op2;
            break;
        case SUBTRACT:
            return op1-op2;
            break;
        case MULTIPLY;
            return op1*op2;
            break;
        case DIVIDE:
            return op1/op2;
            break;
        default;
            break;
    }

    return 0;
}