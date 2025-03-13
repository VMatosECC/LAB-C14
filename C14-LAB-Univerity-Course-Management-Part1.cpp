// C14-LAB-Univerity-Course-Management-Part1.cpp 

/* *************************************************************************************
Lab Experience: University Course Management System (Using Composition & Aggregation)

Problem Description
  Students will design and implement a University Course Management System
  using composition and aggregation principles in C++.
  The system should model the relationships between Students, Courses, Professors,
  and Departments while demonstrating a clear distinction between the
  two object-oriented concepts.

Key Requirements
- A Student can enroll in multiple Courses.
- A Course is taught by a Professor.
- A Course belongs to a specific Department.
- Each Department has multiple Courses and Professors.
- Students, Courses, and Professors must be managed dynamically
  (using pointers and proper memory management).

Concept Implementation
- Composition (Strong Ownership):
  A Department directly contains Courses.
  If a Department is deleted, its Courses should also be deleted.

- Aggregation (Weak Relationship):
  A Course has a Professor and multiple Students, but their lifetimes
  are independent of the Course’s lifetime.

Expected Deliverables
 - A UML Class Diagram showing the relationships.
 - A C++ implementation with appropriate constructors, destructors,
   and memory management.

A main() function is provided to test adding Courses, Professors,
and Students dynamically and prints the Course enrollments.

//TODO Each course uses several textbooks and has one SI tutor.
*****************************************************************************************
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

//------------------------------------------------------------
class Student {
    //TODO: Implement as a lazy-class (quick & dirty)

};
//------------------------------------------------------------
class Professor {
    //TODO: lazy class

};

//-------------------------------------------------------------
class Course {
    //TODO: lazy class

};
//----------------------------------------------------
class Department {
    //TODO: Lazy class

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

