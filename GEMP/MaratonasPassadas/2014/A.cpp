#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
  int x, y;

  scanf("%d %d", &x, &y);

  float numv = y - x;
  numv = y/numv;
  printf("%d\n", (int) ceil(numv));

  return 0;
}
