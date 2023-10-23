//
//  User Story2: Rental Property Owner Set Up.c
//  CS2060CProject
//
//  Created by Devon White on 10/22/23.
//

#define SIZE 80

typedef struct property {
    
    unsigned int interval1Nights;
    unsigned int interval2Nights;
    unsigned long nightlyRate;
    unsigned int discount;
    char propertyName[80];
    char propertyLocation[80];
    
} Property;

#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void setUpProperty(struct property* property);
void displayOrganization(struct property property);
bool getValidInt(const char *input, const int min, const int max, int* validInt);

int main (void) {
    const unsigned int MIN_NIGHTS = 1;
    const unsigned int MAX_NIGHTS = 14;
    char input[SIZE] = {'\0'};
    bool inputValid = false;
    int numNights = 0;
    
    do {
        puts ("Enter number of nights.");
        fgets(input, SIZE, stdin);
        inputValid = getValidInt(input, MIN_NIGHTS, MAX_NIGHTS, &numNights);
    }
    while (inputValid == false);
    
    Property property1 = {};
    
    
    
    return 0;
}

// Function to set up a property structure
// * signifies passing by reference so information at passed
// address is modified.
void setUpProperty(struct property* property){
    
    puts ("Property Set-Up");
    
    // Use scanf to obtain numeric values to initialze value in struct
    // Used & to access the addreass of the desired location
    puts ("Please enter the number of nights until first discount.");
    scanf("%u", &property->interval1Nights);
    
    puts ("Please enter the number of nights until the second discount.");
    scanf("%u", &property->interval2Nights);
    
    puts ("Please enter the nightly rate.");
    scanf("%lu", &property->nightlyRate);
    
    puts ("Please enter the discount amount.");
    scanf ("%u", &property->discount);
    
    // Use fgets read in the string information
    // used to initialize the name and location of the property
    puts ("Enter the name of this Property.");
    fgets(property->propertyName, sizeof(property->propertyName), stdin);
    
    puts ("Enter the Location of this Property.");
    fgets(property->propertyLocation, sizeof(property->propertyLocation), stdin);
    
} //setUpProperty

// Function to display the structure information
// This function will pass by reference to the structure cannot be modified
void displayOrganization(struct property property){
    
    // Use dot ( . ) operator to access information stored in structure members
    // Must use dot operator because structure is passed by value for this fucntion.
    printf ("Property Name: %s\n", property.propertyName);
    printf ("Property Location: %s\n", property.propertyLocation);
    printf ("Nightly Rate: $%.2lu\n", property.nightlyRate);
    printf ("First Discount Number of Nights: %u\n", property.interval1Nights);
    printf ("Second Discount Number of Nights: %u\n", property.interval2Nights);
    printf ("Discount amount: %u\n", property.discount);
    
} //displayOrganization


bool getValidInt(const char *input, const int min, const int max, int* validInt) {
    
    char* end;
    errno = 0;
    bool inputIsValid = false;
    
    long numInput = strtol(input, &end, 10);
    
    if (*end == '\n') {
        *end = '\0';
    }
    
    if (end == input) {
        fprintf(stderr, "Error: %s is not a valid number.\n", input);
    }
    else if ('\0' != *end) {
        fprintf(stderr, "Error: Characters at end of input.\n");
    }
    else if ((LONG_MIN == numInput || LONG_MAX == numInput) && ERANGE == errno) {
        fprintf(stderr, "Error: %s is not between %u and %u\n", input, min, max);
    }
    else if (numInput > max) {
        fprintf(stderr, "Error: %ld is not between %u and %u\n", numInput, min, max);
    }
    else if (numInput < min) {
        fprintf(stderr, "Error: %ld is not between %u and %u\n", numInput, min, max);
    }
    else {
        *validInt = (int)numInput;
        //printf("%d is integer value ", *validInt);
        inputIsValid = true;
    }
    
    return inputIsValid;
}

