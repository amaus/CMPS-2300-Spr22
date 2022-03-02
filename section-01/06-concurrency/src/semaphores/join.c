#include <stdio.h>
#include <unistd.h>
#include "common.h"
#include "common_threads.h"

#ifdef linux
#include <semaphore.h>
#elif __APPLE__
#include "zemaphore.h"
#endif

sem_t done;

void *child(void *arg) {
  sleep(1);
  printf("child\n");
  Sem_post(&done);
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t p;
  Sem_init(&done, 0);
  printf("parent: begin\n");
  Pthread_create(&p, NULL, child, NULL);
  //Pthread_join(p, NULL);
  Sem_wait(&done);
  printf("parent: end\n");
  return 0;
}
