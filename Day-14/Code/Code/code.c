Codes


1. //if else

if(condition){
	//body of if statement;
}
else{
	//body of else statement;
}

//Enter your age and verify your eligible or not for election voting using if else condition

#include<stdio.h>

int main(){
	
	printf("Enter your age: ");
	int age;
	scanf("%d", &age);
	
	if(0 < age && age <= 100){
		if(age >= 18){
			printf("You're eligible for voting !");
		}
		else{
			printf("You're not eligible for voting !");
		}
	}
	else{
		printf("Invalid Input !");
	}
	
	return 0;
}


//Output

[nipunika@ChathuraDN ~]$ vi 1CLangIfElse.c
[nipunika@ChathuraDN ~]$ gcc 1CLangIfElse.c -o 1CLangIfElse
[nipunika@ChathuraDN ~]$ ./1CLangIfElse
Enter your age: -29
Invalid Input !
[nipunika@ChathuraDN ~]$ ./1CLangIfElse
Enter your age: 0
Invalid Input !
[nipunika@ChathuraDN ~]$ ./1CLangIfElse
Enter your age: 15
You're not eligible for voting !
[nipunika@ChathuraDN ~]$ ./1CLangIfElse
Enter your age: 24
You're eligible for voting !
[nipunika@ChathuraDN ~]$ ./1CLangIfElse
Enter your age: 100
You're eligible for voting !
[nipunika@ChathuraDN ~]$ ./1CLangIfElse
Enter your age: 107
Invalid Input !




2. /*instead of if else  we can use,

	Ternary operator
	test_condition ? expression1 : expression2
	
	*/

#include <stdio.h>

int main() {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age >= 0 && age <= 100) {
        age >= 18 ? printf("You're eligible for voting!\n") : printf("You're not eligible for voting!\n");
    } else {
        printf("Invalid Input!\n");
    }

    return 0;
}



//Output

[nipunika@ChathuraDN ~]$ vi 2RegularExp.c
[nipunika@ChathuraDN ~]$ gcc 2RegularExp.c -o 2RegularExp
[nipunika@ChathuraDN ~]$ ./2RegularExp
Enter your age: 24
You're eligible for voting!
[nipunika@ChathuraDN ~]$ ./2RegularExp
Enter your age: 11
You're not eligible for voting!
[nipunika@ChathuraDN ~]$ ./2RegularExp
Enter your age: -8
Invalid Input!
[nipunika@ChathuraDN ~]$ ./2RegularExp
Enter your age: 149
Invalid Input!







3. /*switch operator
	
	switch(variable/expression){
		case 1:
			//body of case 1;
			break;
		case 2:
			//body of case 2;
			break;
		case 3:
			//body of case 3;
			break;
		default:
			//body of default;
	}
	
	*/

/*
Enter the number between 1 to 7: 1
Today is Sunday!
*/


#include <stdio.h>

int main(){
	
	int number;
	printf("Enter the number between 1 to 7: ");
	scanf("%d", &number);
	
	switch(number){
		case 1:
			printf("Monday !\n");
			break;
		case 2:
			printf("Tuesday !\n");
			break;
		case 3:
			printf("Wednesday !\n");
			break;
		case 4:
			printf("Thursday !\n");
			break;
		case 5:
			printf("Friday !\n");
			break;
		case 6:
			printf("Saturday !\n");
			break;
		case 7:
			printf("Sunday !\n");
			break;
		default:
			printf("Invalid Number !\n");
	}
	
	return 0;
}


//Output

[nipunika@ChathuraDN ~]$ vi CLangSwitch.c
[nipunika@ChathuraDN ~]$ gcc CLangSwitch.c -o CLangSwitch
[nipunika@ChathuraDN ~]$ ./CLangSwitch
Enter the number between 1 to 7: 0
Invalid Number !
[nipunika@ChathuraDN ~]$ ./CLangSwitch
Enter the number between 1 to 7: 3
Wednesday !
[nipunika@ChathuraDN ~]$ ./CLangSwitch
Enter the number between 1 to 7: 13
Invalid Number !




4. /*
	Q1) Write a code for small astrology based on your life
path number for that get date of birth from user then
calculate life path number. (use switch case)
	Example:-
		Calculation for life path number: //date is 23
			a=date%10	3
			b=date/10	2
			c=a+b	5
		if life path number:
			1:Lucky
			2:Carefuly do your work
			3:Storger
			4:Happy
			5:Can get help
			6:Doubt
			7:Sad
			8:Like
			9:Courage

	*/
	
	

#include <stdio.h>

int main(){
	
	int date;
	printf("Enter your birth date: ");
	scanf("%d", &date);
	
	int a,b,c,x,y,z;
	
	a = date%10;
	b = date/10;
	c = a+b;
	
	if(c>9){
		x = c%10;
		y = c/10;
		z = x+y;
	}
	else{
		z = c;
	}
	
	switch(z){
		case 1:
			printf("Lucky\n");
			break;
		case 2:
			printf("Carefuly do your work\n");
			break;
		case 3:
			printf("Storger\n");
			break;
		case 4:
			printf("Happy\n");
			break;
		case 5:
			printf("Can get help\n");
			break;
		case 6:
			printf("Doubt\n");
			break;
		case 7:
			printf("Sad\n");
			break;
		case 8:
			printf("Like\n");
			break;
		case 9:
			printf("Courage\n");
			break;
		default:
			printf("Invalid Number\n");
	}
	
	return 0;
}


//Output

[nipunika@ChathuraDN ~]$ vi CLangSwitchEx.c
[nipunika@ChathuraDN ~]$ gcc CLangSwitchEx.c -o CLangSwitchEx
[nipunika@ChathuraDN ~]$ ./CLangSwitchEx
Enter your birth date: 24
Doubt
[nipunika@ChathuraDN ~]$ ./CLangSwitchEx
Enter your birth date: 29
Carefuly do your work	
	
	
	
	
5. //print the integers from 1 to 10 using while loop.


#include <stdio.h>

int main(){
	
	printf("Print integers from 1 to 10.\n");
	
	int i = 1;
	
	while(i<=10){
		printf("%d ",i);
		i++;
	}
	printf("\n");
	
	return 0;
}


//Output

[nipunika@ChathuraDN ~]$ vi 5CLangWhile.c
[nipunika@ChathuraDN ~]$ gcc 5CLangWhile.c -o 5CLangWhile
[nipunika@ChathuraDN ~]$ ./5CLangWhile
Print integers from 1 to 10.
1 2 3 4 5 6 7 8 9 10





6. /*Write a C program to generate and print the Fibonacci series up to a specific number of terms. The program 
should take the number of terms as input from the user and then display the corresponding Fibonacci sequence.
*/


#include <stdio.h>

int main(){
	
	int term;
	printf("Enter the number of terms: ");
	scanf("%d", &term);
	
	int a,b,c;
	
	a = 0;
	b = 1;
	
	for(int i=1; i<=term; i++){
		printf("%d ", a);
		
		c = a+b;
		a = b;
		b = c;
	}
	
	
	return 0;
}


//Output

[nipunika@ChathuraDN ~]$ vi 6CLangFibonacci.c
[nipunika@ChathuraDN ~]$ gcc 6CLangFibonacci.c -o 6CLangFibonacci
[nipunika@ChathuraDN ~]$ ./6CLangFibonacci
Enter the number of terms: 8
0 1 1 2 3 5 8 13
[nipunika@ChathuraDN ~]$ ./6CLangFibonacci
Enter the number of terms: 10
0 1 1 2 3 5 8 13 21 34



7. /*Write a C program to calculate the factorial of given non-negative integer.*/


#include <stdio.h>

int main(){
	
	int number;
	printf("Enter number to get factorial: ");
	scanf("%d", &number);
	
	int fact = 1;
	
	for(int i=1; i<=number; i++){
		fact = fact * i;
	}
	
	printf("Factorial: %d", fact);
	
	return 0;
}


//Output

[nipunika@ChathuraDN ~]$ vi 7CLangFactorial.c
[nipunika@ChathuraDN ~]$ gcc 7CLangFactorial.c -o 7CLangFactorial
[nipunika@ChathuraDN ~]$ ./7CLangFactorial
Enter number to get factorial: 5
Factorial: 120
[nipunika@ChathuraDN ~]$ ./7CLangFactorial
Enter number to get factorial: 8
Factorial: 40320



8. /*Write a C program that takes a binary number(as an integer) as input and converts it to its decimal equivalent.*/


#include <stdio.h>

int main(){
	
	int binary, remainder, decimal=0, base=1;
	printf("Enter a binary number: ");
	scanf("%d", &binary);
	
	while(binary > 0){
		remainder = binary%10;
		
		if (remainder != 0 && remainder != 1) {
			printf("Invalid input! Please enter a binary number.\n");
			return 1;
		}
	
		decimal += remainder * base;
		binary = binary/10;
		base = base*2;
	}
	
	// Output the result
    printf("Decimal equivalent: %d\n", decimal);
	
	return 0;
}


//Output

[nipunika@ChathuraDN ~]$ vi 8BinaryToInt.c
[nipunika@ChathuraDN ~]$ gcc 8BinaryToInt.c -o 8BinaryToInt
[nipunika@ChathuraDN ~]$ ./8BinaryToInt
Enter a binary number: 10101101
Decimal equivalent: 173
[nipunika@ChathuraDN ~]$ ./8BinaryToInt
Enter a binary number: 10101
Decimal equivalent: 21




9. /*Write a C program that : 
	Accepts two string as input from the user.
	Concatenates the two strings Displays the concatenated result.
	*/


#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];

    // Accept input strings from user
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove newline characters if present (fgets adds them)
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    // Concatenate str2 to str1
    strcat(str1, str2);

    // Display the result
    printf("Concatenated string: %s\n", str1);

    return 0;
}


/*
	#include<stdio.h>
	int main(){
		char str1[100],str2[100];
		printf("Enter string1: ");
		scanf("%s",&str1);
		printf("Enter string2: ");
		scanf("%s",&str2);
		printf("%s%s\n",str1,str2);
		return 0;
	}
*/



//Output

[nipunika@ChathuraDN ~]$ vi 9Concat.c
[nipunika@ChathuraDN ~]$ gcc 9Concat.c -o 9Concat
[nipunika@ChathuraDN ~]$ ./9Concat
Enter the first string: Hello
Enter the second string: Friends
Concatenated string: HelloFriends




10. /*Write a C program that : 
	Accepts an array of integers from the user.
	Finds and displays the maximum and minimum values in the array.
	*/

#include <stdio.h>

int main() {
    int n, i;
    int max, min;

    // Prompt user for the number of elements
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Declare the array
    int arr[n];

    // Accept array elements from the user
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize max and min with the first element
    max = arr[0];
    min = arr[0];

    // Find max and min
    for(i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    // Display results
    printf("Maximum value in the array: %d\n", max);
    printf("Minimum value in the array: %d\n", min);

    return 0;
}



//Output


[nipunika@ChathuraDN ~]$ vi 10FindMinNMax.c
[nipunika@ChathuraDN ~]$ gcc 10FindMinNMax.c -o 10FindMinNMax
[nipunika@ChathuraDN ~]$ ./10FindMinNMax
Enter the number of elements in the array: 6
Enter 6 integers:
7
10
4
23
91
5
Maximum value in the array: 91
Minimum value in the array: 4




11. /*C program to generate Pascal's Triangle
	
	no of rows = 5
	      1
		1   1
	   1  2  1
		
*/


#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    int i, fact = 1;
    for(i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate binomial coefficient
int binomialCoefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    int rows = 5;

    for(int i = 0; i < rows; i++) {
        // Print spaces for formatting
        for(int space = 0; space < rows - i - 1; space++) {
            printf("  ");
        }

        // Print numbers
        for(int j = 0; j <= i; j++) {
            printf("%4d", binomialCoefficient(i, j));
        }

        printf("\n");
    }

    return 0;
}



//Output

[nipunika@ChathuraDN ~]$ vi 11PascalsTriangle.c
[nipunika@ChathuraDN ~]$ gcc 11PascalsTriangle.c -o 11PascalsTriangle
[nipunika@ChathuraDN ~]$ ./11PascalsTriangle
           1
         1   1
       1   2   1
     1   3   3   1
   1   4   6   4   1
