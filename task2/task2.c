#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
};

struct node *head = NULL;
struct node *current = NULL;
struct node *temp = NULL;
int i;

void add(int item) {
	current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->data = item;
	current->next = malloc(sizeof(struct node));
	current->next->next = NULL;
}

void set(int index, int item) {
	current = head;
	for (i = 0; i < index; i++) {
		current = current->next;
	}
	current->data = item;
	
}

void insert(int index, int item) {
	current = head;
	if (index == 0) {
		temp = malloc(sizeof(struct node));
		temp->data = item;

		temp->next = head;

		head = temp;
		return;
	}
	for (i = 0; i < index - 1; i++) {
		current = current->next;
	}

	temp = malloc(sizeof(struct node));
	temp->data = item;

	temp->next = current->next;

	current->next = temp;

}

void show() {
	current = head;
	printf("\n");
	while (current->next != NULL) {
		printf_s("%d ", current->data);
		current = current->next;
	}
}

void size() {
	current = head;
	int temp = 0;
	while (current->next != NULL) {
		temp++;
		current = current->next;
	}
	printf_s("\nsize: %d\n", temp);
}

void get(int index) {
	current = head;
	for (i = 0; i < index; i++) {
		current = current->next;
	}
	printf_s("GET: %d\n", current->data);
}

void removeFromList(int index) {
	current = head;

	if (index == 0) {
		head = head->next;
	}

	for (i = 0; i < index - 1; i++) {
		current = current->next;
	}

	current->next = current->next->next;

}

int main() {
	head = malloc(sizeof(struct node));
	head->next = NULL;
	
	add(8);
	add(5);
	add(7);

	show();
	
	set(2, 100);

	insert(3, 200);

	add(9);

	show();

	size();

	get(0);

	removeFromList(2);

	show();

	return 0;
}