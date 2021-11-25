#include<bits/stdc++.h>
using namespace std;
int main()
{
    int person;
    int boat;
    cin>>person>>boat;
    int P[person], B[boat];
    for(int i=0; i<person; i++)
        cin>>P[i];
    for(int i=0; i<boat; i++)
        B[i];
    sort(P, P+person, greater<int>());
    sort(B, B+boat, greater<int>());
    int ans=0, inc = 2, passes=0;
    for(int i=0; i<person; i++)
    {
        int flag = 0, x = 0;
        for(int j=0; j<person; j++)
        {
            if(P[j]!=-1)
            {
                flag = 1;
                if(P[j]<=B[x])
                {
                    passes++;
                    x++;
                    P[j] = -1;
                }
                
            }
        }
        if(passes==person)
            inc = 1;
        ans+=inc;
        if(flag==0)
            break; 
    }
    cout<<ans<<"\n";
}