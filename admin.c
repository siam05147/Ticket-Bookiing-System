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

void adminPanel();
void showUserByNumber();

// Admin Login
int main()
{
    char adminUser[20];
    char adminPass[20];

    printf("Admin Username: ");
    scanf("%s", adminUser);

    printf("Admin Password: ");
    scanf("%s", adminPass);

    if (strcmp(adminUser, "admin") == 0 && strcmp(adminPass, "admin123") == 0)
    {
        adminPanel();
    }
    else
    {
        printf("Incorrect Admin Credentials\n");
    }

    return 0;
}

void adminPanel()
{
    int choice;

    while (1)
    {
        printf("\nAdmin Panel\n");
        printf("1 See User By Phone Number\n");
        printf("2 Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            showUserByNumber();
        else if (choice == 2)
            break;
        else
            printf("Invalid choice\n");
    }
}

// Admin views user details
void showUserByNumber()
{
    FILE *file = fopen("users.txt", "r");
    struct User user;
    char phone[PHONE_LENGTH];
    int found = 0;

    if (!file)
    {
        printf("No user database found\n");
        return;
    }

    printf("\nEnter User Phone Number: ");
    scanf("%s", phone);

    while (fscanf(file, "%s %s %s", user.name, user.phone, user.password) != EOF)
    {
        if (strcmp(user.phone, phone) == 0)
        {
            printf("\nUser Information\n");
            printf("Name: %s\n", user.name);
            printf("Phone: %s\n", user.phone);
            printf("Password: %s\n", user.password);
            found = 1;
            break;
        }
    }
    fclose(file);

    if (!found)
    {
        printf("No user found with this phone number\n");
    }
}
