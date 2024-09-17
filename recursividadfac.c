#include <stdio.h>

/*int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}*/

int factorialm(int i, int resultado, int num) {
    if (i> num ){
     return resultado;
    }
    resultado *= i;
    factorialm (i+1, resultado, num);
}


int main() {
   long int num;
    printf ("Ingresa un numero:");
    scanf ( "%d",&num);
    printf("El factorial de %d es: %d\n", num, factorialm(1, 1, num));
    return 0;
}


 