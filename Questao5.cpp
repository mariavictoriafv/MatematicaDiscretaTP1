#include <iostream>
#include <math.h>

/* função que divide (2n, n) pelos quadrados dos números primos */
int dividePrimo(int combinacao){
    //criamos um vetor com os números primos já declarados para economizar custo operacional
    int primos[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
    int divide; // variavel que irá armazenar o número primo que divide (2n, n)

    for(int i=0; i<168; i++){
        primos[i] = pow(primos[i], 2); //calcula o quadrado dos numeros primos
        if(primos[i]<=combinacao && combinacao%primos[i] == 0){ //verifica se (2n, n) é divisivel pelo quadrado do numero primo
            divide = sqrt(primos[i]);
            break; //o codigo para após encontrar o primeiro quadrado de um primo que divide o número
        }
    }
    return divide;
}

int main(){
    int n;
    std::cout << "Insira um valor para n: (maximo: 34)" << "\n";
    std::cin >> n;
    unsigned long long int pascal[2*n][2*n]; //matriz que irá alocar o triângulo de pascal

    //inicializamos o triângulo de pascal com os valores 1
    pascal[0][0] = 1;
    pascal[1][0] = 1;
    pascal[1][1] = 1;

    //preenchendo a matriz
    for (int i=2; i<2*n; i++){
        for (int j=0; j<=i; j++){
            if(j==0||j==i){ //verifica se a posição acessada é uma das "bordas" do triângulo e coloca o valor 1 caso seja
                pascal[i][j] = 1;
            }
            else{
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j]; //formula para encontrar o valor do numero que ocupará aquela posição, essa relação entre os números é chamada de Relação de Stifel
            }
        }
    }

    for(int i=3; i<n; i++){ //iniciamos pelo numero 3 pois n != 1 e 2
        if(i!=4){ //verificamos se o n!=4
            std::cout << pascal[2*i][i] << " e divisivel por " << dividePrimo(pascal[2*i][i]) << "²";
            std::cout << "\n";
        }
    }
    
    return 0;
    
}