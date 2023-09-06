// fig02_01.c
// A first program in C.
#include <stdio.h>

// function main begins program execution 
int main(void) {
    
    //int is the type of the variable that will be stored in the stack
    //length, width, and area are the names of the variables and is how
    //the program will be able to manipulate the data.
    // "=" is a binary operator which assigns each variable a value. If not used,
    // the variables are only declared.
    // 0 is the value used to initialize each variable.
    int length = 0;
    int width = 0;
    int area = 0;
    
    //Create a variable to store the scanf return value
    unsigned scanfReturn;
    
    //Prompt for length and store in variable length
    //puts() used to securely prompt user for a length
    //scanf() recieves information from the user
    //%d is the format specifier for the desired input from the user
    //& is the address operator used to tell the compiler which address to send
    // recieved input to.
    puts("Enter the length: ");
    
    //Assign scanfReturn with incorrect input.
    scanf("%d", &length);
    
    
    //Prompt for width and store in variable width
    printf("%s", "Enter the width: ");
    scanf("%d", &width);
    
    //Calcuate the area and assign it to the area variable
    // = is used to assgin the result calculation to the area variable
    // * is the arithmetic operator for multiplying the two variables
    area = length * width;
    
    //Print out the information.
    printf("Length: %d  Width: %d  Area: %d\n", length, width, area);
    
    
    
    printf("Welcome to C!\n");
    
    //Add correct return statement at end of main function
    //Main function is supposed to return an int
    //"0" indicates program ran successfully
    return 0;
    
} // end function main 



/**************************************************************************
 * (C) Copyright 1992-2021 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
