#include "transistor.h"
#include <cstdlib>

void NMOS::gate0() {
    is_open = false;
}

void NMOS::gate1() {
    is_open = true;
    
    switch (source) {
        case 0:
            drain = 0;
            break;
        case 1:
            // give 'em weak voltage.
            // might want to make threshold
            // voltage changeable
            drain = 0.7;
            break;
        default:
            break;
    }
}

void NMOS::set_source(int v) {
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

void PMOS::gate0() {
    is_open = true;

    switch (source) {
        case 0:
            // give 'em weak voltage.
            // might want to make threshold
            // voltage changeable
            drain = 0.3;
            break;
        case 1:
            drain = 1;
            break;
        default:
            break;
    }
}

void PMOS::gate1() {
    is_open = false;
}

void PMOS::set_source(int v) {
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

int CMOS_example(int gate, int s_nmos, int s_pmos) {
    NMOS nmos(gate, s_nmos);
    PMOS pmos(gate, s_pmos);

    // very simple logic: don't allow two channels to flood output
    // at once. one must be disconnected.
    if (nmos.is_open == true && pmos.is_open == false) {
        return nmos.drain;
    } else if (pmos.is_open == true && nmos.is_open == false) {
        return pmos.drain;
    } else {
        std::exit(1);
    }

    return 0; // default case
}