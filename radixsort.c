#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct carro {
    int ano;
    char modelo[30];
}Carro;

void preencheArray(Carro *array) {
    array[0].ano = 1998;
    strcpy(array[0].modelo, "Astra (Chevrolet)");

    array[1].ano = 1973;
    strcpy(array[1].modelo, "Chevette (Chevrolet)");

    array[2].ano = 2011;
    strcpy(array[2].modelo, "Cobalt (Chevrolet)");

    array[3].ano = 2010;
    strcpy(array[3].modelo, "Camaro (Chevrolet)");

    array[4].ano = 2000;
    strcpy(array[4].modelo, "Celta (Chevrolet)");

    array[5].ano = 1994;
    strcpy(array[5].modelo, "Corsa (Chevrolet)");

    array[6].ano = 1996;
    strcpy(array[6].modelo, "Palio (Fiat)");

    array[7].ano = 1979;
    strcpy(array[7].modelo, "Fiorino (Fiat)");

    array[8].ano = 2016;
    strcpy(array[8].modelo, "Toro (Fiat)");

    array[9].ano = 2003;
    strcpy(array[9].modelo, "EcoSport (Ford)");

    array[10].ano = 2006;
    strcpy(array[10].modelo, "Fusion (Ford)");

    array[11].ano = 1992;
    strcpy(array[11].modelo, "Civic (Honda)");

    array[12].ano = 2012;
    strcpy(array[12].modelo, "HB20 (Hyundai)");

    array[13].ano = 2015;
    strcpy(array[13].modelo, "Renegade (Jeep)");

    array[14].ano = 2016;
    strcpy(array[14].modelo, "Compass (Jeep)");
}

void imprimeCarro(Carro *array) {
    int i;
    for (i = 0; i<15; i++) {
        printf("%d - ", array[i].ano);
        printf("%s\n", array[i].modelo);

    }
}

int buscaMax(Carro *array, int n) {
    int maior = array[0].ano;
    for (int i = 0; i < n; i++) {
        if (array[i].ano > maior) {
            maior = array[i].ano;
        }
    }
    return maior;
}

void inicializaCount(int *count) {


    for (int i = 0; i<10; i++) {
        count[i] = 0;
    }
}

void countingSort(Carro *array, int n, int pos) {
    Carro aux[n];
    int count[10];
    inicializaCount(count);
    int digito;


    for (int i = 0; i < n; i++) {
        digito = (array[i].ano / pos) % 10;
        count[digito]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] = count[i] + count[i-1];
    }

    for (int i = n-1; i >= 0; i--) {
        digito = (array[i].ano / pos) % 10;
        count[digito]--;
        aux[count[digito]].ano = array[i].ano;
        strcpy(aux[count[digito]].modelo, array[i].modelo);
    }

    for (int i = 0; i < n; i++) {
        array[i].ano = aux[i].ano;
        strcpy(array[i].modelo, aux[i].modelo);
    }
}

void radixSort(Carro *array, int n) {
    int max = buscaMax(array, n);
    for (int pos = 1; (max/pos) > 0; pos*=10) {
        countingSort(array, n, pos);
    }
}

int main(int argc, char const *argv[])
{
    Carro array[15];
    preencheArray(array);

    printf("\n\n -- Antes de ordenar: \n\n");

    imprimeCarro(array);

    radixSort(array, 15);

    printf("\n\n -- Depois de ordenar: \n\n");

    imprimeCarro(array);









    return 0;
}
