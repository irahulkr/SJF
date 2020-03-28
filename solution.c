//In this we are taking the input from terminal and not from any file


#include<stdio.h>
#include<conio.h>
int main()
{
  int p[20], burst_time[20], waiting_time[20], turn_around_time[20], i, k, n=5, temp;
  float waiting_time_avg, turn_around_time_avg;
  for(i=0;i<n;i++)
  {
    p[i]=i;
    printf("Enter Burst Time for Process %d -- ", i);
    scanf("%d", &burst_time[i]);
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

