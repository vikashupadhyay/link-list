
typedef void (*ElementProcessor)(void *);

typedef int(MatchFunc)(void*, void*);

typedef void ConvertFunc(void* hint, void* sourceItem, void* destinationItem);

typedef void* Reducer(void* hint, void* previousItem, void* item);

typedef struct element{
	void* value;
	int index;
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

void * getElementAt(LinkedList, int );

int indexOf(LinkedList, void *);

void * deleteElementAt(LinkedList *, int);

int indexOf(LinkedList, void *);

LinkedList  filter(LinkedList list, MatchFunc *match, void *hint);

LinkedList reverse(LinkedList);

int asArray(LinkedList, void **, int);

void *reduce(LinkedList, Reducer*, void *hint, void *initialValue);

