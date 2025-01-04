#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
string s,s1;
getline(cin,s);



int length =  s.length();

for (int i =0;i<length;++i)
{
    if (s[i]!=' ')
    {
        s1.push_back(s[i]);
    }
}

cout<<s1;

}
