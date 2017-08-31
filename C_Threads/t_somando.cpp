#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t threads[4];
int vetor[2] = {10, 12};

typedef struct {
  int idc, valor;
}thread_args;

void* incrementa(void* args);
void* decrementa(void* args);

int main(int argc, char const *argv[]) {
  thread_args arguments[4];

  arguments[0].idc = 0; arguments[0].valor = 4;
  arguments[1].idc = 1; arguments[1].valor = 5;
  arguments[2].idc = 0; arguments[2].valor = 3;
  arguments[3].idc = 1; arguments[3].valor = 8;

  srand(time(NULL));
  pthread_create(&(threads[0]), NULL, incrementa, (void*) &(arguments[0]));
  pthread_create(&(threads[1]), NULL, decrementa, (void*) &(arguments[2]));
  pthread_create(&(threads[2]), NULL, incrementa, (void*) &(arguments[1]));
  pthread_create(&(threads[3]), NULL, decrementa, (void*) &(arguments[3]));

  for (int i = 0; i < 4; i++) {
    pthread_join(threads[i], NULL);
  }

  printf("[%d, %d]\n", vetor[0], vetor[1]);

  return 0;
}

void* incrementa(void* args) {
  thread_args* argums = (thread_args*) args;
  int local = vetor[argums->idc];
  sleep(((float) rand())/((float) RAND_MAX));
  local += argums->valor;
  vetor[argums->idc] = local;
}

void* decrementa(void* args) {
  thread_args* argums = (thread_args*) args;
  int local = vetor[argums->idc];
  sleep(((float) rand())/((float) RAND_MAX));
  local -= argums->valor;
  vetor[argums->idc] = local;
}
