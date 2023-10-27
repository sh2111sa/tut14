#include "My_class.h"
#include "ClassDef.h"

// Default constructor
MyClass::MyClass() {
    // Struct: Members (variables and functions) in a struct have public access by default. 
    //This means that all members of a struct can be accessed and modified from outside the struct.
    
    // And Members in a class have private access by default. 
    //This means that data members and member functions are encapsulated and not directly accessible from outside the class
}

// Another constructor
MyClass::MyClass(Int_t variable) {
    // Initialize class members based on 'variable' or any other parameters
}

// Destructor
MyClass::~MyClass() {
    // Perform any necessary cleanup or deallocation of resources here
}

ClassImp(MyClass);