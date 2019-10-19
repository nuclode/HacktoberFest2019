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
double a[n];
inp(i,n,a);
priority_queue<double> s; 
priority_queue<double,vector<double>,greater<double> > g; 
double med = a[0];
cout << med << endl;
s.push(a[0]);
for(int i=1; i<n; i++)
{
	double x = a[i];
	if(s.size() > g.size())
	{
		if(x < med)
		{
			g.push(s.top());
			s.pop();
			s.push(x);
		}
		else
		g.push(x);
		med = (s.top() + g.top())/2.0;
	}
	else if(s.size() == g.size())
	{
		if(x < med)
		{
			s.push(x);
			med = s.top();
		}
		else
		{
			g.push(x);
			med = g.top();
		}
	}
	else
	{
		if(x > med)
		{
			s.push(g.top());
			g.pop();
			g.push(x);
		}
		else
		s.push(x);
		med = (s.top() + g.top()) / 2.0;
	}
	cout << med << endl;
}

return 0;
}

