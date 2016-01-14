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
	(*(int *)e = *(int *)e+1);
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

void test_for_get_element_at_given_index(){
	LinkedList list = createList();
	int num[10] = {32,43,223,54,76,7,45,3,4,23};
	for (int i = 0; i < 10; ++i){
		add_to_list(&list,&num[i]);
	};
	 void *ele1 = getElementAt(list,4);
	 void *ele2 = getElementAt(list,6);
	 void *ele3 = getElementAt(list,11);
	 assert(*(int *)ele1==76);
	 assert(*(int *)ele2==45);
	 assert(ele3==NULL);
}

void test_for_get_indexof_given_pointer(){
	LinkedList list = createList();
	int num[10] = {32,43,223,54,76,7,45,3,4,23};
	for (int i = 0; i < 10; ++i){
		add_to_list(&list,&num[i]);
	};
	assert(indexOf(list,&num[5])==5);
	assert(indexOf(list,&num[10])==-1);
};

void test_deleteElementAt_when_element_is_in_middle(){
	LinkedList list = createList();
	int num[10] = {32,43,223,54,76,7,45,3,4,23};
	for (int i = 0; i < 10; ++i){
		add_to_list(&list,&num[i]);
	};
	assert(*(int *)deleteElementAt(&list,3)==54);
	assert(*(int *)getElementAt(list,3)==76);
};

void test_deleteElementAt_when_element_is_in_beginning(){
	LinkedList list = createList();
	int num[10] = {32,43,223,54,76,7,45,3,4,23};
	for (int i = 0; i < 10; ++i){
		add_to_list(&list,&num[i]);
	};
	assert(*(int *)deleteElementAt(&list,0)==32);
	assert(*(int *)getElementAt(list,0)==43);
};

void test_deleteElementAt_when_element_is_in_end(){
	LinkedList list = createList();
	int num[10] = {32,43,223,54,76,7,45,3,4,23};
	for (int i = 0; i < 10; ++i){
		add_to_list(&list,&num[i]);
	};
	assert(*(int *)deleteElementAt(&list,9)==23);
	assert(getElementAt(list,9)==0);
};
int isEven(void *num,void *hint){
	return *(int *)num%2==0;
}
void test_for_filter_even_number_from_list(){
	LinkedList list = createList();
	void *hint;
	int num[10] = {32,43,223,54,76,7,45,3,4,23};
	for (int i = 0; i < 10; ++i){
		add_to_list(&list,&num[i]);
	};
	LinkedList list1 =  filter(list,&isEven,&hint);
	Element *ele = list1.head;
	int filteredValue[4] = {32,54,76,4};
	int i = 0;
	while(ele!=NULL){
		assert(*(int *)ele->value==filteredValue[i]);
		ele = ele->next;
		i++;
	}
	assert(list1.length==4);
}
