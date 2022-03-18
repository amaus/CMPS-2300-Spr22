#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t m;
volatile int counter = 0; 
int loops;

void *worker(void *arg) {
    int i;
    for (i = 0; i < loops; i++) {
	pthread_mutex_lock(&m);
	counter++;
	pthread_mutex_unlock(&m);
    }
    pthread_exit(NULL);
}

int
main(int argc, char *argv[])
{
    if (argc != 2) { 
	fprintf(stderr, "usage: threads <value>\n"); 
	exit(1); 
    } 
    loops = atoi(argv[1]);
    pthread_t p1, p2;
    printf("Initial value : %d\n", counter);
    pthread_mutex_init(&m, NULL);
    pthread_create(&p1, NULL, worker, NULL); 
    pthread_create(&p2, NULL, worker, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("Final value   : %d\n", counter);
    return 0;
}

