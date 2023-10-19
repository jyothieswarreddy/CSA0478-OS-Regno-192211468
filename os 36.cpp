#include <stdio.h>
#include <stdlib.h>

struct block {
    int data;
    struct block *next;
};

int main() {
    int n, i;
    printf("Enter the number of blocks: ");
    scanf("%d", &n);
    struct block *head, *temp, *newNode;
    head = (struct block*)malloc(sizeof(struct block));
    head->data = 0;
    head->next = NULL;
    temp = head;
    for(i = 1; i < n; i++) {
        newNode = (struct block*)malloc(sizeof(struct block));
        newNode->data = i;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
    temp = head;
    printf("Linked File Allocation:\n");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    return 0;
}
