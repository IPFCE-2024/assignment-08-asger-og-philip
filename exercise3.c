/*
 * Exercise 3: Queue Implementation using Singly-Linked Lists
 * Assignment 8 - IPFCE 2025
 * 
 * Implement a queue using singly-linked lists.
 * The queue should maintain FIFO (First-In, First-Out) order.
 */

#include "include/exercise3.h"

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

int main(){
    printf("Test 1: Queue Law 1 - After initialize(q), queue must be empty\n");
    queue q1;
    initialize(&q1);
    assert(empty(&q1) && "Queue should be empty after initialization");
    assert(q1.front == NULL && "Front should be NULL");
    assert(q1.rear == NULL && "Rear should be NULL");
    printf("✓ Queue is empty after initialization\n\n");
    
    // Test 2: Single enqueue/dequeue (Queue Law 2)
    printf("Test 2: Queue Law 2 - enqueue(q,x); y=dequeue(q); x must equal y\n");
    queue q2;
    initialize(&q2);
    int x = 42;
    enqueue(&q2, x);
    int y = dequeue(&q2);
    assert(x == y && "Dequeued value should equal enqueued value");
    assert(empty(&q2) && "Queue should be empty after dequeue");
    printf("✓ x=%d, y=%d (equal)\n\n", x, y);
    
    // Test 3: FIFO order (Queue Law 3)
    printf("Test 3: Queue Law 3 - FIFO order with two elements\n");
    queue q3;
    initialize(&q3);
    int x0 = 10, x1 = 20;
    enqueue(&q3, x0);
    enqueue(&q3, x1);
    int y0 = dequeue(&q3);
    int y1 = dequeue(&q3);
    assert(x0 == y0 && "First dequeued should equal first enqueued");
    assert(x1 == y1 && "Second dequeued should equal second enqueued");
    assert(empty(&q3) && "Queue should be empty");
    printf("✓ FIFO maintained: x0=%d, y0=%d; x1=%d, y1=%d\n\n", x0, y0, x1, y1);
    
    // Test 4: Multiple operations
    printf("Test 4: Multiple operations (5 elements)\n");
    queue q4;
    initialize(&q4);
    for (int i = 1; i <= 5; i++) {
        enqueue(&q4, i);
    }
    for (int i = 1; i <= 5; i++) {
        int val = dequeue(&q4);
        assert(val == i && "Values should be dequeued in FIFO order");
    }
    assert(empty(&q4) && "Queue should be empty");
    printf("✓ Multiple operations maintain FIFO order\n\n");
    
    // Test 5: Interleaved operations
    printf("Test 5: Interleaved enqueue and dequeue\n");
    queue q5;
    initialize(&q5);
    enqueue(&q5, 1);
    enqueue(&q5, 2);
    assert(dequeue(&q5) == 1 && "Should dequeue 1");
    enqueue(&q5, 3);
    assert(dequeue(&q5) == 2 && "Should dequeue 2");
    assert(dequeue(&q5) == 3 && "Should dequeue 3");
    assert(empty(&q5) && "Queue should be empty");
    printf("✓ Interleaved operations work correctly\n\n");
    
    // Test 6: Larger test
    printf("Test 6: Larger test (20 elements)\n");
    queue q6;
    initialize(&q6);
    for (int i = 0; i < 20; i++) {
        enqueue(&q6, i);
    }
    for (int i = 0; i < 20; i++) {
        int val = dequeue(&q6);
        assert(val == i && "Values should match in FIFO order");
    }
    assert(empty(&q6) && "Queue should be empty");
    printf("✓ Larger test passed\n\n");
    
    printf("🎉 All tests passed! All three queue laws verified.\n");
    return 0;
}

