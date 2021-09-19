#ifndef EXERCISE1_H
#define EXERCISE1_H

#include "CircularArrayQ.h"

/** \fn int get_queue_length(CircularArrayQueue list);
 *  \brief Get the number of elements in the current queue.
 *  \param list The current queue.
*/
int get_queue_length(CircularArrayQueue list);

int get_queue_length(CircularArrayQueue list){
	int cnt=0;
	if(is_empty(list)){
		return cnt;
	}else{
		for( ; list.front != (list.rear + 1)%MAX; list.front = (list.front + 1) % MAX) {
        	cnt++;
   		}
    	return cnt;
	}
	
}

/** \fn PersonLinkedList get_all_females(CircularArrayQueue list);
 *  \brief Returns all females as a linked list using the current list without removing them in the current list.
 *  \param list The current queue.
 *  Note: Use the queue basic operations (enqueue, dequeue, front)
*/
PersonLinkedList get_all_females(CircularArrayQueue list);

PersonLinkedList get_all_females(CircularArrayQueue list){
	PersonNode *femalesLL = NULL;
	
	for( ; list.front != (list.rear + 1)%MAX; list.front = (list.front + 1) % MAX) {
        	if(list.data[list.front].sex == 'F'){
        		insert_first_LL(&femalesLL, list.data[list.front]);
			}
   		}
	return femalesLL;
}

/** \fn PersonDynamicArrayList remove_all_males(CircularArrayQueue *list);
 *  \brief Remove all males in the current list and returns the removed males as a dynamic array list.
 *  \param list The current queue.
 *  Note: Use the concept of queue with out using the basic operations.
*/
PersonDynamicArrayList remove_all_males(CircularArrayQueue *list);

PersonDynamicArrayList remove_all_males(CircularArrayQueue *list){
	PersonDynamicArrayList malesLL;
	
	for( ; list->front != (list->rear + 1)%MAX; list->front = (list->front + 1) % MAX) {
        	if(list->data[list->front].sex == 'M'){
        		dequeue(*(&list));
        		insert_last_DAL(&malesLL, list->data[list->front]);
			}
   		}
	return malesLL;
	
}

#endif
