#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	char fim[4];
	int L, N, i, j;

	scanf("%c", fim);
	while(fim[0] != EOF) {
		scanf("%2[^ ]s", fim + 1);
		L = atoi(fim);
		scanf("%d", &N);
		int** conteineres = (int**) malloc(L*sizeof(int*));
		if (conteineres == NULL) {
			printf("Sem espaco na memoria! Tente novamente mais tarde.\n");
			return -1;
		}

		for (i = 0; i < L; i++)	{
			conteineres[i] = (int*) malloc(N*sizeof(int));
			if (conteineres[i] == NULL) {
				printf("Sem espaco na memoria! Tente novamente mais tarde.\n");
				return -1;
			}
		}

		for (i = 0; i < L; i++) {
			for (j = 0; j < N; j++)	{
				scanf("%d", &conteineres[i][j]);
			}
		}

		for (i = 0; i < L; i++) {
			for (j = 0; j < N; j++)	{
				printf("%d   ", conteineres[i][j]);
			}
			printf("\n");
		}

		for (i = 0; i < L; i++)	{
			free(conteineres[i]);
			conteineres[i] = NULL;
		}
		free(conteineres);
		conteineres = NULL;

		scanf("%3[^ ]s", fim);
	}

	return 0;
}