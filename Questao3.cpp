#include <iostream>

int main(){
    int qtd;
    std::cout << "Insira a quantidade de numeros de Fibonacci a serem utilizados: (máximo: 92)" << "\n";
    std::cin >> qtd;

    std::cout << "Lista de numeros de Fibonacci divisiveis por 5: ";

    int div5 = 0;
    long long int* fibo = new long long int[qtd];
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i=2; i<qtd; i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
        if(fibo[i]%5 == 0){
            std::cout << fibo[i] << " ";
            div5++;
        }
    }
    std::cout << "\n"; 
    std::cout << "Quantidade de numeros de Fibonacci divisiveis por 5: " << div5 << "\n";
}