#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000 //define array size



/*_________________________________________________________*/
void bubble_sort (int vetor[], int n) {
    int k, j, aux, flag;

    for (k = 1; k < n; k++)
    {
        flag = 0;
        for (j = 0; j < n - 1; j++)
        {
            if (vetor[j]>vetor[j+1])
            {
                aux=vetor[j];
                vetor[j]=vetor[j + 1];
                vetor[j+1] = aux;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}
/*_________________________________________________________*/




/*_________________________________________________________*/
void selection_sort(int vetor[], int n){
    int k, j, aux, men;

    for (k=0; k<n-1; k++)
    {
        men = k;
        for (j=k+1; j<n; j++)
        {
            if (vetor[men] > vetor[j])
            {
                men = j;
            }
        }
        aux = vetor[k];
        vetor[k] = vetor[men];
        vetor[men] = aux;
    }
}
/*_________________________________________________________*/




/*_________________________________________________________*/
void insertionSort(int vetor[], int n){
    int i, j, p;

    for (i=1; i<n; i++)
    {
        p = vetor[i];
        for (j=i-1; j>=0 && p<vetor[j]; j--)
        {
            vetor[j+1] = vetor[j];
        }
        vetor[j+1] = p;
    }
}
/*_________________________________________________________*/




/*_________________________________________________________*/
int main()
{

    int x, i, aux, j;
    int array[MAX];
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
        array[x] = x; //define the "width" of the numbers
    } */


/*_____________________________________________________________________*/

    //filling array with descending elements
    /* for(x=0; x<MAX; x++)
    {
        array[x] = MAX-x; //define the "width" of the numbers
    } */


/*_____________________________________________________________________*/

    //print before sort:
    printf("\n\n before sorted: \n\n");
    for (i=0; i<MAX; i++)
    {
        printf("%d ", array[i]);
    }
    


/*_________________________________________________________*/
/*_____________________SIMPLE ORDERS_______________________*/

/*_________________________________________________________*/
    //applying bubbleSort;

/*     start = clock();
    bubble_sort(array, MAX);
    end = clock(); */


/*_________________________________________________________*/
    //applying selectionSort;

    /* start = clock();
    selection_sort(array, MAX);
    end = clock(); */


/*_________________________________________________________*/
    //applying insertionSort;

    /* start = clock();
    insertionSort(array, MAX);
    end = clock(); */


/*_________________________________________________________*/



    //print after sort:
    printf("\n\n after sorted: \n\n");
    for (i=0; i<MAX; i++)
    {
        printf("%d ", array[i]);
    }

    

    printf("\n\n\t -> Tempo inicial: %lf milissegundos", ((double)start)/((CLOCKS_PER_SEC)));
    printf("\n\n\t -> Tempo final: %lf milissegundos", ((double)end)/((CLOCKS_PER_SEC)));

    double difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\n\t -> Diferenca em Segundos: %lf\n\n\t -> Diferenca em Milissegundos: %lf", difTempo, difTempo*1000);
    return 0;
}
