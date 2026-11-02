#include <iostream>
using namespace std;
int main(){int a[1000],n;if(!(cin>>n)||n<0||n>1000)return 1;for(int i=0;i<n;i++)if(!(cin>>a[i]))return 1;for(int i=1;i<n;i++){int key=a[i],j=i-1;while(j>=0&&a[j]>key){a[j+1]=a[j];j--;}a[j+1]=key;}for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<"\n";}