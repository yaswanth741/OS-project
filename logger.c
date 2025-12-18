#include <stdio.h>
#include <time.h>
#include "logger.h"

void log_action(const char *action) {
    FILE *log = fopen("logs.txt", "a");
    time_t now = time(NULL);

    fprintf(log, "%s - %s\n", ctime(&now), action);
    fclose(log);
}
