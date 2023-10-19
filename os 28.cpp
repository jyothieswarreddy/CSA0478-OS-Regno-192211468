#include <stdio.h>
#include <string.h>

int main() {
    char filename[100], pattern[100], temp[1000];
    FILE *fp;
    printf("Enter file name: ");
    scanf("%s", filename);
    printf("Enter pattern to be searched: ");
    scanf("%s", pattern);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    while (fgets(temp, 1000, fp) != NULL) {
        if (strstr(temp, pattern) != NULL) {
            printf("%s", temp);
        }
    }
    fclose(fp);
    return 0;
}
