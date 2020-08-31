#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,temp;
		cin>>N;
		int A[N];
		for(int i=0; i<N; i++)
			cin>>A[i];
		for(int i=0; i<N; i++)
		{
			if(A[i]>=0 && A[i]!=i)
			{
				A[A[i]] = (A[A[i]]+A[i])-(A[i]=A[A[i]]);	
			}	
		}
		for(int i=0; i<N; i++)
		{
			if(A[i]!=i)	A[i] = -1;
			cout<<A[i]<<" ";	
		}		
	}
	return 0;
}
