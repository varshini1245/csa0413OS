#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
 int i, pid;
 for(i=1; i<=4; i++) {
 pid = fork(); 
 if(pid == 0) {
 switch(i) {
 case 1: 
 printf("Child %d (PID=%d): ", i, getpid());
 for(int j=1; j<=10; j++) {
 if(j%2 == 1) printf("%d ", j);
 }
 printf("\n");
 break;
 case 2: 
 printf("Child %d (PID=%d): ", i, getpid());
 for(int j=1; j<=10; j++) {
 if(j%2 == 0) printf("%d ", j);
 }
 printf("\n");
 break;
 case 3: 
 printf("Child %d (PID=%d): ", i, getpid());
 for(int j=1; j<=10; j++) {
 if(j%3 == 0) printf("%d ", j);
 }
 printf("\n");
 break;
 case 4: 
 printf("Child %d (PID=%d): ", i, getpid());
 for(int j=1; j<=10; j++) {
 if(j%5 == 0) printf("%d ", j);
 }
 printf("\n");
 break;
 }
 exit(0); 
 }
 }
 return 0;
}
