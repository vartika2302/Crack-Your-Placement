// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *root)
{
	Node *temp = root;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
 

 // } Driver Code Ends
/*

The structure of linked list is the following
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

class Solution
{
    public:
    Node *zigZag(Node*& head)
    {
     // your code goes here
     if(!head || !head->next){
         return head;
     }
     else if(!head->next->next){
         if(head->data > head->next->data){
             swap(head->data,head->next->data);
         }
         return head;
     }
     Node* p = head,* c = p->next,*n = c->next;
     bool flag = true;
     while(n){
         if(flag == true){
             if(p->data > c->data){
                 swap(p->data,c->data);
             }
             if(c->data < n->data){
                 swap(c->data,n->data);
             }
             flag = false;
             p = c;
             c = n;
             n = n->next;
         }
         else{
             if(p->data < c->data){
                 swap(p->data,c->data);
             }
             if(c->data > n->data){
                 swap(c->data,n->data);
             }
             flag = true;
             p = c;
             c = n;
             n = n->next;
         }
     }
     return head;
     
    }
};

// { Driver Code Starts.


int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		Solution ob;
		Node *ans = ob.zigZag(head);
		print(ans);
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends