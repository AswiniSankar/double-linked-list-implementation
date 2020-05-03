#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* pre;
  struct node* next;
};
struct node* root=NULL;
void insertatend();
void insertatbegin();
void insertatmiddle();
int lenght();
void deleteatend();
int len;
void display();
void deleteatbegin();
void deleteatmiddle();
void nodeswap();
void search();
void reverse();
int main()
{
  int ch;
  while(1)
  {printf("\n1.insertatend\n2.insertatbegin\n3.insertatmiddle\n4.display\n5.lenght\n6.deleteatend\n7.deleteatbegin\n8.deleteatmiddle\n9.search\n10.swapnode\n11.reverse\n12.exit\nenter your choice\n\n");
   scanf("%d",&ch);
   switch(ch)
   {case 1:insertatend();break;
     case 2:insertatbegin();break;
     case 3:insertatmiddle();break;
     case 4:display();break;
     case 5:
       len=lenght();
       printf("%d\n",len);
       break;     
     case 6:deleteatend();break;
     case 7:deleteatbegin();break;
     case 8:deleteatmiddle();break;
     case 9:search();break;
     case 10:nodeswap();break;
     case 11:reverse();break;
     case 12:exit(1);
     default:printf("invalid option\n");
   }
  }
printf("\n");
return 0;
}
void insertatend()
{
 struct node* temp,*p;
 temp=(struct node*)malloc(sizeof(struct node));
 printf("enter the data to insert\n");
 scanf("%d",&temp->data);
 temp->pre=NULL;
 temp->next=NULL;
 if(root==NULL)
   root=temp;
 else
 {p=root;
  while(p->next!=NULL)
  {p=p->next;
  }
  p->next=temp;
  temp->pre=p;
 }
}
void insertatbegin()
{
   struct node* temp,*p;
   temp=(struct node*)malloc(sizeof(struct node));
   printf("enter the data\n");
   scanf("%d",&temp->data);
   temp->pre=NULL;
   temp->next=NULL;
   if(root==NULL)
     root=temp;
   else
   {p=root;
   
    temp->next=p;
       p->pre=temp;
     temp->pre=NULL;
      root=temp;
   }
}
int lenght()
{  int c=0;
   struct node* temp=root;
   while(temp!=NULL)
   {c++;
    temp=temp->next;
   }
   return c;
}
void insertatmiddle()
{
  int i=1,pos;
  struct node* temp,*p,*q;
  len=lenght();
  printf("enter the position\n");
  scanf("%d",&pos);
  if(pos>len)
    printf("invalid position\nthe available positions are %d",len);
  else if(len==1)
    insertatbegin();
  else if(len==pos)
    insertatend();
  else
  {
    p=root;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    temp->pre=NULL;
    while(i<pos)
    {p=p->next;
     i++;
    }
    q=p->next;
    temp->next=q;
    q->pre=temp;
    temp->pre=p;
    p->next=temp;
    
  }
}
void display()
{
   struct node* temp;
   temp=root;
    if(temp==NULL)
      printf("the list is empty\n");
    else
   {while(temp!=NULL)
    {printf("%d-->",temp->data);
     temp=temp->next;
    }
   }
  printf("\n");
}
void deleteatend()
{ int i=1;
 struct node *p,*q;
 p=root;
 len=lenght();
 if(len==0)
   printf("list is empty\n");
 else if(len==1)
    root=NULL;
 else
 {
   while(i<len-1)
    { p=p->next;
     i++;
    }
    q=p->next;
    q->next=NULL;
    q->pre=NULL;
    p->next=q->pre;
    free(q);
}
}
void deleteatbegin()
{
 struct node *p=root,*q;
 len=lenght();
 if(len==0)
   printf("list is empty\n");
 else if(len==1)
   root=NULL;
 else
 { q=p->next;
   q->pre=NULL;
   p->next=NULL;
  root=q;
 free(p);
 }
}
void deleteatmiddle()
{
  int i=1,pos;
  struct node *p,*q,*r;
  len=lenght();
  printf("enter the position to delete\n");
  scanf("%d",&pos);
  if(len==0)
    printf("list is empty\n");
  else if(len==1)
    root=NULL;
  else if(pos>len)
    printf("invalid position\nthe available positions are %d",len);
  else if(pos==1)
     deleteatbegin();
  else if(pos==len)
     deleteatend();
  else
  { p=root;
    while(i<pos-1)
     { p=p->next;
        i++;
     }
  q=p->next;
  r=q->next;
  p->next=r;
  r->pre=p;
  q->next=NULL;
  q->pre=NULL;
  free(q);
   }
  
}
void search()
{
 int element,pos=0;
 struct node *p=root;
 len=lenght();
 printf("enter the element to search\n");
 scanf("%d",&element);
 while(p->data!=element)
 { pos++;
   p=p->next;
 }
 printf("the element %d is present in the %d position\n",element,pos+1);
}
void nodeswap()
{
   struct node*p,*q,*r;
   int i=1,pos;
   printf("enter the position to swap\n");
   scanf("%d",&pos);
   len=lenght();
   if(pos>=len)
     printf("invalid option\nthe available options are  %d-%d",2,len-1);
   else
   {p=root; 
    while(i<pos-1)
     {
       p=p->next;
       i++;
     }
     q=p->next;
     r=q->next;
   // printf("%d==%d==%d\n",p->data,q->data,r->data);
    q->next=r->next;
    r->next=q;
    p->next=r;
    r->next->pre=q;
    r->pre=r;
    q->pre=p;
    display();
   }
}
void reverse()
{
   int i,j,k;
  struct node* temp,*p,*q;
  p=q=root;
  len=lenght();
  i=0;
  j=len-1;
  while(i<j)
  {
      k=0;
      while(k<j)
      {q=q->next;
       k++;
      }
     temp->data=p->data;
     p->data=q->data;
     q->data=temp->data;
     p=p->next;
     q=root;
     i++;
     j--;
  }
  display();
  printf("\n");
}
