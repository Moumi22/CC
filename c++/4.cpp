#include<iostream>
using namespace std;
int main()
{
    int n1,n2,quotient,remainder;
    cout<<"enter two numbers\n";
    cin>> n1 >> n2;
    quotient = n1 / n2;
    remainder = n1 % n2;

    cout<< "Quotient = " << quotient <<endl;

    cout<< "Remainder = " << remainder<<endl;
    return 0;
}
