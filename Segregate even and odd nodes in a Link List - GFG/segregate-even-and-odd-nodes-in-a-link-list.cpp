// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        if(!head || !head->next){
            return head;
        }
        Node* prev = NULL;
        Node* curr = head;
        Node* nex = curr->next;
        Node* even = new Node(0);
        Node* temp = even;
        Node*t;
        while(curr){
            if(curr->data & 1){
                prev = curr;
                curr = nex;
                nex = nex ? nex->next : NULL;
            }
            else{
                if(prev != NULL){
                    prev->next = nex;
                    t=curr;
                    temp->next = t;
                    temp = temp->next;
                    curr = nex;
                    nex = nex ? nex->next: NULL;
                }else{
                    temp->next = curr;
                    temp = temp->next;
                    head = head->next;
                    curr = head;
                    nex = curr ? curr->next : NULL;
                }
            }
        }
        temp->next = NULL;
        even = even->next;
        if(even == NULL){
            return head;
        }
        temp->next = head;
        return even;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends