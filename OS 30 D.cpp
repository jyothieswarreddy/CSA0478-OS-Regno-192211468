#include <stdio.h>
#include <pthread.h>

void *print_message(void *ptr) {
    int i = 1;
    printf("Thread starting\n");
    while (i <= 10) {
        printf("Thread: %d\n", i);
        i++;
    }
    printf("Thread exiting\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, print_message, NULL);
    pthread_join(thread, NULL);
    printf("Program exiting\n");
    return 0;
}
