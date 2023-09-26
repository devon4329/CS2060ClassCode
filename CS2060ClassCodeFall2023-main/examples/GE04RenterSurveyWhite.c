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

void printCategories(const char *categories[], size_t totalCategories);

int main (void) {
    
    int unsigned const RENTER_SURVEY_CATEGORIES = 3;
    
    const char *surveyCategories[RENTER_SURVEY_CATEGORIES] = {"Check-in Process", "Cleanliness", "Amenities"};
    
    
    
    return 0;
} //end main

void printCategories(const char *categories[], size_t totalCategories)
{
    //loop to display each category horizontally
    printf("%s", "Rating Categories:\t");
    for (size_t surveyCategory = 0; surveyCategory < totalCategories; ++surveyCategory)
    {
        printf("\t%zu.%s\t", surveyCategory+1, categories[surveyCategory]);
    }
    puts(""); //start new line of output
    
} //end printCategories
