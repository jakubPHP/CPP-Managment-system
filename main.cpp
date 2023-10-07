#include <iostream>
#include <vector>
#include <fstream>

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

class Grade {
public:
    int studentId;
    string courseCode;
    string grade;

    Grade(int studentId, string courseCode, string grade) {
        this->studentId = studentId;
        this->courseCode = courseCode;
        this->grade = grade;
    }
};

class Attendance {
public:
    int studentId;
    string courseCode;
    int attendancePercentage;

    Attendance(int studentId, string courseCode, int attendancePercentage) {
        this->studentId = studentId;
        this->courseCode = courseCode;
        this->attendancePercentage = attendancePercentage;
    }
};

class RecordManagementSystem {
private:
    vector<Student> students;
    vector<Course> courses;
    vector<Grade> grades;
    vector<Attendance> attendance;

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

        void addGrade(int studentId, string courseCode, string grade) {
        Grade newGrade(studentId, courseCode, grade);
        grades.push_back(newGrade);
        cout << "Grade added successfully." << endl;
    }

    void editGrade(int studentId, string courseCode) {
        bool found = false;
        for (int i = 0; i < grades.size(); i++) {
            if (grades[i].studentId == studentId && grades[i].courseCode == courseCode) {
                cout << "Enter new grade for student:" << endl;
                // Pobranie nowego oceny od użytkownika i zaktualizowanie obiektu oceny
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Grade for student with student ID " << studentId << " and course code " << courseCode << " not found." << endl;
        }
    }

    void deleteGrade(int studentId, string courseCode) {
        bool found = false;
        for (int i = 0; i < grades.size(); i++) {
            if (grades[i].studentId == studentId && grades[i].courseCode == courseCode) {
                grades.erase(grades.begin() + i);
                cout << "Grade deleted successfully." << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Grade for student with student ID " << studentId << " and course code " << courseCode << " not found." << endl;
        }
    }

    void displayGrades(int studentId) {
        bool found = false;
        for (int i = 0; i < grades.size(); i++) {
            if (grades[i].studentId == studentId) {
                cout << "Grades for student with student ID " << studentId << ":" << endl;
                cout << "Course Code: " << grades[i].courseCode << endl;
                cout << "Grade: " << grades[i].grade << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No grades found for student with student ID " << studentId << "." << endl;
        }
    }

    void addAttendance(int studentId, string courseCode, int attendancePercentage) {
        Attendance newAttendance(studentId, courseCode, attendancePercentage);
        attendance.push_back(newAttendance);
        cout << "Attendance added successfully." << endl;
    }

    void editAttendance(int studentId, string courseCode) {
        bool found = false;
        for (int i = 0; i < attendance.size(); i++) {
            if (attendance[i].studentId == studentId && attendance[i].courseCode == courseCode) {
                cout << "Enter new attendance percentage for student:" << endl;
                // Pobranie nowej obecności od użytkownika i zaktualizowanie obiektu obecności
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Attendance for student with student ID " << studentId << " and course code " << courseCode << " not found." << endl;
        }
    }

    void deleteAttendance(int studentId, string courseCode) {
        bool found = false;
        for (int i = 0; i < attendance.size(); i++) {
            if (attendance[i].studentId == studentId && attendance[i].courseCode == courseCode) {
                attendance.erase(attendance.begin() + i);
                cout << "Attendance deleted successfully." << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Attendance for student with student ID " << studentId << " and course code " << courseCode << " not found." << endl;
        }
    }

    void displayAttendance(int studentId) {
        bool found = false;
        for (int i = 0; i < attendance.size(); i++) {
            if (attendance[i].studentId == studentId) {
                cout << "Attendance for student with student ID " << studentId << ":" << endl;
                cout << "Course Code: " << attendance[i].courseCode << endl;
                cout << "Attendance Percentage: " << attendance[i].attendancePercentage << "%" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No attendance found for student with student ID " << studentId << "." << endl;
        }
    }



};


int main() {

    RecordManagementSystem rms;

    while (true) {
        int choice;
        cout << "1. Add Student" << endl;
        cout << "2. Edit Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Display Student" << endl;
        cout << "5. Add Course" << endl;
        cout << "6. Edit Course" << endl;
        cout << "7. Delete Course" << endl;
        cout << "8. Display Course" << endl;
        cout << "9. Display All Students" << endl;
        cout << "10. Display All Courses" << endl;
        cout << "11. Add Grade" << endl;
        cout << "12. Edit Grade" << endl;
        cout << "13. Delete Grade" << endl;
        cout << "14. Display Grades" << endl;
        cout << "15. Add Attendance" << endl;
        cout << "16. Edit Attendance" << endl;
        cout << "17. Delete Attendance" << endl;
        cout << "18. Display Attendance" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            string firstName, lastName, email;
            int studentId;
            cout << "Enter first name: ";
            cin >> firstName;
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "Enter student ID: ";
            cin >> studentId;
            cout << "Enter email: ";
            cin >> email;

            Student student(firstName, lastName, studentId, email);
            rms.addStudent(student);
        } else if (choice == 2) {
            int studentId;
            cout << "Enter student ID: ";
            cin >> studentId;
            rms.editStudent(studentId);
        } else if (choice == 3) {
            int studentId;
            cout << "Enter student ID: ";
            cin >> studentId;
            rms.deleteStudent(studentId);
        } else if (choice == 4) {
            int studentId;
            cout << "Enter student ID: ";
            cin >> studentId;
            rms.displayStudent(studentId);
        } else if (choice == 5) {
            string courseName, courseCode, courseDescription;
            cout << "Enter course name: ";
            cin >> courseName;
            cout << "Enter course code: ";
            cin >> courseCode;
            cout << "Enter course description: ";
            cin >> courseDescription;

            Course course(courseName, courseCode, courseDescription);
            rms.addCourse(course);
        } else if (choice == 6) {
            string courseCode;
            cout << "Enter course code: ";
            cin >> courseCode;
            rms.editCourse(courseCode);
        } else if (choice == 7) {
            string courseCode;
            cout << "Enter course code: ";
            cin >> courseCode;
            rms.deleteCourse(courseCode);
        } else if (choice == 8) {
            string courseCode;
            cout << "Enter course code: ";
            cin >> courseCode;
            rms.displayCourse(courseCode);
        } else if (choice == 9) {
            rms.displayAllStudents();
        } else if (choice == 10) {
            rms.displayAllCourses();
        } else if (choice == 11) {
            int studentId;
            string courseCode, grade;
            cout << "Enter student ID: ";
            cin >> studentId;
            cout << "Enter course code: ";
            cin >> courseCode;
            cout << "Enter grade: ";
            cin >> grade;

            rms.addGrade(studentId, courseCode, grade);
        } else if (choice == 12) {
            int studentId;
            string courseCode;
            cout << "Enter student ID: ";
            cin >> studentId;
            cout << "Enter course code: ";
            cin >> courseCode;
            rms.editGrade(studentId, courseCode);
        } else if (choice == 13) {
            int studentId;
            string courseCode;
            cout << "Enter student ID: ";
            cin >> studentId;
            cout << "Enter course code: ";
            cin >> courseCode;
            rms.deleteGrade(studentId, courseCode);
        } else if (choice == 14) {
            int studentId;
            cout << "Enter student ID: ";
            cin >> studentId;
            rms.displayGrades(studentId);
        } else if (choice == 15) {
            int studentId, attendancePercentage;
            string courseCode;
            cout << "Enter student ID: ";
            cin >> studentId;
            cout << "Enter course code: ";
            cin >> courseCode;
            cout << "Enter attendance percentage: ";
            cin >> attendancePercentage;

            rms.addAttendance(studentId, courseCode, attendancePercentage);
        } else if (choice == 16) {
            int studentId;
            string courseCode;
            cout << "Enter student ID: ";
            cin >> studentId;
            cout << "Enter course code: ";
            cin >> courseCode;
            rms.editAttendance(studentId, courseCode);
        } else if (choice == 17) {
            int studentId;
            string courseCode;
            cout << "Enter student ID:";
            cin >> studentId;
            cout << "Enter course code: ";
            cin >> courseCode;
            rms.deleteAttendance(studentId, courseCode);
        } else if (choice == 18) {
            int studentId;
            cout << "Enter student ID: ";
            cin >> studentId;
            rms.displayAttendance(studentId);
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
            
 
 