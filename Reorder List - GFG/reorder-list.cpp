// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends


/* Following is the Linked list node structure */

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
Node* midPoint(Node* head){
    if(!head || !head->next){
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void iterativeReverse(Node*& head){
    Node* prev = NULL;
    Node* curr = head;
    Node* nex;
    while(curr){
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    head = prev;
} 

void reorderList(Node* head) {
    // Your code here
    if(!head || !head->next){
        return;
    }
    Node* mid = midPoint(head);
    Node* sec = mid->next;
    mid->next = NULL;
    iterativeReverse(sec);
    Node* t1 = head;
    Node* t2 = sec;
    Node* newHead = new Node(0);
    Node* temp = newHead;
    while(t1 || t2){
        if(t1){
            temp->next = t1;
            t1 = t1->next;
            temp = temp->next;
        }
        if(t2){
            temp->next = t2;
            t2 = t2->next;
            temp = temp->next;
        }
         
    }
    temp->next = NULL;
    head = newHead->next;
}