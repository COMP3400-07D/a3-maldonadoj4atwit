#include "list.h"
#include <stdlib.h>
#include <stdio.h>
// TODO: Include any necessary header files here

/**
 * Returns the head of the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The head of the linked list. If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_head(struct ll_node *head) {
    return head;
}

/**
 * 
 * Returns the tail (last node) of the linked list
 * 
 * @param head the pointer to the first node
 * @return the pointer to the last node of the list, 
 * or NULL if the list is empty
 */
struct ll_node *ll_tail(struct ll_node *head) {
    if ( head == NULL ) {
        return NULL ;
    }

    struct ll_node *current = head ;

    while ( current ->next != NULL ) {
        current = current ->next ;
    }
    return current ;
}

/**
 * 
 * Counts the number of elements in the linked list
 *
 * @param head the pointer to the first node of the linked list
 * @return the total number of nodes in the list
 * Returns 0 if the list is empty
 */
int ll_size(struct ll_node *head) {

    int count = 0 ;

    struct ll_node *current = head ;

    while ( current != NULL ) {
        count++ ;
        current = current ->next ;
    }

    return count ;
  
}

/**
 * 
 * Searches for a node in the linked list that contains a given value
 *
 * @param head the pointer to the first node of the linked list
 * @param value the integer value to search for in the list
 * @return the pointer to the node that contains the specified value,
 * or NULL if the value is not found.
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
    struct ll_node *current = head ;

    while ( current != NULL ) {
        if ( current ->data == value ) {
            return current ;
        }

        current = current ->next ;
    }

    return NULL ;
   
}

/**
 * 
 * Converts the linked list into a dynamically allocated array
 *
 * @param head the pointer to the first node of the linked list
 * @return the pointer to an integer array containing all node values in order
 * or returns NULL if the list is empty
 */
int *ll_toarray(struct ll_node *head) {

    int size = ll_size( head ) ;
    if ( size == 0 ) {
        return NULL ;
    }

    int *arr = malloc( size * sizeof( int ) ) ;
    if ( arr == NULL ) {
        return NULL ;
    }

    struct ll_node *current = head ;
    for ( int i = 0 ; i < size; i++ ) {
        arr[ i ] = current ->data ;
        current = current ->next ;
    }

    return arr ;
   
}

/**
 * 
 * Creates a new linked list node containing the given integer data
 *
 * @param data the integer value to store in the new node
 * @return the pointer to the newly created node, 
 * or NULL if memory allocation fails
 */
struct ll_node *ll_create(int data) {

    struct ll_node *node = malloc( sizeof( struct ll_node ) ) ;
    if ( node == NULL ) {
        return NULL ;
    }

    node ->data = data ;
    node ->next = NULL ;
    return node ;
   
}

/**
 * 
 * Frees all memory used by the linked list
 *
 * @param head the pointer to the first node of the linked list
 */
void ll_destroy(struct ll_node *head) {

    struct ll_node *current = head ;

    while ( current != NULL ) {
        struct ll_node *next = current ->next ;
        free( current ) ;
        current = next ;
    }
    
}

/**
 * 
 * Appends a new node with the given data to the end of the linked list
 *
 * @param head the pointer to the first node of the linked list
 * @param data the integer value to store in the new node
 */
void ll_append(struct ll_node *head, int data) {

    struct ll_node *new_node = ll_create( data ) ;
    if ( new_node == NULL ) {
        return ;
    }

    if ( head == NULL ) {
        return ;
    }

    struct ll_node *tail = ll_tail( head ) ;
    tail ->next = new_node ;
}

/**
 * 
 * Creates a linked list from an array of integer
 *
 * @param data the pointer to the array of integers
 * @param len the number of elements in the array
 * @return the pointer to the head of the newly created linked list,
 * or NULL if len <= 0 
 */
struct ll_node *ll_fromarray(int* data, int len) {

     if ( data == NULL || len <= 0 ) {
        return NULL ;
     }

    struct ll_node *head = ll_create( data[ 0 ] ) ;
    if ( head == NULL ) {
        return NULL ;
    }

    struct ll_node *tail = head ;
    for ( int i = 1 ; i < len ; i++ ) {
        struct ll_node *new_node = ll_create( data[ i ] ) ;
        if ( new_node == NULL ) {
            break ;
        }

        tail ->next = new_node ;
        tail = new_node ;
    }

    return head ;

}

/**
 * 
 * Removes the first node in the list that contains a specific value
 *
 * @param head the pointer to the first node of the linked list
 * @param value the integer value to search for and remove
 * @return the pointer to the head of the linked list
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {

     if ( head == NULL ) {
        return NULL ;
     }

    if ( head ->data == value ) {
        struct ll_node *next = head ->next ;
        free( head ) ;
        return next ;
    }

    struct ll_node *current = head ;
    while ( current ->next != NULL ) {
        if ( current ->next ->data == value ) {
            struct ll_node *to_delete = current ->next ;
            current ->next = to_delete ->next ;
            free( to_delete ) ;
            break ;
        }
        current = current ->next ;
    }

    return head ;

}

