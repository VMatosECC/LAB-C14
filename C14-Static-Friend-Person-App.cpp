
#include "Person.h"

//An implementation of the friend function
void bestMan(Person& p) {
    cout << "Ladies and gentlemen, I am Barney Gumble, \n"
        << "I'll tell you a secret about my best friend "
        << p.name << ",\nhe is "
        << p.age << " years old " << endl;
}

int main()
{

    //Calling static data member and function
    cout << "How many people are there? " << Person::count << endl;

    //Function is invoked using the class name
    Person::goWarriors();

    //Create some people
    Person p1("Homer", 39);
    Person p2("Lisa", 8);
    Person p3("Bart", 10);

    //Show the people
    for (Person p : {p1, p2, p3, })
    {
        cout << p.toString() << endl;
    }

    //Let's make more noise
    p1.goWarriors();
    p2.goWarriors();
    p3.goWarriors();


    //Using the friend function (it will acces the object's private data)
    bestMan(p1);

    cout << "\nAll done!\n";
}

