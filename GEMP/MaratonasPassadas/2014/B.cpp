#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int p, pos = 1, cont = 0;

  scanf("%d", &p);
  do {
    cont++;
    if (pos <= p/2) {
      pos = 2*pos;
    } else {
      pos = 2*pos - p - 1;
    }
  } while (pos != 1);

  printf("%d\n", cont);

  return 0;
}
