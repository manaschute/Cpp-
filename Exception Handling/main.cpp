#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{

    int a;
    int b;

    cout<<"Enter two numbers"<<endl;
cin>>a;
cin>>b;
    try{

    if(b ==0){
        throw 500;
    }

    cout<<a/b<<endl;

    }

    catch(int error){

    cout<<"the number you have entered will not be divisible"<<endl;


    }
}
