#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 50000 //define array size

/* quick sort */



void swap(int array[], int i, int k){
    int aux = array[i];
    array[i] = array[k];
    array[k] = aux;

}

int particiona(int array[], int inicio, int fim){

    int posPivo = fim;
    int k = inicio;


    for (int i = inicio; i<fim; i++)
    {
        if (array[i] <= array[posPivo])
        {
            swap(array, i, k);
            k++;
        }
    }
    if (array[k] > array[posPivo])
    {
        swap(array, k, posPivo);
        posPivo = k;

    }
    return posPivo;
}

void quickSort(int array[], int inicio, int fim){

    if (inicio < fim)
    {
        int posPivo = particiona(array, inicio, fim);
        quickSort(array, inicio, posPivo-1);
        quickSort(array, posPivo+1, fim);

    }

    
}


int main(){
    int array[MAX];
    int x, i;
    clock_t start, end;


/*_____________________________________________________________________*/

    //filling array with random elements

    /* srand(time(NULL));
    for(x=0; x<MAX; x++)
    {
        array[x] = rand() % 100000; //define the "width" of the numbers
    } */


/*_____________________________________________________________________*/

    //filling array with ascending elements
    /* for(x=0; x<MAX; x++)
    {
        array[x] = x; 
    } */


/*_____________________________________________________________________*/

    //filling array with descending elements
    for(x=0; x<MAX; x++)
    {
        array[x] = MAX-x; 
    }


/*_____________________________________________________________________*/

    //print before sort:
    /* printf("\n\n before sorted: \n\n");
    for (i=0; i<MAX; i++)
    {
        printf("%d ", array[i]);
    } */
    


/*___________________________________________________________*/
/*_____________________EFFICIENT ORDERS_______________________*/

/*_________________________________________________________*/
    //applying  quickSort;

    start = clock();
    quickSort(array, 0, MAX);
    end = clock();


/*_________________________________________________________*/



    //print after sort:
    /* printf("\n\n after sorted: \n\n");
    for (i=0; i<MAX; i++)
    {
        printf("%d ", array[i]);
    } */

    

    printf("\n\n\t -> Tempo inicial: %lf milissegundos", ((double)start)/((CLOCKS_PER_SEC)));
    printf("\n\n\t -> Tempo final: %lf milissegundos", ((double)end)/((CLOCKS_PER_SEC)));

    double difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\n\t -> Diferenca em Segundos: %lf\n\n\t -> Diferenca em Milissegundos: %lf", difTempo, difTempo*1000);
    return 0;

}

