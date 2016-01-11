#include <stdio.h>
#include "LinkedList.c"
#include "assert.h"

void test_create_list(){
	LinkedList list = createList();
	assert(list.head==NULL);
	assert(list.tail==NULL);
	assert(list.length==0);
}

void test_add_element_to_list(){
	LinkedList list = createList();
	int ele1 = 1;
	add_to_list(&list,&ele1);
	assert(*(int *)list.head->value==1);
	assert(*(int *)list.tail->value==1);
	assert(list.length==1);

	int ele2 = 35;
	add_to_list(&list,&ele2);
	assert(*(int *)list.head->value==1);
	assert(*(int *)list.tail->value==35);
	assert(list.length==2);
}

void test_to_get_first_element_of_list(){
	LinkedList list = createList();
	int ele1 = 25;
	int ele2 = 55;
	int ele3 = 35;
	int ele4 = 15;
	int ele5 = 5;
	add_to_list(&list,&ele1);
	add_to_list(&list,&ele2);
	add_to_list(&list,&ele3);
	add_to_list(&list,&ele4);
	add_to_list(&list,&ele5);
	void *head = get_first_element(list);
	assert(*(int *)head==25);
};

void test_to_get_last_element_of_list(){
	LinkedList list = createList();
	int ele1 = 25;
	int ele2 = 55;
	int ele3 = 35;
	int ele4 = 15;
	int ele5 = 5;
	add_to_list(&list,&ele1);
	add_to_list(&list,&ele2);
	add_to_list(&list,&ele3);
	add_to_list(&list,&ele4);
	add_to_list(&list,&ele5);
	void *head = get_last_element(list);
	assert(*(int *)head==5);
}

void increment(void *e){
	*(int *)e = *(int *)e+1;
}

void test_for_forEach_function(){
	LinkedList list = createList();
	int num[10] = {32,43,223,54,76,7,45,3,4,23};
	for (int i = 0; i < 10; ++i){
		add_to_list(&list,&num[i]);
	}
	forEach(list,increment);
	assert(*(int *)list.head->value==33);
	assert(*(int *)list.tail->value==24);
}