#include <iostream>

using namespace std;


class your; // declare that class here before making the friend class, so that my class can know that their is your class
class my
{

    private: int a=10;

    friend void access(); // declare that outside function here and add friend keyword before the function name,now that function can access this class variable
    //remember that function is not part of this class, it can just access the variable of this class basically private variable upon object.

    friend your;
};

void access()
{
    my m; // object should be created

   cout<<m.a<<endl; //we cannot access private variable of a class from a function which is not part of the class like it is outside function
   // unless we have not declared a friend function inside the class
}



class your
{
public:
    my m1;

    void display()
    {

        cout<<m1.a<<endl; // this is also not possible because this is another class, so like friend function just declare friend class in that class
        //of which we are trying to access their private variable
    }
};



int main()
{
access();

your y;
y.display();
    return 0;
}


