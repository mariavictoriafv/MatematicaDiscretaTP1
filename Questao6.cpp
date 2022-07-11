#include <iostream>
#include <cmath>

bool verificaPrimo(unsigned long long int n){
    int cont=0, div=2;
    while(div<=n){
        if(n%div==0) cont++;
        if(cont>1) return false;
        div++;
    }
    
    return true;
}

bool divisaoPorPrimo(unsigned long long int n){

    //Sabemos que o maior numero ao quadrado que divide n, e a raiz quadrada de n

    int c=2; 
    int p;
 
    while(c<sqrt(n)){
        if(verificaPrimo(c)){
            p=pow(c, 2);
            if(n%p==0) return true;
        }
        c++;
    }
    
    return false;
}

int main(){
    std::cout<<"Valores de n, com n< e n impar, tais que C(n, [n/2]) nao e divisivel pelo quadrado de um primo:\n";

    //Para facilitar os calculos, vamos usar o triangulo de Pascal
    unsigned long long int tPascal[70][70]; //Testamos apenas numeros menores que 200

    tPascal[0][0]=1;
    tPascal[1][0]=1;
    tPascal[1][1]=1;
    
    for(int i=2; i<70; i++){
        
        for(int j=0; j<=i; j++){
            
            if(j==0||j==i)//Caso estejamos na lateral da matriz
                tPascal[i][j] = 1;
            else //Senao, a posicao atual e a posicao acima, mais a posicao acima e a esquerda
                tPascal[i][j] = tPascal[i-1][j-1] + tPascal[i-1][j]; 
        }
    } 

    //Agora precisamos calcular as combinacoes pedidas na questao
    for(int i=0; i<70; i++){
       
        if(i%2!=0)
            if(!divisaoPorPrimo(tPascal[i][(i/2)]))
                std::cout<<i<<"-"<<tPascal[i][(i/2)]<<"\n";
    }

    return 0;
}