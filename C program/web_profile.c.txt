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

int main() {

    char *query = getenv("QUERY_STRING");

    char username[100] = "";

    if (query != NULL) {
        getValue(query, "username", username, sizeof(username));
    }

    printf("Content-Type: text/html\r\n");
    printf("\r\n");

    printf("<h1>Profile Test</h1>");
    printf("<p>Username: %s</p>", username);

    return 0;
}