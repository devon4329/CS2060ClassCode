//
//  Exam 2 practice.c
//  CS2060CProject
//
//  Created by Devon White on 11/13/23.
//

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    float zone;
    double heartRate;
    
}Member;

void sortByAge(Member arr[], int size);
void printMembers(Member arr[], int size);

int main (void){
    
    Member member1 = {"Static", 45, 3, 0};
    Member member2 = {"Dynamic", 23, 1, 0};
    Member member3 = {"Queue", 19, 2, 0};
    
    char string1[80] = {"Hello my darling"};
    
    Member gym[3] = {member1, member2, member3};
    
    sortByAge(gym, 3);
    printMembers(gym, 3);
}

void sortByAge(Member arr[], int size){
    Member tempMember = {};
    
    for (size_t i = 0; i < size-1; i++){
        for (size_t j = 0; j < size-1; j++){
            if (arr[j].age > arr[j+1].age){
                tempMember = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tempMember;
            }
        }
    }
}


void printMembers(Member arr[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%s\t\t%d\t\t%.1f\n", arr[i].name, arr[i].age, arr[i].heartRate);
    }
}
