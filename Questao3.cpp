#include <iostream>

int* Fibonacci(int n){
    int* fibo = new int[n];
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i=2; i<n; i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    return fibo;
}

int main(){
    int qtd;
    std::cout << "Insira a quantidade de números de Fibonacci a serem utilizados: " << "\n";
    std::cin >> qtd;

    int div5 = 0;
    int* fibo = Fibonacci(qtd);
    for(int i=0; i<qtd; i++){
        if(fibo[i]%5 == 0){
            div5++;
        }
    }
}