// Passing Primitive Data Types and pointers
//Add comments to explain the code

#include <stdio.h>	
#include <stdlib.h>

int cubePass1(int number);
int cubePass2(const int * numberPtr);

int main(void) {

    // numberMain initialized to 5
	int numberMain = 5;
    
    const int test = 5;
    
    // result initialized to 0
	int result = 0;
    int result2 = 0;
	
    // Printing the value of numberMain
    // numberMain memory location in Main Stack of memory
	printf ("In main before cubePass1  numberMain = %d\n", numberMain);
    printf ("In main before cubePass1  test = %d\n", test);

    
    // printing the address of the variable numberMain
    // located on main stack memory
	printf("&numberMain = %p\n", &numberMain);
    printf("&test = %p\n", &test);

    
    
    // result is being re-initialized to the value that returns from
    // cubePass1 funciton.
    // cubePass1 funciont is passing by value the element present in
    // numberMain
	result = cubePass1(numberMain);
    result2 = cubePass1(test);

    
    // No changes made to value of numberMain
    // cubePass1 was pass-by-value and used a copy of the value
    // located in numberMain
	printf ("In main after cubePass1  numberMain = %d\n", numberMain);
    printf ("In main after cubePass1  test = %d\n", test);

    
    // result initialized to the return value of cubePass1 function.
	printf ("Result = %d\n", result);
    printf ("Result2 = %d\n", result2);

	printf("\nIn main before cubePass2  numberMain = %d\n", numberMain);
    printf("\nIn main before cubePass2  test = %d\n", test);

    
    // cubePass2 function is passing a value by reference
    // numberMain will be modified by this function
    // result is initialized to outcome of the function.
	result = cubePass2(&numberMain);
    result2 = cubePass2(&test);

    
    // numberMain value has changed because cubePass2 passed the address of
    // numberMain and not a copy of its original value.
	printf("\nIn main after cubePass2  numberMain = %d\n", numberMain);
    printf("\nIn main after cubePass2  test = %d\n", test);

    
    // result will show the same value as numberMain because it has been intialized
    // to the return value from the cubePass2 function.
	printf("result = %d\n", result);
    printf("result2 = %d\n", result2);


} // main

// cubePass1 function is pass-by-value.
int cubePass1 (int number)
{
	int cube = 0;
	puts("\nIn cubePass1");
    
    // prints value of number which recieves a copy of the value
    // passed in the function in main.
	printf("number = %d\n", number);
    
    // printing &number will be the address of the variable number
    // located on the memory stack for the function cubePass1.
	printf("&number = %p\n", &number);
    
    // initialize value of cube to the value passed from function call
    // in main.
	cube = number * number * number;
	printf("cube  = %d\n", cube);
    
    // initializing number to the same value as cube.
	number = cube;
    
	printf("number = %d\n", number);
	return cube;
} 

// cubePass2 function is pass-by-reference
// numberPtr is a pointer to the address location on the main
// stack of memory to the variable numberMain.
int cubePass2 (const int * numberPtr)
{
	int cube = 0;
	puts ("\nIn cubePass2");
    
    // Printing the address in which numberPtr is pointing to
    // This address should be the same address as numberMain
	printf("numberPtr = %p\n", numberPtr);
    
    // Printing the value located at the address numbePtr is
    // pointing to
    // "*" is dereferencing the pointer so the value can be printed.
	printf ("*numberPtr = %d\n", *numberPtr);
    
    // printing the address of the pointer numberPtr
    // "&" is allowing the address of numberPtr to be printed
    // This address to numberPtr is located on the cubePass2
    // memory stack.
	printf("&numberPtr = %p\n", &numberPtr);
    
    // variable cube is being initialized to the manipualtion of the
    // dereferenced value from numberPtr.
    // "(* numberPtr)" will result in the dereferenced pointer value,
    // which is 5
	cube = (* numberPtr )* (* numberPtr )* (* numberPtr);
    
    // The value located at the address is being modified to be the
    // same as the value currently in the variable cube.
    // *numberPtr allows the value at the address this pointer is hold to
    // be changed because numberPtr has the "*" symbole infront of it
	numberPtr = &cube;
    
    printf("&cube = %p\n", &cube);
    printf("&numberPtr = %p\n", &numberPtr);
    
    // printing the modified element at the address numberPtr is holding.
	printf ("*numberPtr = %d\n", *numberPtr);
	return cube;
} 


