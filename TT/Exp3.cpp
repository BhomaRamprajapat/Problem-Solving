#include<iostream>

using namespace std;

struct Node
{
 char val;
 Node* next;
};

Node* makeNode(char key)
{
 Node* nd=new Node;

 nd->val=key;
 nd->next=NULL;

 return nd;
}

Node* createList(string s)
{
 Node* head=NULL,*tail;
 for(int i=0;i<s.size();i++)
 {
  Node* tmp=makeNode(s[i]);

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

bool isPalindrome(Node* head)
{
 if(!head) return true;

 Node* slow=head,*fast=head,*prev=NULL;
 
 while(fast && fast->next)
 {
  Node* next=slow->next;
  fast=fast->next->next;

  slow->next=prev;
  prev=slow;
  slow=next;
 }

 if(fast)
  slow=slow->next;
 
 while(prev && slow)
 {
  if(prev->val!=slow->val)
   return false;
  prev=prev->next;
  slow=slow->next;
 }

 return true;
}

int main()
{
 string s1="naman";
 string s2="aman";

 Node* head1=createList(s1);
 Node* head2=createList(s2);

 cout<<"\n\nName : ";
 print(head1);
 
 if(isPalindrome(head1))
  cout<<" : is palindrome";
 else
  cout<<" : not palindrome";

 cout<<"\nName : ";
 print(head2);

 if(isPalindrome(head2))
  cout<<" : is palindrome";
 else
  cout<<"    : not palindrome\n\n";

}