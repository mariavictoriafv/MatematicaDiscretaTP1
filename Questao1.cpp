#include <iostream>
#include <cmath>

//Funcao que testa se n é a soma dos cubos de teste1 e teste2
bool testarCubos(int n, int teste1, int teste2){
    teste1=pow(teste1, 3);
    teste2=pow(teste2, 3);
    if(n==teste1+teste2) 
        return true;

    return false;
}



int main(){
    //Declarando as variaveis usadas no codigo
    long long int limite;
    int cont, raiz3, num1, num2;
    bool achou=false;

    //O usuario escolhe ate onde ele quer procurar os numeros com a caracteristica pedida
    std::cout<<"Digite ate que numero deseja procurar:";
    std::cin>>limite;

    if(limite<=0) //So faz sentido usar o programa com numeros maiores que 0
        std::cout<<"Limite invalido\n";
    else{
        std::cout<<"Numeros que podem ser escritos como a soma de cubos de inteiros positivos de duas maneiras diferentes ate "<<limite<<":\n";

        //Esse for vai permitir que os testes sejam feitos com todos os numeros ate o limite escolhido
        for(int i=1; i<=limite; i++){

            /*A soma de dois cubos positivos e diferentes de 0 so pode resultar em um
            numero maior que o cubo dos fatores da soma. Dessa forma, so faz sentido realizar
            os testes com numeros menores que a raiz cubica do numero pedido. Entao 
            calculamos essa raiz cubica, e ela sera o novo limite das operacoes */
            raiz3=pow(i, (1.0/3.0));
            cont=0; //zeramos o contador para realizar um novo teste

            //Primeiramente, vamos testar o cubo de j com todos os cubos de k ate raiz3
            for(int j=1; j<=raiz3; j++){

                //k comeca de j para evitar repeticao de combincações de somas
                for(int k=j; k<=raiz3; k++){

                    //Se i for a soma dos cubos de j e k, incrementamos o contador
                    //Alem disso, guardamos j e k em num1 e num2, para imprimir os valores caso necessario
                    if(testarCubos(i, j, k)) {
                        cont++;
                        if(cont==1){
                            num1=j;
                            num2=k;
                        }
                    }
                    //Se cont==2, ja achamos duas somas diferentes de cubos que resultam em i
                    //Entao imprimimos i e as combinacoes que resultam nela
                    if(cont==2){
                        std::cout<<i<<"-"<<num1<<"^3"<<"+"<<num2<<"^3, "<<j<<"^3"<<"+"<<k<<"^3"<<"\n";
                        cont=0;
                        //Se achamos um numero com as caracteristicas pedidas, nao imprimos a mensagem do final
                        achou=true; 
                    }

                }

            }

        }

    }

    //Se nao acharmos nenhum numero ate o limite, informamos ao usuario
    if(!achou) std::cout<<"Nenhum numero foi encontrado\n";

    return 0;
}