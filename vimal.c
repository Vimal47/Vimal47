#include<stdio.h>
struct process
{
 int process_number;
 int arrival_time,burst_time,waiting_time,turnaround_time;
 int flag;
}p[10];

int n;
void sorting_on_arrival_time()
{
struct process temp;
int i,j;
for(i=0;i<n-1;i++)
for(j=i+1;j<n;j++)
{
 if(p[i].arrival_time>p[j].arrival_time)
 {
  temp=p[i];
  p[i]=p[j];
  p[j]=temp;
 }
}
}
void Priority(int a)
{
    int i,time,sum_burst_time;
    sum_burst_time=a;
    float sum=0,sum1=0;
    printf("\nname\t\tarrival time\tburst time\twaiting time");
   for(time=p[0].arrival_time;time<sum_burst_time;)
  {

   float check=-1;
   int loc;
  for(i=0;i<n;i++)
  {

   if(p[i].arrival_time<=time && p[i].flag!=1)
            {
              float temp=(p[i].burst_time + (time-p[i].arrival_time))/p[i].burst_time;
              if(check < temp)
               {
                check=temp;
                loc=i;
               }

   }
   }


   time+=p[loc].burst_time;
   p[loc].waiting_time=time-p[loc].arrival_time-p[loc].burst_time;
   p[loc].turnaround_time=time-p[loc].arrival_time;
   p[loc].flag=1;
   sum+=p[loc].waiting_time;
   sum1=p[loc].waiting_time+p[loc].burst_time;
printf("\nprocess%d\t\t%d\t\t%d\t\t%d\t\t%",(p[loc].process_number+1),p[loc].arrival_time,p[loc].burst_time,p[loc].waiting_time);
  }

printf("\naverage waiting time:%f\n",sum/n);
}
int main()
{
 int i,j,sum_burst_time=0;
 printf("enter no of processes for Shortest job first(NP):");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 p[i].process_number=i;
 printf("enter the arrival and burst time %d\n",(p[i].process_number+1));
 printf("enter the arrival time: ");
 scanf("%d",&p[i].arrival_time);
 printf("enter the burst time: ");
 scanf("%d",&p[i].burst_time);
 p[i].flag=0;
 sum_burst_time+=p[i].burst_time;

}
sorting_on_arrival_time();
Priority(sum_burst_time);
}
