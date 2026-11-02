#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){vector<int>a;int n,ch;cout<<"Size: ";if(!(cin>>n)||n<0)return 1;for(int i=0,x;i<n;i++){if(!(cin>>x))return 1;a.push_back(x);}do{cout<<"\n1.Display 2.Insert 3.Delete 4.Search 0.Exit\n";if(!(cin>>ch))return 1;int p,x;switch(ch){case 1:for(int v:a)cout<<v<<" ";cout<<"\n";break;case 2:cout<<"Position and value: ";cin>>p>>x;if(p<1||p>(int)a.size()+1)cout<<"Invalid position\n";else a.insert(a.begin()+p-1,x);break;case 3:cout<<"Position: ";cin>>p;if(p<1||p>(int)a.size())cout<<"Invalid position\n";else a.erase(a.begin()+p-1);break;case 4:cout<<"Value: ";cin>>x;{auto it=find(a.begin(),a.end(),x);if(it==a.end())cout<<"Not found\n";else cout<<"Position "<<it-a.begin()+1<<"\n";}break;}}while(ch!=0);return 0;}