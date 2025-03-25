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
    string Course;
    float Gpa;
};

Student StudentList[MaxStudents];
int StudentCount = 0;

int FindStudentById(int StudentId);
void AddStudent();
void EditStudent();
void DeleteStudent();
void DisplayStudent();
void DisplayAllStudents();
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
    cout << "Enter student ID: ";
    cin >> NewStudent.Id;

    if (FindStudentById(NewStudent.Id) != -1) {
        cout << "Student ID already exists." << endl;
        return;
    }

    cout << "Enter first name: ";
    cin >> NewStudent.FirstName;
    cout << "Enter last name: ";
    cin >> NewStudent.LastName;
    cout << "Enter course: ";
    cin >> NewStudent.Course;
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
    cout << "Enter new course: ";
    cin >> StudentList[Index].Course;
    cout << "Enter new GPA: ";
    cin >> StudentList[Index].Gpa;

    cout << "Student details updated successfully." << endl;
}

void DeleteStudent() {
    int StudentId;
    cout << "Enter student ID to delete: ";
    cin >> StudentId;

    int Index = FindStudentById(StudentId);
    if (Index == -1) {
        cout << "Student not found." << endl;
        return;
    }

    for (int i = Index; i < StudentCount - 1; i++) {
        StudentList[i] = StudentList[i + 1];
    }
    StudentCount--;

    cout << "Student deleted successfully." << endl;
}

void DisplayStudent() {
    int StudentId;
    cout << "Enter student ID to search: ";
    cin >> StudentId;

    int Index = FindStudentById(StudentId);
    if (Index == -1) {
        cout << "Student not found." << endl;
        return;
    }

    cout << "ID: " << StudentList[Index].Id << endl
         << "Name: " << StudentList[Index].FirstName << " " << StudentList[Index].LastName << endl
         << "Course: " << StudentList[Index].Course << endl
         << "GPA: " << StudentList[Index].Gpa << endl;
}

void DisplayAllStudents() {
    if (StudentCount == 0) {
        cout << "No students found." << endl;
        return;
    }

    for (int i = 0; i < StudentCount - 1; i++) {
        for (int j = 0; j < StudentCount - i - 1; j++) {
            if (StudentList[j].Gpa < StudentList[j + 1].Gpa) {
                swap(StudentList[j], StudentList[j + 1]);
            }
        }
    }

    cout << endl << "Students sorted by GPA:" << endl;
    for (int i = 0; i < StudentCount; i++) {
        cout << StudentList[i].Id << " - " << StudentList[i].FirstName << " " << StudentList[i].LastName
             << " - " << StudentList[i].Course << " - GPA: " << StudentList[i].Gpa << endl;
    }
}

void ShowMenu() {
    int Choice;
    do {
        cout << endl
              << "   STUDENT MANAGEMENT MENU   " << endl
             
             << "1. Add New Student" << endl
             << "2. Edit Student Information" << endl
             << "3. Remove Student" << endl
             << "4. Search for a Student" << endl
             << "5. View All Students" << endl
             << "6. Exit Program" << endl
             << "----------------------------" << endl
             << "Enter your choice: ";
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
                DisplayStudent();
                break;
            case 5:
                DisplayAllStudents();
                break;
            case 6:
                cout << "Exiting program... Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (Choice != 6);
}
        cout << "Student not found" << endl;
        return;
    }

    cout << "ID: " << students[index].student_id << endl
         << "Name: " << students[index].first_name << " " << students[index].last_name << endl
         << "Course: " << students[index].course << endl
         << "GPA: " << students[index].gpa << endl;
}

void display_all_students() {
    if (student_count == 0) {
        cout << "No students found" << endl;
        return;
    }

    for (int i = 0; i < student_count - 1; i++) {
        for (int j = 0; j < student_count - i - 1; j++) {
            if (students[j].gpa < students[j + 1].gpa) {
                swap(students[j], students[j + 1]);
            }
        }
    }

    cout << "Students sorted by GPA:" << endl;
    for (int i = 0; i < student_count; i++) {
        cout << students[i].student_id << " - " << students[i].first_name << " " << students[i].last_name
             << " - " << students[i].course << " - GPA: " << students[i].gpa << endl;
    }
}

void menu() {
    int choice;
    while (true) {
        cout << endl
             << "1. Add Student" << endl
             << "2. Edit Student" << endl
             << "3. Delete Student" << endl
             << "4. Search Student" << endl
             << "5. Show All Students" << endl
             << "6. Exit" << endl
             << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: add_student(); break;
            case 2: edit_student(); break;
            case 3: delete_student(); break;
            case 4: display_student(); break;
            case 5: display_all_students(); break;
            case 6: cout << "Exiting" << endl; return;
            default: cout << "Invalid choice" << endl;
        }
    }
}

int main() {
    menu();
    return 0;
}
