#include <stdio.h>
#include <stdlib.h>
#include "ui.h"

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void header(const char *title) {
    printf("╔══════════════════════════════════════╗\n");
    printf("║ %-36s ║\n", title);
    printf("╚══════════════════════════════════════╝\n\n");
}
