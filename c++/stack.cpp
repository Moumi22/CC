#include<iostream>
using namespace std;
class userStack
{
    char myAra[50];
    int topIndex;
public:
    userStack()
    {
        topIndex=1;
    }
    void pop()
    {
        if(topIndex<0)
            cout<<"Underflow";
        else
            topIndex--;

    }
    char top()
    {
        return myAra[topIndex];
    }
    int size()
    {
        return topIndex+1;
    }
    void push(char C)
    {
      if(size()<50)
        {
            topIndex++;
        }
        else
        {
            cout<<"overflow";
        }

    }

};
int main()
{
    userStack stk;
    stk.push('A');
    stk.push('B');
    stk.push('C');
    cout<<stk.top()<<endl;
}
