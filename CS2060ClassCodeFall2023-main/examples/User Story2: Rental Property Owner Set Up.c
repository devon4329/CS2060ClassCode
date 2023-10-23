//
//  User Story2: Rental Property Owner Set Up.c
//  CS2060CProject
//
//  Created by Devon White on 10/22/23.
//

typedef struct property {
    
    unsigned int interval1Nights;
    unsigned int interval2Nights;
    unsigned long nightlyRate;
    unsigned int discount;
    char propertyName[80];
    char propertyLocation[80];
    
} Property;

#include <stdio.h>

void setUpProperty(struct property* property);

int main (void) {
    
    Property property1 = {};
    
    
    return 0;
}

// Function to set up a property structure
// * signifies passing by value so information at passed
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
    
    
}
