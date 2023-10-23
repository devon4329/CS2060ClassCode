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
void displayOrganization(struct property property);

int main (void) {
    
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
