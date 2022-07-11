#include <iostream>
#include <math.h>

int soma(int &base){
    return pow(base[0], 4) + pow(base[1], 4) + pow(base[2], 4) + pow(base[3], 4) + pow(base[4], 4) + pow(base[5], 4) + pow(base[6], 4) + pow(base[7], 4) + pow(base[8], 4) + pow(base[9], 4) + pow(base[1], 4) + pow(base[1], 4) + pow(base[1], 4) + pow(base[1], 4) + pow(base[1], 4) + pow(base[1], 4) + pow(base[1], 4) + pow(base[1], 4);
}

int main(){
    int limite;
    std::cout << "Insira a quantidade de numeros de Fibonacci a serem utilizados: (máximo: 92)" << "\n";
    std::cin >> limite;

    int base[18] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(int i=0; i<18; i++){
        for(int j=0; j<limite; j++){
            base[i]
        }
    }
}