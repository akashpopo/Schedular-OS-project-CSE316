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
	      printf("\n Process[%d]\t %d \t %d \t %d", i + 1, Bt[i], total - At[i], total - At[i] - Bt[i]);
                 Wt = Wt + total - At[i] - Bt[i]; 
                 Tt = Tt + total - At[i]; 
                 count = 0; 
				 } 
            if(i == limit - 1) 
            {      i = 0 ;          }
            else if(At[i + 1] <= total) 
            {    i++ ;  }
            else 
            { i = 0;  }
      } 
      Awt = Wt * 1.0 / limit;
      Awt = Tt * 1.0 / limit;
      printf("\n\n The Average Waiting Time:  %f\n", Awt); 
      printf("The Average Turnaround Time:  %f ", AverageTurnaroundTime); 
      return (0) ; 
}
