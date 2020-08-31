#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,val,count=0;
        cin>>N;
        int l=1, r=N;
        while(l<=r)
        {
            val = l*r;
            if(l%2==0 && r%2==0 && l!=r)
            {
                if(val>N)
                    r--;
                else if(val<N)
                    l++;
                else
                {
                    l++;r--;
                }    
                 continue;
            }
            if(val==N)
            {
                count++;
                l++;
                r--;
            }
            else if(val>N)
                r--;
            else
                l++;
                        
        }  
        cout<<count<<"\n";   
    }
    return 0;
} 
