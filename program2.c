/*
Program Name: EECS 348 Lab 05
Purpose: The purpose of this lab is to get familiar with an IDE, C programming, and Git in an NFL Score Simulator.Pushing projects from the Git repository to GitHub. 
Author: Logan Alexander Smith
KUID: 3096504
Due Date: 10/15/2023
Lab: lab05
Last modified: 10/15/2023
Inputs: None
Outputs: A list of possible scoring combinations for a given score
Sources: None
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    // Safety = 2, Field Goal = 3, Touchdown = 6, TD + Extra Point = 7, TD + Two Point Conversion = 8
    int scores[] = {2,3,6,7,8}; 
    int score; // This will store the score the user enters
    printf("Enter 0 or 1 to STOP:\n");
    bool keep_going = true; // This will be used to determine if the program should keep going
    while(keep_going) {
        printf("Enter a score: ");
        scanf("%d", &score); // Get the score from the user
        if (score <= 1) { // if the score is 0 or 1, the program will terminate and it will not print any possible combinations
            keep_going = false;
            continue; 
        }
    }
    return 0;
}