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
        printf("Possible combinations of scoring plays include:\n\n");
        for(int two_point_conversion = 0; two_point_conversion * scores[4] <= score; two_point_conversion++) { // Goes through every possible two point conversion combination
            for(int extra_point = 0; extra_point * scores[3] <= score; extra_point++) { // Goes through every possible extra point combination
                for(int touchdown = 0; touchdown * scores[2] <= score; touchdown++) { // Goes through every possible touchdown combination
                    for(int field_goal = 0; field_goal * scores[1] <= score; field_goal++) { // Goes through every possible field goal combination
                        for(int safety = 0; safety * scores[0] <= score; safety++) { // Goes through every possible safety combination
                            if (touchdown * scores[2] + field_goal * scores[1] + safety * scores[0] + two_point_conversion * scores[4] + extra_point * scores[3] == score) { // If the combination of scores equals the score the user entered
                                printf("%d TD + 2PT, %d TD + FG, %d TD, %d 3PT FG, %d Safety\n", two_point_conversion, extra_point, touchdown, field_goal, safety); // Print it to the console
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}