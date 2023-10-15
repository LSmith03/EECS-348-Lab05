#include <stdio.h>
#include <math.h>

int get_maximum(double monthly_sales[12]) {
    /*Returns the index of the largest monthly sale*/
    int largest = 0;
    for (int i = 0; i < 12; i++) {
        if (monthly_sales[i] > monthly_sales[largest]) {
            largest = i;
        }
    }
    return largest;
}

int get_minimum(double monthly_sales[12]) {
    /*Returns the index of the largest monthly sale*/
    int smallest = 0;
    for (int i = 0; i < 12; i++) {
        if (monthly_sales[i] < monthly_sales[smallest]) {
            smallest = i;
        }
    }
    return smallest;
}

double get_average_sale(double monthly_sales[12], int start_index, int end_index) {
    /**/
    double average;
    double sum = 0;
    int span = (end_index - start_index) + 1;
    for (int i = start_index; i <= end_index; i++) {
        sum = sum + monthly_sales[i];
    }
    average = sum/span;
    
    // ChatGPT generated to combat floating-point arithmetic
    double decimal_part = (average * 100) - (int)(average * 100);
    if (fabs(decimal_part - 0.5) < 0.0001) {
        average = ceil(average * 100) / 100;
    } else {
        average = round(average * 100) / 100;
    }
    
    return average;
}

int print_sales_report(char months[12][10], double monthly_sales[12]) {
    /**/
    printf("Monthly Sales Report for 2022:\n");

    for (int i = 0; i < 12; i++) {
        printf("%-10s $%.2lf\n", months[i], monthly_sales[i]);
    }
    printf("\n");
    return 0;
}

int print_sales_summary(char months[12][10], double monthly_sales[12]) {
    /**/
    int min_index = get_minimum(monthly_sales);
    int max_index = get_maximum(monthly_sales);
    double average_sale = get_average_sale(monthly_sales, 0, 11);
    printf("Sales Summary:\n");
    printf("Minimum sales: $%.2lf (%s)\n", monthly_sales[min_index], months[min_index]);
    printf("Maximum sales: $%.2lf (%s)\n", monthly_sales[max_index], months[max_index]);
    printf("Average sales: $%.2lf\n", average_sale);
    printf("\n");
    return 0;
}

int print_moving_average(char months[12][10], double monthly_sales[12]) {
    /**/
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i < 7; i++) {
        printf("%-10s - %-10s $%.2lf\n", months[i], months[i+5], get_average_sale(monthly_sales, i, i+5));
    }
    printf("\n");
    return 0;
}

int print_highest_to_lowest(char months[12][10], double monthly_sales[12]) {
    /**/
    int indices[12];
    for (int i = 0; i < 12; i++) {
        indices[i] = i;  // Initialize indices array with 0 to 11
    }
    // Bubble sort the indices array
    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (monthly_sales[indices[i]] < monthly_sales[indices[j]]) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }
    printf("Sales Report (Highest to Lowest):\n");
    printf(" Month       Sales\n");
    for (int i = 0; i < 12; i++) {
        printf("%-10s $%.2lf\n", months[indices[i]], monthly_sales[indices[i]]);
    }
    return 0;
}

int main() {
    FILE *fptr;

    fptr = fopen("program1_input.txt", "r");

    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                           "October", "November", "December"};
    double monthly_sales[12];

    for (int i = 0; i < 12; i++) {
        fscanf(fptr, "%lf", &monthly_sales[i]);
    }

    fclose(fptr);

    print_sales_report(months, monthly_sales);
    print_sales_summary(months, monthly_sales);
    print_moving_average(months, monthly_sales);
    print_highest_to_lowest(months, monthly_sales);

    return 0;
}