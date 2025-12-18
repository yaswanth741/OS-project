#include <stdio.h>
#include "login.h"
#include "dispatcher.h"

int main() {
    if (!authenticate()) {
        printf("\nAccess Denied\n");
        return 0;
    }

    printf("\nLogin Successful\n");
    getchar(); getchar();

    main_menu();
    return 0;
}
