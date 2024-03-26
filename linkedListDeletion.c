// Linked List deletion in 4 ways
// 1. Deletion at begining
// 2. Deletion in between(at index)
// 3. Deletion at the end
// 4. Deletion at a given value 

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

struct Node * deleteAtFirst(struct Node *head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node * deleteAtIndex(struct Node *head, int index){
    struct Node * p = head;
    struct Node * q = head->next;
    
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);
    return head;
}

struct Node * deleteAtEnd(struct Node *head){
    struct Node * p = head;
    struct Node * q = head->next;

    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node * deleteAtValue(struct Node *head, int value){
    struct Node * p = head;
    struct Node * q = head->next;

    while(q->data != value && q->next != NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
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
    printf("Before the Deletion in Linked List \n");
    linkedListTraversal(head);
    printf("\n After the Deletion in Linked List \n");
    // head = deleteAtFirst(head);
    // head = deleteAtEnd(head);
    // head = deleteAtIndex(head, 2);
    head = deleteAtValue(head, 27);
    linkedListTraversal(head);
    return 0;
}


