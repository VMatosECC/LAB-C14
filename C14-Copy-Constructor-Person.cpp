// C14-Copy-Constructor-Person.cpp 


#include "Person.h"

//-------------------------------------------------------------------
int main()
{

    // Pretend the following are paths to portraits 
// of Homer Simpson and Brad Pitt
    string homerPortrait = "c:/pictures/homer.jpg";
    string bradPortrait = "c:/pictures/brad.jpg";

    Person p1("Homer", 38, homerPortrait);
    cout << "p1       " << p1.toString() << endl;

    //Next three cloning options are equivalent
    //Person p2 = p1;   //Copy constructor invoked  
    Person p2(p1);    //Copy constructor invoked
    //Person p2 = Person(p1); //Copy constructor invoked
    cout << "p2       " << p2.toString() << endl;

    //// Caution: ==========================================
    // This is NOT a copy constructor invocation, instead
    // it is an assignment operator invocation
    Person p3;
    p3 = p1;        // requires operator= to be overloaded  
                    // to be discussed later in the course
    cout << "p3       " << p3.toString() << endl;
    ////=====================================================


    //Modify p2
    p2.setName("Homero");
    p2.setAge(65);
    p2.setPortraitPtr(bradPortrait);

    //Display the 'original' p1 and the modified clone p2
    //Observe whether p1 is affected by the changes to p2
    cout << "p1       " << p1.toString() << endl;
    cout << "p2       " << p2.toString() << endl;
    
    //Test the copy-assignment operator
    p3 = p2;
    cout << "p3       " << p3.toString() << endl;
    cout << "All done!\n";
}

