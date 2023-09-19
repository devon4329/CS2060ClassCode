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
void printRetnalPropertyInfo(unsigned int minNights, unsigned int maxNights, unsigned int interval1Nights, unsigned int interval2Nights, double rate, double discount);

// retruns only valid input from the user based on the min and max values inclusively
int getValidInt(int min, int max, int sentinel);

// calculates the charge based on the number of nights rented
double calculateCharges(unsigned int nights, unsigned int interval1Nights, unsigned int interval2Nights, double rate, double discount);

//Prints the number of nights, and the charge if there were any rentals
// Use for printing vacationer charge or for property owner summay
void printNightsCharges(unsigned int nights, double charges);


int main(void){
    
    // constants to be declared in main for rental propterty information
    int const SENTINEL_NEG1 = -1;
    int unsigned const MIN_RENTAL_NIGHTS = 1;
    unsigned int const MAX_RENTAL_NIGHTS = 14;
    unsigned int const INTERVAL_1_NIGHTS = 3;
    unsigned int const INTERVAL_2_NIGHTS = 6;
    double const RENTAL_RATE = 400;
    double const DISCOUNT = 50;
    int numberNights = 0;
    double rentalCharges = 0.0;
    int totalNights = 0;
    double totalCharges = 0.0;
    
    do
    {
        printRetnalPropertyInfo(MIN_RENTAL_NIGHTS, MAX_RENTAL_NIGHTS, INTERVAL_1_NIGHTS, INTERVAL_2_NIGHTS, RENTAL_RATE, DISCOUNT);
        
        numberNights = getValidInt(MIN_RENTAL_NIGHTS, MAX_RENTAL_NIGHTS, SENTINEL_NEG1);
        
        if (numberNights != SENTINEL_NEG1)
        {
            totalNights = totalNights + numberNights;
            
            rentalCharges = calculateCharges(numberNights, INTERVAL_1_NIGHTS, INTERVAL_2_NIGHTS, RENTAL_RATE, DISCOUNT);
            
            totalCharges = totalCharges + rentalCharges;
            
            puts ("Rental Charges\n");
            printNightsCharges(numberNights, rentalCharges);
        }
        
        else if (numberNights == SENTINEL_NEG1)
        {
            puts ("\n");
            puts ("Rental Propterty Owener Total Summary\n");
            printNightsCharges(totalNights, totalCharges);
        }
        
    }
    while (numberNights != SENTINEL_NEG1);
    
    
    
    return 0;
} //end main

/*
 * Function for printing rental property info
 */
void printRetnalPropertyInfo(unsigned int minNights, unsigned int maxNights, unsigned int interval1Nights, unsigned int interval2Nights, double rate, double discount)
{
    printf ("Rental Property can be rented for %d to %d nights.\n", minNights, maxNights);
    printf ("$%.2f rate a night for the first %d nights.\n", rate, interval1Nights);
    printf ("$%.2f discount rate a night for nights %d to %d\n", discount, (interval1Nights + 1), interval2Nights);
    printf ("$%.2f discount rate a night for each reamining nights over %d.\n\n", (discount * 2), interval2Nights);
    
} //end printRentalPropertyInfo function

/*
 * Function to determine input is valid
 */
int getValidInt(int min, int max, int sentinel)
{
    int inputNights = 0;
    double scanfReturn = 0;
    bool validInput = false;
    
    puts ("Enter the number of nights you want to rent the property: ");
    
    // Use a while loop to keep getting input until user input is valid
    do
    {
        //scanf("%d", &inputNights);
        scanfReturn = scanf("%d", &inputNights);
        while (getchar() != '\n');
        
        // if statement for scanfReturn to ensure input is valid
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

/*
 * Function to calculate the charges based off number of nights rented
 */
double calculateCharges(unsigned int nights, unsigned int interval1Nights, unsigned int interval2Nights, double rate, double discount)
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
        totalCharge = (rate * nights) - ((nights - interval2Nights) * (discount * 2) + (interval2Nights - interval1Nights) * discount);
    }
    
    return totalCharge;
} //calculateCharges function end

/*
 * Function to print summary of nights rented and total charges
 */
void printNightsCharges(unsigned int nights, double charges)
{
    
    puts("Nights\tCharge");
    printf("%d\t\t$%.2f\n\n", nights, charges);
    
    
} //printNightsCharges function end

