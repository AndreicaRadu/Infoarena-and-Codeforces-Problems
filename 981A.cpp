#include <iostream>
#include <string>
using namespace std;
 
bool palindrome(string s)
{
    for(int i=0 ; i<s.length()/2 ; i++)
    {
        if(s[i] != s[s.length()-1-i])
            return false;
    }
    return true;
}
 
int main()
{
    string s;
    cin >> s;
    if(!palindrome(s))
    {
        cout << s.length();
        return 0;
    }
    bool same = true;
    for(int i=1 ; i<s.length() ; i++)
    {
        if(s[i-1] != s[i])
        {
            same = false;
            break;
        }
    }
    if(palindrome(s) && !same)
    {
        cout << s.length() - 1;
        return 0;
    }
    cout << 0;
}
