#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of directories and files
#define MAX_DIRS 10
#define MAX_FILES 50

// Structure to represent a file
typedef struct {
    char name[50];
    char content[1000];
} File;

// Structure to represent a directory
typedef struct {
    char name[50];
    File files[MAX_FILES];
    int fileCount;
} Directory;

// Array to store directories
Directory directories[MAX_DIRS];
int directoryCount = 0;

// Function to create a directory
void createDirectory(char name[50]) {
    if (directoryCount < MAX_DIRS) {
        strcpy(directories[directoryCount].name, name);
        directories[directoryCount].fileCount = 0;
        directoryCount++;
        printf("Directory '%s' created successfully.\n", name);
    } else {
        printf("Maximum directory limit reached. Cannot create more directories.\n");
    }
}

// Function to create a file in a directory
void createFile(char dirName[50], char fileName[50], char content[1000]) {
    int dirIndex = -1;
    for (int i = 0; i < directoryCount; i++) {
        if (strcmp(directories[i].name, dirName) == 0) {
            dirIndex = i;
            break;
        }
    }

    if (dirIndex != -1) {
        if (directories[dirIndex].fileCount < MAX_FILES) {
            File newFile;
            strcpy(newFile.name, fileName);
            strcpy(newFile.content, content);
            directories[dirIndex].files[directories[dirIndex].fileCount] = newFile;
            directories[dirIndex].fileCount++;
            printf("File '%s' created in directory '%s'.\n", fileName, dirName);
        } else {
            printf("Maximum file limit reached in directory '%s'. Cannot create more files.\n", dirName);
        }
    } else {
        printf("Directory '%s' not found. Please create the directory first.\n", dirName);
    }
}

// Function to display files in a directory
void listFiles(char dirName[50]) {
    int dirIndex = -1;
    for (int i = 0; i < directoryCount; i++) {
        if (strcmp(directories[i].name, dirName) == 0) {
            dirIndex = i;
            break;
        }
    }

    if (dirIndex != -1) {
        printf("Files in directory '%s':\n", dirName);
        for (int i = 0; i < directories[dirIndex].fileCount; i++) {
            printf("- %s\n", directories[dirIndex].files[i].name);
        }
    } else {
        printf("Directory '%s' not found.\n", dirName);
    }
}

int main() {
    while (1) {
        printf("\nTwo-Level Directory Structure Menu:\n");
        printf("1. Create Directory\n");
        printf("2. Create File\n");
        printf("3. List Files in Directory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Create Directory
                char dirName[50];
                printf("Enter directory name: ");
                scanf("%s", dirName);
                createDirectory(dirName);
                break;

            case 2:
                // Create File
                char dir[50];
                char file[50];
                char content[1000];
                printf("Enter directory name: ");
                scanf("%s", dir);
                printf("Enter file name: ");
                scanf("%s", file);
                printf("Enter file content: ");
                scanf("%s", content);
                createFile(dir, file, content);
                break;

            case 3:
                // List Files in Directory
                char dirToList[50];
                printf("Enter directory name: ");
                scanf("%s", dirToList);
                listFiles(dirToList);
                break;

            case 4:
                // Exit the program
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
