# SUBIBI-ABNER
Assignment: Activity 6 -1D Array of Structure

#include <iostream>
#include <string>

using namespace std;

const int MaxStudents = 100;

struct Student {
    int Id;
    string FirstName;
    string LastName;
    string Section;
    float Gpa;
};

Student StudentList[MaxStudents];
int StudentCount = 0;

int FindStudentById(int StudentId);
void AddStudent();
void EditStudent();
void DeleteStudent();
void ViewStudents();
void ShowMenu();

int main() {
    ShowMenu();
    return 0;
}

int FindStudentById(int StudentId) {
    for (int i = 0; i < StudentCount; i++) {
        if (StudentList[i].Id == StudentId) {
            return i;
        }
    }
    return -1;
}

void AddStudent() {
    if (StudentCount >= MaxStudents) {
        cout << "Student list is full." << endl;
        return;
    }

    Student NewStudent;
    
    do {
        cout << "Enter student ID: ";
        cin >> NewStudent.Id;

        if (FindStudentById(NewStudent.Id) != -1) {
            cout << "Student ID already exists. Please enter a different ID." << endl;
        }
    } while (FindStudentById(NewStudent.Id) != -1);

    cout << "Enter first name: ";
    cin >> NewStudent.FirstName;
    cout << "Enter last name: ";
    cin >> NewStudent.LastName;
    cout << "Enter section: ";
    cin >> NewStudent.Section;
    cout << "Enter GPA: ";
    cin >> NewStudent.Gpa;

    StudentList[StudentCount] = NewStudent;
    StudentCount++;

    cout << "Student added successfully." << endl;
}

void EditStudent() {
    int StudentId;
    cout << "Enter student ID to edit: ";
    cin >> StudentId;

    int Index = FindStudentById(StudentId);
    if (Index == -1) {
        cout << "Student not found." << endl;
        return;
    }

    cout << "Enter new first name: ";
    cin >> StudentList[Index].FirstName;
    cout << "Enter new last name: ";
    cin >> StudentList[Index].LastName;
    cout << "Enter new section: ";
    cin >> StudentList[Index].Section;
    cout << "Enter new GPA: ";
    cin >> StudentList[Index].Gpa;

    cout << "Student details updated successfully." << endl;
}

void DeleteStudent() {
    if (StudentCount == 0) {
        cout << "No student records found." << endl;
        return;
    }

    int StudentId;
    cout << "Enter student ID to delete: ";
    cin >> StudentId;

    int Index = FindStudentById(StudentId);
    if (Index == -1) {
        cout << "Student not found." << endl;
        return;
    }

    cout << "Student found: " << StudentList[Index].FirstName << " " << StudentList[Index].LastName << endl;
    cout << "Are you sure you want to delete this student? (1 - Yes, 2 - No): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        for (int i = Index; i < StudentCount - 1; i++) {
            StudentList[i] = StudentList[i + 1];
        }
        StudentCount--;
        cout << "Student deleted successfully." << endl;
    } else {
        cout << "Deletion canceled." << endl;
    }
}

void ViewStudents() {
    if (StudentCount == 0) {
        cout << "No students found." << endl;
        return;
    }

    int option;
    cout << "Choose viewing option:" << endl;
    cout << "1. Alphabetical Order" << endl;
    cout << "2. GPA (Ascending Order)" << endl;
    cout << "Enter choice: ";
    cin >> option;

    Student SortedList[MaxStudents];
    for (int i = 0; i < StudentCount; i++) {
        SortedList[i] = StudentList[i];
    }

    if (option == 1) {
        for (int i = 0; i < StudentCount - 1; i++) {
            for (int j = 0; j < StudentCount - i - 1; j++) {
                if (SortedList[j].FirstName > SortedList[j + 1].FirstName) {
                    swap(SortedList[j], SortedList[j + 1]);
                }
            }
        }
        cout << endl << "Students Sorted Alphabetically:" << endl;
    } else if (option == 2) {
        for (int i = 0; i < StudentCount - 1; i++) {
            for (int j = 0; j < StudentCount - i - 1; j++) {
                if (SortedList[j].Gpa > SortedList[j + 1].Gpa) {
                    swap(SortedList[j], SortedList[j + 1]);
                }
            }
        }
        cout << endl << "Students Sorted by GPA (Ascending Order):" << endl;
    } else {
        cout << "Invalid choice." << endl;
        return;
    }

    for (int i = 0; i < StudentCount; i++) {
        cout << SortedList[i].Id << " - " << SortedList[i].FirstName << " " << SortedList[i].LastName
             << " - " << SortedList[i].Section << " - GPA: " << SortedList[i].Gpa << endl;
    }
}

void ShowMenu() {
    int Choice;
    do {
        cout << endl << "   STUDENT MANAGEMENT MENU   " << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Edit Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. View Students" << endl;
        cout << "5. Exit" << endl;
        cout << "----------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> Choice;

        switch (Choice) {
            case 1:
                AddStudent();
                break;
            case 2:
                EditStudent();
                break;
            case 3:
                DeleteStudent();
                break;
            case 4:
                ViewStudents();
                break;
            case 5:
                cout << "Exiting program... Goodbye!" << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (true);
}     
