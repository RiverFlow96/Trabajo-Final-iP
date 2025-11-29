#include <iostream>

using namespace std;

//Funcion para calcular el total
int total(int array){
    int total = 0;

    for (int tirada = 0; tirada < 3; tirada++){
        for(int producto = 0; producto < 4; producto++){
            total += producto;
        }
    }

    return total;

}

int main(){

    const int tiradas = 3;
    const int cant_productos = 4;

    //Array de defectos
    int defectos[tiradas][cant_productos] = {
        {1, 2, 3, 4}, 
        {1, 2, 3, 4}, 
        {1, 2, 3, 4}
    };

    //Imprimiendo Total
    cout<<total(defectos[tiradas][cant_productos]);

    return 0;
}