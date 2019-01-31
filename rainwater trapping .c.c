#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct stack
{
    struct node* top;
};
int isEmpty(struct stack*s)
{
    if(s->top==NULL)
        return 1;
    return 0;
}
void push(struct stack* s,int d)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->next=s->top;
    s->top=temp;
}
void pop(struct stack *s)
{
    if(isEmpty(s))
        return ;
    else
        s->top=s->top->next;
}
int top(struct stack *s)
{
    if(s->top==NULL)
        return;
    return s->top->data;
}
int min(int a,int b)
{
    if(a>b)
        return b;
    else
        return a;
}
int rain(int arr[],int n)
{
struct stack*s=(struct stack*)malloc(sizeof(struct stack));
s->top=NULL;
int tp;
int r=0;
int dis;
int height;
int i=0;
while(i<n&&arr[i]==0)
{
i++;
}
while(i<n)
{
if(!isEmpty(s)&&arr[i]>=arr[top(s)])
{
tp=top(s);
pop(s);
if(isEmpty(s))
{

    break;
}
dis=i-top(s)-1;
height=min(arr[i],arr[top(s)])-arr[tp];
r=r+(dis*height);
}
else
push(s,i);
i++;
}
return r;
}
int main()
{
int n;
scanf("%d",&n);
int arr[n];
int i;
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("%d",rain(arr,n));

}
