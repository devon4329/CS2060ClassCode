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

// Symbolic constants to prevent hardcoding
//Maximum length of a string
#define  STRING_LENGTH 80
//Two dimensional array storage amounts for rows and columns of surve data
#define VACATION_RENTERS 5
#define RENTER_SURVEY_CATEGORIES 3
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
//
typedef struct {
    
    
} Property;


int main (void){
    
    
} //main
