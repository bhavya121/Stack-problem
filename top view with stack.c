#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
int val;
struct node* left;
struct node* right;
};
typedef struct stack
{
    struct node* arr[100];
    int top;
}stack;
void push(struct node* root,stack* s)
{
s->top=s->top+1;
s->arr[s->top]=root;
}
struct node* pop(stack *s)
{
if(s->top==-1)
return NULL;
struct node* temp=s->arr[s->top];
s->top=s->top-1;
return temp;
}
void initialize(stack* s)
{
s->top=-1;
}
int isEmpty(stack *s)
{
if(s->top==-1)
return 1;
else
return 0;
}
struct node *createBinary(struct node* root,int d,int v)
{
if(root==NULL)
{
   struct node *nn=(struct node*)malloc(sizeof(struct node));
   nn->data=d;
   nn->val=v;
   nn->left=NULL;
   nn->right=NULL;
   return nn;
}
else if(root->data>d)
{
    root->left=createBinary(root->left,d,v-1);
}
else if(root->data<d)
{
    root->right=createBinary(root->right,d,v+1);
}
return root;
}
void func(struct node* root)
{
    int arr[100];
    int i;
    for(i=0;i<100;i++)
    {
        arr[i]=-1;
    }
    stack *s=(stack*)malloc(sizeof(stack));
    initialize(s);
    push(root,s);
    while(!isEmpty(s))
    {
        struct node* x = pop(s);
        if(arr[x->val+50]==-1)
        {
            arr[x->val+50]=x->data;
        }
        if(x->left)
            push(x->left,s);
        if(x->right)
            push(x->right,s);
    }
    for(i=0;i<100;i++)
    {
        if(arr[i]!=-1)
            printf("%d",arr[i]);
    }

}
int main()
{
    struct node *root=NULL;
    int i;
    int n;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        root=createBinary(root,arr[i],0);
    }
    func(root);


}
