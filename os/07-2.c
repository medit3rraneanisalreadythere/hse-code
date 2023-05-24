#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int a = 0;  

void *mythread(void *dummy)
{
  pthread_t mythid;
  mythid = pthread_self();

  a = a+1;
  printf("Thread %lu, Calculation result = %d\n", mythid, a);
  return NULL;
}

int main(int argc, char **argv)
{
  pthread_t thid, thid2, mythid;
  int       result, result2;

// first thread creation
  result = pthread_create (&thid, (pthread_attr_t *)NULL, mythread, NULL);

  if (result != 0) {
    printf ("Error on thread create, return value = %d\n", result);
    exit(-1);
  }

  printf("Thread created, thid = %lu\n", thid);

// second thread creation
  result2 = pthread_create (&thid2, (pthread_attr_t *)NULL, mythread, NULL);

  if (result2 != 0) {
    printf ("Error on thread create, return value = %d\n", result2);
    exit(-1);
  }

  printf("Thread 2 created, thid = %lu\n", thid2);

  mythid = pthread_self();

  a = a+1;

  printf("Thread %lu, Calculation result = %d\n", mythid, a);
  
  pthread_join(thid, (void **)NULL);
  pthread_join(thid2, (void **)NULL);

  return 0;
}
