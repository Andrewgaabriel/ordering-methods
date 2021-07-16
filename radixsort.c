#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct carro {
    int ano;
    char modelo[15];
}Carro;

void preencheArray(Carro *array) {
    array[0].ano = 1998;
    strcpy(array[0].modelo, "Astra (Chevrolet)");

    array[1].ano = 1973;
    array[1].modelo = "Chevette (Chevrolet)";

    array[2].ano = 2011;
    array[2].modelo = "Cobalt (Chevrolet)";

    array[3].ano = 2010;
    array[3].modelo = "Camaro (Chevrolet)";

    array[4].ano = 2000;
    array[4].modelo = "Celta (Chevrolet)";

    array[5].ano = 1994;
    array[5].modelo = "Corsa (Chevrolet)";

    array[6].ano = 1996;
    array[6].modelo = "Palio (Fiat)";

    array[7].ano = 1979;
    array[7].modelo = "Fiorino (Fiat)";

    array[8].ano = 2016;
    array[8].modelo = "Toro (Fiat)";

    array[9].ano = 2003;
    array[9].modelo = "EcoSport (Ford)";

    array[10].ano = 2006;
    array[10].modelo = "Fusion (Ford)";

    array[11].ano = 1992;
    array[11].modelo = "Civic (Honda)";

    array[12].ano = 2012;
    array[12].modelo = "HB20 (Hyundai)";

    array[13].ano = 2015;
    array[13].modelo = "Renegade (Jeep)";

    array[14].ano = 2016;
    array[14].modelo = "Compass (Jeep)";
}

void imprimeCarroTemp(Carro *array) {
    int i;
    for (i = 0; i<15; i++) {
        printf("_________________________________");
        printf("Ano: ", array[i].ano);
        printf("Modelo: ", array[i].modelo);
        printf("_________________________________");
    }
}



void imprimeCarro(Carro *array) {
    int i;
    for (i = 0; i<15; i++) {
        printf("_________________________________\n");
        printf(" %d - ", array[i].ano);
        printf("%s .\n", array[i].modelo);
        printf("_________________________________\n");
    }
}


int main(int argc, char const *argv[])
{
    Carro array[15];
    preencheArray(array);
    printf("Antes de ordenar: \n");

    imprimeCarroTemp(array);

    //aplica radix;

    imprimeCarroTemp(array);









    return 0;
}

