#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define MAX 10000 //define array size



void intercala(int array[], int inicio, int meio, int fim){

    int aux[fim-inicio+1], i, j, k;
    i = inicio;
    j = meio + 1;
    k = 0;


    while (i <= meio && j<= fim)
    {
        if (array[i] <= array[j])
        {
            aux[k] = array[i];
            i++;

        } else {
            aux[k] = array[j];
            j++;
        }
        k++;
    }

    while(i <= meio)
    {
        aux[k] = array[i];
        i++;
        k++;

    }

    while(j <= fim)
    {
        aux[k] = array[j];
        j++;
        k++;
        
    }

    k = inicio;
    while (k<=fim)
    {
        array[k] = aux[k-inicio];
        k++;
    }
    
    free(aux);
}


void merge_sort(int array[], int inicio, int fim){

    if (inicio>=fim) return;
    
    int meio = (inicio + fim) / 2; //4
    merge_sort(array, inicio, meio);
    merge_sort(array, meio+1, fim);
    intercala(array, inicio, meio, fim);
}



int main(){
    int array[MAX];
    int x, i;
    clock_t start, end;


/*_____________________________________________________________________*/

    //filling array with random elements

    srand(time(NULL));
    for(x=0; x<MAX; x++)
    {
        array[x] = rand() % 10000; //define the "width" of the numbers
    }


/*_____________________________________________________________________*/

    //filling array with ascending elements
    /* for(x=0; x<MAX; x++)
    {
        array[x] = x; 
    } */


/*_____________________________________________________________________*/

    //filling array with descending elements
    /* for(x=0; x<MAX; x++)
    {
        array[x] = MAX-x; 
    } */


/*_____________________________________________________________________*/

    //print before sort:
    /* printf("\n\n before sorted: \n\n");
    for (i=0; i<MAX; i++)
    {
        printf("%d ", array[i]);
    }
     */


/*___________________________________________________________*/
/*_____________________EFFICIENT ORDERS_______________________*/

/*_________________________________________________________*/
    //applying  mergeSort;

    start = clock();
    merge_sort(array, 0, MAX-1);
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