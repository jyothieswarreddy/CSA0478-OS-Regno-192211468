#include <stdio.h>
#include <pthread.h>

void *print_message(void *ptr) {
    char *message = (char *)ptr;
    printf("%s\n", message);
}

int main() {
    pthread_t thread;
    char *message = "Hello, world!";
    pthread_create(&thread, NULL, print_message, (void *)message);
    pthread_join(thread, NULL);
    return 0;
}
