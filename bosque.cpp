#include "bosque.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>

bosque::bosque(){
    this->costo_total = 0;
}

bosque::~bosque(){
       // Liberar la memoria de los objetos arista apuntados por el conjunto
    for (arista* a : lista_aristas) {
        delete a;
    }
    // Limpiar el conjunto
    lista_aristas.clear();
}

/*
aristas** bosque::get_lista_aristas(){
    return this->lista_aristas;
}
*/
int bosque::get_costo_total()
{
    return this->costo_total;
}

void bosque::add_costo(int costo)
{
    int x = this->costo_total;
    x = x + costo;
    this->costo_total = x;
}

void bosque::readfile(string nombre_archivo){
    ifstream file(nombre_archivo); // es un stream de "FileInput" desde un archivo. 
    string line; // es un objeto que representa un arreglo de char que es auto ajustable.
    int count = 0; // cuenta la cantidad de nodos, linea a linea
    std::vector<std::vector<int>> matriz;  // se crea una matriz dinamica

    std::string linea;
    while (std::getline(file, linea)) { //recorremos todo el archivo de entrada y guardamos los datos en una matriz dinamica
        count++;
        std::vector<int> fila;
        std::istringstream ss(linea);
        int valor;

        while (ss >> valor) {
            fila.push_back(valor);
        }

        matriz.push_back(fila);
    }
    this->numero_nodos = count;
     for (size_t i = 0; i < matriz.size(); ++i) { //se recorre toda la matriz y se generan aristas con los valores de la matriz
        for (size_t j = i + 1; j < matriz[i].size(); ++j) {
            int costo = matriz[i][j];
            arista* nueva = new arista(costo, i, j);
            arista prueba = *nueva;
            lista_aristas.insert(nueva);
        }

    }
}


 std::multiset<arista*, Comparador>  bosque::get_lista_aritas(){
    return this->lista_aristas;
 }


std::vector<arista*> bosque::prim() {
    std::vector<bool> nodos_visitados(lista_aristas.size(), false); // crea un vector para guardar los nodos ya visitados
    std::vector<arista*> grafo_resultado; //vector de aristas que representa el grafo luego de aplicar prim
    std::priority_queue<arista*, std::vector<arista*>, Comparador> cola_prioridad;

    // Comienza desde el nodo con menor costo
    arista* primeraarista = *lista_aristas.begin();
    int nodo_inicial = primeraarista->get_nodo_inicial();
    int nodo_final = primeraarista->get_nodo_final();
    nodos_visitados[nodo_inicial] = true;
    for (arista* a : lista_aristas) { //obtiene todas las aristas que posean al nodo inicial
        if (a->get_nodo_inicial() == nodo_inicial) {
            cola_prioridad.push(a);
        }
    }


    while (!cola_prioridad.empty() && grafo_resultado.size() < numero_nodos - 1) {
        arista* a = cola_prioridad.top();
        cola_prioridad.pop();
        int nodo_inicial = a->get_nodo_inicial();
        int nodo_final = a->get_nodo_final();

        if (nodos_visitados[nodo_inicial] != nodos_visitados[nodo_final]) {  //revisa que no hayan ciclos
            nodos_visitados[nodo_final] = true;
            nodos_visitados[nodo_inicial] = true;
            grafo_resultado.push_back(a);
            add_costo(a->get_costo()); //aumenta el costo total del grafo
            for (arista* b : lista_aristas) { // revisa que las aristas que se agregaran para la siguiente iteracion no esten ya en la lista
               if ((b->get_nodo_inicial() == nodo_inicial || b->get_nodo_final() == nodo_inicial || b->get_nodo_inicial() == nodo_final || b->get_nodo_final() == nodo_final)  && (!nodos_visitados[b->get_nodo_final()] || !nodos_visitados[b->get_nodo_inicial()])) {
                    cola_prioridad.push(b); // si cumple con las condiciones se añade para otro ciclo

                }
            }
        }
    }

    return grafo_resultado; //retorna el grafo resultante
}



