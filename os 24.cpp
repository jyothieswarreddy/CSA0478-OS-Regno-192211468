#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Create a new file
    int fd = creat("example.txt", 0666);
    
    if (fd == -1) {
        perror("creat");
        exit(1);
    } else {
        printf("File 'example.txt' created.\n");
    }
    
    // Open the file in write-only mode
    fd = open("example.txt", O_WRONLY | O_APPEND);
    
    if (fd == -1) {
        perror("open");
        exit(1);
    } else {
        printf("File 'example.txt' opened for writing.\n");
    }
    
    // Write data to the file
    char data[] = "Hello, this is a test.\n";
    ssize_t bytes_written = write(fd, data, sizeof(data));
    
    if (bytes_written == -1) {
        perror("write");
        exit(1);
    } else {
        printf("Data written to the file: %s", data);
    }
    
    // Close the file
    if (close(fd) == -1) {
        perror("close");
        exit(1);
    } else {
        printf("File 'example.txt' closed.\n");
    }
    
    return 0;
}
