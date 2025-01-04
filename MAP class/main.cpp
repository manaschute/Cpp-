#include <iostream>
#include <map>

using namespace std;




int main()
{
  map<int,string> m;


  m.insert(pair<int,string>(1,"John"));
  m.insert(pair<int,string>(2,"ravi"));
  m.insert(pair<int,string>(3,"Abdul"));

  map<int,string>::iterator itr;

  for(itr = m.begin();itr != m.end();++itr)
  {
      cout<<itr->first<<" "<<itr->second<<endl;
  }


map <int,string>::iterator itr1;

itr1 = m.find(2);

cout<<itr->first<<" "<<itr1->second<<endl;


int arr[5]={1,2,3,4,5};




    return 0;
}
