#include<stdio.h>
#include<omp.h>

main()
{
printf("Performing Guided scheduling, Threads = 3,Chunk=3,iterations=26\n\n");
int i;
int t0=1,t1=0,t2=0;
omp_set_num_threads(3);
#pragma omp parallel
#pragma omp for schedule(guided,3)
for(i=0;i<27;i++)
{
int id=omp_get_thread_num();
printf("\nValue of i is %d and thread ID is %d",i,id);
if(id==0)
t0=t0+1;
else if(id==1)
t1=t1+1;
else
t2=t2+1;
}
printf("\nThread 0 ran %d times \n Thread 1 ran %d times \n Thread 2 ran %d times\n",t0,t1,t2);
}
