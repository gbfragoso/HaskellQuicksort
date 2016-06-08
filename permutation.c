#include <stdio.h>
#include <stdlib.h>

#define N 5

void swap(int *a, int i, int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

// Source: http://rosettacode.org/wiki/Permutations#C
int lex_permutation(int *a, int n){
	int k, l;

	// Find the largest index k that a[k] < a[k+1]
	for (k = n - 1; k && a[k - 1] >= a[k]; k--);
	if (!k--) return 0;

	// Find the largest index I greater than K
	for (l = n - 1; a[l] <= a[k]; l--);

	swap(a,k,l);

	// Reverse the sequence from a[k + 1] to the end
	for (k++, l = n - 1; l > k; l--, k++)
		swap(a,k,l);

	return 1;
}

void print_array(int *a, int n, FILE *output){
	int i;
	fprintf(output, "%d",a[0]);
	for(i = 1; i<N;i++){
		fprintf(output, " %d",a[i]);
	}
	fprintf(output,"\n");
}

int main(void){

    char filename[32];
	int i, a[N];

	// Start array
	for(i = 0; i<N;i++){
		a[i] = i+1;
	}

    snprintf(filename, sizeof(char) * 32, "permutation_n%i.txt", N);
	FILE *output = fopen(filename,"w");
	if(output != NULL){
		do{
			print_array(a,N,output);
		}while(lex_permutation(a,N));
	}

}
