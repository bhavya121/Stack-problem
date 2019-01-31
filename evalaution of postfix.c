#include<stdio.h>

#include<string.h>

#include<stdbool.h>

#include<stdlib.h>

typedef struct node{

                int  data;

                struct node* next;

}node ;



void push(int val, node** top)

{

                node* nn= (node*)malloc(sizeof(node));

                nn->data=val;

                nn->next=*top;

                *top=nn;

}



void pop(node** top)

{

                struct node* temp=*top;

                *top=temp->next;

                free(temp);

                temp = NULL;



}

int peek(node* top)

{

return top->data;

}

bool isempty(node* top)

{

                if(top == NULL)

                return 1;

                return 0;

}
int main()
{
    struct node * nn=NULL;
    char str[1000];

    scanf("%[^\n]s",str);
    int n=strlen(str);
    int i;
    for(i=0;i<n;i++)
    {
        if(str[i]==' ')
            continue;
        else if(str[i]>='0'&&str[i]<='9')
        {
            int num=0;
            while(str[i]>='0'&&str[i]<='9')
            {
                num=num*10+(int)(str[i]-'0');
                i++;
            }
            i--;
            push(num,&nn);
        }
        else
        {
            int val1=peek(nn);
            pop(&nn);
            int val2=peek(nn);
            pop(&nn);
            switch(str[i])
            {
                case '+' : push(val2+val1,&nn);
                break;
                case '-' : push(val2-val1,&nn);
                break;
                case '*' : push(val2*val1,&nn);
                break;
                case '/' : push(val2/val2,&nn);
                break;
            }
        }

    }
     int x=peek(nn);
       //1pop(&nn);

    printf("%d ",x);



}
