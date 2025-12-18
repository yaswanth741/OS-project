#include <stdio.h>
#include "dispatcher.h"
#include "sysinfo.h"
#include "process.h"
#include "fileops.h"
#include "logger.h"
#include "ui.h"

void main_menu() {
    int choice;
    char sub;

    while (1) {
        clear_screen();
        header("MAIN MENU");

        printf("1. System Information\n");
        printf("2. Process Control\n");
        printf("3. File Management\n");
        printf("0. Exit\n\n");

        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            getchar();
            continue;
        }

        if (choice == 1) {
            clear_screen();
            header("SYSTEM INFORMATION");

            printf("A. Get Process ID\n");
            printf("B. Get System Time\n");
            printf("C. Get OS Info\n");
            printf("X. Back\n\n");

            printf("Enter choice: ");
            scanf(" %c", &sub);

            if (sub == 'A') {
                get_process_id();
                log_action("Get PID");
            } else if (sub == 'B') {
                get_system_time();
                log_action("Get Time");
            } else if (sub == 'C') {
                get_os_info();
                log_action("Get OS Info");
            }

            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }

        else if (choice == 2) {
            clear_screen();
            header("PROCESS CONTROL");

            create_process();
            log_action("Fork Process");

            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }

        else if (choice == 3) {
            clear_screen();
            header("FILE MANAGEMENT");

            file_menu();                 // ✅ CORRECT FIX
            log_action("File Menu Used");

            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }

        else if (choice == 0) {
            break;
        }
    }
}
