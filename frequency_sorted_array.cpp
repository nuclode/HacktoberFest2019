#include<iostream>
using namespace std;
int main()
 {
	//code
    int t;
    cin >> t;
    while(t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for(int i=0; i<n; i++) cin >> a[i];
        int first = -1;
        int low = 0, high =  n-1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(a[mid] == x)
            {
            	if(mid-1 >= 0 and a[mid-1] < x)
            	{
            		first = mid;
            		break;
				}
			}
            if(a[mid] < x) low = mid+1;
            else high = mid-1;
        }
        if(first == -1)
        {
            cout << first << endl;
            continue;
        }
        int last = 0;
        low = 0, high = n-1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(a[mid] == x)
            {
            	if(mid+1 < n and a[mid+1] > x)
            	{
            		last = mid;
            		break;
				}
			}
			if(a[mid] <= x) low = mid+1;
			else high = mid-1;
        }
        cout << last-first+1 << endl;
    }
	return 0;
}
