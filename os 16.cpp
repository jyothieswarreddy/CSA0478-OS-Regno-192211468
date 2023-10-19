#include <stdio.h>
#include <stdlib.h>

struct employee {
    char name[50];
    int age;
    float salary;
};

int main() {
    FILE *fp;
    struct employee emp;
    char filename[] = "employee.dat";
    int choice, pos;

    fp = fopen(filename, "rb+");

    if (fp == NULL) {
        fp = fopen(filename, "wb+");
        if (fp == NULL) {
            printf("Error creating file");
            exit(1);
        }
    }

    while (1) {
        printf("\n1. Add employee details\n2. Read employee details\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter employee name: ");
                scanf("%s", emp.name);
                printf("Enter employee age: ");
                scanf("%d", &emp.age);
                printf("Enter employee salary: ");
                scanf("%f", &emp.salary);

                fseek(fp, 0, SEEK_END);
                fwrite(&emp, sizeof(emp), 1, fp);
                break;

            case 2:
                printf("\nEnter position to read employee details: ");
                scanf("%d", &pos);

                fseek(fp, (pos-1)*sizeof(emp), SEEK_SET);
                fread(&emp, sizeof(emp), 1, fp);

                printf("\nEmployee details at position %d:\n", pos);
                printf("Name: %s\n", emp.name);
                printf("Age: %d\n", emp.age);
                printf("Salary: %.2f\n", emp.salary);
                break;

            case 3:
                fclose(fp);
                exit(0);

            default:
                printf("\nInvalid choice");
        }
    }

    return 0;
}
