// C14-LAB-University-Course-Management-Part3.cpp 
// Prototyping code for the C14 Lab: University Course Management 
// This is a quick & dirty solution. 
// There is much work to be done to make this a decent solution.
//--------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    string name;
public:
    Student(string n) : name(n) {}
    string getName() const { return name; }
};

class Professor {
private:
    string name;
public:
    Professor(string n) : name(n) {}
    string getName() const { return name; }
};

class Course {
private:
    string courseName;
    Professor* professor;  // Aggregation (Course doesn't own Professor)
    vector<Student*> students;  // Aggregation (Course doesn't own Students)
public:
    Course(string name, Professor* prof) : courseName(name), professor(prof) {}

    void enrollStudent(Student* s) {
        students.push_back(s);
    }

    void listStudents() const {
        cout << "Students in " << courseName << ":\n";
        for (const auto& student : students) {
            cout << " - " << student->getName() << endl;
        }
    }

    string getCourseName() const { return courseName; }
    Professor* getProfessor() const { return professor; }
};

class Department {
private:
    string name;
    vector<Course> courses;  // Composition (Courses belong to Department)
    vector<Professor*> professors;  // Aggregation (Department references Professors)
public:
    Department(string n) : name(n) {}

    void addCourse(Course c) {
        courses.push_back(c);
    }

    void addProfessor(Professor* p) {
        professors.push_back(p);
    }

    void listCourses() const {
        cout << "Courses in " << name << " Department:\n";
        for (const auto& course : courses) {
            cout << " - " << course.getCourseName() << " (Professor: "
                << course.getProfessor()->getName() << ")\n";
        }
    }
};

int main() {
    // Create Professors
    Professor prof1("Dr. Russell");
    Professor prof2("Dr. Ambrosio");

    // Create Department
    Department csDept("Computer Science");
    csDept.addProfessor(&prof1);
    csDept.addProfessor(&prof2);

    // Create Courses
    Course course1("Data Structures", &prof1);
    Course course2("Operating Systems", &prof2);

    // Add Courses to Department
    csDept.addCourse(course1);
    csDept.addCourse(course2);

    // Create Students
    Student s1("Lisa");
    Student s2("Bart");
    Student s3("Maggie");

    // Enroll Students
    course1.enrollStudent(&s1);
    course1.enrollStudent(&s2);
    course1.enrollStudent(&s3);

    course2.enrollStudent(&s2);
    course2.enrollStudent(&s3);

    // Display Courses and Students
    csDept.listCourses();
    cout << endl;
    course1.listStudents();
    cout << endl;
    course2.listStudents();

    cout << "\nAll done!\n";
}
