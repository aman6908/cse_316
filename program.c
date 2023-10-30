#include <stdio.h>

#include <stdlib.h>

struct Process {

int id;

int arrivalTime;

int burstTime;

int priority;

int waitingTime;

};

int main() {

int n;

printf("Enter number of processes: ");

scanf("%d", &n);

struct Process p[n];

for(int i=0; i<n; i++) {

p[i].id = i+1;

printf("Enter arrival time and burst time for P%d: ", p[i].id);

scanf("%d%d", &p[i].arrivalTime, &p[i].burstTime);

p[i].waitingTime = 0;

}

int currentTime = 0;

int completed = 0;

while(completed != n) {

int idx = -1;

int maxPriority = -1;

for(int i=0; i<n; i++) {

if(p[i].arrivalTime <= currentTime && p[i].burstTime > 0) {

p[i].priority = 1 + p[i].waitingTime/p[i].burstTime;

if(p[i].priority > maxPriority) {

maxPriority = p[i].priority;

idx = i;

}

}

}

if(idx != -1) {

p[idx].burstTime--;

p[idx].waitingTime++;

if(p[idx].burstTime == 0) {

completed++;

printf("P%d finished\n", p[idx].id);

}

}

currentTime++;

printf("Time %d: ", currentTime);

for(int i=0; i<n; i++)

printf("P%d priority=%d ", p[i].id, p[i].priority);

printf("\n");

}

int totalWaitingTime = 0;

for(int i=0; i<n; i++) {

totalWaitingTime += p[i].waitingTime;

}

float avgWaitingTime = (float)totalWaitingTime/n;

printf("Average waiting time = %f", avgWaitingTime);

return 0; 
    
} 
