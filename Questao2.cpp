#include <iostream>
#include <math.h>
#include <algorithm>

int soma(int &base){
    return pow(base[0], 4) + pow(base[1], 4) + pow(base[2], 4) + pow(base[3], 4) + pow(base[4], 4) + pow(base[5], 4) + pow(base[6], 4) + pow(base[7], 4) + pow(base[8], 4) + pow(base[9], 4) + pow(base[1], 4) + pow(base[1], 4) + pow(base[1], 4) + pow(base[1], 4) + pow(base[1], 4) + pow(base[1], 4) + pow(base[1], 4) + pow(base[1], 4);
}

void defineBases(int &base, int i){
    if(i==17){
        fill_n(base, 17, 0);
        base[i]++;
        return;
    }
    else if(base[i+1]>base[i]){
        base[i]++;
        return;
    }
    else{
        defineBases(&base, i+1);
    }
}

int main(){
    int limite;
    std::cout << "Insira o numero limite do intervalo que o programa ira utilizar: " << "\n";
    std::cin >> limite;

    int base[18];
    fill_n(base, 18, 0);

    for(int i=0; soma(base)<=limite; i++){
        defineBases(base, 0);
        soma(base);
    }
}

