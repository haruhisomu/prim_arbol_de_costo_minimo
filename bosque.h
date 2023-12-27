#include <iostream>
#include <fstream> // para trabajar con archivos
#include <string> // para tener objetos de arreglos de char de largo autoincrementable
#include <sstream> // para trabajar con streams de strings
#include "Comparador.h"
#include <set>
#include <vector>
class bosque{

    private:
    std::multiset<arista*, Comparador> lista_aristas; //set donde estan todas las aristas de la matriz de costos
    int costo_total; //costo total del arbol de recubrimiento minimo
    int numero_nodos;
    public:
    //constructor
    bosque();
    //destructor
    ~bosque();
    //selectores

    // entrada:void
    // salida: int
    // descripcion: este metodo permite obtener el costo total del grafo de costo minimo 
    int get_costo_total();

    // entrada: void
    // salida: set de aristas ordenadas por su costo
    // descripcion: esta funcion obtiene el set de aristas guardado en el objeto arbol.
    std::multiset<arista*, Comparador> get_lista_aritas();
    //modificador

    //entrada: int costo
    //salida void
    //descripcion: modifica el costo total del arbol.
    void add_costo(int costo);
    //otros

    //entrada: string nombre_archivo
    //salida: void
    //descripcion: lee el archivo de entrada y devuelve una lista de nodos. 
    void readfile(string nombre_archivo);

    //entrada: void
    //salida: vector de aristas
    //descripcion: aplica el algoritmo de prim para obtener el arbol minimo recubridor de costo minimo
    std::vector<arista*> prim();
};