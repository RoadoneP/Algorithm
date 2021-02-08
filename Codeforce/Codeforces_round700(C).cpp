#include<bits/stdc++.h>
using namespace std;
 
long long n;
 
int query(int pos){
	if(pos==0 || pos==n+1)return INT_MAX;
	int ans;
	cout<<"? "<<pos<<endl;
	fflush(stdout);
	cin>>ans;
	return ans;
}
 
int check(int pos){
	int a,b,c;
	
	a=query(pos-1);
	b=query(pos);
	c=query(pos+1);
	if(b<a && b<c)return 0;
	if(b>a)return 1;
	else return -1;
}
 
int main(){
 
	cin>>n;
	
	int l=0,r=n+1;
	
	while(true){
		int mid=(l+r)/2;
		int val=check(mid);
		if(val==0){
			cout<<"! "<<mid<<endl;
			return 0;
		}else if(val==1){
			r=mid;
		}else{
			l=mid;
		}
	}
 
	return 0;
}
 