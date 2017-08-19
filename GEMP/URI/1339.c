#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void rotacionar(int* cubo, int lado);

int main(int argc, int const *argv[]) {
	int cubo[54];
	int i, j, k, numTestes, lado;

	scanf("%d", &numTestes);
	for (k = 0; k < numTestes; k++) {
		for (i = 36; i < 45; i++) {
			scanf("%d", &cubo[i]);
		}
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				scanf("%d", &cubo[j + 3*i]);
			}
			for (j = 9; j < 12; j++) {
				scanf("%d", &cubo[j + 3*i]);
			}
			for (j = 18; j < 21; j++) {
				scanf("%d", &cubo[j + 3*i]);
			}
			for (j = 27; j < 30; j++) {
				scanf("%d", &cubo[j + 3*i]);
			}
		}
		for (i = 45; i < 54; i++) {
			scanf("%d", &cubo[i]);
		}

		do {
			scanf("%d", &lado);
			if (lado == 0) break;
			rotacionar(cubo, lado);
		} while (lado != 0);
	}

	for (i = 0; i < 54; i++) {
		if ((i % 3) == 0) {
			printf("\n");
		}
		printf("%d ", cubo[i]);
	}

	return 0;
}

void rotacionar(int* cubo, int lado) {
	int aux, i ;

	if (lado > 0) {
		aux = cubo[2 + 9*(lado - 1)];
		cubo[2 + 9*(lado - 1)] = cubo[0 + 9*(lado - 1)];
		cubo[0 + 9*(lado - 1)] = cubo[6 + 9*(lado - 1)];
		cubo[6 + 9*(lado - 1)] = cubo[8 + 9*(lado - 1)];
		cubo[8 + 9*(lado - 1)] = aux;
		aux = cubo[5 + 9*(lado - 1)];
		cubo[5 + 9*(lado - 1)] = cubo[1 + 9*(lado - 1)];
		cubo[1 + 9*(lado - 1)] = cubo[3 + 9*(lado - 1)];
		cubo[3 + 9*(lado - 1)] = cubo[7 + 9*(lado - 1)];
		cubo[7 + 9*(lado - 1)] = aux;
		switch(lado) {
			case 1:
				for (i = 0; i < 3; i++) {
					aux = cubo[36 + 3*i];
					cubo[36 + 3*i] = cubo[35 - 3*i];
					cubo[35 - 3*i] = cubo[45 + 3*i];
					cubo[45 + 3*i] = cubo[9 + 3*i];
					cubo[9 + 3*i] = aux;
				}
				break;
			case 2:
				for (i = 0; i < 3; i++) {
					aux = cubo[42 + i];
					cubo[42 + i] = cubo[8 - 3*i];
					cubo[8 - 3*i] = cubo[47 - i];
					cubo[47 - i] = cubo[18 + 3*i];
					cubo[18 + 3*i] = aux;
				}
				break;
			case 3:
				for (i = 0; i < 3; i++) {
					aux = cubo[44 - 3*i];
					cubo[44 - 3*i] = cubo[17 - 3*i];
					cubo[17 - 3*i] = cubo[53 - 3*i];
					cubo[53 - 3*i] = cubo[27 + 3*i];
					cubo[27 + 3*i] = aux;
				}
				break;
			case 4:
				for (i = 0; i < 3; i++) {
					aux = cubo[36 + i];
					cubo[36 + i] = cubo[20 + 3*i];
					cubo[20 + 3*i] = cubo[53 - i];
					cubo[53 - i] = cubo[6 - 3*i];
					cubo[6 - 3*i] = aux;
				}
				break;
			case 5:
				for (i = 0; i < 3; i++) {
					aux = cubo[29 - i];
					cubo[29 - i] = cubo[2 - i];
					cubo[2 - i] = cubo[11 - i];
					cubo[11 - i] = cubo[20 - i];
					cubo[20 - i] = aux;
				}
				break;
			case 6:
				for (i = 0; i < 3; i++) {
					aux = cubo[15 + i];
					cubo[15 + i] = cubo[6 + i];
					cubo[6 + i] = cubo[33 + i];
					cubo[33 + i] = cubo[24 + i];
					cubo[24 + i] = aux;
				}
				break;
		}
	} else {
		aux = cubo[2 + 9*(abs(lado) - 1)];
		cubo[2 + 9*(abs(lado) - 1)] = cubo[8 + 9*(abs(lado) - 1)];
		cubo[8 + 9*(abs(lado) - 1)] = cubo[6 + 9*(abs(lado) - 1)];
		cubo[6 + 9*(abs(lado) - 1)] = cubo[0 + 9*(abs(lado) - 1)];
		cubo[0 + 9*(abs(lado) - 1)] = aux;
		aux = cubo[5 + 9*(abs(lado) - 1)];
		cubo[5 + 9*(abs(lado) - 1)] = cubo[7 + 9*(abs(lado) - 1)];
		cubo[7 + 9*(abs(lado) - 1)] = cubo[3 + 9*(abs(lado) - 1)];
		cubo[3 + 9*(abs(lado) - 1)] = cubo[1 + 9*(abs(lado) - 1)];
		cubo[1 + 9*(abs(lado) - 1)] = aux;
		switch(lado) {
			case -1:
				for (i = 0; i < 3; i++) {
					aux = cubo[36 + 3*i];
					cubo[36 + 3*i] = cubo[9 + 3*i];
					cubo[9 + 3*i] = cubo[45 + 3*i];
					cubo[45 + 3*i] = cubo[35 - 3*i];
					cubo[35 - 3*i] = aux;
				}
				break;
			case -2:
				for (i = 0; i < 3; i++) {
					aux = cubo[42 + i];
					cubo[42 + i] = cubo[18 + 3*i];
					cubo[18 + 3*i] = cubo[47 - i];
					cubo[47 - i] = cubo[8 - 3*i];
					cubo[8 - 3*i] = aux;
				}
				break;
			case -3:
				for (i = 0; i < 3; i++) {
					aux = cubo[44 - 3*i];
					cubo[44 - 3*i] = cubo[27 + 3*i];
					cubo[27 + 3*i] = cubo[53 - 3*i];
					cubo[53 - 3*i] = cubo[17 - 3*i];
					cubo[17 - 3*i] = aux;
				}
				break;
			case -4:
				for (i = 0; i < 3; i++) {
					aux = cubo[36 + i];
					cubo[36 + i] = cubo[6 - 3*i];
					cubo[6 - 3*i] = cubo[53 - i];
					cubo[53 - i] = cubo[20 + 3*i];
					cubo[20 + 3*i] = aux;
				}
				break;
			case -5:
				for (i = 0; i < 3; i++) {
					aux = cubo[29 - i];
					cubo[29 - i] = cubo[20 - i];
					cubo[20 - i] = cubo[11 - i];
					cubo[11 - i] = cubo[2 - i];
					cubo[2 - i] = aux;
				}
				break;
			case -6:
				for (i = 0; i < 3; i++) {
					aux = cubo[15 + i];
					cubo[15 + i] = cubo[24 + i];
					cubo[24 + i] = cubo[33 + i];
					cubo[33 + i] = cubo[6 + i];
					cubo[6 + i] = aux;
				}
				break;
		}
	}
}