Code


#include<stdio.h> //output input functionalities
#include<unistd.h> //To get pid fork functionalities

int main(){
	
	fork();
	printf("Hello World!\n");
	
	return 0;
}


[2021ict41@fedora ~]$ vi 1forkOneTime.c
[2021ict41@fedora ~]$ gcc 1forkOneTime.c -o 1forkOneTime
[2021ict41@fedora ~]$ ./1forkOneTime
Hello World!
Hello World!




#include<stdio.h> //output input functionalities
#include<unistd.h> //To get pid fork functionalities

int main(){
	
	fork();
	fork();
	printf("Hello World!\n");
	
	return 0;
}


[2021ict41@fedora ~]$ vi 1forkTwoTime.c
[2021ict41@fedora ~]$ gcc 1forkTwoTime.c -o 1forkTwoTime
[2021ict41@fedora ~]$ ./1forkTwoTime
Hello World!
Hello World!
Hello World!
Hello World!





#include<stdio.h> //output input functionalities
#include<unistd.h> //To get pid fork functionalities

int main(){
	
	fork();
	fork();
	fork();
	printf("Hello World!\n");
	
	return 0;
}


[2021ict41@fedora ~]$ vi 1forkThreeTime.c
[2021ict41@fedora ~]$ gcc 1forkThreeTime.c -o 1forkThreeTime
[2021ict41@fedora ~]$ ./1forkThreeTime
Hello World!
Hello World!
Hello World!
Hello World!
Hello World!
Hello World!
Hello World!
Hello World!









#include<stdio.h> //output input functionalities
#include<unistd.h> //To get pid fork functionalities

int main(){
	
	int pid = fork();
	if(pid == 0){
		printf("I'm Child Process\n");
	}
	else{
		printf("I'm Parent Process\n");
	}
	
	
	return 0;
}


[2021ict41@fedora ~]$ vi 2ParentChildFork.c
[2021ict41@fedora ~]$ gcc 2ParentChildFork.c -o 2ParentChildFork
[2021ict41@fedora ~]$ ./2ParentChildFork
I'm Parent Process
I'm Child Process




/*print numbers from 1 to 10 and
  1 to 5 should be print by child process and
  6 to 10 should be print by parent process 
  calculate summation of those numbers
*/

#include<stdio.h> //output input functionalities
#include<unistd.h> //To get pid fork functionalities

int main(){

        int pid = fork();

        int childSum=0;
        int parentSum = 0;
		
        if(pid == 0){
                for(int i=1; i<=5; i++){
                        printf("Child: %d ",i);
                        childSum += i;
                }
                printf("\nChild Summation: %d\n", childSum);
        }
        else{
                for(int i=6; i<=10; i++){
                        printf("Parent: %d ",i);
                        parentSum += i;
                }
                printf("\nParent Summation: %d\n", parentSum);
        }


        return 0;
}


[nipunika@ChathuraDN ~]$ vi 1Print1to10InChildNParent.c
[nipunika@ChathuraDN ~]$ gcc 1Print1to10InChildNParent.c -o 1Print1to10InChildNParent
[nipunika@ChathuraDN ~]$ ./1Print1to10InChildNParent
Parent: 6 Parent: 7 Parent: 8 Parent: 9 Parent: 10
Parent Summation: 40
Child: 1 Child: 2 Child: 3 Child: 4 Child: 5
Child Summation: 15




//madam 
#include<stdio.h> //output input functionalities
#include<unistd.h> //To get pid fork functionalities

int main(){
	
	int pid = fork();
	int n;
	
	if(pid == 0){
		n=1;
	}
	else{
		n=6;
	}
	
	int sum = 0;
	for(int i=n; i<n+5; i++){
		printf("%d",i);
		sum += i;
	}
	printf("\nSummation: %d\n", sum);

	
	return 0;
}


[nipunika@ChathuraDN ~]$ vi 1Print1to10InChildNParentMadam.c
[nipunika@ChathuraDN ~]$ gcc 1Print1to10InChildNParentMadam.c -o 1Print1to10InChildNParentMadam
[nipunika@ChathuraDN ~]$ ./1Print1to10InChildNParentMadam
678910
Summation: 40
12345
Summation: 15