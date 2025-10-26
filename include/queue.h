/*
 * Exercise 3: Queue Implementation using Singly-Linked Lists
 * Assignment 8 - IPFCE 2025
 * 
 * Implement a queue using singly-linked lists.
 * The queue should maintain FIFO (First-In, First-Out) order.
 */

#include "exercise3.h"

/* 
 * Initialize an empty queue
 * q: pointer to the queue structure
 * 
 * Post-condition: queue is empty with front and rear set to NULL
 */
void initialize(queue *q) {
    /* TODO: Initialize the queue */
    q->front=NULL;
    q->rear=NULL;
    q->count=0;
}

/* 
 * Insert item x at the back of queue q
 * q: pointer to the queue structure
 * x: item to be inserted
 * 
 * Pre-condition: queue is not full
 * Post-condition: x is added to the rear of the queue
 */
void enqueue(queue *q, int x) {
    /* TODO: Implement enqueue */
    
    node* temp = (node *)malloc(sizeof(node));
    temp->data=x;
    temp->next=NULL;
    if(q->front==NULL){
        q->front=temp;
        q->rear=temp;
    }
    else{
        q->rear->next=temp;
        q->rear=temp;
    }
    q->count+=1;
}

/* 
 * Return (and remove) the front item from queue q
 * q: pointer to the queue structure
 * 
 * Pre-condition: queue must not be empty
 * Post-condition: front item is removed and returned
 */
int dequeue(queue *q) {
    /* TODO: Implement dequeue */
    int x = q->front->data;
    q->front=q->front->next;
    q->count-=1;
    if(q->front==NULL){
        q->rear=NULL;
    }
    return x;  
}

/* 
 * Check if the queue is empty
 * q: pointer to the queue structure
 * Returns: true if queue is empty, false otherwise
 */
bool empty(const queue *q) {
    /* TODO: Implement empty check */
    if(q->front == NULL) {  
        return true;
    }
    return false; 
}

/* 
 * Check if the queue is full
 * q: pointer to the queue structure
 * Returns: true if queue is full, false otherwise
 */
bool full(const queue *q) {
    /* TODO: Implement full check */

    //always false for this exercise :D

    return false;
}

/* Helper function to print the queue */
void print_queue(const queue *q) {
    printf("Queue (front to rear): ");
    node *current = q->front;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" <- ");
        }
        current = current->next;
    }
    printf("\n");
}

