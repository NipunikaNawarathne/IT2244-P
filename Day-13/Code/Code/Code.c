1. //Print a statement

[nipunika@ChathuraDN ~]$ vi 1PrintAStatement.c
#include<stdio.h>
int main(){
	
	printf("Hello world! ");
	
	return 0;
}


[nipunika@ChathuraDN ~]$ gcc 1PrintAStatement.c -o 1PrintAStatement

[nipunika@ChathuraDN ~]$ ./1PrintAStatement
Hello world!



2. //Variables

[nipunika@ChathuraDN ~]$ vi 2Variables.c
#include<stdio.h>
int main(){
	
	int age =25;
	printf("Age: %d\n", age);
	
	return 0;
}

[nipunika@ChathuraDN ~]$ gcc 2Variables.c -o 2Variables

[nipunika@ChathuraDN ~]$ ./2Variables
Age: 25




3. //Assign new value for same variable

[nipunika@ChathuraDN ~]$ vi 3AssignValueForSameVaria.c
#include<stdio.h>
int main(){
	
	int age=25;
    printf("Age: %d\n", age);

    printf("C programming \n");

    age=31;
    printf("New age: %d\n", age);
	
	return 0;
}

[nipunika@ChathuraDN ~]$ gcc 3AssignValueForSameVaria.c -o 3AssignValueForSameVaria

[nipunika@ChathuraDN ~]$ ./3AssignValueForSameVaria
Age: 25
C programming
New age: 31



4. //Assigning the variable

[nipunika@ChathuraDN ~]$ vi 4AssigningVariable.c
#include<stdio.h>
int main(){
	
	int firstNumber = 37;
	printf("First Number: %d\n", firstNumber);
	
	int secondNumber = firstNumber;
	printf("Second Number: %d\n", secondNumber);
	
	return 0;
}

[nipunika@ChathuraDN ~]$ gcc 4AssigningVariable.c -o 4AssigningVariable

[nipunika@ChathuraDN ~]$ ./4AssigningVariable
First Number: 37
Second Number: 37



5. //Declare multiple variables in single line

[nipunika@ChathuraDN ~]$ vi 5MultipleVariInSameLine.c
#include<stdio.h>
int main(){
	
	int num1, num2 = 32;
	printf("First Number: %d\n", num1);
	printf("Second Number: %d\n", num2);
	
	return 0;
}

[nipunika@ChathuraDN ~]$ gcc 5MultipleVariInSameLine.c -o 5MultipleVariInSameLine

[nipunika@ChathuraDN ~]$ ./5MultipleVariInSameLine
First Number: -1840443640
Second Number: 32



6. Data Types

[nipunika@ChathuraDN ~]$ vi 6DataTypes.c
#include<stdio.h>
int main(){
	
	printf("Integer\n");
    int age = 41;
    printf("Integer value: %d\n", age);
    printf("Size: %zu\n\n", sizeof(age)); // %zu ==> Undifined length

    printf("Double\n");
    double number = 23.567;
    printf("Decimal Number: %lf\n", number);
    //To two decimal points
    printf("Decimal Number(to two decimal points): %.2lf\n\n", number);

    printf("Float\n");
    float num = 7.35f;
    printf("Float Number: %f\n", num);
    //To one decimal points
    printf("Float Number(to one decimal points): %.1f\n\n", num);

    printf("Character\n");
    char ch = 'n';
    printf("Character: %c\n", ch);
    printf("Character: %d\n", ch); //characters are store as integers in the machine	
	return 0;
}

[nipunika@ChathuraDN ~]$ gcc 6DataTypes.c -o 6DataTypes

[nipunika@ChathuraDN ~]$ ./6DataTypes
Integer
Integer value: 41
Size: 4

Double
Decimal Number: 23.567000
Decimal Number(to two decimal points): 23.57

Float
Float Number: 7.350000
Float Number(to one decimal points): 7.3

Character
Character: n
Character: 110



7. //Take input from users

[nipunika@ChathuraDN ~]$ vi 7Input.c
#include<stdio.h>
int main(){
	
	printf("Integer\n");
    int number;
	printf("Enter an integer: ");
	scanf("%d", &number);
	printf("Integer: %d\n\n", number);

    printf("Double\n");
    double numb;
	printf("Enter a decimal number: ");
	scanf("%lf", &numb);
	printf("Double: %lf\n\n", numb);

    printf("Float\n");
    float num;
	printf("Enter a floating point: ");
	scanf("%f", &num);
	printf("Floating Point: %f\n\n", num);

    printf("Character\n");
    char ch;
	printf("Enter a character: ");
	scanf(" %c", &ch);
	printf("Character: %c\n\n", ch);

	return 0;
}

[nipunika@ChathuraDN ~]$ gcc 7Input.c -o 7Input

[nipunika@ChathuraDN ~]$ ./7Input
Integer
Enter an integer: 3214
Integer: 3214

Double
Enter a decimal number: 53.5632
Double: 53.563200

Float
Enter a floating point: 223244.120
Floating Point: 223244.125000

Character
Enter a character: h
Character: h



8. //Take multiple inputs together

[nipunika@ChathuraDN ~]$ vi 8MultipleInputs.c
#include<stdio.h>
int main(){
	
	double number;
	char alpha;
	
	printf("Enter a decimal and a character: ");
	scanf("%lf %c", &number, &alpha);
	printf("Number is: %lf\n", number);
	printf("Character is: %c\n", alpha);
	
	return 0;
}

[nipunika@ChathuraDN ~]$ gcc 8MultipleInputs.c -o 8MultipleInputs

[nipunika@ChathuraDN ~]$ ./8MultipleInputs
Enter a decimal and a character: 23.452
m
Number is: 23.452000
Character is: m



9. //C Operators

/*
	arithmetic operators
	+
	-
	*
	/
	% - reminder
*/

[nipunika@ChathuraDN ~]$ vi 9ArithmaticOperators.c
#include<stdio.h>
int main(){
	
	int num1, num2;
	printf("Enter number 1: ");
	scanf("%d", &num1);
	printf("Enter number 2: ");
	scanf("%d", &num2);
	
	printf("Addition: %d\n", (num1+num2));
	printf("Subtraction: %d\n", (num1-num2));
	printf("Multiplication: %d\n", (num1*num2));
	printf("Division: %d\n", (num1/num2));
	
	return 0;
}

[nipunika@ChathuraDN ~]$ gcc 9ArithmaticOperators.c -o 9ArithmaticOperators

[nipunika@ChathuraDN ~]$ ./9ArithmaticOperators
Enter number 1: 54
Enter number 2: 12
Addition: 66
Subtraction: 42
Multiplication: 648
Division: 4