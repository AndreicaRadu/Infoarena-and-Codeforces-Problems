#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main()
{
    ifstream fin("parantezare.in");ofstream fout("parantezare.out");
    char s[100001];int M,i,j=0,a,k;
    fin>>s;
    fin>>M;
    for(i=0;i<M;i++)
    {
        fin>>a;
        k=1;
        for(j=a+1;j<=100000;j++)
        {
            if(s[j]=='(') k++;
            if(s[j]==')') k--;
            if(k==0) {fout<<j<<" ";j=100001;}
        }
    }
}
