/*
Author: Oluwatomisin Odewabi
Date: Sep 12, 2024
Time Spent: 1.3 hours
This project familiarizes you with:
arrays, structures, and pointers in C language.
This program creates an array of 5 students and passes
the array to different functions to input and display the students' information.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STUDS 5
#define DATA_LEN 80

typedef struct student {
    char name[DATA_LEN];
    int id;
    double GPA;
} student;

void enterstudinfo(student *slist) {
    char input[DATA_LEN]; // To temporarily hold input values
    for (int i = 0; i < NUM_STUDS; i++) {
        printf("Student %d:\n", i + 1);

        // Enter name
        printf("Enter student %d name: ", i + 1);
        fgets(slist[i].name, DATA_LEN, stdin);
        // Remove trailing newline if present
        slist[i].name[strcspn(slist[i].name, "\n")] = 0;

        // Enter id
        printf("Enter id: ");
        fgets(input, DATA_LEN, stdin);
        sscanf(input, "%d", &slist[i].id);

        // Enter GPA
        printf("Enter GPA: ");
        fgets(input, DATA_LEN, stdin);
        sscanf(input, "%lf", &slist[i].GPA);

        printf("\n");
    }
}

void displstudinfo(student *slist) {
    printf("\n************* Students Report: *************\n");
    printf("--------------------------------------------\n");
    printf("%-25s| %-5s | %s |\n", "NAME", "ID", "GPA ");
    printf("--------------------------------------------\n");

    for (int i = 0; i < NUM_STUDS; i++) {
        printf("%-25s| %-5d | %.2f |\n", slist[i].name, slist[i].id, slist[i].GPA);
    }
}

int main() {
    // Array of students:
    student studArr[NUM_STUDS];

    // Input student data
    enterstudinfo(studArr);

    // Display student data
    displstudinfo(studArr);

    printf("\n");
    return 0;
}
