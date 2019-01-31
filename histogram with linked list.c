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
int getMaxArea(int hist[],int n)
{
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->top=NULL;
    int max=0;
    int tp;
    int area;
    int i=0;
    while(i<n)
    {
        if(isEmpty(s)||(hist[top(s)])<=hist[i])
        {

            push(s,i);
            i++;
        }
        else
        {
            tp=top(s);
            pop(s);
            area=hist[tp]*(isEmpty(s)?i:i-top(s)-1);
            if(max<area)
                max=area;
        }
    }
    while(!isEmpty(s))
    {
        tp=top(s);
        pop(s);
        area=hist[tp]*(isEmpty(s)?i:i-top(s)-1);
        if(max<area)
            max-area;
    }
    return max;
}
int main()
{
    int hist[]={6,2,5,4,5,1,6};
    int n=sizeof(hist)/sizeof(hist[0]);
    printf("%d ",getMaxArea(hist,n));
    return 0;
}
