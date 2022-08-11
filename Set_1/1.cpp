#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int A[N];
    for(int i=0; i<N; i++)
    {   
        cin>>A[i];
    }
    sort(A, A+N);
    int ans=0, selected=0;

    for(int i=1; i< N; i++)
    {
        if(A[i-1] == A[i])
        {
            selected++;
            ans -= A[i];
        }else{
            int give = min(selected, A[i] - A[i-1] - 1);
            ans += give * (give+1)/2 + give * A[i-1];
            selected -= give;
        }
    }
    if(N>0)
    {
        ans += selected*(selected+1)/2 + selected * A[N-1];
    }
    cout<<ans<<"\n";
    return 0;
}