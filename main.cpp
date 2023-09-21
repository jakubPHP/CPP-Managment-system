#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
    string firstName;
    string lastName;
    int studentId;
    string email;

    Student(string firstName, string lastName, int studentId, string email) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->studentId = studentId;
        this->email = email;
    }
};

class Course {
public:
    string courseName;
    string courseCode;
    string courseDescription;

    Course(string courseName, string courseCode, string courseDescription) {
        this->courseName = courseName;
        this->courseCode = courseCode;
        this->courseDescription = courseDescription;
    }
};

class RecordManagementSystem {
private:
    vector<Student> students;
    vector<Course> courses;

public:
    void addStudent(Student& student) {
        students.push_back(student);
        cout << "Student added successfully." << endl;
    }

    void editStudent(int studentId) {
        bool found = false;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].studentId == studentId) {
                cout << "Enter new details for student:" << endl;
                // Pobranie nowych danych od użytkownika i zaktualizowanie obiektu studenta
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Student with ID " << studentId << " not found." << endl;
        }
    }

    void deleteStudent(int studentId) {
        bool found = false;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].studentId == studentId) {
                students.erase(students.begin() + i);
                cout << "Student deleted successfully." << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Student with ID " << studentId << " not found." << endl;
        }
    }

    void displayStudent(int studentId) {
        bool found = false;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].studentId == studentId) {
                cout << "Student Details:" << endl;
                cout << "Name: " << students[i].firstName << " " << students[i].lastName << endl;
                cout << "Student ID: " << students[i].studentId << endl;
                cout << "Email: " << students[i].email << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Student with ID " << studentId << " not found." << endl;
        }
    }

    void addCourse(Course& course) {
        courses.push_back(course);
        cout << "Course added successfully." << endl;
    }

void editCourse(const string& courseId) {
    bool found = false;
    for (int i = 0; i < courses.size(); i++) {
        if (courses[i].courseCode == courseId) {
            cout << "Enter new details for course:" << endl;
            // Pobranie nowych danych od użytkownika i zaktualizowanie obiektu kursu
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Course with code " << courseId << " not found." << endl;
    }
}

void deleteCourse(const string& courseId) {
    bool found = false;
    for (int i = 0; i < courses.size(); i++) {
        if (courses[i].courseCode == courseId) {
            courses.erase(courses.begin() + i);
            cout << "Course deleted successfully." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Course with code " << courseId << " not found." << endl;
    }
}

void displayCourse(string courseId) {
    bool found = false;
    for (int i = 0; i < courses.size(); i++) {
        if (courses[i].courseCode == courseId) {
            cout << "Course Details:" << endl;
            cout << "Name: " << courses[i].courseName  << endl;
            cout << "Code: " << courses[i].courseCode << endl;
            cout << "Description: " << courses[i].courseDescription << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Course with code " << courseId << " not found." << endl;
    }
}
    void displayAllStudents() {
        if (students.empty()) {
            cout << "No student records available." << endl;
        } else {
            cout << "All Students:" << endl;
            for (int i = 0; i < students.size(); i++) {
                cout << "Name: " << students[i].firstName << " " << students[i].lastName << endl;
                cout << "Student ID: " << students[i].studentId << endl;
                cout << "Email: " << students[i].email << endl;
                cout << "------------------" << endl;
            }
        }
    }

    void displayAllCourses() {
        if (courses.empty()) {
            cout << "No course records available." << endl;
        } else {
            cout << "All Courses:" << endl;
            for (int i = 0; i < courses.size(); i++) {
                cout << "Name: " << courses[i].courseName << endl;
                cout << "Code: " << courses[i].courseCode << endl;
                cout << "Description: " << courses[i].courseDescription << endl;
                cout << "------------------" << endl;
            }
        }
    }
};

int main() {
    RecordManagementSystem rms;

    Student student1("John", "Doe", 1001, "john.doe@example.com");
    rms.addStudent(student1);

    Student student2("Jane", "Smith", 1002, "jane.smith@example.com");
    rms.addStudent(student2);

    Course course1("Mathematics", "MATH101", "Introduction to Mathematics");
    rms.addCourse(course1);

    Course course2("Computer Science", "CS101", "Introduction to Computer Science");
    rms.addCourse(course2);

    rms.displayAllStudents();
    rms.displayAllCourses();

    rms.displayStudent(1001);
    rms.displayCourse("CS101");

    return 0;
}