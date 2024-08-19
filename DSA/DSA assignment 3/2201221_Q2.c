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
        printf("enter the data of node %d : ",i+1);
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

node * revsecondhalf(node * head, int pos){
    node * pre, *cur, *lat, *fhe;
    pre = head;
    for (int i = 1; i < (pos); i++){
        pre = pre -> next;
    }
    fhe = head;
    for (int i = 1; i < (pos-1); i++){
        fhe = fhe -> next;
    }
    cur = lat = pre->next;
    pre -> next = NULL;
    while (lat != NULL){
    lat = lat -> next;
    cur -> next = pre;
    pre = cur;
    cur = lat;
    }
    fhe -> next = pre;
    return head;
}

void palindromecheck(node * head, int pos, int n){
    node * p, *fh, *sh;
    fh = sh = head;
    for (int i=1;i<pos;i++){
        sh = sh -> next;
    }
    while (sh != NULL){
        if ((fh -> data) == (sh -> data)){
            fh = fh -> next;
            sh = sh -> next;
            if (sh == NULL){
                printf("it is a palindrome");
            }
        }
        else {
            printf("it is not a palindrome");
            break;
        }
    }
}

int main(){
    node *head, *p;
    int n, pos, m1, m2;
    printf("enter the size of linked list: ");
    scanf("%d", &n);
    head = createlinkedlist(n);
    p = head;
    displaylist(head);
    if (n%2 == 0){
        pos = n/2;
        for (int i=1;i<pos;i++){
            p = p -> next;
        }
        m1 = p -> data;
        p = p -> next;
        m2 = p -> data;
        if (m1 == m2){
            pos = pos+2;
            head = revsecondhalf(head, pos);
            printf("the list after reversing the list after mid element is\n");
            displaylist(head);
        }
    }
    else {
        pos = (n+1)/2;
        pos++;
        head = revsecondhalf(head, pos);
        printf("the list after reversing the list after mid element is\n");
        displaylist(head);
    }
    palindromecheck(head, pos, n);
}