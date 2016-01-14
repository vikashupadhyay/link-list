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
	newElement->next = NULL;
		newElement->index = list->length;
	if(list->length==0){
		list->head=newElement;
		list->tail = newElement;
		newElement->next = NULL;
	}else{
		list->tail->next = newElement;
		list->tail= newElement;
	}
	list->length++;
	free(newElement->next);
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
	free(ele);
};

void * getElementAt(LinkedList list, int index){
	Element *ele = list.head;
	while(ele!=NULL){
		if(ele->index==index){
			return ele->value;
		}
		ele= ele->next;
	}
	free(ele);
	return NULL;
};

int indexOf(LinkedList list, void *value){
	Element *ele = list.head;
	int i = 0;
	while(ele!=NULL){
		if(ele->value==value) return i;
		i++;
		ele = ele->next;
	}
	free(ele);
	return -1;
};
void decrementIndex(Element *ele){
	while(ele){
		ele->index--;
		ele = ele->next;
	}
}

void *deleteFirstElement(LinkedList *list){
	Element *ele = list->head;
	list->head = ele->next;
	decrementIndex(ele);
	free(ele);
	return ele->value;
}

void * deleteElementAt(LinkedList *list, int index){
	Element *ele = list->head;
	void *deletedElement = NULL;
	if(index==0) return deleteFirstElement(list);
	Element *preEle = list->head;
	while(ele!=NULL){
		if(ele->index==index){
			preEle->next = ele->next;
			deletedElement = ele->value;
			decrementIndex(ele);
			free(ele);
			if(index == list->length-1)
				list->tail = preEle;
			return deletedElement;
		}
		preEle = ele;
		ele = ele->next;
	}
	return deletedElement;
};

LinkedList  filter(LinkedList list, MatchFunc *match, void *hint){
	LinkedList newList = createList();
	Element *ele = list.head;
	while(ele!=NULL){
		if(match(ele->value,hint))
			add_to_list(&newList,ele->value);
		ele = ele->next;
	}
	return newList;
};


