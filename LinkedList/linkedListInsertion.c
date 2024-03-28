// Linked List insertion in 4 ways
// 1. Insertion at begining
// 2. Insertion in between(at index)
// 3. Insertion at end
// 4. Insertion after node


#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("Elements: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    return ptr;
}

struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    ptr->data = data;
    int i=0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node * insertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;

    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node)); //dynamic memory creation in heap using malloc
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));    

    head->data = 7;
    head->next = second;

    second->data = 89;
    second->next = third;

    third->data = 27;
    third->next = fourth;

    fourth->data = 790;
    fourth->next = NULL;
    printf("Before the Insertion in Linked List \n");
    linkedListTraversal(head);
    printf("\n After the Insertion in Linked List \n");
    // head = insertAtFirst(head, 40);
    // head = insertAtEnd(head, 40);
    // head = insertAtIndex(head, 40, 3);
    head = insertAfterNode(head, second, 40);
    linkedListTraversal(head);
    return 0;
}


