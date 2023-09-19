/*
 * Name: Devon White
 * Class: CS2060 M/W 10:50 AM-12:05 PM
 * MAC OS
 * Due: Sep 21, 2023
 * Description: This program rents out properties to vactioners from a company
 * called AirUCCS. The pricing has three different tiers. The base rate ranging
 * from the minimum days allowed to interval1. Tier 2 which is a discount rate for
 * days ranging from one day more than interval1 to interval2. And tier 3 where the
 * discount is doubled for day ranging from one day more than interval2 to the
 * maximum days allowed.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function prototypes
// prints the rental property information
void printRetnalPropertyInfo(unsigned int minNights, unsigned maxNights, unsigned int interval1Nights, unsigned int interval2Nights, double rate, double discount);

// retruns only valid input from the user based on the min and max values inclusively
int getValidInt (int min, int max, int sentinel);

// calculates the charge based on the number of nights rented
double calculateCharges (unsigned int nights, unsigned int interval1Nights, unsigned int interval2Nights, double rate, double discount);

//Prints the number of nights, and the charge if there were any rentals
// Use for printing vacationer charge or for property owner summay
void printNightsCharges (unsigned int nights, double charges);


int main(void){
    
    // constants to be declared in main for rental propterty information
    int const SENTINEL_NEG1 = -1;
    int unsigned const MIN_RENTAL_NIGHTS = 1;
    unsigned int const MAX_RENTAL_NIGHTS = 14;
    unsigned int const INTERVAL_1_NIGHTS = 3;
    unsigned int const INTERVAL_2_NIGHTS = 6;
    double const RENTAL_RATE = 400;
    double const DISCOUNT = 50;
    bool validInput = false;
    
    
    
    
    
    return 0;
} //end main
