// Randomly generate numbers between a min and max for user to guess.


// Linking constants from pre-made libraries 
// Functions used the code but not written in the code are able to be used.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defined constants to make the writing of code more efficient.
#define MIN 1
#define MAX 1000

// Function prototyping 
// Allows programmer to know what the return type of each function is
// and which data types is passed through to each function.
void guessGame(void); 
bool isCorrect(int guess, int answer); 

int main(void) {

    // srand() will seed the value in the rand() function so the 
    // sequence is randomized and a rand number will be produced.
    // time() is used with srand() to ensure the seeded value used in 
    // rand() will always be random.
   srand(time(0)); 
   
   // guessGame() calls the function to start the game in the program

    //
   //srand(time(0));
   //printf("Hello Deb");
   //

   guessGame();
} // end main



// Function that contains the code for the program's game
// void is used because this function has no return value
void guessGame(void) {
    
    // Both variables initialized with 0 so both variables have a starting value
   int response = 0;
   int guess = 0;

   // do is used to ensure that the program finds an answer before moving on
   do {

      // rand() finds a pseudorandom integer based off of a repeated sequence
      // 1 should be the constant MIN but is added to rand() to ensure random number is not below 0
      // % is the modulo operator which produces the remainder of a number
      // 1000 should be MAX constant. Used to ensure the random number does not exceed 1000
      int answer = 1 + rand() % 1000;

      // printf function displays string to user
      // %d is a format specifier for the type of data expected to be used in the printed string
      // MIN MAX are the constants of who's values will be placed in format specifiers
      printf("I have a number between %d and %d.\n", MIN, MAX);

      // puts function is secure way of displaying a string that terminates with a newline
      puts("Can you guess my number?\n" 
           "Please type your first guess.");

      // printf function displays a string 
      // %s is the format specifier for an expected string.
      // using %s and "?" to securely use printf to display a string
      printf("%s", "? ");
      

      // scanf function read input from the keyboard
      // %d is the expected integer value entered from the user
      // & is the address operator which passes a memory location to the function to be printed
      scanf("%d", &guess);

      // while loop used to keep reciving input from the user  when the input is incorrect
      // isCorrect function compares the randomized number to the input from user
      // guess is a variable which hold the value of the input from the user
      // answer is a variable which holds the value of the random number produced by rand function
      while (!isCorrect(guess, answer)) {
         scanf("%d", &guess);
      }


      puts("\nExcellent! You guessed the number!\n"
         "Would you like to play again?");
      printf("%s", "Please type (1=yes, 2=no)? ");
      scanf("%d", &response);
      puts("");

   } while (response == 1);
} // end function guessGame

// bool is the return type of this function
// isCorrect function compares the user input to the produced random integer
// int is the data type for the parameters used in the function
// guess and answer are the variables used only in this function
bool isCorrect(int guess, int answer) {

    // bool is the data type for this statement
    // correct is the variable holding the value
    // false is the value assigned to the variable
    bool correct = false;

   // if statment used to compare the values of guess and answer
   // guess and answer are the variabels being compared
   // == is the relational operator which allows for comparison
   // true becomes the value of the variable correct when if guess and answer are equal to eachother
   if (guess == answer) {
      correct = true;
   }

   // < is a relational operator which also allows for comparison
   // printf function prints data to the screen
   // %s is the format specifier for the data to be displayed
   // the string is printed when user input is less than the randomized number 
   // else statement is used for comparison when arguments of the if statement are not fulfilled
   if (guess < answer) {
      printf( "%s", "Too low. Try again.\n? " );
   }
   else {
      printf( "%s", "Too high. Try again.\n? " );
   }

   return correct;
} // end function isCorrect



/**************************************************************************
 * (C) Copyright 1992-2012 by Deitel & Associates, Inc. and               *
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
 **************************************************************************/
