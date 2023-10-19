#include <stdio.h>
#include <pthread.h>

void *print_message(void *ptr) {
    pthread_t tid = pthread_self();
    printf("Thread ID: %lu\n", tid);
}

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, print_message, NULL);
    pthread_create(&thread2, NULL, print_message, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    if (pthread_equal(thread1, thread2)) {
        printf("Threads are equal\n");
    } else {
        printf("Threads are not equal\n");
    }
    return 0;
}
