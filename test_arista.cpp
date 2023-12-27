#include "arista.h"

int main(int argc, char const *argv[])
{
    int costo = 10;
    int nodosid_1 = 1;
    int nodoid_2 = 2;

    arista a(costo, nodosid_1, nodoid_2);
    a.print_arista();
    return 0;
}
