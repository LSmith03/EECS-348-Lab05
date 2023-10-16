/*
Program Name: EECS 348 Lab 05
Purpose: The purpose of this lab is to get familiar with an IDE, C programming, and Git in a real-life application. Pushing projects from the Git repository to GitHub. 
Author: Logan Alexander Smith
KUID: 3096504
Due Date: 10/15/2023
Lab: lab05
Last modified: 10/15/2023
Inputs: A file containing 12 monthly sales values for 2022
Outputs: A report of the monthly sales, a summary of the sales, a six-month moving average report, and a sales report
         sorted from highest to lowest
Sources: ChatGPT for the functionality to round floating point errors up to the nearest penny
*/

#include <stdio.h>
#include <math.h>

int get_maximum(double monthly_sales[12]) {
    /*Returns the index of the largest monthly sale*/
    int largest = 0; // This will hold the greatest index of the largest monthly sale
    for (int i = 0; i < 12; i++) {
        if (monthly_sales[i] > monthly_sales[largest]) { // Loop through sales and if the current index is larger than the largest index
            largest = i; // Replace the largest index with the current index
        }
    }
    return largest;
}

int get_minimum(double monthly_sales[12]) { 
    /*Returns the index of the smallest monthly sale*/
    int smallest = 0; // This will hold the smallest index of the smallest monthly sale
    for (int i = 0; i < 12; i++) {
        if (monthly_sales[i] < monthly_sales[smallest]) { // Loop through sales and if the current index is smaller than the smallest index
            smallest = i; // Replace the smallest index with the current index
        }
    }
    return smallest;
}

double get_average_sale(double monthly_sales[12], int start_index, int end_index) {
    /*Returns the average sale price between 2 months (0-11 is full year)*/
    double average;
    double sum = 0; // Define the sum as zero and add to it
    int span = (end_index - start_index) + 1; // The span is the number of months between the start and end index
    for (int i = start_index; i <= end_index; i++) { 
        sum = sum + monthly_sales[i]; // Loop through the sales and add them to the sum
    }
    average = sum/span; // Divide the sum by the span to get the average
    
    // ChatGPT generated to combat floating-point arithmetic
    double decimal_part = (average * 100) - (int)(average * 100); // Get the decimal part of the average
    if (fabs(decimal_part - 0.5) < 0.0001) { // If the decimal part is 0.5
        average = ceil(average * 100) / 100; // Round up to the nearest penny
    } else {
        average = round(average * 100) / 100; // Otherwise round to the nearest penny
    }
    
    return average;
}

int print_sales_report(char months[12][10], double monthly_sales[12]) {
    /*Prints to the console the full sales report*/
    printf("Monthly Sales Report for 2022:\n");
    for (int i = 0; i < 12; i++) {
        printf("%-10s $%.2lf\n", months[i], monthly_sales[i]); // Loop through the sales and print them to the console with the corresponding month
    }
    printf("\n");
    return 0;
}

int print_sales_summary(char months[12][10], double monthly_sales[12]) {
    /*Prints to the console the full sales summary*/
    int min_index = get_minimum(monthly_sales); // Set the min and max index to the index of the smallest and largest monthly sales
    int max_index = get_maximum(monthly_sales);
    double average_sale = get_average_sale(monthly_sales, 0, 11); // Get the average sale for the full year

    // Print the min and max sales and their corresponding months
    printf("Sales Summary:\n");
    printf("Minimum sales: $%.2lf (%s)\n", monthly_sales[min_index], months[min_index]);
    printf("Maximum sales: $%.2lf (%s)\n", monthly_sales[max_index], months[max_index]);
    printf("Average sales: $%.2lf\n", average_sale);
    printf("\n");
    return 0;
}

int print_moving_average(char months[12][10], double monthly_sales[12]) {
    /*Prints to the console the full 6-month moving average*/
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i < 7; i++) {
        printf("%-10s - %-10s $%.2lf\n", months[i], months[i+5], get_average_sale(monthly_sales, i, i+5)); // Loop through the sales and print the 6-month moving average
    }
    printf("\n");
    return 0;
}

int print_highest_to_lowest(char months[12][10], double monthly_sales[12]) {
    /*Prints to the console the sales report sorted from highest to lowest and their corresponding earnings*/
    int indices[12];
    for (int i = 0; i < 12; i++) {
        indices[i] = i; // Initialize indices array with 0 to 11
    }
    // Simple bubble sort the indices array
    for (int i = 0; i < 12; i++) { 
        for (int j = i + 1; j < 12; j++) {
            if (monthly_sales[indices[i]] < monthly_sales[indices[j]]) { // If the current index is smaller than the next index
                int temp = indices[i]; // Swap the indices
                indices[i] = indices[j];
                indices[j] = temp; // Set the current index to the next index
            }
        }
    }
    printf("Sales Report (Highest to Lowest):\n");
    printf(" Month       Sales\n");
    for (int i = 0; i < 12; i++) {
        printf("%-10s $%.2lf\n", months[indices[i]], monthly_sales[indices[i]]); // Loop through the sales and print them to the console with the corresponding month
    }
    return 0;
}

int main() {
    /*Main Function*/
    FILE *fptr; // Create a file pointer

    fptr = fopen("program1_input.txt", "r"); // Open the file for reading

    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", // Initialize months array (as a 2D array)
                           "October", "November", "December"};
    double monthly_sales[12]; // Initialize monthly_sales array

    for (int i = 0; i < 12; i++) {
        fscanf(fptr, "%lf", &monthly_sales[i]); // Read the file into the monthly_sales array
    }

    fclose(fptr); // Close the file

    print_sales_report(months, monthly_sales); // Print the yearly sales report
    print_sales_summary(months, monthly_sales); // Print the yearly sales summary
    print_moving_average(months, monthly_sales); // Print the 6-month moving average
    print_highest_to_lowest(months, monthly_sales); // Print the sales report sorted from highest to lowest

    return 0;
}