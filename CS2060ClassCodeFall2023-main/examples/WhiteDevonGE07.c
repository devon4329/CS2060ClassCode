/*
 * Name: Devon White
 * Class: CS2060 M/W 10:50AM - 12:05PM
 * MAC OS
 * Due: Nov 13, 2023
 * Description: This program will allow the user to enter pet names
 * and ages where memory will be allocated and they will be stored
 * alphabetically in a linked list.  After pets are enetered, the
 * user can remove the pet and memory will be deallocated.  Before
 * the program ends all the memory will be deallocated for any
 * remaining pets.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define STRING_LENGTH 80

// Requirement 1 - Create a structure
typedef struct node
{
    char name[STRING_LENGTH];
    int age;
    struct node* nextNodePtr;
}Pets;


int compareNames(char* name, Pets* node1);
void insertPet(Pets** headPtr);
char *fgetsWrapper (char *str, int size, FILE *stream);
void printList(Pets* listPtr);
char validateYesNo(void);
void writeNamesToFile(FILE* filePtr, Pets* petPtr);


int main (void){
    
    // Requirement 2 - Use a linked list to store the pet information in
    // alphabetical order
    Pets* headNodePtr = NULL;
    printList(headNodePtr);
    
    insertPet(&headNodePtr);
    printList(headNodePtr);
    
    FILE *nameFilePtr = NULL;
    
    writeNamesToFile(nameFilePtr, headNodePtr);
    
    return 0;
} //main


// Requirement 3 - Create a function to string compare names but ignore the case.
int compareNames(char* name, Pets* node1)
{
    int result = 0;
    int counter = 0;
    char nameToCompare[STRING_LENGTH] = {'\0'};
    char nodeName[STRING_LENGTH] = {'\0'};
    
    strcpy(nodeName, node1->name);
    
    for (size_t i = 0; i < sizeof(name); i++)
    {
        nameToCompare[i] = tolower(name[i]);
    }
    while (nodeName[counter] != '\0')
    {
        nodeName[counter] = tolower(nodeName[counter]);
        counter++;
    }
    counter = 0;
    
    result = strcmp(nameToCompare, nodeName);
    
    if (result < 0)
    {
        return -1;
    }
    else if (result > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
} // compareNames


// Requirement 4 - Create a function to insert pets
void insertPet(Pets** headPtr)
{
    char name[STRING_LENGTH] = {'\0'};
    int age = 0;
    char yesOrNo = ' ';
    
    puts("Do you want to enter a pet?\n");
    yesOrNo = validateYesNo();
    
    while (yesOrNo == 'y')
    {
        printf("%s", "Enter the name of your pet: ");
        fgetsWrapper(name, STRING_LENGTH, stdin);
        printf("%s", "Enter the age of your pet: ");
        scanf("%d", &age);
        while (getchar() != '\n');
        
        Pets* newNodePtr = malloc(sizeof(Pets));
        
        if (newNodePtr != NULL)
        {
            strcpy(newNodePtr->name, name);
            newNodePtr->age = age;
            
            newNodePtr->nextNodePtr = NULL;
            
            Pets* previousPtr = NULL;
            
            Pets* currentPtr = *headPtr;
            
            while (currentPtr != NULL && compareNames(name, currentPtr) >= 0)  // Need to find where to insert the new node.
            {
                previousPtr = currentPtr;
                currentPtr = currentPtr->nextNodePtr;
            }
            
            if (previousPtr == NULL)
            {
                *headPtr = newNodePtr;
            }
            else
            {
                previousPtr->nextNodePtr = newNodePtr;
            }
            
            newNodePtr->nextNodePtr = currentPtr;
        }
        else
        {
            printf("No memory to create node for %s\n", name);
        }
        
        printList(*headPtr);
        puts("Do you want to enter another pet?\n");
        yesOrNo = validateYesNo();
    }

   
} // insertPetName


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
    else
    {
        return NULL;
    }
} //fgetsWrapper

// Requirement 5 - Creat a function to prints the linked list of pets
// Will report if there are no pets in the list
void printList(Pets* listPtr)
{
    //
    if (listPtr != NULL)
    {
        printf("%s", "The list is: \n");
        //
        Pets* currentPtr = listPtr;

        //
        while (currentPtr != NULL)
        {
            // display and go to next node
            printf("%s\t\t%d\n", currentPtr->name, currentPtr->age);
            currentPtr = currentPtr->nextNodePtr;
        }
    }
    //
    else
    {
        puts("There are no pets.\n");
    }
} //

char validateYesNo(void)
{
    char validYesNo;

    do {
        puts("Please enter (y)es or (n)o:");
        validYesNo = getchar();
        while (getchar() != '\n');

        validYesNo = tolower(validYesNo);

    } while (validYesNo != 'y' && validYesNo != 'n');

    return  validYesNo;
} //End validateYesNo


// Requirement 6 - Function to write the names and ages of the pets to a file
void writeNamesToFile(FILE* filePtr, Pets* headPtr)
{
    Pets* current = malloc(sizeof(headPtr));
    
    current = headPtr;
    
    if ((filePtr = fopen("/Users/devonwhite/Desktop/Github/CS2060ClassCode/CS2060ClassCodeFall2023-main/examples/petNames.txt", "w")) == NULL)
    {
        puts("File could not be opened.");
    }
    else
    {
        while (current != NULL)
        {
            
            fprintf(filePtr, "%s\t%d\n", current->name, current->age);
            
            current = current->nextNodePtr;
        }
    }
    
    fclose(filePtr);
    
} // writeNamesToFile