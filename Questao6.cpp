#include <iostream>
#include <cmath>

bool divisaoPorPrimo(int n){

    //Sabemos que n<200. Então o maior numero ao quadrado que divide n, e a raiz quadrada de n
    //O piso da raiz quadrada de 200 é 14
    //Entao precisamos testar a divisibilidade apenas com primos menores que 14
    //Como sao poucos, vamos criar um vetor com todos eles

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

bool verificaPrimo(int n){
    int cont=0, div=2;
    while(div<=n){
        if(n%div==0) cont++;

        div++;
    }

}

int main(){
    std::cout<<"Valores de n, com n< e n impar, tais que C(n, [n/2]) nao e divisivel pelo quadrado de um primo:\n";

    //Para facilitar os calculos, vamos usar o triangulo de Pascal
    unsigned long long int tPascal[80][80]; //Testamos apenas numeros menores que 200

    tPascal[0][0]=1;
    tPascal[1][0]=1;
    tPascal[1][1]=1;
    
    for(int i=2; i<80; i++){
        
        for(int j=0; j<=i; j++){
            
            if(j==0||j==i)//Caso estejamos na lateral da matriz
                tPascal[i][j] = 1;
            else //Senao, a posicao atual e a posicao acima, mais a posicao acima e a esquerda
                tPascal[i][j] = tPascal[i-1][j-1] + tPascal[i-1][j]; 
        }
    } 

    //Agora precisamos calcular as combinacoes pedidas na questao
    for(int i=0; i<80; i++){
       
        if(i%2!=0)
            if(!divisaoPorPrimo(tPascal[i][(i/2)]))
                std::cout<<i<<"-"<<tPascal[i][(i/2)]<<"\n";
    }

    return 0;
}