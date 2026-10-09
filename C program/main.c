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
int employeeIDExists(struct Employee employees[], int employeeCount, char employeeID[]) {

    for (int i = 0; i < employeeCount; i++) {

        if (strcmp(employees[i].employeeID, employeeID) == 0) {
            return 1;
        }
    }

    return 0;
}
int usernameExists(struct Employee employees[], int employeeCount, char username[]) {

    for (int i = 0; i < employeeCount; i++) {

        if (strcmp(employees[i].username, username) == 0) {
            return 1;
        }
    }

    return 0;
}
void addEmployee(struct Employee employees[], int *employeeCount) {

      if (*employeeCount >= 100) {
        printf("\nEmployee limit reached. Cannot add more employees.\n");
        return;
    }

    printf("\n===== Add Employee =====\n");

   printf("Enter Employee ID: ");
fgets(employees[*employeeCount].employeeID,
      sizeof(employees[*employeeCount].employeeID), stdin);
removeNewline(employees[*employeeCount].employeeID);

if (employeeIDExists(employees, *employeeCount,
                     employees[*employeeCount].employeeID)) {

    printf("\nEmployee ID already exists!\n");
    return;
}

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

if (usernameExists(employees, *employeeCount,
                   employees[*employeeCount].username)) {

    printf("\nUsername already exists!\n");
    return;
}

    char confirmPassword[50];

    printf("Enter Password: ");
    fgets(employees[*employeeCount].password,
    sizeof(employees[*employeeCount].password), stdin);
    removeNewline(employees[*employeeCount].password);

   printf("Confirm Password: ");
   fgets(confirmPassword, sizeof(confirmPassword), stdin);
   removeNewline(confirmPassword);

  if (strcmp(employees[*employeeCount].password, confirmPassword) != 0) {

    printf("\nPasswords do not match!\n");
    return;
}

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

int login(struct Employee employees[], int employeeCount) {

    char username[50];
    char password[50];

    printf("\n===== Employee Profile Management System =====\n");

    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    removeNewline(username);

    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    removeNewline(password);

    // Check Admin account
    if (strcmp(username, "admin") == 0 &&
        strcmp(password, "admin123") == 0) {

        printf("\nAdmin login successful!\n");

        return 1;
    }

    // Check Employee accounts
    for (int i = 0; i < employeeCount; i++) {

        if (strcmp(employees[i].username, username) == 0 &&
            strcmp(employees[i].password, password) == 0) {

            printf("\nEmployee login successful!\n");
            printf("Welcome, %s %s!\n",
                   employees[i].firstName,
                   employees[i].lastName);

            return i + 2; // Return index + 2 to distinguish from admin
        }
    }

    printf("\nInvalid username or password.\n");

    return 0;
}

void adminMenu(struct Employee employees[], int *employeeCount) {

    int choice;

    do {

        printf("\n===== ADMIN MENU =====\n");
        printf("1. Add Employee\n");
        printf("2. View Employees\n");
        printf("3. Search Employee\n");
        printf("4. Edit Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Logout\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
                addEmployee(employees, employeeCount);
                saveEmployees(employees, *employeeCount);
                break;

            case 2:
                viewEmployees(employees, *employeeCount);
                break;

            case 3:
                searchEmployee(employees, *employeeCount);
                break;

            case 4:
                editEmployee(employees, *employeeCount);
                saveEmployees(employees, *employeeCount);
                break;

            case 5:
                deleteEmployee(employees, employeeCount);
                saveEmployees(employees, *employeeCount);
                break;

            case 6:
                printf("\nLogging out...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 6);
}

void employeeMenu(struct Employee employees[], int employeeIndex,int employeeCount) {

    int choice;

    do {

        printf("\n===== EMPLOYEE MENU =====\n");
        printf("1. View My Profile\n");
        printf("2. Edit My Profile\n");
        printf("3. Logout\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
                printf("\n===== MY PROFILE =====\n");

                printf("Employee ID: %s\n",
                       employees[employeeIndex].employeeID);

                printf("Name: %s %s %s\n",
                       employees[employeeIndex].firstName,
                       employees[employeeIndex].middleName,
                       employees[employeeIndex].lastName);

                printf("Date of Birth: %s\n",
                       employees[employeeIndex].dateOfBirth);

                printf("Gender: %s\n",
                       employees[employeeIndex].gender);

                printf("Email: %s\n",
                       employees[employeeIndex].email);

                printf("Contact Number: %s\n",
                       employees[employeeIndex].contactNumber);

                printf("Department: %s\n",
                       employees[employeeIndex].department);

                printf("Date Hired: %s\n",
                       employees[employeeIndex].dateHired);

                printf("Username: %s\n",
                       employees[employeeIndex].username);

                break;

            case 2:
                 printf("\n===== EDIT MY PROFILE =====\n");

                 printf("Enter New Email: ");
                 fgets(employees[employeeIndex].email,
                 sizeof(employees[employeeIndex].email), stdin);
                 removeNewline(employees[employeeIndex].email);

                 printf("Enter New Contact Number: ");
                 fgets(employees[employeeIndex].contactNumber,
                 sizeof(employees[employeeIndex].contactNumber), stdin);
                 removeNewline(employees[employeeIndex].contactNumber);

                 printf("Enter New Department: ");
                 fgets(employees[employeeIndex].department,
                 sizeof(employees[employeeIndex].department), stdin);
                 removeNewline(employees[employeeIndex].department);

                 printf("\nProfile updated successfully!\n");

                 saveEmployees(employees, employeeCount);

                break;

            case 3:
                 printf("\nLogging out...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 3);
}
int main() {

    struct Employee employees[100];
    int employeeCount;

    employeeCount = loadEmployees(employees);


    while (1) {

        int loginResult = login(employees, employeeCount);

        if (loginResult == 0) {
            printf("\nLogin failed. Program ended.\n");
            break;
        }

        if (loginResult == 1) {

            adminMenu(employees, &employeeCount);

        }
        else if (loginResult >= 2) {

            int employeeIndex = loginResult - 2;

            employeeMenu(employees, employeeIndex, employeeCount);

        }

        printf("\nReturning to login...\n");
    }

    return 0;
}