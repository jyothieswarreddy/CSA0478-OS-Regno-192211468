#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100

struct file {
    char name[20];
    int size;
};

struct file files[MAX_FILES];
int num_files = 0;

void insert_file() {
    if (num_files == MAX_FILES) {
        printf("Directory is full\n");
        return;
    }
    struct file f;
    printf("Enter file name: ");
    scanf("%s", f.name);
    printf("Enter file size: ");
    scanf("%d", &f.size);
    files[num_files++] = f;
    printf("File inserted successfully\n");
}

void delete_file() {
    char name[20];
    printf("Enter file name: ");
    scanf("%s", name);
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            int j;
            for (j = i; j < num_files - 1; j++) {
                files[j] = files[j + 1];
            }
            num_files--;
            printf("File deleted successfully\n");
            return;
        }
    }
    printf("File not found\n");
}

void search_file() {
    char name[20];
    printf("Enter file name: ");
    scanf("%s", name);
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("File found\n");
            printf("Name: %s\n", files[i].name);
            printf("Size: %d\n", files[i].size);
            return;
        }
    }
    printf("File not found\n");
}

void display_directory() {
    if (num_files == 0) {
        printf("Directory is empty\n");
        return;
    }
    printf("Directory contents:\n");
    int i;
    for (i = 0; i < num_files; i++) {
        printf("%s\t%d\n", files[i].name, files[i].size);
    }
}

int main() {
    int choice;
    do {
        printf("1. Insert a file\n");
        printf("2. Delete a file\n");
        printf("3. Search for a file\n");
        printf("4. Display directory contents\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert_file();
                break;
            case 2:
                delete_file();
                break;
            case 3:
                search_file();
                break;
            case 4:
                display_directory();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}
