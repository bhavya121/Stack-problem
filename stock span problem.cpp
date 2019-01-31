#include<iostream>
#include<stack>
using namespace std;
int main()
{
stack<int>s;
s.push(0);
int n;
cin>>n;
int i;
int arr[n];
for(i=0;i<n;i++)
{
cin>>arr[i];
}
int span[n];
span[0]=1;
for(i=1;i<n;)
{
    if(s.empty())
    {
        span[i]=i+1;
        s.push(i);
        i++;
    }
if(arr[i]<=arr[s.top()])
{
span[i]=(s.empty())?(i+1):(i-s.top());
s.push(i);
i++;
}
else
s.pop();
}
for(i=0;i<n;i++)
{
cout<<span[i]<<"\n";
}
int max=span[0];
for(i=0;i<n;i++)
{
if(span[i]>max)
{
max=span[i];
}
}
cout<<"max is  "<<max;
}

