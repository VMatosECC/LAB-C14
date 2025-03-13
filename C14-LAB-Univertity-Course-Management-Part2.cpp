// C14-LAB-Univertity-Course-Management-Part2.cpp 
/*
This is the UML class diagram for the University Course Management System.


+----------------------------------------------------+
|                  Department                       |
+----------------------------------------------------+
| - name: string                                    |
| - courses: vector<Course>                         |  // Composition
| - professors: vector<Professor*>                  |  // Aggregation
+----------------------------------------------------+
| + addCourse(Course c)                             |
| + addProfessor(Professor* p)                      |
| + listCourses()                                   |
+----------------------------------------------------+

                      1
                      |
                      |
                      n
+----------------------------------------------------+
|                  Course                           |
+----------------------------------------------------+
| - courseName: string                              |
| - professor: Professor*                           |  // Aggregation
| - students: vector<Student*>                      |  // Aggregation
+----------------------------------------------------+
| + enrollStudent(Student* s)                       |
| + listStudents()                                  |
+----------------------------------------------------+

                      1
                      |
                      |
                      1
+----------------------------------------------------+
|                  Professor                        |
+----------------------------------------------------+
| - name: string                                    |
+----------------------------------------------------+

                      1
                      |
                      |
                      n
+----------------------------------------------------+
|                  Student                          |
+----------------------------------------------------+
| - name: string                                    |
+----------------------------------------------------+



*/ 

#include <iostream>
using namespace std;

int main()
{
    cout << "\nAll done!\n";
}

