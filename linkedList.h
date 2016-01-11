typedef void (*ElementProcessor)(void *);

typedef struct element{
	void* value;
	struct element *next;
}Element;

typedef struct list{
	struct element *head;
	struct element *tail;
	int length;
}LinkedList;

LinkedList createList(void);

int add_to_list(LinkedList *,void *);

void *get_first_element(LinkedList list);

void *get_last_element(LinkedList list);


void forEach(LinkedList, ElementProcessor e);