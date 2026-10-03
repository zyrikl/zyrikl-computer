class NMOS {
public:
    int source = 0;
    int drain = 0;
    bool is_open = false;

    void gate0();
    void gate1();
    void set_source(int v);

    NMOS(int gate, int s = 0);
};

class PMOS {
public:
    int source = 0;
    int drain = 0;
    bool is_open = false;

    void gate0();
    void gate1();
    void set_source(int v);

    PMOS(int gate, int s = 0);
};

int CMOS_example(int gate, int s_nmos = 0, int s_pmos = 1);