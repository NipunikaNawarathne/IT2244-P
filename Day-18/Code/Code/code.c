Code


#include <stdio.h>
#include <stdlib.h> // for exit()
#include <unistd.h> // for sleep()

int main(){
	
	printf("Program Started. \n");
	
	printf("Sleeping for 3 seconds... \n");
	sleep(3); //pause for 3 seconds
	
	printf("Exiting the program. \n");
	exit(0); //clean exit
	
	return 0;
}

[nipunika@ChathuraDN ~]$ vi SleepExit.c
[nipunika@ChathuraDN ~]$ gcc SleepExit.c -o SleepExit
[nipunika@ChathuraDN ~]$ ./SleepExit
Program Started.
Sleeping for 3 seconds...
Exiting the program.




#include <stdio.h>
#include <stdlib.h> // for exit()
#include <unistd.h> // for fork(), sleep()
#include <sys/wait.h> // for wait()

int main(){
	
	pid_t pid; //data type (to initialize pid)
	
	printf("Parent process started. PID: %d\n", getpid());
	
	pid = fork(); //create a new child process
	
	if(pid <0){
		perror("Fork Failed");
		exit(1);
	}
	
	if(pid==0){
		//Child process
		printf("Child process. PID: %d, Sleeping for 2 seconds... \n", getpid());
		sleep(2);
		printf("Child process existing.\n");
		exit(0); //child exit with status 0
	}
	else{
		//Parent process
		int status;
		printf("Parent waiting for child to finish... \n");
		wait(&status); // wait for child to finish
		
		if(WIFEXITED(status)){ //WIFEXITED(status) returns true if child terminated normally.
			printf("Child exited with status: %d\n", WEXITSTATUS(status));
			//WEXITSTATUS(status) gets the actual exit code (0 here).
		}
		else{
			printf("Child did not exit normally. \n");
		}
		printf("Parent process ending.\n");
	}
	
	
	return 0;
}


[nipunika@ChathuraDN ~]$ vi SleepExitEx.c
[nipunika@ChathuraDN ~]$ gcc SleepExitEx.c -o SleepExitEx
[nipunika@ChathuraDN ~]$ ./SleepExitEx
Parent process started. PID: 81
Parent waiting for child to finish...
Child process. PID: 82, Sleeping for 2 seconds...
Child process existing.
Child exited with status: 0
Parent process ending.





/*
	Exercise:
	
	First child: Slept for 1 second.
	Second child: Slept for 3 seconds.
	Parent: Both children have finished.
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	
	pid_t pid_child, pid_sibling;
	
	printf("I'm Parent\n");
	printf("My ID %d\n", getpid());
	printf("My parent ID %d\n", getppid());
	
	pid_child=fork();
	
	if(pid_child<0){
		perror("Fork Failed");
		exit(1);
	}
	
	
	if(pid_child==0){
		// Child process
        printf("I'm Child\n");
        printf("My parent ID %d\n", getppid());
		sleep(1);
		printf("Sleeping for 1 seconds... \n");
        return 0;
	}
	else{ //still in the paren process
		
		pid_sibling = fork();

        if (pid_sibling == 0) { //checking the second chlild
            // This is the Sibling process (another child of original parent)
            printf("I'm Sibling\n");
            printf("My parent ID %d\n", getppid());
			sleep(3);
			printf("Sleeping for 3 seconds... \n");
			return 0;
        }
		else {
			//parent process
            wait(NULL); // Wait for any child
            wait(NULL); // Wait for the other child
			printf("Parent: Both children have finished.\n");
        }	
	}
	
	
	return 0;
}


[nipunika@ChathuraDN ~]$ vi SleepExitEx1.c
[nipunika@ChathuraDN ~]$ gcc SleepExitEx1.c -o SleepExitEx1
[nipunika@ChathuraDN ~]$ ./SleepExitEx1
I'm Parent
My ID 99
My parent ID 12
I'm Child
My parent ID 99
I'm Sibling
My parent ID 99
Sleeping for 1 seconds...
Sleeping for 3 seconds...
Parent: Both children have finished.
