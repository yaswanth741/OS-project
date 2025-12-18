#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include "fileops.h"

#define DIR_PATH "files/"

/* Show all files in directory */
void show_files() {
    DIR *d;
    struct dirent *dir;

    d = opendir(DIR_PATH);
    if (!d) {
        perror("opendir");
        return;
    }

    printf("\nFiles in '%s':\n", DIR_PATH);
    while ((dir = readdir(d)) != NULL) {
        if (dir->d_name[0] != '.')
            printf(" - %s\n", dir->d_name);
    }
    closedir(d);
}

/* Create & write file */
void write_file() {
    char name[50], path[100], data[100];

    printf("Enter filename: ");
    scanf("%s", name);

    sprintf(path, DIR_PATH "%s", name);

    int fd = open(path, O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        perror("open");
        return;
    }

    printf("Enter data: ");
    scanf(" %[^\n]", data);

    write(fd, data, strlen(data));
    close(fd);

    printf("File written successfully.\n");
    show_files();
}

/* Read file */
void read_file() {
    char name[50], path[100], buf[200] = {0};

    printf("Enter filename: ");
    scanf("%s", name);

    sprintf(path, DIR_PATH "%s", name);

    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return;
    }

    read(fd, buf, sizeof(buf));
    printf("File content:\n%s\n", buf);
    close(fd);

    show_files();
}

/* Delete file */
void delete_file() {
    char name[50], path[100];

    printf("Enter filename to delete: ");
    scanf("%s", name);

    sprintf(path, DIR_PATH "%s", name);

    if (unlink(path) == 0)
        printf("File deleted.\n");
    else
        perror("unlink");

    show_files();
}

/* Rename file */
void rename_file() {
    char oldn[50], newn[50], oldp[100], newp[100];

    printf("Old filename: ");
    scanf("%s", oldn);
    printf("New filename: ");
    scanf("%s", newn);

    sprintf(oldp, DIR_PATH "%s", oldn);
    sprintf(newp, DIR_PATH "%s", newn);

    if (rename(oldp, newp) == 0)
        printf("File renamed.\n");
    else
        perror("rename");

    show_files();
}

/* File menu */
void file_menu() {
    int ch;

    do {
        printf("\nFILE OPERATIONS\n");
        printf("1. Write File\n");
        printf("2. Read File\n");
        printf("3. Delete File\n");
        printf("4. Rename File\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: write_file(); break;
            case 2: read_file(); break;
            case 3: delete_file(); break;
            case 4: rename_file(); break;
        }
    } while (ch != 0);
}
