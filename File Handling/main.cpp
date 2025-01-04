#include <iostream>
#include <fstream>

using namespace std;

int main()
{

string s;
getline(cin,s);
cout<<s<<endl;



    string str;

    ofstream file;

    file.open("C:\\Users\\manas\\OneDrive\\Desktop\\new.txt");
    file<<"first program in c++"<<endl;
    file.close();

    ifstream rea;

    rea.open("C:\\Users\\manas\\OneDrive\\Desktop\\new.txt");

    while(getline(rea,str))
    {
        cout<<str<<endl;
    }

}
