/* test multithreading in C
  note that since C++11 , there is dedicated C++ support: https://www.geeksforgeeks.org/multithreading-in-cpp/
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

#define MIN(a,b) (((a)<(b))?(a):(b))

static int global = 0;
static int global_2 = 0;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;


typedef struct
{
  int id;
  int info;
  int global;
} data;

void	*thread_function(void* vargp);

uint64_t gettid();


int main()
{
  int nthreads = 3;
  
  printf("About to create %d threads \n",nthreads);
  
  pthread_t tid[nthreads];
  int i;
  int err;
  
  data my_data[nthreads];


  
  for(i = 0; i < nthreads; i++)
  {
    my_data[i].info = 2;
    my_data[i].id = i;
    my_data[i].global = global_2;
    err = pthread_create(&tid[i], NULL, thread_function, &my_data[i]);
    if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
    global_2++;
  }
  
  printf("Finished creating threads\n");
  pthread_exit(NULL);
  return 0;
    
}



void	*thread_function(void* vargp)
{
  pthread_mutex_lock( &mutex1 ); printf("lock\n");
  global++;
  uint64_t local_id = gettid();
  printf("The local thread id %" PRIu64  "\n",local_id);

  data local = *((data*) vargp);
  printf("my data at start: %d, %d, %d, %d\n",local.id,local.info,local.global,global);
   pthread_mutex_unlock( &mutex1 ); printf("unlock\n"); //unlock at the middle of the thread
  usleep(100000);
  printf("my data at end: %d, %d, %d, %d\n",local.id,local.info,local.global,global);
  //pthread_mutex_unlock( &mutex1 ); //unlock t the end of the whole thred

  return NULL;
}


uint64_t gettid() {
    pthread_t ptid = pthread_self();
    uint64_t threadId = 0;
    memcpy(&threadId, &ptid, MIN(sizeof(threadId), sizeof(ptid)));
    return threadId;
}
