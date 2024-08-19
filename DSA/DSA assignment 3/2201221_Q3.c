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
    printf("NULL\n");
}

void printintersection(node *head1, node *head2, int n1, int n2){
    node *p1, *p2, *temp, *head;
    head = NULL;
    p1 = head1;
    for (int i = 0; i < n1; i++){
        p2 = head2;
        for (int j = 0; j < n2; j++){
            if ((p1 -> data) == (p2 -> data)){
                int found = 0;
                node *p = head;
                while (p != NULL){
                    if ((p -> data) == (p1 -> data)){
                        found = 1;
                        break;
                    }
                    p = p -> next;
                }
                if (!found){
                    temp = (node*)malloc(sizeof(node));
                    temp -> data = p1 -> data;
                    temp -> next = NULL;
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
            }
            p2 = p2 -> next;
        }
        p1 = p1 -> next;
    }
    printf("the linked list containing the intersected data is:\n");
    displaylist(head);
    free(temp);
}

int main(){
    node *head1, *head2, *p1, *p2;
    p1=head1;
    p2=head2;
    int n1, n2;
    printf("enter the size of linked list 1: ");
    scanf("%d", &n1);
    printf("enter the elements of list 1\n");
    head1 = createlinkedlist(n1);
    printf("enter the size of linked list 2: ");
    scanf("%d", &n2);
    printf("enter the elements of list 2\n");
    head2 = createlinkedlist(n2);
    printf("the elements of list 1 are: \n");
    displaylist(head1);
    printf("the elements of list 2 are: \n");
    displaylist(head2);
    printintersection(head1, head2, n1, n2);
}