#include <stdio.h>
#include <string.h>
#include "login.h"
#include "ui.h"

int authenticate() {
    char user[20], pass[20];

    clear_screen();
    header("SECURE SYSTEM CALL INTERFACE");

    printf("Login Required\n\n");

    printf("Username: ");
    scanf("%s", user);

    printf("Password: ");
    scanf("%s", pass);

    if (strcmp(user, "admin") == 0 && strcmp(pass, "1234") == 0)
        return 1;

    return 0;
}

