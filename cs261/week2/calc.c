#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"


/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
 //   assert(stack->size > 1);
    double a, b, sum;
	/* FIXME: You will write this function */
    a =topDynArr(stack);
    popDynArr(stack);
    b = topDynArr(stack);
    popDynArr(stack);
    
    sum = a + b;
    pushDynArr(stack, sum);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	/* FIXME: You will write this function */
    //assert(stack->size > 1);
    double a, b, sub;
	/* FIXME: You will write this function */
    a =topDynArr(stack);
    popDynArr(stack);
    b = topDynArr(stack);
    popDynArr(stack);
    
    sub = a - b;
    pushDynArr(stack, sub);
    
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	/* FIXME: You will write this function */

    double a, b, div;
	/* FIXME: You will write this function */
    a =topDynArr(stack);
    popDynArr(stack);
    b = topDynArr(stack);
    popDynArr(stack);
    
    div = a/b;
    pushDynArr(stack, div);
}
void multiply(struct DynArr *stack){

    double a, b, mult;
    a =topDynArr(stack);
    popDynArr(stack);
    b = topDynArr(stack);
    popDynArr(stack);
    
    mult = a*b;
    pushDynArr(stack, mult);
}
void exponent(struct DynArr *stack){

    double a, b, exp;
    a =topDynArr(stack);
    popDynArr(stack);
    b = topDynArr(stack);
    popDynArr(stack);
    
    exp = pow(a,b);
    pushDynArr(stack, exp);
}
void square(struct DynArr *stack){
    
    double a, sqr;
    a =topDynArr(stack);
    popDynArr(stack);
    
    sqr = pow(a,2);
    pushDynArr(stack, sqr);
}
void cube(struct DynArr *stack){
    
    double a, cube;
    a =topDynArr(stack);
    popDynArr(stack);
    
    cube = pow(a,3);
    pushDynArr(stack, cube);
}

void absolute(struct DynArr *stack){
    
    double a, abso;
    a =topDynArr(stack);
    popDynArr(stack);
    if(a<0)
        abso = (-1)*a;
    else
        abso = a;
    
    pushDynArr(stack, abso);
}
void sroot(struct DynArr *stack){
    
    double a, root;
    a =topDynArr(stack);
    popDynArr(stack);
    
    root = sqrt(a);
    pushDynArr(stack, a);
}
void expo(struct DynArr *stack){
    
    double a, b, exp;
    a =topDynArr(stack);
    popDynArr(stack);
    b = topDynArr(stack);
    popDynArr(stack);
    
    exp = pow(a,b);
    pushDynArr(stack, exp);
}

void natln(struct DynArr *stack){
    
    double a, natl;
    a =topDynArr(stack);
    popDynArr(stack);

    natl = log(a);
    pushDynArr(stack, natl);
}

void logten(struct DynArr *stack){
    
    double a, natl;
    a =topDynArr(stack);
    popDynArr(stack);
    
    natl = log10(a);
    pushDynArr(stack, natl);
}


double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0)
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if(strcmp(s, "/") == 0)
			divide(stack);
		else if(strcmp(s, "x") == 0)
			/* FIXME: replace printf with your own function */
			multiply(stack);
		else if(strcmp(s, "^") == 0)
			/* FIXME: replace printf with your own function */
			//printf("Power\n");
            exponent(stack);
		else if(strcmp(s, "^2") == 0)
			/* FIXME: replace printf with your own function */
			//printf("Squaring\n");
            square(stack);
		else if(strcmp(s, "^3") == 0)
			/* FIXME: replace printf with your own function */
			//printf("Cubing\n");
            cube(stack);
		else if(strcmp(s, "abs") == 0)
			/* FIXME: replace printf with your own function */
			//printf("Absolute value\n");
            absolute(stack);
		else if(strcmp(s, "sqrt") == 0)
			/* FIXME: replace printf with your own function */
			//printf("Square root\n");
            sroot(stack);
		else if(strcmp(s, "exp") == 0)
			/* FIXME: replace printf with your own function */
			//printf("Exponential\n");
            expo(stack);
		else if(strcmp(s, "ln") == 0)
			/* FIXME: replace printf with your own function */
			//printf("Natural Log\n");
            natln(stack);
		else if(strcmp(s, "log") == 0)
			/* FIXME: replace printf with your own function */
			//printf("Log\n");
            logten(stack);
		else
		{
            double number;
            if(isNumber(s, &number))
               pushDynArr(stack, number);
            else
                printf("%s", "error");

			// FIXME: You need to develop the code here (when s is not an operator)
			// Remember to deal with special values ("pi" and "e")
            }
		
	}	//end for
    

	/* FIXME: You will write this part of the function (2 steps below) 
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
    result = topDynArr(stack);
    popDynArr(stack);
	
    printf("%f result", result);
	return result;
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;

    
	calculate(argc,argv);
    
	return 0;
}
