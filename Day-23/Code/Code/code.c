//Code

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //for read(), write(), 
#include <sys/wait.h>
#define MSGSIZE 16

//name for the memory location (msg1, msg2, msg3)
char* msg1 = "hello, world #1";
char* msg2 = "hello, world #2";
char* msg3 = "hello, world #3";

int main(){
	
	char inbuf[MSGSIZE]; // inbuf is an array
	int p[2], pid, nbytes; // p is array of size 2 to read and write //to define file descriptor('fd()') fd(1)=>write, fd(0)=>read
	
	if(pipe(p) < 0)
		exit(1);
	
	/* continued */
	if((pid = fork()) > 0){
		write(p[1], msg1, MSGSIZE); //write(filedescriptor, msg, msgSize)
		write(p[1], msg2, MSGSIZE); 
		write(p[1], msg3, MSGSIZE); 
	
		wait(NULL);
	}
	else{
		while((nbytes = read(p[0], inbuf, MSGSIZE)) > 0)
			printf("%s\n", inbuf);
		if(nbytes != 0)
			exit(2);
		printf("Finished reading\n");
	}
	
	return 0;
}


//Output
[nipunika@ChathuraDN ~]$ vi pipeOtherWay.c
[nipunika@ChathuraDN ~]$ gcc pipeOtherWay.c -o pipeOtherWay
[nipunika@ChathuraDN ~]$ ./pipeOtherWay
hello, world #1
hello, world #2
hello, world #3






// Exercise (02)
 step01: parent process get input from user
 step02: sending these inputs to child process
 step03: child process getting these inputs from parent and doing calculation
 step04: step the calculated values to parent
 step05: parent print the outputs
 
 [circle,rectangle,triangle,square]
 
 
// Expected Output
Area calculation program

Circle => C
Triangle => T
Square => S
Rectangle => R

Enter your choice: C

Circle Area Calculation

Enter the radius: 20.9
Area is: 1371.58


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Function declarations
char get_shape_input();
void get_dimensions(char shape, double *v1, double *v2);
void send_inputs_to_child(int fd[], char shape, double v1, double v2);
void calculate_area_in_child(int fd_read[], int fd_write[]);
double receive_area_from_child(int fd[]);

int main() {
    int fd1[2], fd2[2];
    pipe(fd1); // Parent to child
    pipe(fd2); // Child to parent

    pid_t pid = fork();

    if (pid > 0) {
        // Parent process
        close(fd1[0]); // Close read end of pipe1
        close(fd2[1]); // Close write end of pipe2

        printf("Area calculation program\n\n");
        printf("Circle => C\nTriangle => T\nSquare => S\nRectangle => R\n\n");

        char shape = get_shape_input();

        double v1 = 0.0, v2 = 0.0;
        get_dimensions(shape, &v1, &v2);
        send_inputs_to_child(fd1, shape, v1, v2);

        double area = receive_area_from_child(fd2);
        printf("Area is: %.2lf\n", area);

        close(fd1[1]);
        close(fd2[0]);
        wait(NULL); // Wait for child process to finish
    } else {
        // Child process
        close(fd1[1]); // Close write end of pipe1
        close(fd2[0]); // Close read end of pipe2

        calculate_area_in_child(fd1, fd2);

        close(fd1[0]);
        close(fd2[1]);
        exit(0);
    }

    return 0;
}

// Get shape input from user
char get_shape_input() {
    char shape;
    printf("Enter your choice: ");
    scanf(" %c", &shape);
    return shape;
}

// Get dimensions based on shape
void get_dimensions(char shape, double *v1, double *v2) {
    switch (shape) {
        case 'C':
            printf("Circle Area Calculation\nEnter the radius: ");
            scanf("%lf", v1);
            break;
        case 'T':
            printf("Triangle Area Calculation\nEnter the base: ");
            scanf("%lf", v1);
            printf("Enter the height: ");
            scanf("%lf", v2);
            break;
        case 'S':
            printf("Square Area Calculation\nEnter the side: ");
            scanf("%lf", v1);
            break;
        case 'R':
            printf("Rectangle Area Calculation\nEnter the width: ");
            scanf("%lf", v1);
            printf("Enter the height: ");
            scanf("%lf", v2);
            break;
        default:
            printf("Invalid shape.\n");
            exit(1);
    }
}

// Send shape and dimensions to child
void send_inputs_to_child(int fd[], char shape, double v1, double v2) {
    write(fd[1], &shape, sizeof(shape));
    write(fd[1], &v1, sizeof(v1));
    write(fd[1], &v2, sizeof(v2));
}

// Calculate area in child and send to parent
void calculate_area_in_child(int fd_read[], int fd_write[]) {
    char shape;
    double v1, v2, area;

    read(fd_read[0], &shape, sizeof(shape));
    read(fd_read[0], &v1, sizeof(v1));
    read(fd_read[0], &v2, sizeof(v2));

    switch (shape) {
        case 'C':
            area = 3.14159 * v1 * v1;
            break;
        case 'T':
            area = 0.5 * v1 * v2;
            break;
        case 'S':
            area = v1 * v1;
            break;
        case 'R':
            area = v1 * v2;
            break;
        default:
            area = -1.0;
    }

    write(fd_write[1], &area, sizeof(area));
}

// Receive area from child process
double receive_area_from_child(int fd[]) {
    double area;
    read(fd[0], &area, sizeof(area));
    return area;
}



//Output
[nipunika@ChathuraDN ~]$ vi CirTraiRectSqua.c
[nipunika@ChathuraDN ~]$ gcc CirTraiRectSqua.c -o CirTraiRectSqua
[nipunika@ChathuraDN ~]$ ./CirTraiRectSqua
Area calculation program

Circle => C
Triangle => T
Square => S
Rectangle => R

Enter your choice: C
Circle Area Calculation
Enter the radius: 7
Area is: 153.94
[nipunika@ChathuraDN ~]$ ./CirTraiRectSqua
Area calculation program

Circle => C
Triangle => T
Square => S
Rectangle => R

Enter your choice: T
Triangle Area Calculation
Enter the base: 6
Enter the height: 12
Area is: 36.00
[nipunika@ChathuraDN ~]$ ./CirTraiRectSqua
Area calculation program

Circle => C
Triangle => T
Square => S
Rectangle => R

Enter your choice: S
Square Area Calculation
Enter the side: 10
Area is: 100.00
[nipunika@ChathuraDN ~]$ ./CirTraiRectSqua
Area calculation program

Circle => C
Triangle => T
Square => S
Rectangle => R

Enter your choice: R
Rectangle Area Calculation
Enter the width: 8
Enter the height: 10
Area is: 80.00