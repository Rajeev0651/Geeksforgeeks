#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,min,first=0,loc;
		cin>>N;
		int A[N];
		for(int i=0; i<N; i++)
			cin>>A[i];
		int K;
		cin>>K;	
		sort(A, A+N);
		cout<<A[K-1]<<"\n";	
	}
	return 0;
}
