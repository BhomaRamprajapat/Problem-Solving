#include<iostream>

using namespace std;

struct Node
{
 int val;
 Node* next;
};

void print(Node *ptr)
{
 while(ptr)
 {
  printf("%d ",ptr->val);
  ptr=ptr->next;
 }
}

Node *makeNode(int n)
{
 Node *nd=(Node*)malloc(sizeof(Node));
 nd->val=n;
 nd->next='\0';
 return nd;
}

Node* deleteNode(Node* head,int key)
{
 Node* tmp=head,*prev=NULL;

 while(tmp && tmp->val!=key)
 {
  prev=tmp;
  tmp=tmp->next;
 }

 if(prev && tmp)
  prev->next=tmp->next;
 else if(tmp)
  head=tmp->next;

 delete tmp;
 return head;
}

Node* insert(Node* head,int key,int pos)
{
 Node* tmp=head,*prev=NULL;
 Node* t=makeNode(key);

 while(tmp && pos>1)
 {
  prev=tmp;
  tmp=tmp->next;
  pos--;
 }
 
 if(!prev)
 {
  t->next=head;
  head=t;
 }
 else
 {
  prev->next=t;
  t->next=tmp;
 }

 return head;
}

int main()
{
 Node* head=NULL;

 head=insert(head,1,1);

 cout<<"\nList after insertion : ";
 print(head);
 
 head=insert(head,2,2);
 
 cout<<"\nList after insertion : ";
 print(head);

 head=insert(head,3,3);

 cout<<"\nList after insertion : ";
 print(head);

 head=insert(head,4,2);

 cout<<"\nList after insertion : ";
 print(head);

 cout<<"\n\nEnter Element to Delete : ";
 int n;
 cin>>n;
 head=deleteNode(head,n);

 cout<<"\nList is : ";
 print(head);
 cout<<"\n\n";
}














