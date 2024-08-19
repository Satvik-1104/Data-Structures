#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
}node;

node * createlinkedlist(int n){
    node *head, *temp, *p;
    head = NULL;
    for (int i=0;i<n;i++){
        temp = (node*)malloc(sizeof(node));
        printf("enter the data of node %d: ",i+1);
        scanf("%d", &(temp->data));
        temp->next = NULL;
        if (head == NULL){
            head = temp;
        }
        else {
            p = head;
            while (p->next != NULL){
                p = p->next;
            }
            p->next = temp;
        }
    }
    return head;
    free(temp);
}

void displaylist(node * head){
    node *p;
    p = head;
    while (p != NULL){
        printf("%d -> ", p->data);
        p=p->next;
    }
    printf("NULL");
}

node * insertatbeginning(node *head, int insert){
    node * ins= (node*)malloc(sizeof(node));
    ins->data = insert;
    ins->next = head;
    head = ins;
    return head;
    free(ins);
}

node * deletefrommiddle(node *head, int pos){
    node *bef, *aft, *p;
    bef = aft = head;
    for (int i=1;i<(pos-1);i++){
        bef = bef -> next;
    }
    for (int i=1;i<(pos+1);i++){
        aft = aft -> next;
    }
    p = bef -> next;
    bef -> next = aft;
    free(p);
    return head;
}

int main(){
    node *head;
    int n;
    printf("enter the size of linked list: ");
    scanf("%d", &n);
    head = createlinkedlist(n);
    displaylist(head);
    int insert;
    printf("\nenter the data of the node to be inserted: ");
    scanf("%d", &insert);
    printf("the node data to be inserted is: %d\n", insert);
    head = insertatbeginning(head, insert);
    n++;
    printf("the list after inserting element at the beginning is: ");
    displaylist(head);
    int pos;
    if (n%2==0){
        pos = n/2;
    }
    else {
        pos = (n+1)/2;
    }
    printf("\nmiddle node data I would like to delete is: ");
    node * p = head;
    for (int i=1;i<pos;i++){
        p=p->next;
    }
    printf("%d\n", p->data);
    head = deletefrommiddle(head, pos);
    printf("the list after deleting the middle element is: ");
    displaylist(head);
}