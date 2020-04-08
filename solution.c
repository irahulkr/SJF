#include<stdio.h>
#include<conio.h>
int main()
{
  int p[20], burst_time[20], waiting_time[20], turn_around_time[20], i=0, k, n=5, temp;
  float waiting_time_avg, turn_around_time_avg;
  FILE *fp = fopen("CPU_BURST.txt", "r");
  while((getc(fp))!=EOF)
    {

           fscanf(fp, "%d", &burst_time[i]);
           if(burst_time[i]>0)
            {
               p[i]=i+1;
                i++;
            }
    }
  for(i=0;i<n;i++)
  {
    for(k=i+1;k<n;k++)
    {
      if(burst_time[i]>burst_time[k])
      {
        temp=burst_time[i];
        burst_time[i]=burst_time[k];
        burst_time[k]=temp;
        temp=p[i];
        p[i]=p[k];
        p[k]=temp;
      }
    }
  }
  waiting_time[0] = waiting_time_avg = 0;
  turn_around_time[0] = turn_around_time_avg = burst_time[0];
  for(i=1;i<n;i++)
  {
    waiting_time[i] = waiting_time[i-1] +burst_time[i-1];
    turn_around_time[i] = turn_around_time[i-1] +burst_time[i];
    waiting_time_avg = waiting_time_avg + waiting_time[i];
    turn_around_time_avg = turn_around_time_avg + turn_around_time[i];
  }
  printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
  for(i=0;i<n;i++)
  printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i], burst_time[i], waiting_time[i], turn_around_time[i]);
  printf("\nAverage Waiting Time -- %f", waiting_time_avg/n);
  printf("\nAverage Turnaround Time -- %f", turn_around_time_avg/n);
  getch();
}
