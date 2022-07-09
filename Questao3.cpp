#include <iostream>

int* Fibonacci(int n){
    int Fibo[n];
    Fibo[0] = 0;
    Fibo[1] = 1;
    for(int i=2; i<n; i++){
        Fibo[i]=Fibo[i-1]+Fibo[i-2];
    }
}

int main(){

}