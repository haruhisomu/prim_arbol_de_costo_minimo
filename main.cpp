#include <iostream>
#include <fstream> // para trabajar con archivos
#include <string> // para tener objetos de arreglos de char de largo autoincrementable
#include <sstream> // para trabajar con streams de strings
#include "bosque.h"
#include <ctime>

using namespace std;

int main(){
int verificador = 0; //condicion para salir del buble while y por ende finalizar el programa
cout << "----------------------------------------------";
cout << endl;
cout << "Hola, este es un programa para obtener un arbol de recubrimiento minimo";
cout << endl;
cout << "----------------------------------------------";
cout << endl;


//asegurar que el ciclo se repita hasta que se elija la opcion de salir
while(verificador == 0){
    string nombre_archivo; 
    cout << "por favor ingrese el nombre del archivo de la matriz de costos: ";
    cout << endl;
    getline(cin,nombre_archivo); //leer el nombre del archivo
    cout << endl;
    std::ifstream archivo(nombre_archivo);

    if(archivo.is_open()){ //revisa si el archivo se habrio correctamente, de ser asi aplica prim

        bosque bosque_a_talar = bosque();
        bosque_a_talar.readfile(nombre_archivo); //se crean las aristas de todo el arbol, se guardan dentro del objeto bosque_a_talar 
         clock_t start = clock();   //empezar a registrar el tiempo del codigo
        std::vector<arista*> arbol_podado = bosque_a_talar.prim(); //aplicar prim, retorna un vector
        clock_t end = clock(); //terminar de registrar el tiempo de ejecucion del codigo
        double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC; //calcula el tiempo de ejecucion del programa

        cout << "arbol resultante: ";
        cout << endl;
        for(int i =0 ; i < arbol_podado.size(); i++){ //imprime todo el arbol de recubrimiento minimo
            int nodo_inicial = arbol_podado[i]->get_nodo_inicial();
            int nodo_final = arbol_podado[i]->get_nodo_final();
            int costo = arbol_podado[i] ->get_costo();
            cout << "-------------------------------------------------------------------" << endl;
            cout << "nodo inicial: " << nodo_inicial;
            cout << endl;
            cout <<  "nodo final: " << nodo_final;
            cout << endl;
            cout << "costo del movimiento: " << costo;
            cout << endl;

        }

        cout << "-----------------------------------------------------------------------" << endl;
        cout << "costo total del arbol: " << bosque_a_talar.get_costo_total() << endl; 
        cout << endl;
        cout << "tiempo de ejecucion: " << elapsed_time; //imprime el tiempo de ejecucion del programa
        cout << endl;
    //    bosque_a_talar.~bosque(); //libera memoria
        cout << "¿desea ingresar otro archivo?" << endl;
        cout << "si desea ingresar otro archivo presione 1" << endl;
        cout << "si desea salir del programa ingrese otro numero" << endl;
        int utilidad = 0;
        cin >> utilidad; //guarda el valor ingresado por el usuario

        if(utilidad == 1){
            verificador = 0;
     }
        else{
            verificador = 1;
        }
        cin.ignore(); //elimina posibles saltos de linea o espacios de la lectura por consola
       
    }
    else{ //si no se ingreso un archivo valido o un archivo inexistente, se vuelve a solicitar el archivo
        cout <<"ingreso mal el nombre del archivo, intentelo otra vez" << endl;
        verificador = 0;
    }
}
return 0;
}
