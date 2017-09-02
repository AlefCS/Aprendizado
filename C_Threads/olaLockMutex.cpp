#include <stdio.h>
#include <thread>
#include <mutex>

using namespace std;

mutex f_lock;

void print_thread_id(int id) {
  f_lock.lock();
  printf("thread #%d\n", id);
  f_lock.unlock();
}

int main(int argc, char const *argv[]) {
  thread threads[10];

  for (int i = 0; i < 10; i++) {
    threads[i] = thread(print_thread_id, i+1);
  }

  for (int i = 0; i < 10; i++) {
    threads[i].join();
  }

  return 0;
}
