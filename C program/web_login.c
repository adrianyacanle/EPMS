#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char adminPassword[100] = "admin123";

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

int loadEmployees(struct Employee employees[]) {

    FILE *file = fopen("C:/Users/Administrator/OneDrive/Desktop/CODE/C program/employees.dat", "rb");

    if (file == NULL) {
        return 0;
    }

    int count = fread(
        employees,
        sizeof(struct Employee),
        MAX_EMPLOYEES,
        file
    );

    fclose(file);

    return count;
}

int checkEmployeeLogin(struct Employee employees[], int employeeCount,
                       char username[], char password[]) {

    for (int i = 0; i < employeeCount; i++) {

        if (strcmp(employees[i].username, username) == 0 &&
            strcmp(employees[i].password, password) == 0) {

            return i;
        }
    }

    return -1;
}

int main() {

    char *data = getenv("CONTENT_LENGTH");
    int length = 0;

    if (data != NULL) {
        length = atoi(data);
    }

    char input[500];

    if (length > 0 && length < sizeof(input)) {

        fread(input, 1, length, stdin);
        input[length] = '\0';

    } else {

        input[0] = '\0';

    }

    char username[100] = "";
    char password[100] = "";

sscanf(input, "username=*%*99[^&]&password=%99s",
       username, password);

/* LOAD ADMIN PASSWORD */

FILE *adminFile = fopen(
    "C:/Users/Administrator/OneDrive/Desktop/CODE/C program/admin_password.txt",
    "r"
);

if (adminFile != NULL) {

    fgets(adminPassword, sizeof(adminPassword), adminFile);

    adminPassword[strcspn(adminPassword, "\r\n")] = '\0';

    fclose(adminFile);
}

/* ADMIN LOGIN */

if (strcmp(username, "admin") == 0 &&
    strcmp(password, adminPassword) == 0) {

        printf("Status: 302 Found\r\n");
        printf("Location: /CODE/dashboard.html\r\n");
        printf("\r\n");

        return 0;
    }

    /* EMPLOYEE LOGIN */

    struct Employee employees[MAX_EMPLOYEES];

    int employeeCount = loadEmployees(employees);

    int employeeIndex = checkEmployeeLogin(
        employees,
        employeeCount,
        username,
        password
    );

    if (employeeIndex != -1) {

        printf("Status: 302 Found\r\n");
        printf("Location: /CODE/employee-dashboard.html?username=%s\r\n", username);
        printf("\r\n");

        return 0;

    } else {

        printf("Content-Type: text/html\r\n");
        printf("\r\n");

        printf("<h1>Login Failed</h1>");
        printf("<p>Incorrect username or password.</p>");
    }

    return 0;
}