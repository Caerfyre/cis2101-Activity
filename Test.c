#include <stdio.h>
#include <string.h>
#include "Exercise1.h"

void visualizeQueue(CircularArrayQueue list);
void displayList(CircularArrayQueue list);
int main(void) 
{
    // To do code logic here.
    Person p1, p2, p3, p4, p5;
    p1=createPerson("mary", 'F', "cebu");
    p2=createPerson("tom", 'M', "carcar");
    p3=createPerson("susan", 'F', "antipolo");
    p4=createPerson("Bob", 'M', "davao");
	p5=createPerson("anne", 'F', "carcar");
	
	PersonDynamicArrayList DAL1;
	PersonDynamicArrayList *DAL2;
	PersonNode *personLL = NULL;
    
    PersonCusorBasedList list1 = -1;
    VSpace mySpace;
    
    
    CircularArrayQueue Qlist = create_array_queue();
    PersonLinkedList allFemales;
    PersonDynamicArrayList allMales;
    bool retval;
    int x;
    
    	/*CIRCULAR ARR QUEUE*/
    	x = get_queue_length(Qlist);
		printf("Queue length= %d\n", x);
    	retval = enqueue(&Qlist, p1);
    	printf("retval = %d\n", retval);
    	retval = enqueue(&Qlist, p2);
    	printf("retval = %d\n", retval);
    	retval = enqueue(&Qlist, p3);
    	printf("retval = %d\n", retval);
    	retval = enqueue(&Qlist, p4);
    	printf("retval = %d\n", retval);
    	retval = enqueue(&Qlist, p5);
    	printf("retval = %d\n", retval);

		x = get_queue_length(Qlist);
		printf("\nQueue length= %d\n", x);
		
		retval = dequeue(&Qlist);
		printf("retval= %d\n", retval);
		retval = dequeue(&Qlist);
		printf("retval= %d\n", retval);
		displayList(Qlist);
		
		displayPersonInfo(front(Qlist));
		
		x = get_queue_length(Qlist);
		printf("\n\nQueue length= %d\n", x);

		allFemales = get_all_females(Qlist);
		display_LL(allFemales); 
		
		allMales = remove_all_males(&Qlist);
		display_DAL(allMales); 
		/*CIRCULAR ARR QUEUE*/
	
		
    	/*STATIC ARRAY LIST*/
/*  	PersonStaticArrayList stat;
  	insert_first_SAL(&stat, p1);
  	insert_first_SAL(&stat, p2);
	insert_first_SAL(&stat, p3);
	insert_last_SAL(&stat, p4);
	insert_at_SAL(&stat, p5, 2);
	display_SAL(stat);
	
	delete_first_SAL(&stat);
	delete_last_SAL(&stat);
	delete_by_sex_SAL(&stat, 'F');
	display_SAL(stat);              */
		/*STATIC ARRAY LIST*/


		/*DYNAMIC ARRAY LIST 1*/

/*	init_DAL(&DAL1);
	insert_first_DAL(&DAL1, p1);
	insert_last_DAL(&DAL1, p2);
	insert_at_DAL(&DAL1, p3, 3);
	delete_first_DAL(&DAL1);
	delete_last_DAL(&DAL1);
	delete_by_city_DAL(&DAL1, "cebu"); 
	display_DAL(DAL1);                  */
		/*DYNAMIC ARRAY LIST 1*/
	
	
		/*DYNAMIC ARRAY LIST 2*/
/*	init_DAL_2(&DAL2);
	insert_first_DAL_2(*(&DAL2), p1);
	insert_first_DAL_2(*(&DAL2), p2);
	insert_last_DAL_2(*(&DAL2), p3);
	insert_at_DAL_2(*(&DAL2), p4, 2);

	display_DAL_2(*DAL2);            */
		/*DYNAMIC ARRAY LIST 2*/


		/*LINKED LIST */
/*	insert_first_LL(&personLL, p1);
	insert_first_LL(&personLL, p2);
	insert_first_LL(&personLL, p3);
	insert_last_LL(&personLL, p4);
	insert_last_LL(&personLL, p5);
	display_LL(personLL);
	
	delete_by_city_LL(&personLL, "carcar"); 
	display_LL(personLL);
	
	delete_first_LL(&personLL);
	insert_after_LL(&personLL, p5, "mary");
	display_LL(personLL);
	
	delete_last_LL(&personLL);
	display_LL(personLL);       */
		/*LINKED LIST */
		
		
		/*CURSOR BASED*/
/*    init_vspace(&mySpace);
	insert_first_CBL(&mySpace, &list1, p1);
	insert_first_CBL(&mySpace, &list1, p2);
	insert_last_CBL(&mySpace, &list1, p3);
	insert_last_CBL(&mySpace, &list1, p4);
	display_CBL(mySpace, list1);
	delete_first_CBL(&mySpace, &list1);
	delete_last_CBL(&mySpace, &list1);
	delete_by_sex_CBL(&mySpace, &list1, 'F'); 
	insert_at_CBL(&mySpace, &list1, p5, 28);
	display_CBL(mySpace, list1);              */
	/*CURSOR BASED*/
	
    return 0;
}



