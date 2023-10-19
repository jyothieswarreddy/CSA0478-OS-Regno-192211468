#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

void print_permissions(const char *filename) {
    struct stat file_stat;
    
    if (stat(filename, &file_stat) == 0) {
        printf("File: %s\n", filename);
        
        // Display owner's name and permissions
        struct passwd *owner_info = getpwuid(file_stat.st_uid);
        printf("Owner: %s\n", owner_info ? owner_info->pw_name : "Unknown");
        printf("Permissions for owner: %o\n", file_stat.st_mode & S_IRWXU);
        
        // Display group's name and permissions
        struct group *group_info = getgrgid(file_stat.st_gid);
        printf("Group: %s\n", group_info ? group_info->gr_name : "Unknown");
        printf("Permissions for group: %o\n", file_stat.st_mode & S_IRWXG);
        
        // Display others' permissions
        printf("Permissions for others: %o\n", file_stat.st_mode & S_IRWXO);
    } else {
        perror("stat");
    }
}

int main() {
    const char *filename = "example.txt"; // Replace with the file you want to inspect
    print_permissions(filename);
    return 0;
}
