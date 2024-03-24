#include<stdio.h>

#include"queuehead.h"

void InitLQueue(LQueue* Q) {
    if (Q == NULL) {
        return;
    }
    Q->front = NULL;
    Q->rear = NULL;
    Q->length = 0;
}

void DestroyLQueue(LQueue* Q) {
    if (Q == NULL) {
        return; 
    }
    Node* current = Q->front;
    while (current != NULL) {
        Node* next = current->next; 
        free(current->data); 
        free(current); 
        current = next; 
    }
    Q->front = NULL;
    Q->rear = NULL;
    Q->length = 0; 
}

Status IsEmptyLQueue(const LQueue* Q) {
    if (Q->front == NULL) {
        return TRUE; 
    }
    else {
        return FALSE;
    }
}

Status GetHeadLQueue(LQueue* Q, void* e) {
    if (Q == NULL || Q->front == NULL) {
        return FALSE;
    }
    e = Q->front->data;

    return TRUE;
}

int LengthLQueue(LQueue* Q) {
    if (Q == NULL) {
        return -1;
    }
    else {
        return Q->length;
    }
}

Status EnLQueue(LQueue* Q, void* data) {
    if (Q == NULL) {
        return FALSE; 
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return FALSE; 
    }

    newNode->data = data;
    newNode->next = NULL; 

    if (Q->rear == NULL) {
        Q->front = newNode;
        Q->rear = newNode;
    }
    else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
    Q->length++;

    return TRUE; 
}

Status DeLQueue(LQueue* Q) {
    if (Q == NULL || Q->front == NULL) {
        return FALSE; 
    }
    Node* tempNode = Q->front; 
    Q->front = Q->front->next; 
    if (Q->front == NULL) {
        Q->rear = NULL;
    }

    free(tempNode->data);
    free(tempNode); 

    Q->length--;
    return TRUE;
}