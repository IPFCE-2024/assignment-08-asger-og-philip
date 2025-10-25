/*
 * Exercise 2: Insertion Sort for Singly Linked List
 * Assignment 8 - IPFCE 2025
 *
 * Implement insertion sort for a singly linked list of integers.
 * The list should be sorted in-place from smallest to largest.
 * No new nodes should be allocated - only pointers should be changed.
 */

#include "include/exercise2.h"
node *create_list_from_array(int arr[], int size)
{
    if (size == 0)
        return NULL;

    node *head = create_node(arr[0]);
    node *current = head;

    for (int i = 1; i < size; i++)
    {
        current->next = create_node(arr[i]);
        current = current->next;
    }

    return head;
}
/*
 * Sort a singly linked list in-place using insertion sort
 * list: pointer to the first node of the list
 *
 * The function should sort the list by rearranging pointers,
 * not by creating new nodes or swapping data values.
 * Returns pointer to the new head of the sorted list.
 */
node *isort(node *list)
{
    node* c = list;
    node* s = NULL;
    while (c != NULL)
    {
        node* ne =c->next;
        if(s==NULL||s->data>c->data){
            c->next=s;
            s=c;
        }
        else{
            node* fourth=s;
            while(fourth->next!=NULL && fourth->next->data<c->data){
                fourth=fourth->next;
            }
            c->next=fourth->next;
            fourth->next=c;
        }
        c=ne;
    }
    return s; // Placeholder implementation
}



/*void main()
{
    int arr1[] = {-5,3,-2,0};
    node *list1 = create_list_from_array(arr1, 4);
    print_list(isort(list1));
}*/

/* Helper function to print the list */
void print_list(node *list)
{
    node *current = list;
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

/* Helper function to create a node */
node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (!new_node)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Helper function to free the list */
void free_list(node *list)
{
    node *current = list;
    node *next_node;

    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}
