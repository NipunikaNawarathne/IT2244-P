Codes

#include<stdio.h>
#include<unistd.h>

int main(){
	
	printf("Hello World !\n");
	
	int f = fork();
	int pid = getpid();
	printf("The pid is: %d\n", pid);
	printf("The fork is: %d\n", f);
	
	
	return 0;
	
}

//Output

[nipunika@ChathuraDN ~]$ vi 1fork.c
[nipunika@ChathuraDN ~]$ gcc 1fork.c -o 1fork
[nipunika@ChathuraDN ~]$ ./1fork
Hello World !
The pid is: 163
The fork is: 164
The pid is: 164
The fork is: 0




#include<stdio.h>
#include<unistd.h>

int main(){
	
	fork();
	fork();
	printf("\nHello World\n");
	
	return 0;
}


//Output

[nipunika@ChathuraDN ~]$ vi 2fork.c
[nipunika@ChathuraDN ~]$ gcc 2fork.c -o 2fork
[nipunika@ChathuraDN ~]$ ./2fork

Hello World

Hello World

Hello World

Hello World






#include<stdio.h>
#include<unistd.h>

int main(){
	
	int f = fork();
	if(f==0){
		printf("Hello I'm child\n");
	}
	else{
		printf("Hello I'm parent\n");
	}
	
	return 0;
}



//Output

[nipunika@ChathuraDN ~]$ vi 3fork.c
[nipunika@ChathuraDN ~]$ gcc 3fork.c -o 3fork
[nipunika@ChathuraDN ~]$ ./3fork
Hello I'm parent
Hello I'm child




#include<stdio.h>
#include<unistd.h>

int main(){
	
	int f = fork();
	if(f==0){
		printf("Hello I'm child\n");
	}
	else{
		printf("Hello I'm parent\n");
	}
	
	printf("hello\n")
	
	return 0;
}



//Output

[nipunika@ChathuraDN ~]$ vi 4fork.c
[nipunika@ChathuraDN ~]$ gcc 4fork.c -o 4fork
[nipunika@ChathuraDN ~]$ ./4fork
Hello I'm parent
hello
Hello I'm child
hello





#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid, sibling_pid;

    printf("I'm Parent\n");
    printf("My ID %d\n", getpid());
    printf("My parent ID %d\n", getppid());

    child_pid = fork();

    if (child_pid == 0) {
        // This is the Child process
        printf("I'm Child\n");
        printf("My parent ID %d\n", getppid());
    } else {
        wait(NULL); // Wait for the child to finish

        sibling_pid = fork();

        if (sibling_pid == 0) {
            // This is the Sibling process (another child of original parent)
            printf("I'm Sibling\n");
            printf("My parent ID %d\n", getppid());
        } else {
            wait(NULL); // Wait for the sibling to finish
        }
    }

    return 0;
}



//Output

[nipunika@ChathuraDN ~]$ vi 5ParentChildSibling.c
[nipunika@ChathuraDN ~]$ gcc 5ParentChildSibling.c -o 5ParentChildSibling
[nipunika@ChathuraDN ~]$ ./5ParentChildSibling
I'm Parent
My ID 57
My parent ID 12
I'm Child
My parent ID 57
I'm Sibling
My parent ID 57


