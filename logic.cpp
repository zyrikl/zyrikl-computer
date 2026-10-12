#include "logic.h"
#include "transistor.h"
#include <cstdlib>
#include <iostream>

State not_gate(State s) {
    if (s.is_open) {
        State rval;
        NMOS t1(s.value);
        PMOS t2(s.value);

        rval.value = combine_output(t1.drain, t2.drain).value;

        return rval;
    } else {
        std::cerr << "Not able to NOT a disconnected state." << std::endl;
        std::exit(1);
    }
}

State not_gate(int i) {
    NMOS t1(i, 0);
    PMOS t2(i, 1);

    return combine_output(t1.drain, t2.drain);
}

State nand_gate(State s1, State s2) {
    if (s1.is_open && s2.is_open) {
        NMOS n1(s1.value, 0);
        NMOS n2(s2.value, 0);
        PMOS p1(s1.value, 1);
        PMOS p2(s2.value, 1);

        return combine_output(
            combine_output(p1.drain, p2.drain),
            combine_output(n1.drain, n2.drain)
        );
    } else {
        std::cerr << "At least one input to AND gate is disconnected." << std::endl;
        std::exit(1);
    }
}

State nand_gate(int i1, int i2) {
    NMOS n1(i1, 0);
    NMOS n2(i2, n1.drain);
    PMOS p1(i1, 1);
    PMOS p2(i2, 1);

    return combine_output(
        combine_output(p1.drain, p2.drain),
        n2.drain
    );
}