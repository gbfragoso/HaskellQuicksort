#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int *vet, int esq, int dir);

int main(int argc, char **argv){

        int i, j = 0, num = 0;
        int size = 5;
        int *array;

        // Opening archives
        FILE *archive = fopen("permutation_n5.txt","r");

        array = (int*) calloc(size,sizeof(int));

        // Read each row and put in array to sort
        printf("Running Quicksort on each combinations.txt row ...");
        clock_t start2 = clock();
        fscanf(archive,"%1d", &num);
        while(!feof(archive)){
            if(j < size){
                array[j++] = num;
                fscanf(archive,"%1d", &num);
            }else{
                quicksort(array,0,size-1);
                j=0;
            }
        }
        quicksort(array,0,size-1);
        clock_t end2 = clock();
        float seconds2 = (float)(end2 - start2) / CLOCKS_PER_SEC;
        printf("done! Time: %f s\n",seconds2);

        // Closing archives
        fclose(archive);

        // Free memory
        free(array);

    return 0;
}

void quicksort(int *vet, int esq, int dir){
    int pivo = esq,i,ch,j;
    for(i=esq+1;i<=dir;i++){
        j = i;
        if(vet[j] < vet[pivo]){
         ch = vet[j];
         while(j > pivo){
            vet[j] = vet[j-1];
            j--;
         }
         vet[j] = ch;
         pivo++;
        }
    }
    if(pivo-1 >= esq){
        quicksort(vet,esq,pivo-1);
    }
    if(pivo+1 <= dir){
        quicksort(vet,pivo+1,dir);
    }
}
