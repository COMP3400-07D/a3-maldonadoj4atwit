#include "list.h"
#include <stdlib.h>
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
 * TODO: Describe what the function does
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

    {
        /* data */
    };
    
    
}

/**
 * TODO: Describe what the function does
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
 * TODO: Describe what the function does
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
 * TODO: Describe what the function does
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
 * TODO: Describe what the function does
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
 * TODO: Describe what the function does
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
 * TODO: Describe what the function does
 */
void ll_append(struct ll_node *head, int data) {

    struct ll_node *new_node = ll_create( data ) ;
    if ( new_node == NULL )
        return ;

    if ( head == NULL )
        return ;

    struct ll_node *tail = ll_tail( head ) ;
    tail ->next = new_node ;
}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_fromarray(int* data, int len) {

     if ( data == NULL || len <= 0 ){
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
 * TODO: Describe what the function does
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {

     if (head == NULL) {
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

