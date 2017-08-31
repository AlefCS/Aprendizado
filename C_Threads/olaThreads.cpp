#include <stdio.h>
#include <pthread.h>

// Structs - INÍCIO
typedef struct {
  int idc, tam;
}thread_args;
// Structs - FIM

// Variáveis globais - INÍCIO
pthread_t threads[3];
// Variáveis globais - FIM

// Protótipos - INÍCIO
void *thread_func(void *arg);
// Protótipos - FIM

int main(int argc, char const *argv[]) {
  thread_args argum[3];

  for (int i = 0; i < 3; i++) {
    argum[i].idc = i * 10;
    argum[i].tam = 10;
    pthread_create(&(threads[i]), NULL, thread_func, (void*) &(argum[i]));
  }

  for (int i = 0; i < 3; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}

void *thread_func(void *arg) {
  thread_args* t_arg = (thread_args*) arg;
  for (int i = t_arg->idc; i < t_arg->idc + t_arg->tam; i++) {
    printf("Thread %d - valor %d\n", (int) pthread_self(), i);
  }
}
