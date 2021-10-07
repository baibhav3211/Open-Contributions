#include<bits/stdc++.h>
using namespace std;

#define b(x) (1<<((x)-1))
int i,j,k,n,m,t,a[1000500],res,pre[2005000],lst[1005000],f[2000500][2],it;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pre[i]=(pre[i-1]^a[i]);
	}
	for(i=1;i<=20;i++){
		memset(f,0,sizeof(f));
		for(j=n;j>=1;j--){
			if(!(a[j]&b(i)))lst[j]=0;
			else{
				lst[j]=(!lst[j+1])?j:lst[j+1];
			}
		}
		it=0;
		for(j=1;j<=n;j++){
			f[pre[j]][(1&j)&1]=j;
			while(it<=n&&lst[it]<=j){
				if(lst[it]){
					res=max(res,f[pre[it-1]][(it&1)^1]-it+1);
				}
				it++;
			}
		}
		for(j=1;j<=n;j++)pre[j]>>=1;
	}
	if(res==1)res=0;
	printf("%d",res);
}