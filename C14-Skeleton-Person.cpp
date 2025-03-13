// C14-Skeleton-Person.cpp 
// TODO 1. Manage the ID & counter for the Person class
// TODO 2. Implement the copy-constructor for the Person class
// TODO 3. Implement the assignment operator for the Person class
// TODO 4. Implement the operator<< for the Person class
// TODO 5. Implement the operator== for the Person class
// TODO 6. Implement the operator< for the Person class
// TODO 7. Create a vector of Person objects
// TODO 8. Show the vector of Person objects
// TODO 9. Sort the vector of Person objects
// TODO10. Make a clone of Diana Prince
// TODO11. Diana's clone moves to Los Angeles.
// TODO12. Show the vector of Person objects again


#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Person
{
protected:
    int     id;     //Unique ID = object counter + 1000
    string  name;
    string* address;
    int     age;

public:
    //Condensed Lazy Constructor (List Initializer Mode)
    Person(const string& n = "none", const int& ag = 0, const string& ad = "n.a")
        : name(n), age(ag), address(new string(ad)) { }

    //Just in-case destructor
    virtual ~Person() {}

    //Base explainer
    virtual string to_string() const
    {
        ostringstream sout;
        sout << this << " Person[ID: " << id << ", Name: " << name
            << ", Age: " << age
            << ", Address: " << *address << "]";
        return sout.str();
    }
};

int main()
{
    //Create several Person object (pointer to Person)
    Person* p1 = new Person("Homer", 39, "742 Evergreen Terrace");
    //SHerlock Holmes
    Person* p2 = new Person("Sherlock", 34, "221B Baker Street");
    //Bruce Wayne
    Person* p3 = new Person("Bruce", 35, "1007 Mountain Drive");
    //Tony Stark
    Person* p4 = new Person("Tony", 40, "10880 Malibu Point");
    //Diana Prince
    Person* p5 = new Person("Diana", 30, "Themyscira");

    
    cout << "All done!\n";
}

