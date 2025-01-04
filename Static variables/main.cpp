#include <iostream>

using namespace std;


class base
{
public:


int a =10;
static int num; // this is static variable, the assign value on this variable at first object creation will be the same in the next
               // object creation
                 //nut for the same class

    base()
    {

        ++num;
        ++a;

    }


    static int display() // this is static functions, this functions only and only work operations on static variables.
    {
        return num;
    }
};

int base::num =0; // this is global variable we need to create after creation of static variables ****this needs to be declare very imp****
// means this variable will only accessible to objects of this class only

int main()
{
    base b1; //here a =11 and count =1
    base b2; // here a=11 and count =2;  count value remains same as incremented as constructor is incrementing, and when this object is created again
             //constructor called and again, they incremented he static variable from 1 to 2. a is not
            //static so it goes to its predeclared value and incremented again

    cout<<"num = " <<b1.num<<endl;
    cout<<"a = "<<b1.a<<endl;

   base b3;
   cout<<"num = " <<b1.num<<endl;  //here a =11 and count =3
    cout<<"a = "<<b1.a<<endl;

    // this is a single static variable which can be access by objects also as well as class name also

    cout<<base::num<<endl;// like this

    //same goes with static functions

    cout<<b2.display()<<endl;
    //or
    cout<<base::display()<<endl;

    return 0;
}

