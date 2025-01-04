#include <iostream>

using namespace std;


class complex{
private:

    int real;
    int img;

public:
    complex(int r=0,int im=0)
    {
        real = r;
        img = im;
    }

/*When you overload an operator and use it like c1 + c2 (or call it as a method like c1.add(c2)), here's what happens internally:

Key Points:
c1.add(c2) or c1 + c2 means that:

c1 is the object that calls the method.
c2 is the object passed as the parameter.
How the method works internally:

The method has access to the calling object (c1 in this case) through the implicit this pointer.
The passed object (c2) is directly accessible as the function argument.*/

   /* complex operator+(complex x)
    {
        complex temp;

        temp.real = real + x.real;
        temp.img = img + x.img;

        return temp;
    }*/


    friend complex operator+(complex t, complex u);
    friend ostream& operator<<(ostream &o, complex c1);


};

complex operator+(complex t, complex u)
{

  complex h;
  h.real = t.real + u.real;       /*Here, both operands (the left-hand side and the right-hand side of the + operator)
                                   are passed explicitly as parameters to the function.
                                    There is no implicit this pointer because this is not a member function.*/
  h.img = t.img +  u.img;

  return h;

}

ostream &operator<<(ostream &o, complex c)
{
    o<<c.real<<" + "<<" i"<<c.img<<endl;
}


int main()
{
    complex c1(3,4);
    complex c2(2,5);
    complex c3;
    c3 = c1+c2;//The compiler interprets this as: c3 = operator+(c1, c2); when both operands are passing in non member function of a class.

    cout<<c3; //same is below line here "<<" this operator is overloaded
    operator<<(cout,c3);//same as above line, operator<< - this is function name


    return 0;
}
