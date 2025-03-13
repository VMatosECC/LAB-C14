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
    static int count;

    void setId() {
        id = 1000 + count;
    }

public:
    //Condensed Lazy Constructor (List Initializer Mode)
    Person(const string& n = "none", const int& ag = 0, const string& ad = "n.a")
        : name(n), age(ag), address(new string(ad)) {

        count++;
        setId();
    }

    //Copy-constructor
    Person(const Person& other) {
        this->name = other.name;
        this->age = other.age;

        this->id = other.id;        //TODO - assign unique ids

      /*  count++;
        this->setId();*/

        this->address = new string(*other.address);
        
    }

    Person operator= (const Person& other) {
        //avoid self-assignment
        if (this != &other) {
            this->name = other.name;
            this->age = other.age;
            this->id = other.id;

            delete this->address;

            this->address = new string();
            *this->address = *(other.address);

        }
        return *this;
    }

    friend ostream& operator<< (ostream& sout, const Person& p) {
        sout << p.toString();
        return sout;
    }


    //Just in-case destructor
    virtual ~Person() {}

    //Base explainer
    virtual string toString() const
    {
        ostringstream sout;
        sout << this << " Person[ID: " << id << ", Name: " << name
            << ", Age: " << age
            << ", address*: " << address
            << ", Address: " << *address << "]";
        return sout.str();
    }
};

int Person::count = 0;

//-------------------------------------------------------------------
int main()
{
    //Create several Person object (pointer to Person)
    Person* p1 = new Person("Homer", 39, "742 Evergreen Terrace");
    cout << "p1 " << p1->toString() << endl;

    //Clone
    //Person p6 = *p1;  //equivalent versions
    Person p6(*p1);
    cout << "p6 " << p6.toString() << endl;

    //Testing copy assignment
    Person p7;
    cout << "p7 before " << p7.toString() << endl;
    
    //I want to be like Homer!
    p7 = *p1;

    cout << "p7 after " << p7.toString() << endl;

    cout << "p7 " << p7 << endl;




    //Sherlock Holmes
    Person* p2 = new Person("Sherlock", 34, "221B Baker Street");
    //Bruce Wayne
    Person* p3 = new Person("Bruce", 35, "1007 Mountain Drive");
    //Tony Stark
    Person* p4 = new Person("Tony", 40, "10880 Malibu Point");
    //Diana Prince
    Person* p5 = new Person("Diana", 30, "Themyscira");
    cout << "All done!\n";
}

