#include "arista.h"

arista::arista(int costo, int nodosid_1, int nodoid_2){
    this->costo = costo;
    this->nodoid_1 = nodosid_1;
    this->nodoid_2 = nodoid_2;
}

arista:: ~arista(){ }

void arista::print_arista(){
    int i = this->nodoid_1;
    int j = this->nodoid_2;
    int costo = this->costo;
    cout << endl;
    cout << "nodo 1 = ";
    cout << i;
    cout  << endl;
    cout << "nodo 2 = ";
    cout << j;
    cout << endl;
    cout << "costo = ";
    cout << costo;
}

int arista::get_costo(){
    return this->costo;
}

int arista::get_nodo_inicial(){
    return this->nodoid_1;
}

int arista::get_nodo_final(){
    return this->nodoid_2;
}