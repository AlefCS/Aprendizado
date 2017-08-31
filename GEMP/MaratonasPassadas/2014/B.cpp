#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int n, cont = 0;
  //int *x, *xi, *xf;
  int x[200000], xi[100000], xf[100000];
  bool continuar = true;

  scanf("%d", &n);

  // x = (int*) malloc(n*8);
  // xi = (int*) malloc(n*4);
  // xf = (int*) malloc(n*4);

  for (int i = 0; i < 2*n; i+=2) {
    x[i] = i + 1;
    x[i + 1] = i + 2;
  }

  while (continuar) {
    cont++;
    for (int i = 0; i < n; i++) {
      xi[i] = x[i];
      xf[i] = x[i + n];
    }

    for (int i = 0; i < 2*n; i += 2) {
      x[i] = xf[i/2];
      x[i + 1] = xi[i/2];
    }

    continuar = false;

    for (int i = 1; i < 2*n; i++) {
      if (x[i - 1] > x[i]) {
        continuar = true;
      }
    }
  }

  printf("Foram: %d\n", cont);

  return 0;
}
