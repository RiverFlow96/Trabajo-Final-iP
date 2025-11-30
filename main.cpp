#include <iostream>
#include <vector>

using namespace std;

struct Resultados
{
    int total;
    int mayor;
    int menor;
    bool necesita_mantenimiento;
};


//Funcion para calcular el total
Resultados Funcionalidades(int tiradas, int cant_productos, vector<vector<int>>& array){
    int total = 0;
    vector<int>total_por_tiradas(tiradas, 0);
    int tirada_menor = 0;
    int tirada_mayor = 0;
    bool necesita_mantenimiento = false;

    // calculo del total
    for (int tirada = 0; tirada < tiradas; tirada++){
        for(int producto = 0; producto < cant_productos; producto++){
            total += array[tirada][producto];
            total_por_tiradas[tirada] += array[tirada][producto];
        }
    }

    // Mostrar tirada de menor cantidad de defectos
    for (int tirada = 1; tirada < tiradas; tirada++){
        if(total_por_tiradas[tirada-1] < total_por_tiradas[tirada]) {
            tirada_menor = tirada-1;
        }
        else tirada_menor = tirada;
        
        if(total_por_tiradas[tirada-1] > total_por_tiradas[tirada]) {
            tirada_mayor = tirada-1;
        }
        else tirada_mayor = tirada;
    }

    // Funcionalidad de eficiencia
    if ((total_por_tiradas.back() + total_por_tiradas[total_por_tiradas.size() - 2]) > 150) necesita_mantenimiento = true;

    return {total, tirada_mayor+1, tirada_menor+1, necesita_mantenimiento};

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
    cout<<"El total de productos es: "<<resultados.total<<endl;
    cout<<"La tirada con menor defectos en sus productos fue: "<<resultados.menor<<endl;
    cout<<"La tirada con mayor defectos en sus productos fue: "<<resultados.mayor<<endl;
    resultados.necesita_mantenimiento == true ? cout<<"El horno necesita mantenimiento"<<endl : cout<<"El horno no necesita mantenimiento"<<endl;

    return 0;
}