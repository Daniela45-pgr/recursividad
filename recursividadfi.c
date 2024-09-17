#include <stdio.h>
int fibonacci(int n) {
    if (n == 0) { // en caso de que la posicion sea 0
        return 0;
    }
    if (n == 1) { // en caso de que la posicion sea 1
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // en caso de que la posicion sea >= 2
                 // (2-1) + (2-2)=1
}

int main() {
    int num;
    printf ("Ingresa la posicion:");
    scanf ( "%d",&num);
    printf("La serie Fibonacci en la posicion %d es: %d\n", num, fibonacci(num));
    return 0;
}
