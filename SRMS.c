#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// <------------------------------------ STRUCTURE FOR STUDENTS NAME ------------------------------------------>
typedef struct {
    int rollNo;
    char name[30];
    float marks;
} Student;

// <------------------------------------ FUNCTION DECLARATION ------------------------------------------>
void addStudent();
void viewStudent();
void updateStudent();
void deleteStudent();
void menu();
void displayMenu();

// <------------------------------------ GLOBAL VARS ------------------------------------------>

Student students[100];  
int studentCount = 0;

// <------------------------------------ MAIN FUNCTION ------------------------------------------>

int main() {
    animation();
    menu();
    return 0;
}

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

// <------------------------------------ DISPLAY MENU FUNCTION ------------------------------------------>

void displayMenu() {
	printf("\n\t\t--------------------------\n");
    printf("\t\t1. Add Student Record\n");
    printf("\t\t2. View All Student Records or Specific Student Record\n");
    printf("\t\t3. Update Student Record\n");
    printf("\t\t4. Delete Student Record\n");
    printf("\t\t5. Exit\n");
    printf("\t\tEnter your choice: ");
}

// <------------------------------------ MENU FUNCTION ------------------------------------------>

void menu() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
	    printf("\t\t--------------------------\n");

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudent();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("\t\tExiting...\n");
                break;
            default:
                printf("\t\tInvalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

// <------------------------------------ addStudent() FUNCTION ------------------------------------------>

void addStudent() {
    if (studentCount >= 100) {
        printf("\t\tMaximum student limit reached. Cannot add more records.\n");
        return;
    }

    printf("\n\t\t--- Add Student Record ---\n");

    int rollNo;
    int duplicate = 0;
    do {
        printf("\t\tEnter roll number: ");
        if (scanf("%d", &rollNo) != 1) {
            printf("\t\tInvalid input! Please enter a valid integer roll number.\n\n");
            while(getchar() != '\n');  // Buffer clear kar dega takay valid roll no enter ho
            duplicate = 1;
        } else {
            duplicate = 0;
            for (int i = 0; i < studentCount; i++) {
                if (students[i].rollNo == rollNo) {
                    printf("\t\tRoll number already exists! Try again with a unique roll number.\n\n");
                    duplicate = 1;
                    break;
                }
            }
        }
    } while (duplicate);

    students[studentCount].rollNo = rollNo;


    printf("\t\tEnter name: ");
    scanf(" %[^\n]", students[studentCount].name); 


	// ye check karay ga marks are between 0 and 100
    do {
        printf("\t\tEnter marks (0-100): ");
        if (scanf("%f", &students[studentCount].marks) != 1) {
            printf("\t\tInvalid input! Please enter a valid numeric value for marks.\n");
            while(getchar() != '\n');  
        } else if (students[studentCount].marks < 0 || students[studentCount].marks > 100) {
            printf("\t\tMarks must be between 0 and 100.\n");
        } else {
            break;  
        }
    } while (1);

    studentCount++;
    printf("\n\t\tStudent record added successfully!\n");
}


// <------------------------------------ viewStudent() FUNCTION ------------------------------------------>

void viewStudent() {
    int choice, rollNo, found = 0;

    if (studentCount == 0) {
        printf("\n\t\tNo student records available.\n");
        return;
    }
	
	printf("\n\t\t--------------------------");
    printf("\n\t\tDo you want to:\n");
    printf("\t\t1. View all student records\n");
    printf("\t\t2. View a specific student by roll number\n");
    printf("\t\tEnter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
    	char str[] = "STUDENT RECORDS";
    	int j = 0 ;
        printf("\n\n\n\t\t----------------------------- ");

		while(str[j] != '\0'){
			printf("%c",str[j]);
			Sleep(100);
			j++;
		}
		
		printf(" ----------------------------\n");
        printf("\t\t%-10s%-30s%-15s\n", "Roll No", "Name", "Marks");
        printf("\t\t--------------------------------------------------------------------------\n");

        for (int i = 0; i < studentCount; i++) {
            printf("\t\t%-10d%-30s%-15.2f\n", students[i].rollNo, students[i].name, students[i].marks);
            if (i != studentCount - 1) {
                printf("\n");
            }
        }
        printf("\t\t--------------------------------------------------------------------------\n");
    } 
    else if (choice == 2) {
        printf("\n\t\tEnter the roll number of the student: ");
        scanf("%d", &rollNo);

        for (int i = 0; i < studentCount; i++) {
            if (students[i].rollNo == rollNo) {
                printf("\n\t\tStudent Details:\n");
                printf("\t\t%-10s%-30s%-15s\n", "Roll No", "Name", "Marks");
                printf("\t\t--------------------------------------------------------------------------\n");
                printf("\t\t%-10d%-30s%-15.2f\n", students[i].rollNo, students[i].name, students[i].marks);
                printf("\t\t--------------------------------------------------------------------------\n");

                found = 1;
                break;
            }
        }

        if (!found) {
            printf("\n\t\tNo student found with roll number %d.\n", rollNo);
        }
    } 
    else {
        printf("\n\t\tInvalid choice! Please enter 1 or 2.\n");
    }
}




// <------------------------------------ updateStudent() FUNCTION ------------------------------------------>

void updateStudent() {
    if (studentCount == 0) {
        printf("\n\t\tNo student records available.\n");
        return;
    }

    int rollNo;

    printf("\n\t\tEnter the roll number of the student to update: ");
    while (scanf("%d", &rollNo) != 1) {
        printf("\t\tInvalid input! Please enter a valid integer roll number.\n");
        while (getchar() != '\n'); // input buffer clear karega 
        printf("\n\t\tEnter the roll number of the student to update: ");
    }

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == rollNo) {
            printf("\n\t\t------------------------ CURRENT RECORD OF STUDENT ----------------------\n");
            printf("\t\t%-10s%-30s%-15s\n", "Roll No", "Name", "Marks");
            printf("\t\t--------------------------------------------------------------------------\n");
            printf("\t\t%-10d%-30s%-15.2f\n", students[i].rollNo, students[i].name, students[i].marks);
            printf("\t\t--------------------------------------------------------------------------\n");

            printf("\n\t\t--- Update Record ---\n");

            printf("\t\tEnter new name: ");
            scanf(" %[^\n]", students[i].name);

            do {
                printf("\t\tEnter new marks (0-100): ");
                if (scanf("%f", &students[i].marks) != 1) {
                    printf("\t\tInvalid input! Please enter a valid numeric value for marks.\n");
                    while (getchar() != '\n'); 
                } else if (students[i].marks < 0 || students[i].marks > 100) {
                    printf("\t\tMarks must be between 0 and 100.\n");
                } else {
                    break; 
                }
            } while (1);

            printf("\n\t\tRecord updated successfully!\n");
            return;
        }
    }

    printf("\n\t\tNo student found with roll number %d.\n", rollNo);
}


// <------------------------------------ deleteStudent() FUNCTION ------------------------------------------>

void deleteStudent() {
    if (studentCount == 0) {
        printf("\n\t\tNo student records available.\n");
        return;
    }

    int rollNo, found = 0;

    printf("\n\t\tEnter the roll number of the student to delete: ");
    scanf("%d", &rollNo);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == rollNo) {
            found = 1;

            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }

            studentCount--; 
            printf("\n\t\tRecord with roll number %d deleted successfully.\n", rollNo);
            break;
        }
    }

    if (!found) {
        printf("\n\t\tNo student found with roll number %d.\n", rollNo);
    }
}
