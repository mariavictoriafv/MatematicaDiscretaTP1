#include <iostream>
#include <cmath>

//Funcao que verifica se n e primo
bool verificaPrimo(unsigned long long int n){
    int cont=0, div=2;
    while(div<=n){
        if(n%div==0) cont++;
        if(cont>1) return false;
        div++;
    }
    
    return true;
}

//Funcao que testa se n e divisivel pelo quadrado de algum primo
bool divisaoPorPrimo(unsigned long long int n){

    int c=2; 
    int p;
 
    //Sabemos que o maior numero ao quadrado que divide n, e a raiz quadrada de n
    //Entao testamos a divisao por quadrados de primos apenas ate a raiz quadrada de n
    while(c<sqrt(n)){
        if(verificaPrimo(c)){//Se c e primo
            p=pow(c, 2);
            if(n%p==0) return true; //Retornamos true se a divisao e exata
        }
        c++;
    }
    
    return false;
}

int main(){
    std::cout<<"Valores de n, com n<70 e n impar, tais que C(n, [n/2]) nao e divisivel pelo quadrado de um primo:\n";

    //Para facilitar os calculos, vamos usar o triangulo de Pascal
    unsigned long long int tPascal[70][70]; 
    //Meu computador conseguiu fazer os calculos ate 70, entao deixei esse limite

    //Iniciando os primeiros valores no Triangulo de Pascal
    tPascal[0][0]=1;
    tPascal[1][0]=1;
    tPascal[1][1]=1;
    
    //Preenchendo os valores no triangulo de acordo com a Relação de Stifel
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
       
        if(i%2!=0) //Se o numero for impar 
            if(!divisaoPorPrimo(tPascal[i][(i/2)]))//Se a combinacao de i e i/2 nao e divisivel pelo quadrado de um primo
                std::cout<<i<<"-"<<tPascal[i][(i/2)]<<"\n"; //Imprimimos i e o resultado da combinacao
    }

    return 0;
}