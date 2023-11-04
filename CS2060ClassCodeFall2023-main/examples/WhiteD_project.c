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
//Two dimensional array storage amounts for rows and columns of survey data
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
    char categories[RENTER_SURVEY_CATEGORIES][STRING_LENGTH];
    double averageRatings[RENTER_SURVEY_CATEGORIES];
    double totalRevenue;
    int totalNights;
    int ratingsEntered;
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
void printNightsCharges(unsigned int nights, double charges);
void rentalMode(Property *currentPropPtr);
void getRatings(int maxRating, int minRating, const int numRatings, const int numCategories,Property *arrayPtr);
void printCategories(Property *categoryPtr);
void calculateCategoryAverages(Property *currentProp);
void printSurveyResults(Property *propPtr);
void ownerReportMode(Property *currentProp);


int main (void){
    
    Property property1;
    
   
    
    // User Story 1: Rental Property Owner Login
    if (ownerLogin(CORRECT_ID, CORRECT_PASSCODE, LOGIN_MAX_ATTEMPTS) == true)
    {
        puts("Login Successful\n");
        
        // User Story 2: Rental Property Owner Set-up
        setUpProperty(MIN_RENTAL_NIGHTS, MAX_RENTAL_NIGHTS, MIN_RATE, MAX_RATE, &property1);
        
        // User Story 3: Vacationer Rental Mode
        rentalMode(&property1);
        
        // User Story 4: Rental Property Owner Report mode
        // Task 4.1 - Display property report
        ownerReportMode(&property1);
        
        puts("\nExiting AirUCCS");
        
    }
    else
    {
        puts("Incorrect Login more than 3 times. Exiting AirUCCS.");
    }
    
    return 0;
} //main

// Task 3.1 - Display rental property information and Ratings
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
    puts("");
    
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
    
    puts("Enter the number of nights you want to stay.");
    
    while (intIsValid == false)
    {
        validInt = scanInt(input);
        
        if (validInt >= min && validInt <= max)
        {
            intIsValid = true;
        }
        else if (validInt == sentinel)
        {
            intIsValid = true;
        }
        else
        {
            printf("Error: Input must be between %d and %d.\n", min, max);
        }
    }
    return validInt;
} //getValidNights

// printNightsCharges
// Prints number of nights and charges for current customer.
void printNightsCharges(unsigned int nights, double charges)
{
    puts("Nights\tCharge");
    printf("%d\t\t$%.2f\n\n", nights, charges);
} //printNightsCharges function end


// rentalMode
// vacationer  rental mode to select the property they want to rent
// get the deails and provide a rating for the property.
void rentalMode(Property *currentPropPtr)
{
    bool sentinalEntered = false;
    int validInt = 0;
    double totalCost = 0.0;
    currentPropPtr->ratingsEntered = 0;
    
    do 
    {
        // Task 3.1 - Display rental property information and Ratings
        printRetnalPropertyInfo(currentPropPtr);
        
        if (currentPropPtr->ratingsEntered <= VACATION_RENTERS)
        {
            printSurveyResults(currentPropPtr);
        }
        
        // Task 3.2 - Get number of nights
        validInt = getValidNights(MIN_RENTAL_NIGHTS, MAX_RENTAL_NIGHTS, SENTINAL_NEG1);
        
        if (validInt == SENTINAL_NEG1)
        {
            // get owner login
            puts("");
            ownerLogin(CORRECT_ID, CORRECT_PASSCODE, LOGIN_MAX_ATTEMPTS);
            puts("");
            sentinalEntered = true;
        }
        else
        {
            // calculate charge
            totalCost = calculateCharges(validInt, currentPropPtr->interval1, currentPropPtr->interval2, currentPropPtr->rate, currentPropPtr->discount, DISCOUNT_MULTIPLIER);
            
            // Increment totalRenters element in property structure
            currentPropPtr->totalRenters++;
            
            // Print charges for current stay
            puts("");
            printNightsCharges(validInt, totalCost);
            
            // Add to totalRevenue element in property structure
            currentPropPtr->totalRevenue = currentPropPtr->totalRevenue + totalCost;
            
            // Add to totalNights element in property structure
            currentPropPtr->totalNights = currentPropPtr->totalNights + validInt;
            
            // Task 3.3 - Get property ratings from Renter
            if (currentPropPtr->ratingsEntered < VACATION_RENTERS)
            {
                getRatings(MAX_RATING, MIN_RATING, currentPropPtr->totalRenters, RENTER_SURVEY_CATEGORIES, currentPropPtr);
                puts("");
            }
            else
            {
                puts("Maximum number of rating has been reached.");
            }
        }
    } while (sentinalEntered == false);
} //rentalMode


// getRatings
// Get ratings from user
// A function that points to the property structure to access and mainuplate the
// 2D property array in the structure.
void getRatings(int maxRating, int minRating, const int numRatings, const int numCategories, Property *arrayPtr)
{
    // use of char array to place the strings needed for the categories in categories structure
    // element.
    // declared as const for use with strcpy() function.
    const char *surveyCats[RENTER_SURVEY_CATEGORIES] = {"Check-in Process", "Cleanliness", "Amenities"};
    
    // Puts categories into array located in structure
    // strcpy function copies strings from "surveyCats[i]" and puts in categories[i] element in
    // the structure.
    // for loop used to iterate through both arrays and put in corresponding indexes.
    for (size_t i = 0; i < RENTER_SURVEY_CATEGORIES; i++)
    {
        strcpy(arrayPtr->categories[i], surveyCats[i]);
    }
    
    puts("We want to know how your experience was renting out property. Using the rating system 1 to 5 to enter your rating for each category:");
    for (size_t i = 0; i < numCategories; i++)
    {
        printf("%zu: %s\n", i + 1, arrayPtr->categories[i]);
    }
    puts("");
    if (arrayPtr->ratingsEntered < VACATION_RENTERS)
    {
        for (size_t i = arrayPtr->ratingsEntered; i < numRatings; i++)
        {
            for (size_t j = 0; j < numCategories; j++)
            {
                puts("Enter your rating for");
                printf("Category %zu: ", j+1);
                arrayPtr->ratings[i][j] = getValidInt(minRating, maxRating);
            } //inner
        } //outer
        puts("");
        arrayPtr->ratingsEntered++;
    }
} //getRatings



// printCategories
// Displays the categories of the survey that are stored in the categories element
// in the property structure.
void printCategories(Property *categoryPtr)
{
    //loop to display each category horizontally
    puts("Survey Results");
    printf("%s", "Rating Categories:\t");
    for (size_t surveyCategory = 0; surveyCategory < RENTER_SURVEY_CATEGORIES; ++surveyCategory)
    {
        printf("\t%zu.%s\t", surveyCategory+1, categoryPtr->categories[surveyCategory]);
    }
    puts("");
    
} //printCategories

// calculateCategoryAverages
// Calcuates the averages of each category and stores that value into
// an averages array elemeent inside the property structure.
// Use of an array element to store category averages so it can be stored with this
// specific property and not lost once method is completed.
void calculateCategoryAverages(Property *currentProp)
{
    double average = 0.0;
    int sum = 0;
    
    // For loop to iterate through the columns second
    // allows for easy calculation of sum an averages of each column
    for (size_t i = 0; i < RENTER_SURVEY_CATEGORIES; i++)
    {
        sum = 0;
        
        // Nested for loop to iterate through each survey in the first column
        // to obtain sum and average
        for (size_t j = 0; j < currentProp->totalRenters; j++)
        {
            sum = sum + currentProp->ratings[j][i];
            
            // If used for when the sum of all columns have been obtained
            // then able to find the average and store in the averageCatergories array in main
            if (j == (currentProp->totalRenters - 1))
            {
                average = (double)sum / currentProp->totalRenters;
                currentProp->averageRatings[i] = average;
            }
            
        } //nested for
    } //for
} //calculateCategoryAverages end


// printSurveyResults
// Displays the results of every survey completed for a property.
void printSurveyResults(Property *propPtr)
{
    if (propPtr->totalRenters == 0)
    {
        puts("Survey Results");
        puts("No Ratings Currently");
        puts("");
    }
    else
    {
        puts("");
        printCategories(propPtr);
        for (size_t i = 0; i < VACATION_RENTERS; i++)
        {
            printf("%s %zu: ", "Survey", i+1);
            
            for (size_t j = 0; j < RENTER_SURVEY_CATEGORIES; j++)
            {
                printf("%21d", propPtr->ratings[i][j]);
            } //nested for
            puts("");
        } //for
    }
    puts("");
} //printSurveyResults end


// ownerReportMode
// Prints the report of total property renters, nights rented, revenue made and ratings
void ownerReportMode(Property *currentProp)
{
    puts("Rental Property Report");
    printf("Name: %s\n", currentProp->name);
    printf("Location: %s\n\n", currentProp->location);
    
    puts("Rental Property Totals");
    puts("Renters\t\tNights\t\tCharges");
    printf("%d\t\t\t\t%d\t\t$%d\n\n", currentProp->totalRenters, currentProp->totalNights, (int)currentProp->totalRevenue);
    
    calculateCategoryAverages(currentProp);
    
    puts("Category Rating Averages");
    for (size_t i = 0; i < RENTER_SURVEY_CATEGORIES; i++)
    {
        printf("%s: %.1lf\n", currentProp->categories[i], currentProp->averageRatings[i]);
    }
} //ownerReportMode
