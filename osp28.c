#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1000

int main() {
    char buffer[MAX_BUFFER_SIZE];
    int fd, bytesRead, bytesWritten;

    // Create a file using system call
    fd = open("data.txt", O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        perror("Error creating the file");
        exit(1);
    }

    printf("Enter data to write to the file (max %d characters):\n", MAX_BUFFER_SIZE);
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Write the data to the file
    bytesWritten = write(fd, buffer, sizeof(buffer));
    if (bytesWritten == -1) {
        perror("Error writing to the file");
        exit(1);
    }

    close(fd);

    // Read the data from the file and print it on the console
    fd = open("data.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening the file");
        exit(1);
    }

    printf("Data read from the file:\n");

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
    }

    close(fd);

    return 0;
}
