#include "bosque.h"

int main(int argc, char const *argv[])
{
    bosque b = bosque();
    b.add_costo(33);
    b.add_costo(1);
    int costo =  b.get_costo_total();
    cout << "costo del arbol de prueba = " << costo << endl;
    return 0;
}
