#include <stdio.h>

int main() {
    int indexBlock[50], files[50];
    int indBlock, n, flag = 0, ch = 0;
    for(int i = 0; i < 50; i++) {
        files[i] = 0;
    }
    do {
        printf("Enter the index block: ");
        scanf("%d", &indBlock);
        if(files[indBlock] != 1) {
            printf("Enter no of blocks needed and no of files for the index %d on the disk : \n", indBlock);
            scanf("%d", &n);
        }
        else {
            printf("%d index is already allocated \n", indBlock);
            continue;
        }
        flag = 0;
        printf("Enter the blocks for the file: \n");
        for(int i = 0; i < n; i++) {
            scanf("%d", &indexBlock[i]);
            if(files[indexBlock[i]] == 0) {
                flag++;
            }
        }
        if(flag == n) {
            for(int j = 0; j < n; j++) {
                files[indexBlock[j]] = 1;
            }
            printf("Allocated\n");
            printf("File Indexed\n");
            for(int k = 0; k < n; k++) {
                printf("%d ------> %d : %d\n", indBlock, indexBlock[k], files[indexBlock[k]]);
            }
        }
        else {
            printf("File in the index is already allocated \n");
        }
        printf("Do you want to enter more files?\n");
        printf("Enter 1 for Yes, Enter 0 for No: ");
        scanf("%d", &ch);
    } while(ch == 1);
    return 0;
}
