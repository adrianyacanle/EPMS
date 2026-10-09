#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    char password[100] = "";

    if (query != NULL) {

        getValue(
            query,
            "password",
            password,
            sizeof(password)
        );
    }

    urlDecode(
        password,
        password,
        sizeof(password)
    );

    if (strlen(password) == 0) {

        printf("Content-Type: text/html\r\n");
        printf("\r\n");

        printf("<h1>Password Change Failed</h1>");
        printf("<p>Password cannot be empty.</p>");

        return 1;
    }

    FILE *file = fopen(
        "C:/Users/Administrator/OneDrive/Desktop/CODE/C program/admin_password.txt",
        "w"
    );

    printf("Content-Type: text/html\r\n");
    printf("\r\n");

    if (file == NULL) {

        printf("<h1>Error</h1>");
        printf("<p>Could not save admin password.</p>");

        return 1;
    }

    fprintf(file, "%s", password);

    fclose(file);

    printf("<h1>Password Updated!</h1>");
    printf("<p>Admin password has been changed successfully.</p>");

    printf(
        "<p><a href=\"/CODE/admin-settings.html\">"
        "Back to Settings</a></p>"
    );

    return 0;
}