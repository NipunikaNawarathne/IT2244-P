Code

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int a, b, c; //global variables
int main() {
    pid_t pid_child, pid_sibling;

    // Parent prints first
	printf("Parent: \n");
	printf("My ID %d\n", getpid()); //parent id
	printf("My parent ID %d\n", getppid()); //parent process id
	
	//USER INPUT
	printf("Enter values for A, B, C: \n");
	scanf("%d %d %d", &a, &b, &c);

    pid_child = fork();

    if (pid_child == 0) {
		
        // Child process
        printf("\nChild: \n");
		printf("My parent ID %d\n", getppid()); //parent process id
		
		//FACTORIAL OF A(VARIABLE)
		int fact = 1;
		for(int i=2; i<=a; i++){
			fact *= i;
		}
		printf("Factorial is: %d\n", fact);
		
        return 0;
    }

    // Parent waits for child to finish before creating sibling
    wait(NULL);

    pid_sibling = fork();

    if (pid_sibling == 0) {
        // Sibling process
        printf("\nSibling\n");
        printf("My parent ID %d\n", getppid());
		
		
		//FIBONACCI UP TO B(VARIABLE)
		int x = 0;
		int y = 1;
		int z;
		
		for(int i=0; i<=b; i++){
			printf("%d ", x);
			
			z = (x+y);
			x = y;
			y = z;
		}
		printf("\n\n");
		
		
		//PRIME NUMBERS UP TO C(VARIABLE)
		int isPrime;
		
		if(c<=1){
			isPrime = 0;
		}
		else{
			for(int i = 2; i*i<=c; i++){
				if(c%i == 0){
					isPrime = 0;
					break;
				}
			}
		}
		
		if(isPrime){
			printf("%d is a prime number.\n", c);
		}
		else{
			printf("%d is not a prime number.\n", c);		
		}
		
        return 0;
    }

    // Parent waits for sibling to finish
    wait(NULL);

    return 0;
}


[nipunika@ChathuraDN ~]$ vi ParentChildSiblingEx.c
[nipunika@ChathuraDN ~]$ gcc ParentChildSiblingEx.c -o ParentChildSiblingEx
[nipunika@ChathuraDN ~]$ ./ParentChildSiblingEx
Parent:
My ID 48
My parent ID 12
Enter values for A, B, C:
5
7
12

Child:
My parent ID 48
Factorial is: 120

Sibling
My parent ID 48
0 1 1 2 3 5 8 13

12 is not a prime number.

