#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include </usr/include/semaphore.h>
#include <unistd.h>

#define BUFF_SIZE 10 /* total number of slots */
#define NP 3 /* total number of producers */
#define NC 3 /* total number of consumers */
#define NITERS 4 /* number of items produced/consumed */
typedef struct
{
 int buf[BUFF_SIZE]; /* shared var */
 int in; /* buf[in%BUFF_SIZE] is the first empty slot */
 int out; /* buf[out%BUFF_SIZE] is the first full slot */
 sem_t full; /* keep track of the number of full spots */
 sem_t empty; /* keep track of the number of empty spots */
 // use correct type here
 pthread_mutex_t mutex; /*enforce mutual exclusion to shared data*/
} sbuf_t;
sbuf_t shared;

void *Producer(void *arg)
{
 int i, item;
 long index;
 index = (long)arg;
 
 item = i;

 sem_wait(&shared.empty);
 pthread_mutex_lock(&shared.mutex);

 for(int j=0;j<10;j++)
 	if(buffer[j] == -1)
 	
 pthread_mutex_unlock(&shared.mutex);
 sem_post(&shared.full);
 
 return 0;
}
void *Consumer(void *arg)
{
 int i, item;
 long index;
 index = (long)arg;
 for (i=NITERS; i > 0; i--){
 sem_wait(&shared.full);
 pthread_mutex_lock(&shared.mutex);
 item=shared.buf[shared.out];
 shared.out = (shared.out+1)%BUFF_SIZE;
 printf("[C%ld] Consuming %d ...\n", index, item);
 fflush(stdout);
 // Release buffer
 pthread_mutex_unlock(&shared.mutex);
 // Increment the number of full slots
 sem_post(&shared.empty);
 // Inetrleave
 if (i % 2 == 1)
 sleep(1);
 }
 return 0;
}
int main()
{
 pthread_t idP, idC;
 long index;

 sem_init(&shared.full, 0, 0);
 sem_init(&shared.empty, 0, BUFF_SIZE);
 pthread_mutex_init(&shared.mutex, NULL);

 for (index = 0; index < NP; index++) {
 // Create new producer
 pthread_create(&idP, NULL, Producer, (void *)index);
 }
 // Create new consumer
 for(index=0; index<NC; index++) {
 pthread_create(&idC, NULL, Consumer, (void *)index);
 }
 pthread_exit(NULL);
 return 0;
}