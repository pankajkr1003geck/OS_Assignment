#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>

int main(){
int arr[30],key1,key2,status;
pid_t p1,p2;
srand(time(null));
printf("array");
for(int i=0;i<30;i++){
arr[i] = rand() % 50+1;
printf("%d",arr[i]);
}
printf("\n \n Enter key1 and key2:");
scanf("%d %d", &key1,key2);
       \\child 1
p1 = fork();
if(p1= =0){
for(int i=0;i<=14;i++){
if(arr[i] = key1){
printf("%d",i);
}
}
}
\\parent wait for child 1
waitpid(p1,&status,0);
intres1 = WEXITSTATUS(status);
     \\ child 2
p2 = fork();
if(p= = 0){
for(int i=15;i<=29;i++){
if(arr[i] = key2){
printf("%d",i);
}
}
}
\\parent wait for child 2
waitpid(p2,&status,0);
intres2 = WEXITSTATUS(status);
return 0;
}
