#include <iostream>
using namespace std;
const int M=1000;
void merge(int a[],int l,int m,int r){int t[M],i=l,j=m+1,k=0;while(i<=m&&j<=r)t[k++]=(a[i]<=a[j]?a[i++]:a[j++]);while(i<=m)t[k++]=a[i++];while(j<=r)t[k++]=a[j++];for(int x=0;x<k;x++)a[l+x]=t[x];}
void ms(int a[],int l,int r){if(l>=r)return;int m=l+(r-l)/2;ms(a,l,m);ms(a,m+1,r);merge(a,l,m,r);}
int main(){int a[M],n;if(!(cin>>n)||n<0||n>M)return 1;for(int i=0;i<n;i++)if(!(cin>>a[i]))return 1;if(n)ms(a,0,n-1);for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<"\n";}