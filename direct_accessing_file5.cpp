#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};

void addStudent() {
    ofstream outFile("student_data.txt", ios::app);

    if (!outFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    Student newStudent;
    cout << "Enter Roll Number: ";
    cin >> newStudent.rollNumber;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, newStudent.name);
    cout << "Enter Division: ";
    getline(cin, newStudent.division);
    cout << "Enter Address: ";
    getline(cin, newStudent.address);

    outFile << newStudent.rollNumber << " " << newStudent.name << " " << newStudent.division << " " << newStudent.address << endl;
    outFile.close();

    cout << "Student added successfully!" << endl;
}

void displayStudent(int rollNumber) {
    ifstream inFile("student_data.txt");

    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    Student student;
    bool found = false;

    while (inFile >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber == rollNumber) {
            found = true;
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            break;
        }
    }

    if (!found) {
        cout << "Student with roll number " << rollNumber << " not found!" << endl;
    }

    inFile.close();
}

void deleteStudent(int rollNumber) {
    ifstream inFile("student_data.txt");

    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    ofstream tempFile("temp.txt");

    Student student;
    bool found = false;

    while (inFile >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber != rollNumber) {
            tempFile << student.rollNumber << " " << student.name << " " << student.division << " " << student.address << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    remove("student_data.txt");
    rename("temp.txt", "student_data.txt");

    if (found) {
        cout << "Student deleted successfully!" << endl;
    } else {
        cout << "Student with roll number " << rollNumber << " not found!" << endl;
    }
}

int main() {
    int choice, rollNumber;

    do {
        cout << "\n1. Add Student\n2. Delete Student\n3. Display Student\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                cout << "Enter Roll Number to delete: ";
                cin >> rollNumber;
                deleteStudent(rollNumber);
                break;
            case 3:
                cout << "Enter Roll Number to display: ";
                cin >> rollNumber;
                displayStudent(rollNumber);
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
