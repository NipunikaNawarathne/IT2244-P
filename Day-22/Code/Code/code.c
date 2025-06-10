//Code

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MSGSIZE 16


//name for the memory location (msg1, msg2, msg3)
char* msg1 = "hello, world #1";
char* msg2 = "hello, world #2";
char* msg3 = "hello, world #3";

int main(){
	
	char inbuf[MSGSIZE]; // inbuf is an array
	int p[2], i; // p is array of size 2 to read and write //to define file descriptor('fd()') fd(1)=>write, fd(0)=>read
	
	if(pipe(p) < 0)
		exit(1);
	
	/* continued */
	/* write pipe */
	
	write(p[1], msg1, MSGSIZE); //write(filedescriptor, msg, msgSize)
	write(p[1], msg2, MSGSIZE); 
	write(p[1], msg3, MSGSIZE); 
	
	for(i=0; i<3; i++){
		read(p[0], inbuf, MSGSIZE); //read(filedescriptor, msg, msgSize)
		printf("%s\n", inbuf);
	}
	
	return 0;
}


//Output

[nipunika@ChathuraDN ~]$ vi pipe.c
[nipunika@ChathuraDN ~]$ gcc pipe.c -o pipe
[nipunika@ChathuraDN ~]$ ./pipe
hello, world #1
hello, world #2
hello, world #3




//Question

/*
1. Get three input from user (//parent process)
 name: 
 reg no: 
 age: 

2. Print the output from the child(//child process)
 name: abc
 reg no: 2022/ict/01
 age: 25
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MSGSIZE 16

int main() {
    char name[MSGSIZE], regno[MSGSIZE], age[MSGSIZE];
    int p[2], f, i;

    if (pipe(p) < 0) {
        perror("Pipe failed");
        exit(1);
    }

    if ((f = fork()) == 0) {
        // Child process
        close(p[1]); // Close write end
        for (i = 0; i < 3; i++) {
            char inbuf[MSGSIZE];
            read(p[0], inbuf, MSGSIZE);
            printf("%s", inbuf);
        } 
        close(p[0]);
    } else if (f > 0) {
        // Parent process
        close(p[0]); // Close read end
        printf("Name: ");
        fgets(name, MSGSIZE, stdin);
        printf("Reg No: ");
        fgets(regno, MSGSIZE, stdin);
        printf("Age: ");
        fgets(age, MSGSIZE, stdin);

        write(p[1], name, MSGSIZE);
        write(p[1], regno, MSGSIZE);
        write(p[1], age, MSGSIZE);
        close(p[1]);
    } else {
        perror("Fork failed");
        exit(1);
    }

    return 0;
}




//Output

[nipunika@ChathuraDN ~]$ vi pipeExercise.c
[nipunika@ChathuraDN ~]$ gcc pipeExercise.c -o pipeExercise
[nipunika@ChathuraDN ~]$ ./pipeExercise
Name: Nipunika
Reg No: 2021/ICT/41
Age: 24
Nipunika
2021/ICT/41
24








