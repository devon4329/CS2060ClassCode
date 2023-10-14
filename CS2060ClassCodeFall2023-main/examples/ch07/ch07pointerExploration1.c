/*******************
 Understanding pointers

 Add comments to explain the code
**************/

#include <stdio.h>


int main (void)
{
	// Initalize houseNum
	int houseNum = 13;
    
    // Initialize calcHouseNum1
	int calcHouseNum1 = 0;
    
    //Initialize calcHouseNum2
	int calcHouseNum2 = 0;
    
    // Initialize houseNumPtr
    // "*" dereferences the the pointer allowing access to
    // to the stored value.
    // &houseNum is the address of where the pointer is pointing
	int *houseNumPtr = &houseNum;
	
    // %d tells the print function that an integer will be printed
    // houseNum is the variable that stores the element's value in memory
	printf("houseNum %d\n", houseNum);
    
    // %p is the format specifier to print a memory address
    // &houseNum is telling the print function to print the actual memeory
    // address of the variable "houseNum"
	printf("&houseNum %p\n\n", &houseNum);

    // *houseNumPtr is a pointer variable that points to the address of the
    // first element of houseNum.
    // The "*" dereferences the pointer allowing the value of the "pointed to"
    // address to be used and printed.
    // %d is used because the value that is going to be dereferenced is an int.
	printf ("*houseNumPtr  %d\n", *houseNumPtr);

    // houseNumPtr is a pointer which holds an address
    // namely this is holding the address of houseNum.
    // Using %p allows us to print the address the pointer is holding.
	printf ("houseNumPtr %p\n\n", houseNumPtr);

    // &houseNumPtr signifies that it will print the address of the pointer itself.
    // The address the pointer it pointing to (houseNum) will not be printed.
	printf ("&houseNumPtr %p\n\n", &houseNumPtr);

    // *houseNumPtr will give us the dereferenced value of hosueNumPtr
    // Since it is dereferenced twice, the value houseNumPtr is pointing to
    // will be added to itself.
    // calcHouseNum1 will be initialized to the sum of the defreferenced values.
	calcHouseNum1 =  *houseNumPtr + *houseNumPtr;

    // Prints the value stored in calcHouseNum1.
	printf("*houseNumPtr + *houseNumPtr is %d\n\n", calcHouseNum1);

    // The () allows houseNumPtr to be dereferenced first.
    // Then the dereferenced value is multiplied by two.
    // calcHouseNum2 is then initialized to the dereferenced value of
    // houseNumPtr and multiplied by two.
	calcHouseNum2 = 2 * (*houseNumPtr);

    // Prints the value stored in the variable calcHouseNum2.
	printf("2 * (*houseNumPtr) is %d\n\n", calcHouseNum2);

    // &* and *& are interchangeable.
    // They will both print the same thing, which in this case is the address
    // to the location of the element the pointer is pointing to.
    // This print should display the exact same address as &houseNum.
	printf("\n&*houseNumPtr = %p"
		"\n*&houseNumPtr = %p\n", &*houseNumPtr, *&houseNumPtr);
			
	return 0;
}
