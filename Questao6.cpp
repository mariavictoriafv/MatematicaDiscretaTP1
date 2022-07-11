#include <iostream>
#include <cmath>

bool divisaoPorPrimo(int n){
    //Um numero nao sera divisivel pelo quadrado de outro maior que sua propria raiz quadrada
    //Por isso definimos o limite
    int limite=sqrt(n);
    int c=1;

    while(c<=limite){
        if(n% ==0) return true;
    }

    return false;
}

int main(){
    std::cout<<"Valores de n, com n<200 e n impar, tais que C(n, [n/2]) nao e divisivel pelo quadrado de um primo:\n";

    //Para facilitar os calculos, vamos usar o triangulo de Pascal
    long long int tPascal[199][199]; //Apenas valores menores que 200

    tPascal[0][0]=tPascal[1][0]=tPascal[1][1]=1;

    for(int i=2; i<200; i++){
        for (int j=0; j<=i; j++){
            if(j==0||j==i)//Caso estejamos na lateral da matriz
                tPascal[i][j] = 1;
            else //Senao, a posicao atual e a posicao acima, mais a posicao acima e a esquerda
                tPascal[i][j] = tPascal[i-1][j-1] + tPascal[i-1][j]; 
        }
    } 

    //Agora precisamos calcular as combinacoes pedidas na questao
    for(int i=0; i<200; i++){
        if(i%2!=0)
            if(divisaoPorPrimo(tPascal[i][i/2]))
                std::cout<<i<<" \n";
    }

    return 0;
}