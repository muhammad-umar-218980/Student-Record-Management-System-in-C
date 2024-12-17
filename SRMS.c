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
	
//	animation();
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
//         Sleep(100);
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
                viewStudent();
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


// <------------------------------------ viewStudent() ------------------------------------------>
void viewStudent() {
    int choice;
    int rollNo;
    int found = 0;

    if (studentCount == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\nDo you want to:\n");
    printf("1. View all student records\n");
    printf("2. View a specific student by roll number\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\n--- All Student Records ---\n");
        for (int i = 0; i < studentCount; i++) {
            printf("Roll No: %d\n", students[i].rollNo);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            printf("----------------------\n");
        }
    } else if (choice == 2) {
        printf("\nEnter the roll number of the student: ");
        scanf("%d", &rollNo);

        for (int i = 0; i < studentCount; i++) {
            if (students[i].rollNo == rollNo) {
                printf("\n--- Student Record ---\n");
                printf("Roll No: %d\n", students[i].rollNo);
                printf("Name: %s\n", students[i].name);
                printf("Marks: %.2f\n", students[i].marks);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("\nNo student found with roll number %d.\n", rollNo);
        }
    } else {
        printf("\nInvalid choice! Please enter 1 or 2.\n");
    }
}

