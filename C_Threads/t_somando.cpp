#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

thread threads[4];
int vetor[2] = {10, 12};
mutex f_lock;

void incrementa(int idc, int valor);
void decrementa(int idc, int valor);

int main(int argc, char const *argv[]) {
  srand(time(NULL));

  threads[0] = thread(incrementa, 0, 4);
  threads[1] = thread(decrementa, 0, 3);
  threads[2] = thread(incrementa, 1, 5);
  threads[3] = thread(decrementa, 1, 8);

  for (int i = 0; i < 4; i++) {
    threads[i].join();
  }

  printf("[%d, %d]\n", vetor[0], vetor[1]);

  return 0;
}

void incrementa(int idc, int valor) {
  f_lock.lock();
  int aux = vetor[idc];
  this_thread::sleep_for(chrono::nanoseconds(rand()));
  aux += valor;
  vetor[idc] = aux;
  f_lock.unlock();
}

void decrementa(int idc, int valor) {
  f_lock.lock();
  int aux = vetor[idc];
  this_thread::sleep_for(chrono::nanoseconds(rand()));
  aux -= valor;
  vetor[idc] = aux;
  f_lock.unlock();
}
