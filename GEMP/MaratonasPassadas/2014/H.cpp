#include <stdio.h>

int main(int argc, char const *argv[]) {
  int n, m, aux;
  int cont = 0;
  bool goleador;

  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++) {
    goleador = true;
    for (int j = 0; j < m; j++) {
      scanf("%d", &aux);
      if (!aux) goleador = false;
    }
    cont = cont + (int) goleador;
  }

  printf("%d\n", cont);

  return 0;
}
