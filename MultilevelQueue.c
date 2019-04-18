#include<stdio.h> 
#include<stdlib.h>
#include<unistd.h>
#include<conio.h>
#include<string.h>

int main()
{ 
      int count = 0, waitingtime = 0, turnaroundtime = 0, total = 0 ; 
	  int TimeQuantum, limit, Wt, Tt, Awt; 
	  int At[10], Bt[10], temp[10]; 
	  int i, x ;
      float AverageTurnaroundTime; 
      printf("Enter the number of Processes you want to execute :\t \n"); 
      scanf("%d", &limit); 
      x =limit; 
      for(i = 0; i < limit; i++) 
      { printf("Process[%d]\n", i+1);
            printf("Arrival Time of the Process:\t ");
            scanf("%d", &At[i]);
            printf("Burst Time of the Process:\t");
            scanf("%d", &Bt[i]); 
            temp[i] =Bt[i];}
      printf("\nEnter Time Quantum for the processes:\t"); 
      scanf("%d", &TimeQuantum); 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;) 
      { if(temp[i] <= TimeQuantum && temp[i] > 0) 
            { total = total + temp[i]; 
                  temp[i] = 0; 
                  count = 1;} 
            else if(temp[i] > 0) 
            {  temp[i] = temp[i] - TimeQuantum; 
                  total = total + TimeQuantum;    } 
            if(temp[i] == 0 && count == 1) 
            { x-- ; 
