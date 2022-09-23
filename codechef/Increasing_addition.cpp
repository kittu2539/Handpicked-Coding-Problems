// link :- https://www.codechef.com/LTIME112A/problems/INCADD
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		map<int,int>m;
		for(int i=1;i<n;i++){
			m[(a[i]-a[i-1])]++;
		}
		
		for(int i=0;i<q;i++){
			int ind,x;
			cin>>ind>>x;
			ind--;
			if(ind==0){
				m[(a[ind+1]-a[ind])]--;
				if(m[(a[ind+1]-a[ind])]==0){
					m.erase((a[ind+1]-a[ind]));
				}
				a[ind]=x;
				m[(a[ind+1]-a[ind])]++;
			}else if(ind==n-1){
				m[(a[ind]-a[ind-1])]--;
				if(m[(a[ind]-a[ind-1])]==0){
					m.erase((a[ind]-a[ind-1]));
				}
				a[ind]=x;
				m[(a[ind]-a[ind-1])]++;
			}else{
				m[(a[ind+1]-a[ind])]--;
				if(m[(a[ind+1]-a[ind])]==0){
					m.erase((a[ind+1]-a[ind]));
				}
				

				m[(a[ind]-a[ind-1])]--;
				if(m[(a[ind]-a[ind-1])]==0){
					m.erase((a[ind]-a[ind-1]));
				}
				a[ind]=x;

				m[(a[ind+1]-a[ind])]++;
				m[(a[ind]-a[ind-1])]++;
			}
			cout<<max(0,-m.begin()->first)<<'\n';
		}
	}
	return 0;
}
