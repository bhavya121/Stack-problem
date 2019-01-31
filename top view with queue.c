#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    int val;
    struct node *left;
    struct node *right;
};
struct queue
{
    struct node* arr[50];
    int front;
    int rear;
};
struct queue* initializeQueue()
{
    int i;
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    for(i=0;i<50;i++)
    {
        q->arr[i]=NULL;
        q->front=-1;
        q->rear=-1;

    }
    return q;
}
void add(struct queue* q,struct node* root)
{
    if(q->rear==-1&&q->front==-1)
        q->front++;
    q->rear++;
    q->arr[q->rear]=root;
}
struct node* poll(struct queue* q)
{
    struct node* temp=q->arr[q->front];
    if(q->front==q->rear)
    {
        q->front=-1;
        q->rear=-1;
    }
     else
     {
     q->front++;
    }
    return temp;
}
bool isEmpty(struct queue *q)
{
    if(q->front==-1&&q->rear==-1)
        return 1;
    else
        return 0;

}

struct node *newnode()
{
    struct node *nn=(struct node*)malloc(sizeof(struct node));
    return nn;

};
struct node* insertion(struct node* root,int data,int v)
{
    if(root==NULL)
    {
        struct node*nn=newnode();
        nn->data=data;
        nn->val=v;
        nn->left=nn->right=NULL;
        return nn;
    }
    if(data>root->data)
        root->right=insertion(root->right,data,v-1);
    else if(data<root->data)
        root->left=insertion(root->left,data,v+1);
    return root;
}
void topview(struct node *root,int *l,int *r)
{
    int arr[100];
    int i;
    for(i=0;i<100;i++)
    {
     arr[i]=0;
    }
    struct queue* obj=initializeQueue();
    add(obj,root);
 //   *l=*r=root->val+50;
    while(!isEmpty(obj))
    {
        struct node* temp=poll(obj);
        if(temp->left)
        {
            add(obj,temp->left);
            //printf("fyv");
        }
        if(temp->right)
        {
            add(obj,temp->right);
            //printf("gg");
        }
    if(arr[temp->val+10]==0)
    {
    arr[temp->val+10]=temp->data;
    if(*l>temp->val+10)
    {
        *l=temp->val+10;
    }
    if(*r<temp->val+10)
    {
        *r=temp->val+10;
    }
    }
    }
    for(i=*l;i<=*r;i++)
    {
        //if(arr[i]!=-1)
        //{
        printf("%d ",arr[i]);
        //}
    }
}
int main()
{
    struct node* root=NULL;
    int arr[10];
    int i;
    for(i=0;i<8;i++)
    {

        scanf("%d",&arr[i]);
    }
    for(i=0;i<8;i++)
    {
        root=insertion(root,arr[i],0);

    }
    int l = 10;
    int r = 10;
    topview(root, &l, &r);
     for(i=l;i<=r;i++)
    {
        //if(arr[i]!=-1)
        //{
        printf("%d ",arr[i]);
        //}
    }
}
/*void print(struct node* root)
{

    if(root!=NULL)
    {
        print(root->left);
        printf("%d",root->data);
        print(root->right);
    }
}

/*void print(struct node* nn,int n )
{
    queue<struct node*>q;
    q.push(nn);
    while(!q.empty())
    {
        struct node* s=q.front();
        cout<<s->data<<" ";
        q.pop();
        if(s->left)
            q.push(s->left);
        if(s->right)
            q.push(s->right);
    }


}*/

