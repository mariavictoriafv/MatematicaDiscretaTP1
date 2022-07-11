#include <iostream>

int main(){
    //Variaveis que serao usadas no codigo
    long long int limite, i, j, k, cont;
    bool achou=false;

    //O usuario escolhe ate onde ele quer procurar os numeros com a caracteristica pedida
    std::cout<<"Digite ate que numero deseja procurar:";
    std::cin>>limite;

    std::cout<<"Numeros de Fibonacci divisiveis por 3 ate "<<limite<<":\n";

    //Sabemos que a sequencia de Fibonacci e feita com n=(n-1)+(n+2)
    //Usando 1 como passo base
    //O codigo vai achar os numeros de Fibonacci ate o limite
    //Ele vai verificar se cada numero e divisivel por 3

    j=0;
    k=1;
    i=1;
    cont=2;
    while(i<=limite){
        //Se i for multiplo de 3, imprimimos i
        //Achamos ao menos um numero de Fibonacci divisivel por 3
        if(i%3==0){
            std::cout<<"Posicao:"<<cont<<"-"<<i<<"\n";
            achou=true;
        }

        //O proximo numero sera a soma dele mesmo, mais o seu antecessor na sequencia
        //O antecessor esta armazenado em k
        //j recebe k, e j sera o novo atecessor
        //k recebe o i atual
        //e atualizamos o i
        j=k;
        k=i;
        i=i+j;
        
        cont++;//esse contador apenas guarda a posicao do numero na sequencia
    }

    //Se nao acharmos nenhum numero ate o limite, informamos ao usuario
    if(!achou) std::cout<<"Nenhum numero foi encontrado\n";

    return 0;
}