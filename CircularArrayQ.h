#ifndef CIRCULARARRAYQ_H
#define CIRCULARARRAYQ_H

#include <stdbool.h>
#include "Person.h"
#define MAX 10

typedef Person Type;

typedef struct {
    Type data[MAX];
    int front;
    int rear;
} CircularArrayQueue;

/** \fn CircularArrayQueue create_array_queue();
 *  \brief Create an empty circular array queue.
*/
CircularArrayQueue create_array_queue();

CircularArrayQueue create_array_queue(){
	CircularArrayQueue caq;
    int x;
    for(x=0; x<MAX; ++x) {

        caq.data[x] = createPerson("x", 'x', "x");
    }
    caq.front = 0;      
    caq.rear = MAX-1;  

    return caq;
}

/** \fn void init_array_queue(CircularArrayQueue *list);
 *  \brief Initialize as an empty circular array queue.
 *  \param list The queue that needs to be initialize.
*/
void init_array_queue(CircularArrayQueue *list);
void init_array_queue(CircularArrayQueue *list){
	list->front = 6;
	list->rear = 5;
}

/** \fn bool enqueue(CircularArrayQueue *list, Type p);
 *  \brief Adds a new person element into the last element available in the current queue. Returns true for a successful operation otherwise false.
 *  \param list The current queue.
 *  \param p The person to be added in the queue.
*/
bool enqueue(CircularArrayQueue *list, Type p);
bool enqueue(CircularArrayQueue *list, Type p){
	if((list->rear+2)%MAX != list->front){                      
        list->rear = (list->rear + 1) % MAX;
        list->data[list->rear] = p;
        return true;
    }else{
    	return false;
	}
    
}

/** \fn bool dequeue(CircularArrayQueue *list);
 *  \brief Remove the first inserted element from the current queue. Returns true for a successful operation otherwise false.
 *  \param list The current queue.
*/
bool dequeue(CircularArrayQueue *list);
bool dequeue(CircularArrayQueue *list){
	if((list->rear+1)%MAX != list->front){ 
		list->front = (list->front + 1) % MAX;
		return true;
	}else{
    	return false;
	}
	
}

/** \fn bool is_empty(CircularArrayQueue list);
 *  \brief Return true if the current list is empty otherwise false.
 *  \param list The current queue.
*/
bool is_empty(CircularArrayQueue list);
bool is_empty(CircularArrayQueue list){
	return (list.rear+1)%MAX == list.front;
}

/** \fn bool is_full(CircularArrayQueue list);
 *  \brief Return true if the current list is full otherwise false.
 *  \param list The current queue.
*/
bool is_full(CircularArrayQueue list);
bool is_full(CircularArrayQueue list){
	return (list.rear+2)%MAX == list.front;
}

/** \fn Type front(CircularArrayQueue list);
 *  \brief Return the person in the front without removing them.
 *  \param list The current queue.
*/
Type front(CircularArrayQueue list);
Type front(CircularArrayQueue list){
	Type x = list.data[list.front];
	return x;
}

#endif
