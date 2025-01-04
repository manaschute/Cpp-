#include <iostream>

using namespace std;
// this is polymorphism
class car
{

public:
   virtual void start()=0;//pure virtual function
   //this class is an abstract class now, now we cannot create object of that class
   //so why we have written this function to force to create this start() function to create in the derived class
   //we cannot create any object of this class, but we can create pointer variable which will store the address of the object of the other derived class

};

class Innova: public car{

public:

    void start() // we have acheive polymorphism here, because this derived class now must override this function
    {
        cout<<"Innova started"<<endl;
    }
};
class Harrier: public car
{

    public:

    void start()
    {
        cout<<"Harrier started"<<endl;
    }

};


int main()
{

Innova I;
Harrier H;

car *c; //there is a pointer variable of type class car,

c = &I;//this pointer variable store the address of the derived class name innova


c->start();//with this start() function which is created in the innova class will be execute

c = &H;

c->start(); // this and that line are same they are executing the same function but from different class, this is called runtime polymorphism

// but to create polymorphism we need to create pure virtual function which will force to create the function in the base classes.


    return 0;
}
