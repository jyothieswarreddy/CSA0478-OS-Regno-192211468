#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Define a structure for the message
struct message {
    long mtype;     // Message type
    char mtext[100]; // Message data
};

int main() {
    key_t key;
    int msgid;

    // Generate a unique key for the message queue
    key = ftok("/tmp", 'A');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create a message queue with read/write permissions for the owner
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    // Fork a child process
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child process (Receiver)

        struct message msg;
        msg.mtype = 1; // Message type

        // Receive a message from the queue
        msgrcv(msgid, &msg, sizeof(msg.mtext), 1, 0);

        printf("Received: %s\n", msg.mtext);
    } else {
        // Parent process (Sender)

        struct message msg;
        msg.mtype = 1; // Message type
        strcpy(msg.mtext, "Hello from the sender!");

        // Send a message to the queue
        if (msgsnd(msgid, &msg, sizeof(msg.mtext), 0) == -1) {
            perror("msgsnd");
            exit(1);
        }

        // Wait for the child process to finish
        wait(NULL);
    }

    // Remove the message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
