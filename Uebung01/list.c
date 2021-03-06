#include <stdio.h>
#include <stdlib.h>
#include "list.h"

char *getEnumName(enrolled in)
{
	switch (in)
	{
	case IFM:
		return "IFM";
		break;
	case ELM:
		return "ELM";
	}
    return NULL;
}

struct node{
	struct node *prev;
	struct node *next;
	student data;
} node;

struct node *new_list(student data)
{
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return new;
}

struct node *getLastElement(struct node* list){
	struct node* current = list;
	while(current->next != NULL){
		current = current->next;
	}
	return current;
}

void insert_next(struct node *list, student data)
{
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = data;
	new->prev = list;
	new->next = list->next;
	list->next = new;
	new->next->prev = new;
}

void append(struct node* list,student element){
	struct node *new = (struct node *)malloc(sizeof(struct node));
	struct node *lastelement = getLastElement(list);
	new->data = element;
	new->prev = lastelement;
	new->next = NULL;
	lastelement->next = new;
}

void delete(struct node *element, int deleteStudent)
{
	element->next->prev = element->prev; /*setzt linken Wert des rechten Nachbarn auf linken Wert von element*/
	element->prev->next = element->next; /*setzt rechten Wert des linken Nachbarn auf rechten Wert von element*/
	if(deleteStudent > 0) {
		student *p = &(element->data);
		free(p);
	}
	free(element);
}

void clear(struct node *list, int deleteStudent) {
	struct node* nextElement = list;
	while(nextElement != NULL) {
		struct node* ne = nextElement->next;
		delete(nextElement, deleteStudent);
		nextElement = ne;
	}
}

void print_list(struct node *list)
{
	struct node* next = list;
	while (next != NULL)
	{
		printf("name: %s | enrolled: %s | credit points: %i\n", next->data.name, getEnumName(next->data.enrolled), next->data.cps);
		next = next->next;
	}
}

int count(struct node *list) {
	int count = 0;
	struct node* current = list;
	while(current->next != NULL){
		current = current->next;
		count ++;
	}
	return count;
}

struct node* filterByStudiengang(struct node* list, enrolled gang) {
	struct node* newList = NULL;
	struct node* current = list;
	while(current->next != NULL){
		if(current->data.enrolled == gang) {
			if(newList == NULL) {
				newList = new_list(current->data);
			} else {
				append(newList, current->data);
			}
		}
		current = current->next;
	}
	return newList;
}