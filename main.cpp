#include <iostream>
#include <vector>

using namespace std;

struct Resultados
{
    int total;
};


//Funcion para calcular el total
Resultados Funcionalidades(int tiradas, int cant_productos, vector<vector<int>>& array){
    int total = 0;

    for (int tirada = 0; tirada < tiradas; tirada++){
        for(int producto = 0; producto < cant_productos; producto++){
            total += array[tirada][producto];
        }
    }

    return {total};

}

int main(){

    int tiradas = 3;
    int cant_productos = 4;

    // Valores por pantalla
    cout<<"Ingrese la cantidad de tiradas: ";
    cin>>tiradas;

    cout<<"Ingrese la cantidad de productos por tiradas: ";
    cin>>cant_productos;
    
    // Inicializando vector de defectos
    vector<vector<int>> defectos(tiradas, vector<int>(cant_productos)); 

    cout<<"CANTIDAD DE DEFECTOS"<<endl;

    // Recorriendo el vector y rellenando
    for(int i = 0; i < tiradas; i++){
        cout<<"---Tirada "<<i+1<<"---"<<endl;
        for(int j = 0; j < cant_productos; j++){
            cout<<"Producto "<<j+1<<": ";
            cin>>defectos[i][j];
        }
    }
 
    Resultados resultados = Funcionalidades(tiradas, cant_productos, defectos);
    //Imprimiendo Total
    cout<<"El total de productos es: "<<resultados.total;

    return 0;
}