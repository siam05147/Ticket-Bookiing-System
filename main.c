#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define PHONE_LENGTH 20
#define PASSWORD_LENGTH 30

struct User
{
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char password[PASSWORD_LENGTH];
};

void signup();
void userLogin();
void userHome(char phone[]);

int main()
{
    int choice;

    while (1)
    {
        printf("\nMain Menu\n");
        printf("1 User Login\n");
        printf("2 User Signup\n");
        printf("3 Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            userLogin();
        else if (choice == 2)
            signup();
        else if (choice == 3)
            break;
        else
            printf("Invalid choice\n");
    }

    return 0;
}

// User Signup
void signup()
{
    struct User newUser;
    FILE *file = fopen("users.txt", "a");

    printf("\nEnter Name: ");
    scanf("%s", newUser.name);

    printf("Enter Phone Number: ");
    scanf("%s", newUser.phone);

    printf("Enter Password: ");
    scanf("%s", newUser.password);

    fprintf(file, "%s %s %s\n", newUser.name, newUser.phone, newUser.password);
    fclose(file);

    printf("Signup Successful You can now login\n");
}

// User Login
void userLogin()
{
    struct User user;
    char phone[PHONE_LENGTH];
    char pass[PASSWORD_LENGTH];
    int found = 0;

    FILE *file = fopen("users.txt", "r");
    if (!file)
    {
        printf("No users registered yet\n");
        return;
    }

    printf("\nEnter Phone: ");
    scanf("%s", phone);

    printf("Enter Password: ");
    scanf("%s", pass);

    while (fscanf(file, "%s %s %s", user.name, user.phone, user.password) != EOF)
    {
        if (strcmp(user.phone, phone) == 0 && strcmp(user.password, pass) == 0)
        {
            found = 1;
            userHome(phone);
            break;
        }
    }
    fclose(file);

    if (!found)
    {
        printf("Invalid phone or password\n");
    }
}

// User Homepage
void userHome(char phone[])
{
    printf("\nUser Homepage\n");
    printf("Welcome user with phone: %s\n", phone);
}
