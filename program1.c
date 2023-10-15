#include <stdio.h>

int print_sales_report(char months[12][10], double monthly_sales[12]) {
    /**/
    printf("Monthly Sales Report for 2022:\n");

    for (int i = 0; i < 12; i++) {
        printf("%-10s $%.2lf\n", months[i], monthly_sales[i]);
    }
    printf("\n");
    return 0;
}

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

double get_average_sale(double monthly_sales[12]) {
    /**/
    double average;
    double sum;
    for (int i = 0; i < 12; i++) {
        sum = sum + monthly_sales[i];
    }
    average = sum/sizeof(monthly_sales);
    return average;
}

int print_sales_summary(char months[12][10], double monthly_sales[12]) {
    /**/
    int min_index = get_minimum(monthly_sales);
    int max_index = get_maximum(monthly_sales);
    double average_sale = get_average_sale(monthly_sales);
    printf("Sales Summary:\n");
    printf("Minimum sales: $%.2lf (%s)\n", monthly_sales[min_index], months[min_index]);
    printf("Maximum sales: $%.2lf (%s)\n", monthly_sales[max_index], months[max_index]);
    printf("Average sales: $%.2lf (%s)\n", average_sale);
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

    return 0;
}