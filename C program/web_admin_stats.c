#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    char employeeID[20];
    char firstName[50];
    char middleName[50];
    char lastName[50];
    char dateOfBirth[20];
    char gender[20];
    char email[100];
    char contactNumber[20];
    char department[50];
    char dateHired[20];
    char username[50];
    char password[50];
};

int main() {

    FILE *file = fopen(
        "C:/Users/Administrator/OneDrive/Desktop/CODE/C program/employees.dat",
        "rb"
    );

    printf("Content-Type: text/html\r\n");
    printf("\r\n");

    if (file == NULL) {

        printf("<h1>Error</h1>");
        printf("<p>Could not open employee data.</p>");

        return 1;
    }

    struct Employee employee;

    int totalEmployees = 0;
    int itEmployees = 0;
    int hrEmployees = 0;

    while (fread(&employee, sizeof(struct Employee), 1, file) == 1) {

        totalEmployees++;

        if (strcmp(employee.department, "IT") == 0 ||
            strcmp(employee.department, "it") == 0) {

            itEmployees++;
        }

        if (strcmp(employee.department, "Human Resources") == 0 ||
            strcmp(employee.department, "hr") == 0) {

            hrEmployees++;
        }
    }

    fclose(file);

    printf("<p id=\"total\">%d</p>", totalEmployees);
    printf("<p id=\"it\">%d</p>", itEmployees);
    printf("<p id=\"hr\">%d</p>", hrEmployees);

    return 0;
}