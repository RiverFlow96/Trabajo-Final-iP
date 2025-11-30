#include <iostream>
#include <vector>

using namespace std;

struct Resultados
{
    int total;
    int mayor;
    int menor;
    bool necesita_mantenimiento;
    bool trabaja_eficientemente;
};


//Funcion para calcular el total
Resultados Funcionalidades(int tiradas, int cant_productos, vector<vector<int>>& array){
    int total = 0;
    vector<int>total_por_tiradas(tiradas, 0);
    int tirada_menor = 0;
    int tirada_mayor = 0;
    bool necesita_mantenimiento = false;
    bool trabaja_eficientemente = false;

    // calculo del total
    for (int tirada = 0; tirada < tiradas; tirada++){
        for(int producto = 0; producto < cant_productos; producto++){
            total += array[tirada][producto];
            total_por_tiradas[tirada] += array[tirada][producto];
        }
    }

    // Mostrar tirada de menor cantidad de defectos
    for (int tirada = 1; tirada < tiradas; tirada++){
        if(total_por_tiradas[tirada] < total_por_tiradas[tirada_menor]) {
            tirada_menor = tirada;
        }
        
        if(total_por_tiradas[tirada] > total_por_tiradas[tirada_mayor]) {
            tirada_mayor = tirada;
        }
    }

    // Funcionalidad de mantenimiento
    if (tiradas >= 2) if ((total_por_tiradas.back() + total_por_tiradas[total_por_tiradas.size() - 2]) > 150) necesita_mantenimiento = true;

    // Funcionalidad de eficiencia
    if (tiradas > 5 && total <= 50) trabaja_eficientemente = true;

    return {total, tirada_mayor+1, tirada_menor+1, necesita_mantenimiento, trabaja_eficientemente};

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
    if (tiradas >= 2)
        resultados.necesita_mantenimiento == true ? cout<<"El horno necesita mantenimiento"<<endl : cout<<"El horno no necesita mantenimiento"<<endl;
    else cout<<"Necesitas realizar minimo 2 tiradas para verificar si necesita mantenimiento o no"<<endl;
        
    if (tiradas > 5)
    {
        resultados.trabaja_eficientemente == true ? cout<<"El horno trabaja eficientemente"<<endl : cout<<"El horno no trabaja eficientemente"<<endl;
    } else cout<<"Necesitas realizar mas de 5 tiradas para comprobar la eficiencia"<<endl;
    
    return 0;
}