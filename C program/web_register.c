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

void getValue(char input[], char field[], char output[], int outputSize) {

    char search[100];
    sprintf(search, "%s=", field);

    char *start = strstr(input, search);

    if (start == NULL) {
        output[0] = '\0';
        return;
    }

    start += strlen(search);

    char *end = strchr(start, '&');

    if (end != NULL) {
        int length = end - start;

        if (length >= outputSize) {
            length = outputSize - 1;
        }

        strncpy(output, start, length);
        output[length] = '\0';

    } else {
        strncpy(output, start, outputSize - 1);
        output[outputSize - 1] = '\0';
    }
}
void getValue(char input[], char field[], char output[], int outputSize) {

    // your existing getValue code...

}   // ← end of getValue()


void urlDecode(char *src, char *dest, int size) {

    int i = 0;
    int j = 0;

    while (src[i] != '\0' && j < size - 1) {

        if (src[i] == '+') {

            dest[j++] = ' ';
            i++;

        } else if (
            src[i] == '%' &&
            src[i + 1] != '\0' &&
            src[i + 2] != '\0'
        ) {

            int value;

            sscanf(src + i + 1, "%2x", &value);

            dest[j++] = (char)value;

            i += 3;

        } else {

            dest[j++] = src[i++];
        }
    }

    dest[j] = '\0';
}


int main() {

    char *contentLength = getenv("CONTENT_LENGTH");
    int length = 0;

    if (contentLength != NULL) {
        length = atoi(contentLength);
    }

    char input[2000];

    if (length > 0 && length < sizeof(input)) {

        fread(input, 1, length, stdin);
        input[length] = '\0';

    } else {

        input[0] = '\0';

    }

        struct Employee employee;

    getValue(input, "employee_id", employee.employeeID,
             sizeof(employee.employeeID));

    getValue(input, "first_name", employee.firstName,
             sizeof(employee.firstName));

    getValue(input, "middle_name", employee.middleName,
             sizeof(employee.middleName));

    getValue(input, "last_name", employee.lastName,
             sizeof(employee.lastName));

    getValue(input, "date_of_birth", employee.dateOfBirth,
             sizeof(employee.dateOfBirth));

    getValue(input, "gender", employee.gender,
             sizeof(employee.gender));

    getValue(input, "email", employee.email,
             sizeof(employee.email));

    getValue(input, "contact_number", employee.contactNumber,
             sizeof(employee.contactNumber));

    getValue(input, "department", employee.department,
             sizeof(employee.department));

    getValue(input, "date_hired", employee.dateHired,
             sizeof(employee.dateHired));

    getValue(input, "username", employee.username,
             sizeof(employee.username));

    getValue(input, "password", employee.password,
             sizeof(employee.password));

    char confirmPassword[50];

    getValue(input, "confirm_password",
             confirmPassword, sizeof(confirmPassword));

        getValue(input, "confirm_password",
         confirmPassword, sizeof(confirmPassword));


        urlDecode(employee.employeeID, employee.employeeID, sizeof(employee.employeeID));
        urlDecode(employee.firstName, employee.firstName, sizeof(employee.firstName));
        urlDecode(employee.middleName, employee.middleName, sizeof(employee.middleName));
        urlDecode(employee.lastName, employee.lastName, sizeof(employee.lastName));
        urlDecode(employee.dateOfBirth, employee.dateOfBirth, sizeof(employee.dateOfBirth));
        urlDecode(employee.gender, employee.gender, sizeof(employee.gender));
        urlDecode(employee.email, employee.email, sizeof(employee.email));
        urlDecode(employee.contactNumber, employee.contactNumber, sizeof(employee.contactNumber));
        urlDecode(employee.department, employee.department, sizeof(employee.department));
        urlDecode(employee.dateHired, employee.dateHired, sizeof(employee.dateHired));
        urlDecode(employee.username, employee.username, sizeof(employee.username));
        urlDecode(employee.password, employee.password, sizeof(employee.password));
        urlDecode(confirmPassword, confirmPassword, sizeof(confirmPassword));


        if (strcmp(employee.password, confirmPassword) != 0) {

        printf("Content-Type: text/html\r\n");
        printf("\r\n");

        printf("<h1>Registration Failed</h1>");
        printf("<p>Passwords do not match.</p>");

        return 0;
    }

        struct Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;

    FILE *file = fopen(
        "C:/Users/Administrator/OneDrive/Desktop/CODE/C program/employees.dat",
        "rb"
    );

    if (file != NULL) {

        employeeCount = fread(
            employees,
            sizeof(struct Employee),
            MAX_EMPLOYEES,
            file
        );

        fclose(file);
    }

        for (int i = 0; i < employeeCount; i++) {

        if (strcmp(employees[i].employeeID,
                   employee.employeeID) == 0) {

            printf("Content-Type: text/html\r\n");
            printf("\r\n");

            printf("<h1>Registration Failed</h1>");
            printf("<p>Employee ID already exists.</p>");

            return 0;
        }

        if (strcmp(employees[i].username,
                   employee.username) == 0) {

            printf("Content-Type: text/html\r\n");
            printf("\r\n");

            printf("<h1>Registration Failed</h1>");
            printf("<p>Username already exists.</p>");

            return 0;
        }
    }

        if (employeeCount >= MAX_EMPLOYEES) {

        printf("Content-Type: text/html\r\n");
        printf("\r\n");

        printf("<h1>Registration Failed</h1>");
        printf("<p>Employee limit reached.</p>");

        return 0;
    }

    employees[employeeCount] = employee;
    employeeCount++;

        file = fopen(
        "C:/Users/Administrator/OneDrive/Desktop/CODE/C program/employees.dat",
        "wb"
    );

    if (file == NULL) {

        printf("Content-Type: text/html\r\n");
        printf("\r\n");

        printf("<h1>Registration Failed</h1>");
        printf("<p>Could not save employee data.</p>");

        return 0;
    }

    fwrite(
        employees,
        sizeof(struct Employee),
        employeeCount,
        file
    );

    fclose(file);

        printf("Content-Type: text/html\r\n");
        printf("\r\n");

        printf("<h1>Registration Successful!</h1>");
        printf("<p>Your employee account has been created.</p>");
        printf("<p><a href=\"/CODE/login.html\">Go to Login</a></p>");

    return 0;
}