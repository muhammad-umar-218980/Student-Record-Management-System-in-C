#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int rollNo ;
	char name[30];
	float marks;
} Student;

// <------------------------------ FUNCTION DECLARATIONS ------------------------------->

void addStudent();
void viewStudent();
void updateStudent();
void deleteStudent();
void menu();


// <------------------------------ GLOBAL VARS ------------------------------->

Student students[100];
int studentCount = 0;



// <------------------------------ main() FUNCTION ------------------------------->

int main() {
	
	animation();
	menu();
	
    return 0;
}

// <------------------------------ FUNCTION DEFINITIONS ------------------------------->

// <------------------------------------ ANIMATION ------------------------------------------>

void animation() {
    char text[] = " WELCOME TO STUDENT RECORD MANAGEMENT SYSTEM (SRMS)";
    int length = strlen(text);

    printf("          ");
    for (int i = 0; i < length + 30; i++) {
        printf("-");
    }
    printf("\n\n");

    printf("\t\t\t");

    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c", text[i]);
        Sleep(100);
    }

    
printf("\n\n");

    printf("          ");
    for (int i = 0; i < length + 30; i++) {
        printf("-");
    }
    printf("\n");
}


// <------------------------------------ MENU ------------------------------------------>

void menu() {
    int choice;
    do {
        printf("\n--- Student Record Management System ---\n");
        printf("1. Add Student Record\n");
        printf("2. View All Student Records\n");
        printf("3. Update Student Record\n");
        printf("4. Delete Student Record\n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 5) {
            printf("Invalid choice! Please try again.\n");
        } else {
            if (choice == 1) {
                addStudent();
            } else if (choice == 2) {
//                viewStudents();
            } else if (choice == 3) {
//                updateStudent();
            } else if (choice == 4) {
//                deleteStudent();
            } else if (choice == 5) {
                printf("Exiting...\n");
            }
        }
    } while (choice != 5);
}

// <------------------------------------ addStudent() ------------------------------------------>

void addStudent() {
    if (studentCount < 100) {
        printf("\n--- Add Student Record ---\n");
        
        printf("Enter roll number: ");
        scanf("%d", &students[studentCount].rollNo);
        
        printf("Enter name: ");
        scanf(" %[^\n]", students[studentCount].name); 
        
        printf("Enter marks: ");
        scanf("%f", &students[studentCount].marks);
        
        studentCount++;
        printf("Student record added successfully!\n");
    } else {
        printf("Maximum student limit reached. Cannot add more records.\n");
    }
}

