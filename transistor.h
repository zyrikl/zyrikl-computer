#pragma once

struct State {
    float value = 0;
    bool is_open = true;
};

class Transistor {
public:
    virtual ~Transistor() = 0;
};

class NMOS : public Transistor {
public:
    int source = 0;
    State drain;

    void gate0();
    void gate1();
    void set_source(int v);

    NMOS(int gate, int s = 0);
    NMOS(int gate, State s_state);
};

class PMOS : public Transistor {
public:
    int source = 0;
    State drain;

    void gate0();
    void gate1();
    void set_source(int v);

    PMOS(int gate, int s = 0);
    PMOS(int gate, State s_state);
};

// all transistor-related functions should return a State
// struct to prevent mix-up
State combine_output(State s1, State s2);