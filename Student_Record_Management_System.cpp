//Student Record Management System in C++

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define the Student class
class Student 
{
private:
    int rollNumber;
    string name;
    float marks;

public:
    // Constructor to initialize Student object
    Student(int rollNumber, const string& name, float marks) 
	{
        this->rollNumber = rollNumber;
        this->name = name;
        this->marks = marks;
    }

    // Method to get roll number
    int getRollNumber() const 
	{
        return rollNumber;
    }

    // Method to display student details
    void displayDetails() const 
	{
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
        cout << "-------------------" << endl;
    }
};

// Define the StudentRecordSystem class
class StudentRecordSystem {
private:
    vector<Student> students;

public:
    // Method to add a new student
    void addStudent() 
	{
        int rollNumber;
        string name;
        float marks;

        cout << "Enter roll number: ";
        cin >> rollNumber;

        cout << "Enter name: ";
        cin.ignore(); // Ignore any newline character in the input buffer
        getline(cin, name);

        cout << "Enter marks: ";
        cin >> marks;

        Student newStudent(rollNumber, name, marks);
        students.push_back(newStudent);
        cout << "Student added successfully!\n";
    }

    // Method to display all students
    void displayAllStudents() const 
	{
        if (students.empty()) 
		{
            cout << "No students in record\n";
        } 
		else 
		{
            cout << "Student Details:\n";
            cout << "-------------------\n";
            for (size_t i = 0; i < students.size(); ++i) 
			{
                students[i].displayDetails();
            }
        }
    }

    // Method to display details of a specific student by index
    void displayStudentDetails(size_t index) const {
        if (index < students.size()) {
            students[index].displayDetails();
        } else {
            cout << "Invalid student index\n";
        }
    }

    // Method to search for a student by roll number
    void searchStudentByRollNumber() const {
        int rollNumber;
        cout << "Enter roll number to search: ";
        cin >> rollNumber;

        bool found = false;
        for (size_t i = 0; i < students.size(); ++i) {
            if (students[i].getRollNumber() == rollNumber) {
                students[i].displayDetails();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Student with roll number " << rollNumber << " not found\n";
        }
    }
};

// Main function to drive the student record system
int main() {
    StudentRecordSystem recordSystem;
    int choice;

    do {
        // Display menu
        cout << "\nStudent Record Management System\n";
        cout << "--------------------------------\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                recordSystem.addStudent();
                break;
            case 2:
                recordSystem.displayAllStudents();
                break;
            case 3:
                recordSystem.searchStudentByRollNumber();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 4.\n";
        }

    } while (choice != 4);

    return 0;
}

