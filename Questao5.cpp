#include <iostream>
#include <math.h>

int dividePrimo(int combinacao){
    int primos[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
    int divisivel;

    for(int i=0; i<168; i++){
        primos[i] = pow(primos[i], 2);
        if(primos[i]<=combinacao && combinacao%primos[i] == 0){
            divisivel = primos[i];
        }
    }
    return divisivel;
}

int main(){
    int n;
    std::cout << "Insira um valor para n: (Maximo: 34)" << "\n";
    std::cin >> n;
    long long int pascal[2*n][2*n];
    pascal[0][0] = 1;
    pascal[1][0] = 1;
    pascal[1][1] = 1;
    for (int i=2; i<2*n; i++){
        for (int j=0; j<=i; j++){
            if(j==0||j==i){
                pascal[i][j] = 1;
            }
            else{
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
    }

    for(int i=0; i<n; i++){
        if(pascal[2*i][i]!=1){
            std::cout << pascal[2*i][i] << " é divisivel por " << dividePrimo(pascal[2*i][i]);
            std::cout << "\n";
        }
    }
    return 0;
    
}