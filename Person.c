#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Person.h"

Person createPerson(String name, char sex, String city) {
    Person p;

    strcpy(p.name, name);
    p.sex = sex;
    strcpy(p.city, city);

    return p;
}

void displayPersonInfo(Person p) {
    printf("{%s | %c | %s}", p.name, p.sex, p.city);
}

/////////////////////////////////////////////////////////////////////////////
/* Static Array List*/
void init_SAL(PersonStaticArrayList *list){
	list->count = 0;
}

void insert_first_SAL(PersonStaticArrayList *list, Person p){
	if(list->count < MAX_LIST){
		int x;
		for(x=list->count; x>0; x--){
			list->data[x] = list->data[x-1]; 
		}
		list->data[x]= p;
		++list->count;	
	}
	
}

void insert_last_SAL(PersonStaticArrayList *list, Person p){  
	if(list->count < MAX_LIST){
		list->data[list->count] = p;
		++list->count;
	}	
}

void insert_at_SAL(PersonStaticArrayList *list, Person p, int index){  
	if(list->count < MAX_LIST){
		int x;
		for(x=list->count; x>=index; x--){
			list->data[x] = list->data[x-1];
		}
		list->data[index] = p;
		++list->count;
	}
}

void delete_first_SAL(PersonStaticArrayList *list){
	if(list->count != 0){
		int x;
		for(x=0; x<list->count-1; x++){
			list->data[x] = list->data[x+1];
		}
		--list->count;
	}
}

void delete_last_SAL(PersonStaticArrayList *list){
	if(list->count != 0){
		--list->count;
	}
}

void delete_by_sex_SAL(PersonStaticArrayList *list, char sex){  // all ocurrences    //check again lang 'F' doesn't seem to work
	if(list->count !=0){
		int x, y;
		for(x=0; x<list->count; x++){
			if(list->data[x].sex == sex){
				--list->count;
				for(y=x; y<list->count;y++){
					list->data[y] = list->data[y+1];
				}
			}
		}
	}
} 
void display_SAL(PersonStaticArrayList list){
	int x;
	printf("%15s | %s \n\n", "INDEX", "DATA");
	for(x=0; x<list.count; x++){
		printf("%15d | ", x);
		displayPersonInfo(list.data[x]);
		printf("\n");
	}
	printf("\n %20s %d \n\n", "COUNT:", list.count);
}
//////////////////////////////////////////////////////////////////////////////

/* Dynamic Array List - v1 
 * Doubles the maximum size of the array when full.
 */
void init_DAL(PersonDynamicArrayList *list){
	list = (PersonDynamicArrayList *) malloc(sizeof(PersonDynamicArrayList));

    list->count = 0;
    list->max = 4;
    list->data = (Person *) malloc(sizeof(Person)*list->max);
}

void insert_first_DAL(PersonDynamicArrayList *list, Person p){
	int x;
	if(list->count >= list->max){
		list->max *= 2;
		list->data = realloc(list->data, list->max);
	}
	
	for(x=list->count; x>0; --x){
		list->data[x] = list->data[x-1];
	}
	list->data[x] = p;
	list->count++;
}

void insert_last_DAL(PersonDynamicArrayList *list, Person p){
	if(list->count >= list->max){
		list->max *= 2;
		list->data = realloc(list->data, list->max);
	}
	list->data[list->count++] = p;
}

void insert_at_DAL(PersonDynamicArrayList *list, Person p, int index){
	int x;
	if(list->count >= list->max){
		list->max *= 2;
		list->data = realloc(list->data, list->max);
	}
	for(x=list->count; x>=index; x--){
		list->data[x] = list->data[x-1];
	}
	list->data[index] = p;
	list->count++;
}
void delete_first_DAL(PersonDynamicArrayList *list){
	if(list->count != 0){
		int x;
		for(x=0; x<list->count-1; x++){
			list->data[x] = list->data[x+1];
		}
		--list->count;
	}	
}

void delete_last_DAL(PersonDynamicArrayList *list){
	if(list->count != 0){
		list->count--;
	}
}
void delete_by_city_DAL(PersonDynamicArrayList *list, String city){ // first ocurrence
	int x, pos;
	
	for(x=0; x<list->count; ++x) {
        if(list->data[x].city == city) {
            pos=x;
            break;
        }
    }
    
    if(x<list->count) {
        for(x=pos; x<list->count-1; ++x) {
            list->data[x] = list->data[x+1];
        }
        list->count--;
    }
}
void display_DAL(PersonDynamicArrayList list){
//	int x;
//	printf("%15s | %s \n\n", "INDEX", "DATA");
//	for(x=0; x<list.count; ++x){
//		printf("%15d | ", x);
//		displayPersonInfo(list.data[x]);
//		printf("\n");
//	}
//	printf("\n %20s %d \n\n", "COUNT:", list.count);
   int i;
    printf("{");
    for(i=0; i<list.count; ++i) {
        displayPersonInfo(list.data[i]);
        if(list.count-1 > i) {
            printf(", ");
        }
    }
    printf("} Count: %d; Max: %d\n", list.count, list.max);
}
///////////////////////////////////////////////////////////////////////////////////


/* Dynamic Array List - v2 
 * Doubles the maximum size of the array when full.
 * The Dynamic Array List must also be created in the heap.
 */
void init_DAL_2(PersonDynamicArrayList **list){
	list = (PersonDynamicArrayListPointer *) malloc(sizeof(PersonDynamicArrayList));
	(*list)->count =0;
	(*list)->max = 4;
    (*list)->data = (Person *) malloc(sizeof(Person)*(*list)->max);
	
}

void insert_first_DAL_2(PersonDynamicArrayList *list, Person p){
	int x;
	if(list->count >= list->max){
		list->max *= 2;
		list->data = realloc(list->data, list->max);
	}
	
	for(x=list->count; x>0; x--){
		list->data[x] = list->data[x-1];
	}
	list->data[x] = p;
	list->count++;
}

void insert_last_DAL_2(PersonDynamicArrayList *list, Person p){
	if(list->count >= list->max){
		list->max *= 2;
		list->data = realloc(list->data, list->max);
	}
	list->data[list->count++] = p;
}

void insert_at_DAL_2(PersonDynamicArrayList *list, Person p, int index){
	int x;
	if(list->count >= list->max){
		list->max *= 2;
		list->data = realloc(list->data, list->max);
	}
	for(x=list->count; x>=index; x--){
		list->data[x] = list->data[x-1];
	}
	list->data[index] = p;
	list->count++;
}

void delete_first_DAL_2(PersonDynamicArrayList *list){
	if(list->count != 0){
		int x;
		for(x=0; x<list->count-1; x++){
			list->data[x] = list->data[x+1];
		}
		--list->count;
	}	
}

void delete_last_DAL_2(PersonDynamicArrayList *list){
	if(list->count != 0){
		list->count--;
	}
}
void delete_by_name_DAL_2(PersonDynamicArrayList *list, String name){ // last ocurrence
	int x, pos;
	
	for(x=list->count-1; x>0; --x) {
        if(strcmp(list->data[x].name, name) == 0) {
            pos=x;
            break;
        }
    }
    
    if(x<list->count) {
        for(x=pos; x<list->count-1; ++x) {
            list->data[x] = list->data[x+1];
        }
        list->count--;
    }
}

void display_DAL_2(PersonDynamicArrayList list){
	int x;
	printf("%15s | %s \n\n", "INDEX", "DATA");
	for(x=0; x<list.count; ++x){
		printf("%15d | ", x);
		displayPersonInfo(list.data[x]);
		printf("\n");
	}
	printf("\n %20s %d \n\n", "COUNT:", list.count);
}
////////////////////////////////////////////////////////////


/* Singly Linked List */
void insert_first_LL(PersonLinkedList *list, Person p){
	PersonLinkedList temp = (PersonLinkedList) malloc(sizeof(PersonNode));
	
	if(temp != NULL) {
        temp->next = *list;
        *list = temp;
        temp->elem = p;
    }
}

void insert_last_LL(PersonLinkedList *list, Person p){
	PersonLinkedList *current;
    PersonLinkedList temp = (PersonLinkedList) malloc(sizeof(PersonNode));

    if(temp != NULL) {
        for(current = list; *current != NULL; current = &(*current)->next) {}
        temp->next = NULL;
        *current = temp;
        temp->elem = p;
    }
}

void insert_after_LL(PersonLinkedList *list, Person p, String name){
	PersonLinkedList *current;
    PersonLinkedList temp = (PersonLinkedList) malloc(sizeof(PersonNode));

    if(temp != NULL) {
        for(current = list; *current != NULL && strcmp((*current)->elem.name, name) != 0; current = &(*current)->next) {}
        if(*current != NULL){
        	temp->next = (*current)->next;
        	(*current)->next = temp;
        	temp->elem = p;
		}
       
    }
}
void delete_first_LL(PersonLinkedList *list){
	PersonLinkedList  temp;
	
	if(*list != NULL) {
        temp = *list;
        *list = temp->next; 
        free(temp);
    }
}
void delete_last_LL(PersonLinkedList *list){
	PersonLinkedList *current, temp;

    if(*list != NULL) {
        for(; (*list)->next != NULL; list = &(*list)->next) {}
            temp = *list;
            *list = NULL; 
            free(temp);
    }  
}
void delete_by_city_LL(PersonLinkedList *list, String city){ // all ocurrences    
	PersonLinkedList *current, temp;

    if(*list != NULL) {
        for(current = list; *current != NULL; ) {
		if(strcmp((*current)->elem.city, city) == 0) {
            temp = *current;
            *current = temp->next; 
            free(temp);
        	}else{
        		current = &(*current)->next;
			}
		}
        
    }  
}
void display_LL(PersonLinkedList list){
	printf("[");

    for(;list != NULL; list = list->next) {
        displayPersonInfo(list->elem);
        if(list->next != NULL) {
            printf(" -> ");
        }
    }

    printf("]\n\n");
}
////////////////////////////////////////////////////////////////////////////////

/* Implement all VSpace conncept and Cusor Based List*/
void init_vspace(VSpace *vs){
	int x;
    for(x=MAX_VSPACE-1; x>=0; --x) {
        vs->data[x].next = x-1;
    }
    vs->avail = MAX_VSPACE-1;
}
Position alloc_space(VSpace *vs){
	Position avail = vs->avail;

    if(avail != -1) {
        vs->avail = vs->data[avail].next;
    }

    return avail;
	
}
void free_space(VSpace *vs, Position index){
	if(index != -1 && index < MAX_VSPACE) {
        vs->data[index].next = vs->avail;
        vs->avail = index;
    }
}
void insert_first_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){
	Position temp = alloc_space(vs);

    if(temp != -1) {
        vs->data[temp].elem = p;
        vs->data[temp].next = *list;
        *list = temp;
    }
}
void insert_last_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){
	PersonCusorBasedList *current, temp;
	temp = alloc_space(vs);
	
	 if(temp != -1) {
        for(current = list; *current != -1; current = &vs->data[*current].next) {}
        vs->data[temp].elem = p;
        vs->data[temp].next = *current;
        *current = temp;
    }
}
void insert_at_CBL(VSpace *vs, PersonCusorBasedList *list, Person p, int index){
	PersonCusorBasedList *current, temp;
	temp = alloc_space(vs);
	
	 if(temp != -1) {
        for(current = list; *current != -1 && *current != index; current = &vs->data[*current].next) {}
       
        if(*current != -1){
        	vs->data[temp].elem = p;
        	vs->data[temp].next = *current;
        	*current = temp;
		}
    }
}
void delete_first_CBL(VSpace *vs, PersonCusorBasedList *list){
	Position temp = *list;

    if(*list != -1) {
        *list = vs->data[*list].next;
        free_space(vs, temp);
    }
}
void delete_last_CBL(VSpace *vs, PersonCusorBasedList *list){
	PersonCusorBasedList *current;
	Position temp = *list;
	
        for(current = list; *current != -1 && vs->data[*current].next != -1; current = &vs->data[*current].next) {}
        
     	if(*current != -1) {  	
         	temp = *current;
            *current = vs->data[*current].next;
            free_space(vs, temp);
    }
}
void delete_by_sex_CBL(VSpace *vs, PersonCusorBasedList *list, char sex){ // all ocurrences
	PersonCusorBasedList *current;
    Position temp;

    current = list;
    while(*current != -1){
        if( sex == vs->data[*current].elem.sex){
            temp = *current;
            *current = vs->data[temp].next;
            free_space(vs, temp);
        }else{
        	current= &vs->data[*current].next;
		}
    }
}
void display_CBL(VSpace vs, PersonCusorBasedList list){
	Position avail = vs.avail;
	int x;
	
	printf("%15s | %15s\n", "INDEX", "ELEM");
	for(x=list; x!= -1; x = vs.data[x].next){
		printf("%15d | ", x);
		printf("          ");
		displayPersonInfo(vs.data[x].elem);
		printf("\n");
	}
	printf("\n");

}


