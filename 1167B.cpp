#include <bits/stdc++.h>
using namespace std;
int arr[] = {4, 8, 15, 16, 23,  42};
int r12 , r13 , r45 , r46;
 
void generate_comb(int nr , int n , vector<int>uz , vector<int> &cmb)
{
    if (nr == n)
    {
        if(r12 == arr[cmb[0]] * arr[cmb[1]] && r13 == arr[cmb[0]] * arr[cmb[2]] && r45 == arr[cmb[3]] * arr[cmb[4]] && r46 == arr[cmb[3]] * arr[cmb[5]])
        {
            cout << "! ";
            for(int i=0 ; i<6 ; i++)
            cout << arr[cmb[i]] << " ";
        }
        return;
    }
    for (int i=0 ; i<n ; i++)
        if(!uz[i])
        {
            cmb[nr] = i; uz[i] = 1;
            generate_comb(nr + 1 , n , uz , cmb);
            cmb[nr] = 0; uz[i] = 0;
        }
}
int main()
{
    printf("? 1 2\n");
    fflush(stdout); cin >> r12;
    printf("? 1 3\n");
    fflush(stdout); cin >> r13;
    printf("? 4 5\n");
    fflush(stdout); cin >> r45;
    printf("? 4 6\n");
    fflush(stdout); cin >> r46;
    vector<int> cmb(6) , uz(6);
    generate_comb(0 , 6 , uz , cmb);
}
