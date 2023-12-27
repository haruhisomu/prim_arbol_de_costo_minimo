#include <iostream>

using namespace std;

class arista{
    public:
    int costo;
    int nodoid_1;
    int nodoid_2;
    public:
    //constructor
    arista(int costo, int nodoid_1, int nodoid_2);
    // destructor
    ~arista();
    //capa selectora

    // entrada: void
    // salida: int
    // descripcion: obtiene el costo de cada arista
    int get_costo();
    // otros

    // entrada: void
    // salida: void
    // desripcion: imprime los nodos inciales y finales de la arista, y su costo
    void print_arista();

    // entrada: void
    // salida: int
    // descripcion: obtiene el nodo inicial de la arista
    int get_nodo_inicial();

    //entrada: void
    //salida: int
    //descripcion: obtiene el nodo final de la arista
    int get_nodo_final();
};