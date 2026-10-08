#include <stdio.h>

#define MAX 5

struct Patient {
    int id, age;
    char name[30], problem[30];
};

struct Patient queue[MAX];
int front = 0, rear = -1, count = 0;

void addPatient() {
    if (count == MAX) {
        printf("Queue is full!\n");
        return;
    }

    rear = (rear + 1) % MAX;

    printf("Enter Patient ID: ");
    scanf("%d", &queue[rear].id);

    printf("Enter Name: ");
    scanf("%s", queue[rear].name);

    printf("Enter Age: ");
    scanf("%d", &queue[rear].age);

    printf("Enter Problem: ");
    scanf("%s", queue[rear].problem);

    count++;
    printf("Patient added successfully!\n");
}

void servePatient() {
    if (count == 0) {
        printf("No patients waiting!\n");
        return;
    }

    printf("Serving Patient: %s\n", queue[front].name);

    front = (front + 1) % MAX;
    count--;
}

void displayPatients() {
    int i, pos;

    if (count == 0) {
        printf("No patients waiting!\n");
        return;
    }

    printf("\n--- Waiting Patients ---\n");

    for (i = 0; i < count; i++) {
        pos = (front + i) % MAX;
        printf("ID: %d | Name: %s | Age: %d | Problem: %s\n",
               queue[pos].id, queue[pos].name,
               queue[pos].age, queue[pos].problem);
    }
}

int main() {
    int choice;

    do {
        printf("\n===== HOSPITAL PATIENT QUEUE =====\n");
        printf("1. Add Patient\n");
        printf("2. Serve Patient\n");
        printf("3. Display Patients\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPatient(); break;
            case 2: servePatient(); break;
            case 3: displayPatients(); break;
            case 4: printf("Thank you!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}