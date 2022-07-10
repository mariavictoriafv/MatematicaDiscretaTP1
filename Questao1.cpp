#include <iostream>
#include <cmath>

bool testarCubos(int n, int teste1, int teste2){
    teste1=pow(teste1, 3);
    teste2=pow(teste2, 3);
    if(n==teste1+teste2) 
        return true;

    return false;
}

int main(){
    long long int limite;
    int cont, raiz3, num1, num2;
    bool achou=false;

    std::cout<<"Digite ate que numero deseja procurar:";
    std::cin>>limite;

    if(limite<=0) 
        std::cout<<"Limite invalido\n";
    else{
        std::cout<<"Numeros que podem ser escritos como a soma de cubos de inteiros positivos de duas maneiras diferentes ate "<<limite<<":\n";

        for(int i=1; i<=limite; i++){

            raiz3=pow(i, (1.0/3.0));
            cont=0;

            for(int j=1; j<=raiz3; j++){

                for(int k=j; k<=raiz3; k++){

                    if(testarCubos(i, j, k)) {
                        cont++;
                        if(cont==1){
                            num1=j;
                            num2=k;
                        }
                    }
                    if(cont==2){
                        std::cout<<i<<"-"<<num1<<"^3"<<"+"<<num2<<"^3, "<<j<<"^3"<<"+"<<k<<"^3"<<"\n";
                        cont=0;
                        achou=true;
                    }

                }

            }

        }

    }

    if(!achou) std::cout<<"Nenhum numero foi encontrado\n";

    return 0;
}