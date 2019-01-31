#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  int hd;
  struct node* left;
  struct node* right;
};
struct queue
{
    struct node* arr[100];
    int front;
    int rear;
};
void initializequeue(struct queue *q)
{
    int i;
    for(i=0;i<100;i++)
    {
        q->arr[i]=NULL;
    }
    q->front=-1;
    q->rear=-1;

}
int isEmpty(struct queue *q)
{
    if(q->front==-1&&q->rear==-1)
        return 1;
    else
        return 0;
}
void push(struct queue *q,struct node* root)
{
    q->rear=q->rear+1;
    q->arr[q->rear]=root;
    if(q->front==-1)
    {
        q->front=q->rear;
    }

}
struct node* poll(struct queue *q)
{
    struct node* root = q->arr[q->front];
    if(q->front==q->rear)
    {
        q->front=q->rear=-1;
    }
    else{
        q->front=q->front+1;
    }
    return root;
};
struct node* createtree(struct node* root,int d,int hd)
{
    if(root==NULL)
    {
        struct node* nn=(struct node*)malloc(sizeof(struct node));
        nn->data=d;
        nn->hd=hd;
        nn->left=NULL;
        nn->right=NULL;
        return nn;
    }
    else if(root->data>d)
    {
        root->left=createtree(root->left,d,hd-1);
    }
    else if(root->data<d)
    {
        root->right=createtree(root->right,d,hd+1);
    }
    return root;

};
void bottomview(struct node* root,int *l,int *r)
{
    int arr[100];
    int i;
    for(i=0;i<100;i++)
    {
        arr[i]=0;
    }
    struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    initializequeue(q);
    push(q,root);
    while(!isEmpty(q))
    {
        struct node* temp=poll(q);
        if(temp->left)
            push(q,temp->left);
        if(temp->right)
            push(q,temp->right);
        arr[temp->hd+50]=temp->data;
        if(*l>temp->hd+50)
            *l=temp->hd+50;
        if(*r<temp->hd+50)
            *r=temp->hd+50;
    }
    for(i=*l;i<=*r;i++)
    {
        printf("%d",arr[i]);
    }

};
int main()
{
struct node* root=NULL;
int n;
scanf("%d",&n);
int i;
int arr[n];
for(i=0;i<n;i++)
{
    scanf("%d",&arr[i]);
}
for(i=0;i<n;i++)
{
    root=createtree(root,arr[i],0);
}
int l=50;
int r=50;

bottomview(root,&l,&r);
}
