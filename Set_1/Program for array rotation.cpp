#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,X;
		cin>>N>>X;
		int A[N],B[N],les=0;
		for(int i=0; i<N; i++)
			cin>>A[i];
		for(int i=X; i<N; i++)
		{
			B[les++] = A[i]; 	
		}
		for(int i=0; i<X; i++)
		{
			B[les++] = A[i];	
	 	}
		for(int i=0; i<les; i++)
		{
			cout<<B[i]<<"\t"; 	
		}	 
	}
	return 0;
}
