#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
	int size;
	struct DLink *firstLink;// this is front sentinel
	struct DLink *lastLink;// this is back sentineiel
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) {
  /* FIXME: you must write this */
    // create sentinel pointers here
    // point them to each other
    assert(lst != NULL);
    lst->size = 0;
    lst->firstLink = (struct DLink *) malloc(sizeof(struct DLink));
    assert(lst->firstLink != 0);
    lst->lastLink = (struct DLink *) malloc(sizeof(struct DLink));
    assert(lst->lastLink != 0);
    lst->firstLink->next = lst->lastLink;// first link is front sentinenl and you're linking ot back sentinel
    lst->lastLink->prev = lst->firstLink;// last link is back sentinel and you're linking ot front sentinel
}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
	/* FIXME: you must write this */
    // call new struct for creating of newlink
    // malloc it
    // assign value, and pointers
    // point previous element to newLink
    
    
	assert(lst != NULL);
	assert(l != NULL);
    
	struct DLink* new = (struct DLink *)(malloc(sizeof(struct DLink)));
	assert(new != 0);
    new->value = v;
	new->prev = l->prev;
	new->next = l;
	
    l->prev = new;
    l->prev->next = new;// l->lastlink->prev= newLink


}


/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct linkedList *lst, TYPE e)
{
    
	/* FIXME: you must write this */
	assert(lst != NULL);
	_addLinkBefore(lst, lst->firstLink->next, e);
    lst->size++;
	
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addBackList(struct linkedList *lst, TYPE e) {
  
	/* FIXME: you must write this */
    assert(lst != NULL);
    _addLinkBefore(lst, lst->lastLink, e);
    lst->size++;
    
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct linkedList *lst) {
	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
	assert(lst != NULL);
	assert(!isEmptyList(lst));
	return(lst->firstLink->next->value);
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct linkedList *lst)
{
	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
	assert(lst != NULL);
	assert(!isEmptyList(lst));
	return(lst->lastLink->prev->value);

}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct linkedList *lst, struct DLink *l)
{

	/* FIXME: you must write this */
	assert(lst != NULL);
	assert(l != NULL);
	l->prev->next = l->next;
	l->next->prev = l->prev;
	free(l);
	lst->size--;
	
}

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *lst) {
   	/* FIXME: you must write this */
	assert(lst != NULL);
	assert(!isEmptyList(lst));
	_removeLink(lst, lst->firstLink->next);
    
}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct linkedList *lst)
{	
	/* FIXME: you must write this */
    
	assert(lst != NULL);
	assert(!isEmptyList(lst));
	_removeLink(lst, lst->lastLink->prev);

	
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(struct linkedList *lst) {
 	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
 	assert(lst != NULL);
	return(lst->size == 0);
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{
	/* FIXME: you must write this */
	assert(lst != NULL);
	assert(!isEmptyList(lst));
	struct DLink *counter = lst->firstLink->next;
	assert(counter != 0);
	while(counter != lst->lastLink){
		printf("%d\n", counter->value);
		counter = counter->next;
	}

}

/* 
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
	/* FIXME: you must write this */
	assert(lst != NULL);
//	assert(!isEmptyList(lst));
	addBackList(lst, v);
    
    
}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) {
	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
	assert(lst != NULL);
	assert(!isEmptyList(lst));
	// sentinel points to what you're looking for
    struct DLink* i = lst->firstLink->next;
	assert(i != 0);
	while(i != lst->lastLink){
		if(i->value == e)
			return(1);
		i = i->next;
	}
	return(0);
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) {
	/* FIXME: you must write this */
	assert(lst != NULL);
	assert(!isEmptyList(lst));
	struct DLink* i = lst->firstLink;
	assert(i != 0);
	while(i != lst->lastLink){
		i = i->next;
		if(i->value == e){
			_removeLink(lst, i);
			break;
		}
	}
    
}
