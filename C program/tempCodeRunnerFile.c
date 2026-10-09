#include <stdio.h>
#include <string.h>

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
    void removeNewline(char text[]) {
    text[strcspn(text, "\n")] = '\0';
}

void addEmployee(struct Employee employees[], int *employeeCount) {

    printf("\n===== Add Employee =====\n");

    printf("Enter Employee ID: ");
    fgets(employees[*employeeCount].employeeID,
          sizeof(employees[*employeeCount].employeeID), stdin);
          removeNewline(employees[*employeeCount].employeeID);

    printf("Enter First Name: ");
    fgets(employees[*employeeCount].firstName,
          sizeof(employees[*employeeCount].firstName), stdin);
          removeNewline(employees[*employeeCount].firstName);

    printf("Enter Middle Name: ");
    fgets(employees[*employeeCount].middleName,
          sizeof(employees[*employeeCount].middleName), stdin);
          removeNewline(employees[*employeeCount].middleName);

    printf("Enter Last Name: ");
    fgets(employees[*employeeCount].lastName,
          sizeof(employees[*employeeCount].lastName), stdin);
          removeNewline(employees[*employeeCount].lastName);

    printf("Enter Date of Birth: ");
    fgets(employees[*employeeCount].dateOfBirth,
          sizeof(employees[*employeeCount].dateOfBirth), stdin);
          removeNewline(employees[*employeeCount].dateOfBirth);

    printf("Enter Gender: ");
    fgets(employees[*employeeCount].gender,
          sizeof(employees[*employeeCount].gender), stdin);
          removeNewline(employees[*employeeCount].gender);

    printf("Enter Email: ");
    fgets(employees[*employeeCount].email,
          sizeof(employees[*employeeCount].email), stdin);
          removeNewline(employees[*employeeCount].email);

    printf("Enter Contact Number: ");
    fgets(employees[*employeeCount].contactNumber,
          sizeof(employees[*employeeCount].contactNumber), stdin);
          removeNewline(employees[*employeeCount].contactNumber);

    printf("Enter Department: ");
    fgets(employees[*employeeCount].department,
          sizeof(employees[*employeeCount].department), stdin);
          removeNewline(employees[*employeeCount].department);

    printf("Enter Date Hired: ");
    fgets(employees[*employeeCount].dateHired,
          sizeof(employees[*employeeCount].dateHired), stdin);
          removeNewline(employees[*employeeCount].dateHired);

    printf("Enter Username: ");
    fgets(employees[*employeeCount].username,
          sizeof(employees[*employeeCount].username), stdin);
          removeNewline(employees[*employeeCount].username);

    printf("Enter Password: ");
    fgets(employees[*employeeCount].password,
          sizeof(employees[*employeeCount].password), stdin);
          removeNewline(employees[*employeeCount].password);

    (*employeeCount)++;

    printf("\nEmployee added successfully!\n");
}

void viewEmployees(struct Employee employees[], int employeeCount) {

    printf("\n===== Employee Records =====\n");

    if (employeeCount == 0) {
        printf("No employees found.\n");
        return;
    }

    for (int i = 0; i < employeeCount; i++) {

        printf("\nEmployee #%d\n", i + 1);
        printf("Employee ID: %s", employees[i].employeeID);
        printf("Name: %s %s %s", 
               employees[i].firstName,
               employees[i].middleName,
               employees[i].lastName);
        printf("Date of Birth: %s", employees[i].dateOfBirth);
        printf("Gender: %s", employees[i].gender);
        printf("Email: %s", employees[i].email);
        printf("Contact Number: %s", employees[i].contactNumber);
        printf("Department: %s", employees[i].department);
        printf("Date Hired: %s", employees[i].dateHired);
        printf("Username: %s", employees[i].username);
    }
}
void searchEmployee(struct Employee employees[], int employeeCount) {

    char searchID[20];
    int found = 0;

    printf("\n===== Search Employee =====\n");

    printf("Enter Employee ID: ");
    fgets(searchID, sizeof(searchID), stdin);
    removeNewline(searchID);

    for (int i = 0; i < employeeCount; i++) {

        if (strcmp(employees[i].employeeID, searchID) == 0) {

            printf("\nEmployee Found!\n");
            printf("Employee ID: %s\n", employees[i].employeeID);
            printf("Name: %s %s %s\n",
                   employees[i].firstName,
                   employees[i].middleName,
                   employees[i].lastName);

            printf("Date of Birth: %s\n", employees[i].dateOfBirth);
            printf("Gender: %s\n", employees[i].gender);
            printf("Email: %s\n", employees[i].email);
            printf("Contact Number: %s\n", employees[i].contactNumber);
            printf("Department: %s\n", employees[i].department);
            printf("Date Hired: %s\n", employees[i].dateHired);
            printf("Username: %s\n", employees[i].username);

            found = 1;
            break;
        }
    }
    

    if (found == 0) {
        printf("\nEmployee not found.\n");
    }
}
void editEmployee(struct Employee employees[], int employeeCount) {

    char searchID[20];
    int found = 0;

    printf("\n===== Edit Employee =====\n");

    printf("Enter Employee ID: ");
    fgets(searchID, sizeof(searchID), stdin);
    removeNewline(searchID);

    for (int i = 0; i < employeeCount; i++) {

        if (strcmp(employees[i].employeeID, searchID) == 0) {

            printf("\nEmployee Found!\n");

            printf("Enter New Email: ");
            fgets(employees[i].email, sizeof(employees[i].email), stdin);
            removeNewline(employees[i].email);

            printf("Enter New Contact Number: ");
            fgets(employees[i].contactNumber,
                  sizeof(employees[i].contactNumber), stdin);
            removeNewline(employees[i].contactNumber);

            printf("Enter New Department: ");
            fgets(employees[i].department,
                  sizeof(employees[i].department), stdin);
            removeNewline(employees[i].department);

            printf("\nEmployee updated successfully!\n");

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nEmployee not found.\n");
    }
}

void deleteEmployee(struct Employee employees[], int *employeeCount) {

    char searchID[20];
    int found = 0;

    printf("\n===== Delete Employee =====\n");

    printf("Enter Employee ID: ");
    fgets(searchID, sizeof(searchID), stdin);
    removeNewline(searchID);

    for (int i = 0; i < *employeeCount; i++) {

        if (strcmp(employees[i].employeeID, searchID) == 0) {

            for (int j = i; j < *employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }

            (*employeeCount)--;

            printf("\nEmployee deleted successfully!\n");

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nEmployee not found.\n");
    }
}
void saveEmployees(struct Employee employees[], int employeeCount) {

    FILE *file = fopen("employees.dat", "wb");

    if (file == NULL) {
        printf("\nError opening file.\n");
        return;
    }

    fwrite(employees, sizeof(struct Employee), employeeCount, file);

    fclose(file);

    printf("\nEmployee records saved successfully!\n");
}


int loadEmployees(struct Employee employees[]) {

    FILE *file = fopen("employees.dat", "rb");

    if (file == NULL) {
        return 0;
    }

    int employeeCount = fread(
        employees,
        sizeof(struct Employee),
        100,
        file
    );

    fclose(file);

    return employeeCount;
}

int main() {

    struct Employee employees[100];
    int employeeCount;
    int choice;

    employeeCount = loadEmployees(employees);

    do {

        printf("\n===== Employee Profile Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. View Employees\n");
        printf("3. Search Employee\n");
        printf("4. Edit Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        getchar();

        switch (choice) {

            case 1:
                 addEmployee(employees, &employeeCount);
                 saveEmployees(employees, employeeCount);
                 break;

            case 2:
                viewEmployees(employees, employeeCount);
                break;

            case 3:
                searchEmployee(employees, employeeCount);
                break;

           case 4:
                editEmployee(employees, employeeCount);
                saveEmployees(employees, employeeCount);
             break;

            case 5:
                deleteEmployee(employees, &employeeCount);
                saveEmployees(employees, employeeCount);
                break;

            case 6:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}