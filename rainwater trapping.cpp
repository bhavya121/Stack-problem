#include<iostream>
#include<stack>
using namespace std;
int main()
{
stack<int>s;
int arr[]={0,1,0,2,1,0,1,3,2,1,2,1};
int n=12;
int top;
int dis;
int height;
int r=0;
int i=0;
while(i<n&&arr[i]==0)
{
    i++;
}
while(i<n)
{
while(!s.empty()&&arr[i]>=arr[s.top()])
{
top=s.top();
s.pop();
if(s.empty())
{
    break;
}
dis=i-s.top()-1;
height=min(arr[i],arr[s.top()])-arr[top];
r=r+(dis*height);
}
s.push(i);
i++;

}
cout<<r;
}
