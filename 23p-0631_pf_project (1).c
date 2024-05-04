#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// here i used define because define|const are used to enhance readability and it give us option to easily change it 
 
#define MAX_STUDENTS 100

char StudentID[MAX_STUDENTS][10];
char StudentName[MAX_STUDENTS][20];
char StudentEmail[MAX_STUDENTS][30];
char StudentPhone[MAX_STUDENTS][20];
int NumberOfCourses[MAX_STUDENTS];
int TotalStudents = 0;

// Function prototypes
void ShowAllStudents();
void EditStudent(int StudentFoundIndex);
int  SearchStudent(char StudentID[10]);
void DeleteStudent(int StudentIndex);
void AddStudent();

int main() {
    int choice;

    do {

        printf("1. Add student\n");
        printf("2. Edit student\n");
        printf("3. Show students \n");
        printf("4. Search student\n");
        printf("5. Delete student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");


        scanf("%d", &choice);

        

        switch (choice) {
            case 1: {

                AddStudent();

                }
                break;

            
            case 2: {

                 int StudentFoundIndex;
                printf("Enter student ID | rollNO to edit: ");
                scanf("%s", StudentID[TotalStudents]);
                StudentFoundIndex = SearchStudent(StudentID[TotalStudents]);
                if (StudentFoundIndex != -1) {
                    EditStudent(StudentFoundIndex);
                
            
                }
                
                break;
                 }
            case 3: {
               
               ShowAllStudents();
               
                break;


            }
            case 4: {
                
                
               
                char SearchID[10];        // will take 10 char no more char
                printf("Enter student ID to search: ");
                scanf("%s", SearchID);
                SearchStudent(SearchID);





                }
                break;

            case 5:{
                
                int StudentIndex;
                printf("Enter student ID to delete: ");
                scanf("%s", StudentID[TotalStudents]);
                StudentIndex = SearchStudent(StudentID[TotalStudents]);
                if (StudentIndex != -1) {
                    DeleteStudent(StudentIndex);}
                break;
                }
            case 6:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

   return 0;
}

void ShowAllStudents() {
    int i, j;
    printf("|==========|====================|==============================|====================|=============|\n");
    printf("|    ID    |        Name        |            Email             |       Phone        |  NO.Course  |\n");
    printf("|==========|====================|==============================|====================|=============|\n");
    for (i = 0; i < TotalStudents; i++) {
        printf("|%s", StudentID[i]);
        for (j = 0; j < (10 - strlen(StudentID[i])); j++) {
            printf(" ");
        }
        printf("|%s", StudentName[i]);
        for (j = 0; j < (20 - strlen(StudentName[i])); j++) {
            printf(" ");
        }
        printf("|%s", StudentEmail[i]);
        for (j = 0; j < (30 - strlen(StudentEmail[i])); j++) {
            printf(" ");
        }
        printf("|%s", StudentPhone[i]);
        for (j = 0; j < (20 - strlen(StudentPhone[i])); j++) {
            printf(" ");
        }
        printf("|%d", NumberOfCourses[i]);
        for (j = 0; j < 12; j++) {
            printf(" ");
        }
        printf("|\n");
        printf("|----------|--------------------|------------------------------|--------------------|-------------|\n");
    }
    printf("\n");
}

void EditStudent(int StudentFoundIndex) {
    int IsValidName = 0;
    char NewName[20];

    // Validate and get the new name
    while (!IsValidName) {
        printf("Enter the new Name (0 to skip): ");
        scanf(" %[^\n]", NewName);

        if (strcmp(NewName, "0") == 0) {
            // User chose to skip editing the name
            break;
        }

        if (strlen(NewName) > 20) {
            printf("Error: Name cannot be more than 20 characters.\n\n");
        } else if (strlen(NewName) <= 0) {
            printf("Error: Name cannot be empty.\n\n");
        } else {
            IsValidName = 1;
        }
    }
    if (IsValidName) {
        strcpy(StudentName[StudentFoundIndex], NewName);
    }

    printf("Student updated successfully.\n\n");
}

int SearchStudent(char SearchID[10]) {
    int StudentFoundIndex = -1;
    int i;
    for (i = 0; i < TotalStudents; i++) {
        if (strcmp(SearchID, StudentID[i]) == 0) {
            StudentFoundIndex = i;
            printf("\n One Student Found for ID: %s\n\n", SearchID);
            printf(" Student Informations\n");
            printf("-------------------------\n");
            printf(" ID:    %s\n", StudentID[i]);
            printf(" Name:  %s\n", StudentName[i]);
            printf(" Email: %s\n", StudentEmail[i]);
            printf(" Phone: %s\n", StudentPhone[i]);
            printf("\n Total Number of Courses: %d\n", NumberOfCourses[i]);
            break;
        }
    }

    if (StudentFoundIndex == -1) {
        printf("Student not found.\n\n");
    }

    return StudentFoundIndex;
}

void DeleteStudent(int StudentIndex) {
	int i;
    for (i = StudentIndex; i < TotalStudents - 1; i++) {
        strcpy(StudentID[i], StudentID[i + 1]);
        strcpy(StudentName[i], StudentName[i + 1]);
        strcpy(StudentEmail[i], StudentEmail[i + 1]);
        strcpy(StudentPhone[i], StudentPhone[i + 1]);
        NumberOfCourses[i] = NumberOfCourses[i + 1];
    }

    TotalStudents--;
    printf("Student deleted successfully.\n\n");
    
}

void AddStudent() {
    printf("Enter student details:\n");
    printf("Student ID: ");
    scanf("%s", StudentID[TotalStudents]);
    printf("Name: ");
    scanf(" %[^\n]", StudentName[TotalStudents]);
    printf("Email: ");
    scanf(" %[^\n]", StudentEmail[TotalStudents]);
    printf("Phone: ");
    scanf("%s", StudentPhone[TotalStudents]);
    printf("Number of Courses: ");
    scanf("%d", &NumberOfCourses[TotalStudents]);

    TotalStudents++;
    printf("Student added successfully.\n\n");
}