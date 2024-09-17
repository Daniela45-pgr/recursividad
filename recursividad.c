#include <stdio.h>

void decimalABinario(int n) {
    if (n == 0) {
        return;
    }
    decimalABinario(n / 2);
    printf("%d", n % 2);
}

int main (){
    int num=0;
    printf ("Ingresa un numero:");
    scanf ( "%d",&num);

    if
     (num > 0){
      printf("La representacion binaria de %d es: ", num);
    decimalABinario (num);

   } else{
        printf ("Ingresa un numero positivo");
    }

    
}