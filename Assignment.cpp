# SUBIBI-ABNER
Assignment: Activity 6 -1D Array of Structure

#include <iostream>
#include <string>

using namespace std;

const int max_students = 100;

struct student {
    int student_id;
    string first_name;
    string last_name;
    string course;
    float gpa;
};

student students[max_students];
int student_count = 0;

int find_student(int id) {
    for (int i = 0; i < student_count; i++) {
        if (students[i].student_id == id) {
            return i;
        }
    }
    return -1;
}

void add_student() {
    if (student_count >= max_students) {
        cout << "Student list is full" << endl;
        return;
    }

    cout << "Enter student ID: ";
    cin >> students[student_count].student_id;

    if (find_student(students[student_count].student_id) != -1) {
        cout << "Student ID already exists" << endl;
        return;
    }

    cout << "Enter first name: ";
    cin >> students[student_count].first_name;
    cout << "Enter last name: ";
    cin >> students[student_count].last_name;
    cout << "Enter course: ";
    cin >> students[student_count].course;
    cout << "Enter GPA: ";
    cin >> students[student_count].gpa;

    student_count++;
    cout << "Student added" << endl;
}

void edit_student() {
    int id;
    cout << "Enter student ID to edit: ";
    cin >> id;

    int index = find_student(id);
    if (index == -1) {
        cout << "Student not found" << endl;
        return;
    }

    cout << "Enter new first name: ";
    cin >> students[index].first_name;
    cout << "Enter new last name: ";
    cin >> students[index].last_name;
    cout << "Enter new course: ";
    cin >> students[index].course;
    cout << "Enter new GPA: ";
    cin >> students[index].gpa;

    cout << "Student updated" << endl;
}

void delete_student() {
    int id;
    cout << "Enter student ID to delete: ";
    cin >> id;

    int index = find_student(id);
    if (index == -1) {
        cout << "Student not found" << endl;
        return;
    }

    for (int i = index; i < student_count - 1; i++) {
        students[i] = students[i + 1];
    }
    student_count--;
    cout << "Student deleted" << endl;
}

void display_student() {
    int id;
    cout << "Enter student ID to search: ";
    cin >> id;

    int index = find_student(id);
    if (index == -1) {
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
