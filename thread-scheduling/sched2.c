#include<stdio.h>
#include<omp.h>

main()
{
printf("Performing Dynamic scheduling, Threads = 4,Chunk=4,iterations=25\n\n");
int i,t0=0,t1=0,t2=0,t3=0;
omp_set_num_threads(4);
#pragma omp parallel
#pragma omp for schedule(dynamic,4)
for(i=0;i<26;i++)
{
int id=omp_get_thread_num();
printf("\nvalue of i is %d and thread ID is %d",i,omp_get_thread_num());
if(id==0)
t0=t0+1;
else if(id==1)
t1=t1+1;
else if(id==2)
t2=t2+1;
else
t3=t3+1;
}
printf("\nThread 0 ran %d times \n Thread 1 ran %d times \n Thread 2 ran %d times\nThread 3 ran %d times\n",t0,t1,t2,t3);
}
