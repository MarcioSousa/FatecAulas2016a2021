typedef struct SDNODO TDNODO;
typedef char TINFO;

struct SDNODO {
    TDNODO * ant;
    TINFO info;
    TDNODO * prox;
};
