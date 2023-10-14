#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    char str[100], ch;
    int i, j, k, len, freq=0;
    cout<<"Enter the String: ";
    gets(str);
    len = strlen(str);
    cout<<"\nCharacter\tFrequency";
    for(i=0; i<len; i++)
    {
        ch = str[i];
        for(j=0; j<len; j++)
        {
            if(ch==str[j])
            {
                freq++;
                for(k=j; k<(len-1); k++)
                    str[k] = str[k+1];
                len--;
                str[len] = '\0';
                j--;
            }
        }
        cout<<endl<<ch<<"\t\t"<<freq;
        freq=0;
        i--;
    }
    cout<<endl;
	return 0;
}
