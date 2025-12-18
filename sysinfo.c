#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/utsname.h>
#include "sysinfo.h"

void get_process_id() {
    printf("Process ID: %d\n", getpid());
}

void get_system_time() {
    time_t now = time(NULL);
    printf("System Time: %s", ctime(&now));
}

void get_os_info() {
    struct utsname info;
    uname(&info);
    printf("OS Name : %s\n", info.sysname);
    printf("Version : %s\n", info.release);
}
