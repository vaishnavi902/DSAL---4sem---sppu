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
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    Student newStudent;
    cout << "Enter Roll Number: ";
    cin >> newStudent.rollNumber;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, newStudent.name);
    cout << "Enter Division: ";
    getline(cin, newStudent.division);
    cout << "Enter Address: ";
    getline(cin, newStudent.address);

    outFile << newStudent.rollNumber << " " << newStudent.name << " " << newStudent.division << " " << newStudent.address << endl;

    cout << "Student information added successfully!" << endl;

    outFile.close();
}

void deleteStudent(int rollNumberToDelete) {
    ifstream inFile("student_data.txt");
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile) {
        cerr << "Error opening temporary file!" << endl;
        inFile.close();
        return;
    }

    bool found = false;
    Student student;
    while (inFile >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber != rollNumberToDelete) {
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
        cout << "Student information deleted successfully!" << endl;
    } else {
        cout << "Student with roll number " << rollNumberToDelete << " not found!" << endl;
    }
}

void displayStudent(int rollNumberToDisplay) {
    ifstream inFile("student_data.txt");
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    Student student;
    bool found = false;
    while (inFile >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber == rollNumberToDisplay) {
            found = true;
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            break;
        }
    }

    if (!found) {
        cout << "Student with roll number " << rollNumberToDisplay << " not found!" << endl;
    }

    inFile.close();
}

int main() {
    int choice;
    int rollNumber;

    do {
        cout << "\n1. Add Student\n2. Delete Student\n3. Display Student\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                cout << "Enter Roll Number of student to delete: ";
                cin >> rollNumber;
                deleteStudent(rollNumber);
                break;
            case 3:
                cout << "Enter Roll Number of student to display: ";
                cin >> rollNumber;
                displayStudent(rollNumber);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}