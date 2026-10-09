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

        } else if (src[i] == '%' &&
                   src[i + 1] != '\0' &&
                   src[i + 2] != '\0') {

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
    char email[100] = "";
    char contact[100] = "";
    char department[100] = "";

    if (query != NULL) {

        getValue(query, "username", username,
                 sizeof(username));

        getValue(query, "email", email,
                 sizeof(email));

        getValue(query, "contact", contact,
                 sizeof(contact));

        getValue(query, "department", department,
                 sizeof(department));
    }

    urlDecode(username, username, sizeof(username));
    urlDecode(email, email, sizeof(email));
    urlDecode(contact, contact, sizeof(contact));
    urlDecode(department, department, sizeof(department));

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

    struct Employee employees[MAX_EMPLOYEES];

    int count = 0;
    int found = 0;

    while (count < MAX_EMPLOYEES &&
           fread(&employees[count],
                 sizeof(struct Employee),
                 1,
                 file) == 1) {

        count++;
    }

    fclose(file);

    for (int i = 0; i < count; i++) {

        if (strcmp(employees[i].username, username) == 0) {

            strcpy(employees[i].email, email);

            strcpy(employees[i].contactNumber, contact);

            strcpy(employees[i].department, department);

            found = 1;

            break;
        }
    }

    if (!found) {

        printf("<h1>Update Failed</h1>");
        printf("<p>Employee was not found.</p>");

        return 1;
    }

    file = fopen(
        "C:/Users/Administrator/OneDrive/Desktop/CODE/C program/employees.dat",
        "wb"
    );

    if (file == NULL) {

        printf("<h1>Error</h1>");
        printf("<p>Could not save employee data.</p>");

        return 1;
    }

    fwrite(
        employees,
        sizeof(struct Employee),
        count,
        file
    );

    fclose(file);

    printf("<h1>Profile Updated!</h1>");
    printf("<p>Your profile has been updated successfully.</p>");
    printf("<p><a href=\"/CODE/my-profile.html?username=%s\">");
    printf("View My Profile</a></p>", username);

    return 0;
}