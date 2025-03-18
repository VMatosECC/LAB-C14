
// C14-Course-Person-Textbook.cpp 

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
//------------------------------------------------
class Textbook {
private:
    string title;
public:
    //Condensed Constructor (Lazy initializer)
    Textbook(string t = "Untitled") : title(t) {};

    //User-defined methods
    string toString() {
        stringstream sout;
        sout << " Book [title: " << title << "]";
        return sout.str();
    }
};

//-----------------------------------------------
class Person {
private:
    string name;
public:
    void setName(string n) { name = n; }
    
    //Condensed costructor (Lazy Initializer)
    Person(string n = "no name") : name(n) {}

    //User-defined methods
    string toString() {
        stringstream sout;
        sout << " Person[ Name:" << name << "]";
        return sout.str();
    }
};

//----------------------------------------------
class Section {
private:
    vector<Person*> roster;
    Textbook       book;
public:
    Section(Textbook b = {}, vector<Person*> r = {}) :
        roster(r), book(b) {}

    //User-defined methods
    string toString() {
        stringstream sout;
        sout << " Section [ Book: " << book.toString() << "\n\tRoster:\n";
        for (Person* p : roster) {
            sout << "\t" << p->toString() << endl;
        }
        return sout.str();
    }
};

//------------------------------------------------
int main()
{
    //Create a list of Person objects
    Person* p1 = new Person("Homer");
    Person* p2 = new Person("Marge");
    Person* p3 = new Person("Bart");
    Person* p4 = new Person("Lisa");

    vector<Person*> vdb{ p1, p2, p3, p4 };

    //STudents
    vector<Person*> vp{ p1, p3 };

    Textbook b("OO using C++");

    Section cs2(b, vp);
    cout << "cs2 before changes " << cs2.toString() << endl;

    //Show database
    cout << "\nDatabase\n" << endl;
    for (Person* p : vdb) { cout << p->toString() << endl; }

    p1->setName("Homero");

    cout << "cs2 After changes " << cs2.toString() << endl;

    //Show database
    cout << "\nDatabase\n" << endl;
    for (Person* p : vdb) { cout << p->toString() << endl; }

    cout << "\nAll Done!\n";
}
