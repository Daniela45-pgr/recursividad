#include <stdio.h>

#define MAX_DISCOS 10  // Máximo número de discos permitido

// Función para imprimir las tres torres de manera gráfica
void imprimirTorres(int torres[3][MAX_DISCOS], int num_discos) {
    printf("\n");
    for (int i = num_discos - 1; i >= 0; i--) {
        for (int torre = 0; torre < 3; torre++) {
            if (torres[torre][i] == 0) {
                printf("|\t");  // Espacio vacío
            } else {
                printf("%d\t", torres[torre][i]);  // Disco
            }
        }
        printf("\n");
    }
    printf("A\tB\tC\n");  // Nombres de las torres
    printf("-------------------\n");
}

// Función para mover un disco de una torre a otra y actualizar la representación gráfica
void moverDisco(int torres[3][MAX_DISCOS], int n, int origen, int destino) {
    // Encontrar el disco en la torre de origen
    int disco;
    for (int i = 0; i < n; i++) {
        if (torres[origen][i] != 0) {
            disco = torres[origen][i];
            torres[origen][i] = 0;  // Remover el disco de la torre de origen
            break;
        }
    }

    // Colocar el disco en la torre de destino
    for (int i = 0; i < n; i++) {
        if (torres[destino][i] == 0) {
            torres[destino][i] = disco;
            break;
        }
    }

    // Mostrar las torres después de cada movimiento
    imprimirTorres(torres, n);
}

// Función recursiva para resolver el problema de las Torres de Hanoi
void torresDeHanoi(int n, int torres[3][MAX_DISCOS], int origen, int destino, int auxiliar) {
    if (n == 1) {
        moverDisco(torres, MAX_DISCOS, origen, destino);
        return;
    }
    torresDeHanoi(n - 1, torres, origen, auxiliar, destino);
    moverDisco(torres, MAX_DISCOS, origen, destino);
    torresDeHanoi(n - 1, torres, auxiliar, destino, origen);
}

int main() {
    int n;
    int torres[3][MAX_DISCOS] = {0};  // Representación de las tres torres

    // Pedir al usuario el número de discos
    printf("Introduce el numero de discos (máximo %d): ", MAX_DISCOS);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_DISCOS) {
        printf("El número de discos debe estar entre 1 y %d.\n", MAX_DISCOS);
        return 1;
    }

    // Inicializar la primera torre con los discos
    for (int i = 0; i < n; i++) {
        torres[0][i] = n - i;  // Los discos son numerados del más grande (n) al más pequeño (1)
    }

    // Mostrar el estado inicial de las torres
    printf("Estado inicial:\n");
    imprimirTorres(torres, n);

    // Resolver el problema de las Torres de Hanoi
    torresDeHanoi(n, torres, 0, 2, 1);  // 0 = Torre A, 1 = Torre B, 2 = Torre C

    return 0;
}
