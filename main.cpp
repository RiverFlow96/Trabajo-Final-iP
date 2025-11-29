#include <iostream>

using namespace std;

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

    int defectos[tiradas][cant_productos] = {
        {1, 2, 3, 4}, 
        {1, 2, 3, 4}, 
        {1, 2, 3, 4}
    };

    cout<<total(defectos[tiradas][cant_productos]);

    return 0;
}