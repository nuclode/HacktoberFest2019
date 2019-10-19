#include <bits/stdc++.h>
#define MAX 100005
#define pb push_back
#define mp make_pair
#define M 1000000007
#define fi first
#define se second
#define inp(i, n, a) for(int i=0;i<n;i++) cin>>a[i];
#define int long long
using namespace std;

signed main()
{
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);

int n;
cin >> n;
int a[n];
inp(i,n,a);
int k;
cin >> k;
deque<int> dq;
int max = 0, ind = -1;
int i;
for(i=0; i<k; i++) 
{
	while(!dq.empty() and a[i] >= a[dq.back()])
	dq.pop_back();
	dq.push_back(i);
}
for(; i<n; i++)
{
	cout << a[dq.front()] << " ";
	while(!dq.empty() and dq.front() <= i-k)
	dq.pop_front();
	while(!dq.empty() and a[i] >= a[dq.back()])
	dq.pop_back();
	dq.push_back(i);
}
cout << a[dq.front()];
return 0;
}

