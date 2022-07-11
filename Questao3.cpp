#include <iostream>

int main(){
    int qtd;
    std::cout << "Insira a quantidade de numeros de Fibonacci a serem utilizados: (máximo: 92)" << "\n";
    std::cin >> qtd;

    std::cout << "Lista de numeros de Fibonacci divisiveis por 5: \n";

    int div5 = 0; //variavel que irá armazenar quantos numeros dentro do intervalo são divisiveis por 5
    long long int* fibo = new long long int[qtd]; //o vetor para armazenar os numeros de Fibonacci é long long devido ao fato de que quanto maior o intervalo maiores os numeros da sequencia
    
    //os primeiros números da sequência sempre são 0 e 1, respectivamente
    fibo[0] = 0; 
    fibo[1] = 1;

    //encontrando os numeros de Fibonacci
    for(int i=2; i<qtd; i++){ //começamos a preencher a partir da posição 2 pois as duas primeiras já foram preenchidas
        fibo[i]=fibo[i-1]+fibo[i-2]; //fórmula da sequência de Fibonacci
        if(fibo[i]%5 == 0){ //verifica se o número é ou não divisível por 5
            std::cout << i << " - " << fibo[i] << "\n";
            div5++;
        }
    }
    std::cout << "\n"; 
    std::cout << "Quantidade de numeros de Fibonacci divisiveis por 5: " << div5 << "\n";

    return 0;
}