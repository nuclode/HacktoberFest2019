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
int a[n], b[n];
a[0] = b[0] = 1;
for(int i=1; i<n; i++)
{
	a[i] = a[i-1] + b[i-1];
	b[i] = a[i-1];
}
cout << a[n-1] + b[n-1] << endl;

return 0;
}

