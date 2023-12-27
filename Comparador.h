#include "arista.h"
#include <iostream>

class Comparador{
     public:
     // entrada: arista* a, arista* b
     // salida: bool
     // descripcion: este metodo compara dos aristas es utilizado exclusivamente para la estructura set
     bool operator()(const arista* a, const arista* b) const;
};
