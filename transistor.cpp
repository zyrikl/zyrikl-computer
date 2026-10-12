#include "transistor.h"
#include <cstdlib>
#include <iostream>

Transistor::~Transistor() {}

void NMOS::gate0() {
    drain.is_open = false;
}

void NMOS::gate1() {
    drain.is_open = true;
    
    switch (source) {
        case 0:
            drain.value = 0;
            break;
        case 1:
            // give 'em weak voltage.
            // might want to make threshold
            // voltage changeable
            drain.value = 0.7;
            break;
        default:
            break;
    }
}

void NMOS::set_source(int v) {
    // this just swaps out the source. to update
    // gate as well run gate#()
    source = v;
}

NMOS::NMOS(int gate, int s) {
    source = s;
    switch (gate) {
        case 0:
            gate0();
            break;
        case 1:
            gate1();
            break;
        default:
            break;
    }
}

NMOS::NMOS(int gate, State s_state) {
    if (s_state.is_open) {
        // handle like any other
        source = s_state.value;

        switch (gate) {
            case 0:
                gate0();
                break;
            case 1:
                gate1();
                break;
            default:
                break;
        }
    } else {
        drain.is_open = false;
    }
}

void PMOS::gate0() {
    drain.is_open = true;

    switch (source) {
        case 0:
            // give 'em weak voltage.
            // might want to make threshold
            // voltage changeable
            drain.value = 0.3;
            break;
        case 1:
            drain.value = 1;
            break;
        default:
            break;
    }
}

void PMOS::gate1() {
    drain.is_open = false;
}

void PMOS::set_source(int v) {
    // this just swaps out the source. to update
    // gate as well run gate#()
    source = v;
}

PMOS::PMOS(int gate, int s) {
    source = s;
    switch (gate) {
        case 0:
            gate0();
            break;
        case 1:
            gate1();
            break;
        default:
            break;
    }
}

State combine_output(State s1, State s2) {
    State rval;

    if (s1.is_open && !s2.is_open) {
        rval.value = s1.value;
    } else if (!s1.is_open && s2.is_open) {
        rval.value = s2.value;
    } else if (!s1.is_open && !s2.is_open) {
        rval.is_open = false;
    } else if (s1.is_open && s2.is_open) {
        if (s1.value == 0 && s2.value == 0) {
            rval.value = 0;
        } else if (s1.value == 1 && s2.value == 1) {
            rval.value = 1;
        } else {
            std::cerr << "Short circuit!" << std::endl;
            std::exit(1);
        }
    } else {
        std::cerr << "Unexpected behavior received (transistor.cpp, line 110)" << std::endl;
        std::exit(1);
    }
    
    return rval;
}