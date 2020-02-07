#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    string s1 , s2;
    int l1 , l2;
    cin >> l1 >> l2 >> s1 >> s2;
    if(s1 == s2)
    {
        cout << "YES";
        return 0;
    }
    if(l1 > l2+1)
    {
        cout << "NO";
        return 0;
    }
    int i=0;
    while(s1[i] != '*')
    {
        if(s1[i] != s2[i])
        {
            cout << "NO";
            return 0;
        }
        i++;
    }
    i = 0;
    while(s1[l1 - 1 - i] != '*')
    {
        if(s1[l1 - 1 - i] != s2[l2 - 1 - i])
        {
            cout << "NO";
            return 0;
        }
        i++;
    }
    cout << "YES";
}
