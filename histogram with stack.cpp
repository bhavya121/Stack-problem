#include<iostream>
#include<stack>
using namespace std;
int main()
{
int arr[]={2,1,3,4,5,6};
int n=6;
stack<int>s;
int max=0;
int top;
int area;
int i;
for(i=0;i<n;)
{
if(s.empty()||arr[i]>=arr[s.top()])
{
s.push(i);
i++;
}
else
{
top=s.top();
s.pop();
area=arr[top]*(s.empty()?i:i-s.top()-1);
if(max<area)
max=area;
}
}
while(s.empty()==false)
{
top=s.top();
s.pop();
area=arr[top]*(s.empty())?i:i-s.top()-1;
if(max<area)
max=area;
}
cout<<max;
}
