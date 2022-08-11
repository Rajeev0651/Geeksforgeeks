#include<bits/stdc++.h>
using namespace std;
map <int, int> ans;
void findbit(int N, vector<int> A)
{
    if(A.size()<=N)
    {
        int temp = 0;
        for(int i=0; i<A.size(); i++)
        {
            temp+= pow((double)2, i)*A[A.size()-i-1];
        }
        ans[temp] = 1;
        int l = A[A.size()-1];
        if(l==1)
        {
            A.push_back(0);
            findbit(N,A);
        }
        else
        {
            A.push_back(1);
            findbit(N,A);
            A.pop_back();
            A.push_back(0);
            findbit(N,A);
        }
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        vector<int> A;
        int N;
        cin>>N;
        A.push_back(1);
        findbit(N, A);
        for(map<int, int>:: iterator i = ans.begin(); i!=ans.end(); i++)
            cout<<i->first<<" ";
        cout<<"\n";
    }
    return 0;
}