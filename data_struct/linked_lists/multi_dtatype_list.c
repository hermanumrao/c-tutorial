#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* crt_node(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void ins_end(Node** hd, int data) {
    Node* newNode = crt_node(data);
    if (*hd == NULL) {
        newNode->next = newNode;
        *hd = newNode;
    } else {
        Node* temp = *hd;
        while (temp->next != *hd) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *hd;
    }
}

void split_CL(Node* hd, Node** hd1, Node** hd2);
void displayl(Node* hd) {
    // if (hd == NULL) {
    //     return;
    // }

    Node* current = hd;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != hd);
    printf("\n");
}




int main(int argc, char const *argv[]){
    int n;
    scanf("%d", &n);

    Node* circularLinkedList = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        ins_end(&circularLinkedList, data);
    }

    Node* hd1 = NULL;
    Node* hd2 = NULL;
    split_CL(circularLinkedList, &hd1, &hd2);
    displayl(hd1);
    displayl(hd2);
    // ry
    Node* temp = hd1;


    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
        if (temp == hd1) {
            break;
        }
    }

    temp = hd2;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
        if (temp == hd2) {
            break;
        }
    }
}

void split_CL(Node* hd, Node** hd1, Node** hd2) {
    if (hd == NULL) {
        *hd1 = NULL;
        *hd2 = NULL;
        return;
    }

    Node* p1 = hd;
    Node* p2 = hd;

    //  pointer two steps and p1 pointer one step
    while (p2->next != hd && p2->next->next != hd) {
        p2 = p2->next->next;
        p1 = p1->next;
    }
    // pointers for the two resulting circular linked lists

    *hd1 = hd;
    *hd2 = p1->next;
    // first list circular
    p1->next = *hd1;
    // second list circular
    p2 = *hd2;
    while (p2->next != hd) {
        p2 = p2->next;
    }
    p2->next = *hd2;
}