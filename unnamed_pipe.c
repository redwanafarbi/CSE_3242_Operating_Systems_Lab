#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipe_fd[2];  // Array to hold the two ends of the pipe (pipe_fd[0] for read, pipe_fd[1] for write)
    pid_t pid;
    
    // Create the pipe
    if (pipe(pipe_fd) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) { // Parent process
        close(pipe_fd[0]);  // Close the read end of the pipe in the parent

        char message[] = "Hello from parent!";
        write(pipe_fd[1], message, strlen(message) + 1); // Write message to the pipe
        close(pipe_fd[1]);  // Close the write end after writing

        wait(NULL); // Wait for the child to finish
    } else { // Child process
        close(pipe_fd[1]);  // Close the write end of the pipe in the child

        char buffer[100];
        read(pipe_fd[0], buffer, sizeof(buffer)); // Read the message from the pipe
        printf("Child received: %s\n", buffer);  // Print the message received from the parent

        close(pipe_fd[0]);  // Close the read end after reading
    }

    return 0;
}

