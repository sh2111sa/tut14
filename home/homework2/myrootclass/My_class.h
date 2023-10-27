#ifndef __MYCLASS_H__
#define __MYCLASS_H__
#include <TObject.h>

class MyClass : public TObject {
public:
    MyClass();                   // Default constructor
    MyClass(Int_t variable);    // Another constructor
    virtual ~MyClass();          // Destructor
    //In ROOT, the TObject class is a fundamental base class for most classes used within the ROOT framework. It provides a set of common functionalities 
    //and features that are important for objects that will be used in a ROOT environment. Here's why it's beneficial to derive your class from TObject:

private:
    // Private members
    
    ClassDef(MyClass, 1); // MyClass
};

#endif // __MYCLASS_H__
