#include<iostream>

using namespace std;

struct Node
{
 int val;
 Node* next;
};

Node* makeNode(int key)
{
 Node* nd=new Node;

 nd->val=key;
 nd->next=NULL;
 
 return nd;
}

Node* createList(int *arr,int n)
{
 Node* head=NULL,*tail;

 for(int i=0;i<n;i++)
 {
  Node* tmp=makeNode(arr[i]);

  if(!head)
   head=tmp;
  else
   tail->next=tmp;

  tail=tmp;
 }

 return head;
}

void print(Node* head)
{ 
 if(head)
  cout<<head->val;
 head=head->next;

 while(head)
 {
  cout<<"->"<<head->val;
  head=head->next;
 }
}

int rev(Node* head)
{
 if(!head) return 0;

 return head->val+rev(head->next)*10;
}

Node* sum(Node* first,Node* second)
{
 int num1=rev(first);
 int num2=rev(second);

 int sum=num1+num2;

 Node* head=NULL,*tail;
 while(sum)
 {
  int r=sum%10;
  sum=sum/10;

  Node* tmp=makeNode(r);

  if(!head) head=tmp;
  else
   tail->next=tmp;

  tail=tmp;
 }
 return head;
}

int main()
{
 int list1[]={7,1,5};
 int list2[]={5,9,2};

 Node* first=createList(list1,sizeof(list1)/sizeof(int));
 Node* second=createList(list2,sizeof(list2)/sizeof(int));

 Node* head=sum(first,second);
 cout<<"\nlist 1      : ";
 print(first);

 cout<<"\nList 2      : ";
 print(second);
 
 cout<<"\nSum of List : ";
 print(head);
}