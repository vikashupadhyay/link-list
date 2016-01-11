#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"


LinkedList createList(void){
	LinkedList *myList = (LinkedList *)malloc(sizeof(LinkedList));
	myList->head =  NULL;
	myList->tail = NULL;
	myList->length=0;
	return *myList;
};

int add_to_list(LinkedList *list,void *element){
	Element *newElement = (Element *)malloc(sizeof(Element));
	newElement->value =  element;
	if(list->length==0){
		list->head=newElement;
		list->tail = newElement;
		newElement->next = NULL;
	}else{
		list->tail->next = newElement;
		list->tail= newElement;
	}
	list->length++;
	return list->length;
};

void *get_first_element(LinkedList list){
	return list.head->value;
};


void *get_last_element(LinkedList list){
	return list.tail->value;
};

void forEach(LinkedList list, ElementProcessor e){
	Element *ele = list.head;
	while(ele!=NULL){
		e(ele->value);
		ele = ele->next;
	}
};
