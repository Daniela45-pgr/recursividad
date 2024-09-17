#include <stdio.h>

// Función recursiva para resolver el problema de las Torres de Hanoi
void torresDeHanoi(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        // Caso base: mover un disco directamente del origen al destino
        printf("Mover disco 1 de %c a %c\n", origen, destino);
        return;
    }

    // Mover n-1 discos del origen al auxiliar, usando el destino como auxiliar
    torresDeHanoi(n - 1, origen, auxiliar, destino);

    // Mover el disco restante del origen al destino
    printf("Mover disco %d de %c a %c\n", n, origen, destino);

    // Mover los n-1 discos del auxiliar al destino, usando el origen como auxiliar
    torresDeHanoi(n - 1, auxiliar, destino, origen);
}

int main() {
    int n;

    // Pedir al usuario el número de discos
    printf("Introduce el numero de discos: ");
    scanf("%d", &n);

    // Validar que el número de discos sea mayor que 0
    if (n <= 0) {
        printf("El número de discos debe ser mayor que 0.\n");
        return 1;
    }

    // Llamada inicial a la función recursiva
    printf("Solución para %d discos:\n", n);
    torresDeHanoi(n, 'A', 'C', 'B');

    return 0;
}
