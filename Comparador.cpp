#include "Comparador.h"

bool Comparador::operator()(const arista* a, const arista* b) const {
    int costo1 = a->costo;
    int costo2 = b->costo;
    return costo1 > costo2;
}