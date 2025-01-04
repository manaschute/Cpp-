#include <iostream>

using namespace std;

class node{

public:
int data;
node *next;


};

node *create(int A[],int size)
{
node *first;

first = new node;

node *last;
node *temp;

last = first;

first ->data= A[0];

first->next = nullptr;


for(int i =1; i<size; ++i)
{

    temp = new node;
    temp->data = A[i];
    temp ->next = nullptr;
    last ->next = temp;
    last = temp;


}

return first;
}

int display(node *first)
{

    node *p = first;

    while(p!=nullptr)
{

    cout <<p->data<<endl;
    p = p->next;
}

}

int del(node *p,int pos)
{

 node *q = nullptr;

 for (int i =0;i< pos-1; ++i)
 {
     q=p;
     p=p->next;
 }
    q->next = p->next;
    int x = p->data;

    delete p;
    cout << "deleted "<<x<<endl;


}

int add(node *p, int A[])
{
int sum=0;
node *temp;
temp = p;
int count =0;

while (temp!=nullptr)
{
  sum = sum + temp->data;
  temp = temp->next;
  count = count +1;

}
   cout <<"sum of all elements in LL " <<sum<<endl;
   cout <<"count of all elements in LL " <<count<<endl;
}

bool checkifsorted(node *first){

int x = -32768;
node *p;
p = first;

while (p!=nullptr)
{

    if(p->data < x){
        return false;
    }

    x=p->data;
    p=p->next;
}
return true;
}




int main()

{

int A[] = {1,2,3,4,5,34,76,12,87,34,56,78,22,334,998,334,556,456,11,34};

int size = (sizeof(A)/sizeof(A[0]));
node *first = create(A,size);
display(first);
add(first,A);
del(first,3);
display(first);

bool sorted = checkifsorted(first);
if(sorted){
    cout<<"Linked List is sorted"<<endl;
}
else{
    cout<<"Linked List is not Sorted"<<endl;
}
}
