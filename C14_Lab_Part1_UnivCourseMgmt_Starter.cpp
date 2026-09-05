// UnivCourseMgmt_solution.cpp
// C14 Lab - University Course Management System, Part 1 (VERIFICATION BUILD)
// Reverse-engineered from the starter/skeleton at:
// https://github.com/VMatosECC/LAB-C14/blob/main/C14-LAB-Univerity-Course-Management-Part1.cpp
// Built only to confirm the API implied by that file's main() compiles and
// produces coherent, correct output for the lab handout.

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

//------------------------------------------------------------
class Student {
private:
    string name;
public:
    Student(string name) { this->name = name; }
    string getName() const { return name; }
};

//------------------------------------------------------------
class Professor {
private:
    string name;
public:
    Professor(string name) { this->name = name; }
    string getName() const { return name; }
};

//-------------------------------------------------------------
class Course {
private:
    string title;
    Professor* professor;          // aggregation: Course does NOT own this
    vector<Student*> students;     // aggregation: Course does NOT own these
public:
    Course(string title, Professor* professor) {
        this->title = title;
        this->professor = professor;
    }

    string getTitle() const { return title; }
    Professor* getProfessor() const { return professor; }

    void enrollStudent(Student* s) {
        students.push_back(s);
    }

    void listStudents() const {
        cout << "Course: " << title << "  (Professor: " << professor->getName() << ")" << endl;
        for (size_t i = 0; i < students.size(); i++) {
            cout << "  - " << students[i]->getName() << endl;
        }
    }
};

//----------------------------------------------------
class Department {
private:
    string name;
    vector<Professor*> professors;  // aggregation: Department does NOT own these
    vector<Course> courses;         // composition: Department OWNS these (by value)
public:
    Department(string name) { this->name = name; }

    // No user-written destructor is actually required here, but writing
    // one explicitly makes the ownership rules visible:
    ~Department() {
        // courses (vector<Course>) destroys its own Course objects
        // automatically - that IS the composition relationship.
        // professors (vector<Professor*>) only discards pointers here;
        // it must NOT delete the Professor objects themselves, since
        // Department merely references them (aggregation) and does not
        // own them - main() (or whoever created them) is responsible
        // for their lifetime.
    }

    void addProfessor(Professor* p) {
        professors.push_back(p);
    }

    void addCourse(const Course& c) {
        courses.push_back(c);   // copies c into the Department's own vector
    }

    void listCourses() const {
        cout << "Department: " << name << endl;
        for (size_t i = 0; i < courses.size(); i++) {
            cout << "  - " << courses[i].getTitle()
                 << "  (Professor: " << courses[i].getProfessor()->getName() << ")" << endl;
        }
    }
};

// --------------------------------------------------------
// Use the following main program to test your solution
int main()
{
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

    cout << "All done!\n";
}
