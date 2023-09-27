/*
 * Name: Devon White
 * Class: CS2060 M/W 10:50 AM-12:05 PM
 * MAC OS
 * Due: Sep 26, 2023
 * Description: This program allows vacation renters and the rental property
 * owner to see the ratings given for the rental property. It also allows the
 * renter to rate the property.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void printCategories(const char *categories[], size_t totalCategories);
int getValidInt(int min, int max, int sentinel);
void getRatings(int ratingsArray[][3], int maxRating, int minRating, const int numRatings, const int numCategories, int sentinel);

int main (void) {
    
    int unsigned const RENTER_SURVEY_CATEGORIES = 3;
    int unsigned const MAX_RATING = 5;
    unsigned int const MIN_RATING = 1;
    int const SENTINEL_NEG1 = -1;
    int unsigned const NUM_RATINGS = 5;
    
    const char *surveyCategories[RENTER_SURVEY_CATEGORIES] = {"Check-in Process", "Cleanliness", "Amenities"};
    
    //display rating categories information
    printCategories(surveyCategories, RENTER_SURVEY_CATEGORIES);
    
    //create 2D array to hold ratings of the survey.
    int rentalSurvey[NUM_RATINGS][RENTER_SURVEY_CATEGORIES] = {0};
    
    getRatings(rentalSurvey, MAX_RATING, MIN_RATING, NUM_RATINGS, RENTER_SURVEY_CATEGORIES, SENTINEL_NEG1);
    
    
    
    return 0;
} //end main

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

// Function for get valid input
int getValidInt(int min, int max, int sentinel)
{
    int inputNights = 0;
    double scanfReturn = 0;
    bool validInput = false;
    
    // Use a while loop to keep getting input until user input is valid
    do
    {
        //scanf("%d", &inputNights);
        scanfReturn = scanf("%d", &inputNights);
        while (getchar() != '\n');
        
        // if statement for scanfReturn to ensure input is valid
        // Acceptance Criteria 1.2.a
        if (scanfReturn == 1)
        {
         
            // if statement to check the validity of the range of user input
            // initializes validInput to true to exit while loop
            if (inputNights >= min && inputNights <= max)
            {
                validInput = true;
            } //if check nightly range
            
            // else if checking for input of the sentinel value
            // this input will also initialize validInput to true to exit while loop
            else if (inputNights == -1)
            {
                validInput = true;
            } //end else if
            
            // else for error of input not within the range of min and max nights
            // Acceptance Criteria 1.2.a
            else
            {
                printf ("Error: Not within %d and %d. Please enter the value again: ", min, max);
            } //else error 2
            
        } //if check valid input
        
        // else for error of input not being an integer value
        else
        {
            puts ("Error: Not an integer number. Please enter the value again.");
        } //else error 1
        
    } //Do-While loop end
    while (validInput == false);
    
    return inputNights;
    
} //end getValidInt function


// Get ratings from user
void getRatings(int ratingsArray[][3], int maxRating, int minRating, const int numRatings, const int numCategories, int sentinel)
{
    int categoryNum = 1;
    bool surveyComplete = false;
    
    for (size_t i = 0; i < numRatings; i++)
    {
        for (size_t j = 0; j < numRatings; j++)
        {
            printf("%s%zu\n", "Renter ", i+1);
            
            do
            {
                puts("Enter your rating for");
                printf("Category%d: ", categoryNum);
                ratingsArray[i][j] = getValidInt(maxRating, minRating, sentinel);
                categoryNum++;
                
                if (categoryNum == 3)
                {
                    surveyComplete = true;
                }
                
            } //do
            while (surveyComplete == false);
            
        } //nested for loop end
    
    } // end for loop
    
} //end getRatings
