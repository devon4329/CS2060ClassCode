/*
 * Name: Devon White
 * Class: CS2060 M/W 10:50AM - 12:05PM
 * MAC OS
 * Due: Nov 05, 2023
 * Description: This program rents out properties to vactioners from a company
 * called AirUCCS. The pricing has three different tiers. The base rate ranging
 * from the minimum days allowed to interval1. Tier 2 which is a discount rate for
 * days ranging from one day more than interval1 to interval2. And tier 3 where the
 * discount is doubled for day ranging from one day more than interval2 to the
 * maximum days allowed. The program will prompt for a userID and password for the
 * user to enter "owner mode" and set up a property containing the previously stated
 * parameters. In addition, the owner can input the sentinel value when in "renter
 * mode" to have the progrom print out a summary report of the property's rental numbers,
 * total amount made, and average rankings provided by the renter.
 * Renters are able rent a property while in "rental mode" and rank the property based on
 * the provided categories.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

// Symbolic constants to prevent hardcoding
//Maximum length of a string
#define  STRING_LENGTH 80
//Two dimensional array storage amounts for rows and columns of surve data
#define VACATION_RENTERS 5
#define RENTER_SURVEY_CATEGORIES 3
#define MIN_RATING 1
#define MAX_RATING 5
//Rental property login and sentinal values
#define CORRECT_ID "id1"
#define CORRECT_PASSCODE "ABCD"
#define LOGIN_MAX_ATTEMPTS 3
#define SENTINAL_NEG1 -1
//rental property constant ranges
#define MIN_RENTAL_NIGHTS 1
#define MAX_RENTAL_NIGHTS 14
#define MIN_RATE 1
#define MAX_RATE 1000
#define DISCOUNT_MULTIPLIER 2

// Structure for rental property information
// Holds the values each property needs to hold
// typedef allows for easy creation and reference of the property
typedef struct Property {
    char name[STRING_LENGTH];
    char location[STRING_LENGTH];
    int interval1;
    int interval2;
    int totalRenters;
    double rate;
    double discount;
    int ratings[VACATION_RENTERS][RENTER_SURVEY_CATEGORIES];
    int totalRevenue;
    int totalNights;
} Property;


// Function Prototypes
void printRetnalPropertyInfo(Property *currentPropPtr);
void setUpProperty(int minNights, int maxNights, int minRate, int maxRate, Property *propertyPtr);
int scanInt(char* str);
int getValidInt(unsigned int min, unsigned int max);
char *fgetsWrapper (char *str, int size, FILE *stream);
double calculateCharges(unsigned int nights, unsigned int interval1Nights, unsigned int interval2Nights, double rate, double discount, int multiplier);
bool ownerLogin(const char* username, const char* passcode, unsigned int attempts);
int getValidNights(unsigned int min, unsigned int max, const int sentinel);
void rentalMode(Property *currentPropPtr);
void getPropertyRatings(Property *propPtr);
void printCategories(const char *categories[], size_t totalCategories);


int main (void){
    
    /*
    //test
    puts("Test");
    char test[STRING_LENGTH] = {'\0'};
    getValidInt(MIN_RENTAL_NIGHTS, MAX_RENTAL_NIGHTS);
    printf("%s", test);
    */
    
    Property property1;
    
    
    // User Story 1: Rental Property Owner Login
    if (ownerLogin(CORRECT_ID, CORRECT_PASSCODE, LOGIN_MAX_ATTEMPTS) == true)
    {
        puts("Login Successful\n");
        
        // User Story 2: Rental Property Owner Set-up
        setUpProperty(MIN_RENTAL_NIGHTS, MAX_RENTAL_NIGHTS, MIN_RATE, MAX_RATE, &property1);
        printRetnalPropertyInfo(&property1);
    }
    else
    {
        puts("Incorrect Login more than 3 times. Exiting AirUCCS.");
    }
    
    return 0;
} //main

// printRentalPropertyInfo
// Prints property information using a pointer to the information held in the
// property structure.
void printRetnalPropertyInfo(Property *currentPropPtr)
{
    printf("Rental Property: %s\n", currentPropPtr->name);
    printf("Location: %s\n", currentPropPtr->location);
    printf("Rental Property can be rented for %d to %d nights.\n", MIN_RENTAL_NIGHTS, MAX_RENTAL_NIGHTS);
    printf("$%.2f rate a night for the first %d nights.\n", currentPropPtr->rate, currentPropPtr->interval1);
    printf("$%.2f discount rate a night for nights %d to %d\n", currentPropPtr->discount, (currentPropPtr->interval1 + 1), currentPropPtr->interval2);
    printf("$%.2f discount rate a night for each remaining night over %d.\n\n", (currentPropPtr->discount * DISCOUNT_MULTIPLIER), currentPropPtr->interval2);
    
   
    
} //printRentalPropertyInfo


// setUpProperty
// Sets up the property once a valid userID and password have been
// entered within 3 attempts.
void setUpProperty(int minNights, int maxNights, int minRate, int maxRate, Property *propertyPtr)
{
    propertyPtr->totalRenters = 0;
    propertyPtr->totalNights = 0;
    
    // Task 2.1 - Get interval 1 number of nights.
    puts("\nEnter the number of nights until the first discount: ");
    propertyPtr->interval1 = getValidInt(minNights, maxNights);
    
    // Task 2.2 - Get interval 2 number of nights.
    puts("\nEnter the number of night suntil the second discount: ");
    propertyPtr->interval2 = getValidInt(minNights, maxNights);
    
    // Task 2.3 - Get nightly rental rate.
    puts("\nEnter the nightly rental rate: ");
    propertyPtr->rate = (double)getValidInt(minRate, maxRate);
    
    // Task 2.4 - Get the discount amount.
    puts("\nEnter the discount: ");
    propertyPtr->discount = (double)getValidInt(minRate, maxRate);
    
    // Task 2.5 * 2.6 - Get rental property name and location.
    puts("\nEnter the location of the property: ");
    fgetsWrapper(propertyPtr->location, STRING_LENGTH, stdin);
    puts("\nEnter the name of the property: ");
    fgetsWrapper(propertyPtr->name, STRING_LENGTH, stdin);
    
} //setUpProperty


// getValidInt
// Checks the range of the input from the user
int getValidInt(unsigned int min, unsigned int max)
{
    bool intIsValid = false;
    int validInt = 0;
    char input[STRING_LENGTH];
    
    while (intIsValid == false)
    {
        validInt = scanInt(input);
        
        if (validInt >= min && validInt <= max)
        {
            intIsValid = true;
        }
        else
        {
            printf("Error: Input must be between %d and %d.\n", min, max);
        }
    }
    return validInt;
} //getValidInt


// scanInt
// Obtains a valid integer value and loops if a valid integer is not input by user.
// Will replace stdio function "scanf"
int scanInt(char* str)
{
    char* end;
    errno = 0;
    int validInt = 0;
    bool intIsValid = false;
    
    do
    {
        // Use fgetsWrapper method to get rid of '\n' and replace with '\0'
        fgetsWrapper(str, STRING_LENGTH, stdin);
        long intTest = strtol(str, &end, 10);
        
        if (end == str)
        {
            fprintf(stderr, "Not an integer value. Please try again.\n");
        }
        else if ('\0' != *end) 
        {
            fprintf(stderr, "Input has extra characters at end: %s Please try again.\n", end);
        }
        else if ((LONG_MIN == intTest || LONG_MAX == intTest) && ERANGE == errno) 
        {
            fprintf(stderr, "Input is out of range. Please try again.\n");
        }
        else if (intTest > INT_MAX) 
        {
            fprintf(stderr, "%ld is too large. Please try again.\n", intTest);
        }
        else if (intTest < INT_MIN) 
        {
            fprintf(stderr, "%ld is too small. Please try again.\n", intTest);
        }
        else 
        {
            validInt = (int)intTest;
            intIsValid = true;
        }
    }
    while (intIsValid == false);
    return validInt;
} //scanInt


// fgetsWrapper
// Replaces '\n' character with '\0' character from user input.
// Passing variable "str" not as constant because value will be changed at its address
char *fgetsWrapper (char *str, int size, FILE *stream)
{
    size_t length = 0;
    
    fgets(str, size, stream);
    
    if (str != NULL)
    {
        length = strlen(str);
        
        if (length > 0 && str[length - 1] == '\n')
        {
            str[length - 1] = '\0';
        }
        return str;
    }
    else{
        return NULL;
    }
} //fgetsWrapper


// calcualteCharges
// calculates the charge based on the number of nights rented
double calculateCharges(unsigned int nights, unsigned int interval1Nights, unsigned int interval2Nights, double rate, double discount, int multiplier)
{
    double totalCharge = 0.0;
    
    if (nights <= interval1Nights)
    {
        totalCharge = (nights * rate);
    } //if base chage end
    else if (nights > interval1Nights && nights <= interval2Nights)
    {
        totalCharge = (rate * nights) - ((nights - interval1Nights) * discount);
    } //else interval1Nights discount
    else if (nights > interval2Nights)
    {
        totalCharge = (rate * nights) - ((nights - interval2Nights) * (discount * multiplier) + (interval2Nights - interval1Nights) * discount);
    }
    return totalCharge;
} //calculateCharges


// Task 1.1
// ownerLogin
// This method will return a bool value if the login for the owner is valid.
// Pass constant pointers to username and passcode because values will not be changed
// Use of fgetsWrapper method to obtain string values from user input -- do not need to be
// validated.
// strcmp function used to compare input string (character by character) for valid login
bool ownerLogin(const char* username, const char* passcode, unsigned int attempts)
{
    bool validLogin = false;
    int counter = 1;
    char inputID[STRING_LENGTH] = {'\0'};
    char inputPassword[STRING_LENGTH] = {'\0'};
    
    
    while (counter <= attempts && validLogin == false)
    {
        puts("Enter User ID:");
        fgetsWrapper(inputID, STRING_LENGTH, stdin);
        puts("Enter User Password: ");
        fgetsWrapper(inputPassword, STRING_LENGTH, stdin);
        
        if (strcmp(username, inputID) == 0 && strcmp(passcode, inputPassword) == 0)
        {
            validLogin = true;
        }
        else
        {
            puts("User ID or Password incorrect. Try again.");
            printf("Attempts remaining: %d\n\n", attempts - counter);
            counter++;
        }
    }
    return validLogin;
}


// getValidNight
// Checks the range of the input from the user
int getValidNights(unsigned int min, unsigned int max, const int sentinel)
{
    bool intIsValid = false;
    int validInt = 0;
    char input[STRING_LENGTH];
    
    while (intIsValid == false)
    {
        validInt = scanInt(input);
        
        if (validInt >= min && validInt <= max)
        {
            intIsValid = true;
        }
        else
        {
            printf("Error: Input must be between %d and %d.\n", min, max);
        }
    }
    return validInt;
} //getValidInt


// rentalMode
// This method is for the vacationer to select the properlty they want to rent
// get the deails and provide a rating for the property.
void rentalMode(Property *currentPropPtr)
{
    bool sentinalEntered = false;
} //rentalMode


// getPropertyRatings
// A function that points to the property structure to access and mainuplate the
// 2D property array in the structure.
void getPropertyRatings(Property *propPtr)
{
    if (propPtr->totalRenters <= sizeof(propPtr->ratings))
    {
        // display survey info
        for (int i = 0; i < (propPtr->totalRenters + 1); i++)
        {
            for (int j = 0; j < RENTER_SURVEY_CATEGORIES; j++)
            {
                propPtr->ratings[i][j] = getValidInt(MIN_RATING, MAX_RATING);
            }
        }
    }
    else
    {
        puts("Maximum number of rating has been reached.");
    }
}



// Prints categories of the survey
void printCategories(const char *categories[], size_t totalCategories)
{
    //loop to display each category horizontally
    puts("We want to know how your experience was renting out property. Using the rating system 1 to 5 to enter your rating for each category.");
    printf("%s", "Rating Categories:\t");
    for (size_t surveyCategory = 0; surveyCategory < totalCategories; ++surveyCategory)
    {
        printf("\t%zu.%s\t", surveyCategory+1, categories[surveyCategory]);
    }
    puts(""); //start new line of output
    
} //end printCategories
