#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#define n_primos 1000000 // Constante que indica a quantidade de números que iremos percorrer para encontrar primos.
#define MICRO_PER_SECOND 1000000

/* Algoritmo de força bruta, utilizado para encontrar a quantidade de números primos em um limite máximo
* pré-determinado, como implicito na constante 'n_primos'.
*/

int main()
{  
  struct timeval start_time;
  struct timeval stop_time;
  float time_diff;

  int   i=0,
        j=0,
        count=0,
        primo=0;
  gettimeofday(&start_time,NULL);

  for(i = 2; i <= n_primos; i++)
  {
    if(i % 2 != 0)
    {
       j = i-1;
       primo=1;
       do{
           if(i % j == 0)
             primo = 0;
           j--;
       }while(j > 1 && primo == 1);
       if(primo == 1)
          count++;
    }

  }
  gettimeofday(&stop_time,NULL);

  time_diff = (float)(stop_time.tv_sec - start_time.tv_sec);
  time_diff += (stop_time.tv_usec - start_time.tv_usec) / (float)MICRO_PER_SECOND;

  printf("Tempo gasto:%.6f\n",time_diff);
  printf("Total de primos encontrados:%d\n",count);
  
  return 0;
} 
