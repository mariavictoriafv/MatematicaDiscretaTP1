#include <iostream>
#include <math.h>

int soma(int &base){
    return pow(base[0], 4) + pow(base[1], 4) + pow(base[2], 4) + pow(base[3], 4) + pow(base[4], 4) + pow(base[5], 4) + pow(base[6], 4) + pow(base[7], 4) + pow(base[8], 4) + pow(base[9], 4) + pow(base[1], 4) + pow(base[1], 4) + pow(base[1], 4) + pow(base[1], 4) + pow(base[1], 4) + pow(base[1], 4) + pow(base[1], 4) + pow(base[1], 4);
}

int defineBases(int &base, int i){
    if(i==17){
        for(int j=0; j<17; j++){
            base[j] =  0;
        }
        base[i]++;
        return;
    }
    else if(base[i+1]>base[i]){
        base[i]++;
        return;
    }
    else{
        return defineBases(&base, i++);
    }
}

int main(){
    int limite;
    std::cout << "Insira o numero maximo que as bases podem assumir: " << "\n";
    std::cin >> limite;

    int base[18] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
}

