#include <stdio.h>
#include <pthread.h>
void *threadFunction(void *arg) {
    char *message = (char *)arg;
    for (int i = 0; i < 5; i++) {
        printf("%s\n", message);
    }
    return NULL;
}
int main() {
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    // Create two threads
    pthread_create(&thread1, NULL, threadFunction, (void *)message1);
    pthread_create(&thread2, NULL, threadFunction, (void *)message2);
    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Both threads have completed.\n");
    return 0;
}
