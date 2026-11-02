#include <iostream>
using namespace std;
int main(){int a[1000],n;if(!(cin>>n)||n<0||n>1000)return 1;for(int i=0;i<n;i++)if(!(cin>>a[i]))return 1;for(int i=0;i<n-1;i++){int m=i;for(int j=i+1;j<n;j++)if(a[j]<a[m])m=j;int t=a[i];a[i]=a[m];a[m]=t;}for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<"\n";}