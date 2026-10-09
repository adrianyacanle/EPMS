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

    char *query = getenv("QUERY_STRING");

    char username[100] = "";
    char password[100] = "";

    if (query != NULL) {

        getValue(
            query,
            "username",
            username,
            sizeof(username)
        );

        getValue(
            query,
            "password",
            password,
            sizeof(password)
        );
    }


    urlDecode(
        username,
        username,
        sizeof(username)
    );

    urlDecode(
        password,
        password,
        sizeof(password)
    );


        FILE *file = fopen(
        "C:/Users/Administrator/OneDrive/Desktop/CODE/C program/employees.dat",
        "rb"
    );

    if (file == NULL) {
        printf("Content-Type: text/html\r\n\r\n");
        printf("<h1>Error</h1><p>Could not open employee data.</p>");
        return 1;
    }

    struct Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int found = 0;

    while (count < MAX_EMPLOYEES &&
           fread(&employees[count], sizeof(struct Employee), 1, file) == 1) {
        count++;
    }
    fclose(file);

    for (int i = 0; i < count; i++) {
        if (strcmp(employees[i].username, username) == 0) {
            strcpy(employees[i].password, password);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Content-Type: text/html\r\n\r\n");
        printf("<h1>Update Failed</h1><p>Employee was not found.</p>");
        return 1;
    }

    file = fopen(
        "C:/Users/Administrator/OneDrive/Desktop/CODE/C program/employees.dat",
        "wb"
    );

    if (file == NULL) {
        printf("Content-Type: text/html\r\n\r\n");
        printf("<h1>Error</h1><p>Could not save employee data.</p>");
        return 1;
    }

    fwrite(employees, sizeof(struct Employee), count, file);
    fclose(file);

    // Success: redirect only, no Content-Type before this
    printf("Status: 302 Found\r\n");
    printf("Location: /CODE/login.html\r\n\r\n");

    return 0;
}