#include <iostream>
#include <cmath>

bool testarCubos(int n, int teste1, int teste2){
    if(n==(pow(teste1, 3)+pow(teste2, 3))) 
        return true;

    return false;
}

int main(){
    long long int limite;
    int cont=0, raiz3;

    std::cout<<"Digite ate que numero deseja procurar:";
    std::cin>>limite;

    if(limite<=0) 
        std::cout<<"Limite invalido\n";
    else{
        std::cout<<"Numeros que podem ser escritos como a soma de cubos de inteiros positivos de duas maneiras diferentes ate "<<limite<<":\n";

        for(int i=1; i<=limite; i++){

            raiz3=pow(i, (1.0/3.0));

            for(int j=1; j<raiz3; j++){

                for(int k=j; k<raiz3; k++){

                    if(cont==2){
                        std::cout<<i<<"\n";
                        cont=0;
                    }
                    if(testarCubos(i, j, k)) cont++;

                }

            }

        }

    }

    return 0;
}