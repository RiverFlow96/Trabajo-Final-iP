#include <iostream>
#include <vector>
#include <random>

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

void VerificarCincoIguales(int tiradas, int cant_productos, vector<vector<int>>& array) {
    vector<int> todos_los_elementos;
    for(int i = 0; i < tiradas; i++) {
        for(int j = 0; j < cant_productos; j++) {
            todos_los_elementos.push_back(array[i][j]);
        }
    }

    // Validar que existan al menos 5 elementos
    if (todos_los_elementos.size() < 5) {
        cout << "Se necesitan minimo 5 elementos" << endl;
        return;
    }

    // 2. Seleccionar 5 al azar (mezclando el vector)
    for (int i = 0; i < todos_los_elementos.size(); i++) {
        int r = rand() % todos_los_elementos.size();
        swap(todos_los_elementos[i], todos_los_elementos[r]);
    }

    bool sonIguales = true;
    int primerValor = todos_los_elementos[0];

    cout << "Elementos seleccionados: ";
    for(int i = 0; i < 5; i++) {
        cout << todos_los_elementos[i] << " ";
        if(todos_los_elementos[i] != primerValor) {
            sonIguales = false;
        }
    }
    cout << endl;

    // 4. Mostrar resultado
    if (sonIguales == true) {
        cout << "Resultado: SI, todos los elementos seleccionados son iguales." << endl;
    } else {
        cout << "Resultado: NO, los elementos seleccionados son diferentes." << endl;
    }
}

void Matriz(int tiradas, int cant_productos, vector<vector<int>>& array, int id_1, int id_2){
    if(cant_productos>=2 && tiradas >=2){
        // Uso de IA para verificacion de errores
        const int TAMANIO_ARRAY = array.size();
        
        if (id_1 == TAMANIO_ARRAY) id_1--;
        if (id_2 == TAMANIO_ARRAY) id_2--;
        
        const int ULTIMO_INDICE = TAMANIO_ARRAY - 1;
        const int PENULTIMO_INDICE = TAMANIO_ARRAY - 2;
        
        if (id_1 == ULTIMO_INDICE) {
            id_1 = PENULTIMO_INDICE;
        }
        if (id_2 == ULTIMO_INDICE) {
            id_2 = PENULTIMO_INDICE;
        }

        if (TAMANIO_ARRAY < 2 || id_1 < 0 || id_2 < 0 || 
            id_1 >= TAMANIO_ARRAY - 1 || id_2 >= TAMANIO_ARRAY - 1) {
            
            // Este error ocurre si el array tiene menos de 2 elementos,
            // o si los IDs originales eran 0 y el array solo tenía 1 elemento.
            cerr << "\nERROR Matriz: Los datos son insuficientes (se requieren al menos 2 tiradas válidas)." << endl;
            cerr << "El rango de tiradas válidas (0-base) es de 0 a " << TAMANIO_ARRAY - 2 << " (para poder formar la pareja)." << endl;
            return; 
        }

        if (array[id_1].size() < 2 || array[id_1+1].size() < 2 || 
            array[id_2].size() < 2 || array[id_2+1].size() < 2) {
            cerr << "\nERROR Matriz: Las tiradas seleccionadas deben tener al menos 2 productos (columnas)." << endl;
            return; 
        }
        
        //realizando metodo de multiplicacion de matrices 2x2
        //Seleccionar los productos de las 2 primeras tiradas segun su indice o id
        vector<vector<int>> matriz_1 (2, vector<int>(2));
        vector<vector<int>> matriz_2 (2, vector<int>(2));
        // ID=1 (Tirada 1 [0][1] x tirada 2[0][1])
        
        matriz_1[0][0] = array[id_1][0];
        matriz_1[0][1] = array[id_1][1];
        matriz_1[1][0] = array[id_1+1][0];
        matriz_1[1][1] = array[id_1+1][1];

        matriz_2[0][0] = array[id_2][0];
        matriz_2[0][1] = array[id_2][1];
        matriz_2[1][0] = array[id_2+1][0];
        matriz_2[1][1] = array[id_2+1][1];

        vector<vector<int>> matriz_resultante(2, vector<int> (2));
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                matriz_resultante[i][j] = matriz_1[i][j] * matriz_2[i][j];
            }
        }

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                cout<<matriz_resultante[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}

int main(){
    int id_1 = 0, id_2 = 0;
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
    VerificarCincoIguales(tiradas, cant_productos, defectos);
    cout<<"Ingrese el primer ID: "; cin>>id_1;
    cout<<"Ingrese el segundo ID: "; cin>>id_2;
    Matriz(tiradas, cant_productos, defectos, id_1-1, id_2-1);
    
    return 0;
}