#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 50000 //define array size

/* heap sort */



void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;

}

void makeHeap(int array[], int n, int i){
    int maior = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left < n && array[left] > array[maior])
    {
        maior = left;
    }

    if (right < n && array[right] > array[maior])
    {
        maior = right;
    }

    if (maior != i)
    {
        swap(&array[i], &array[maior]);
        makeHeap(array, n, maior);
    }

}

void heapSort(int array[], int n){

    
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        makeHeap(array, n ,i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&array[0], &array[i]);
        makeHeap(array, i, 0);
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
    }
 */

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
        printf("%d  ", array[i]);
    }
     */


/*___________________________________________________________*/
/*_____________________EFFICIENT ORDERS_______________________*/

/*_________________________________________________________*/
    //applying  heapSort;

    start = clock();
    heapSort(array, MAX);
    end = clock();


/*_________________________________________________________*/



    //print after sort:
  /*   printf("\n\n after sorted: \n\n");
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

