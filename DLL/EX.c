/**
 * Implementation of Doubly Linked List
 * Operations: Create list, insert value to last, insert value to first, insert at specific position, search a value, delete a value, traverse list forward and backward
 *
 * Average Time Complexity
 * Insert/delete at beginning  Θ(1)
 * Insert/delete at end    Θ(1)
 * Insert/delete in middle search time + Θ(1)
 * Space complexity: O(n)
 */

#include <stdio.h>
#include <stdlib.h>

struct linked_list {
	int data;
	linked_list *prev;
	linked_list *next;
};

typedef struct linked_list node;
node *front = NULL;
node *end = NULL;
void create();
void insert_at_first(int);
void insert_at_last(int);
void insert_at_position(int, int);
void delete_node(int);
void search(int);
void forward_traverse();
void backward_traverse();

int main() {
	int position, value;

    printf("\nCreate Linked List\n");
    create();
    printf("\nTraversing forward\n");
    forward_traverse();
    printf("\nTraversing backward\n");
    backward_traverse();

    printf("\nInsert a value at first\n");
    scanf("%d", &value);
    insert_at_first(value);
    printf("\nTraversing forward\n");
    forward_traverse();

    printf("\nInsert a value at last\n");
    scanf("%d", &value);
    insert_at_last(value);
    printf("\nTraversing backward\n");
    backward_traverse();

    printf("\nInsert a value at position\n");
    scanf("%d", &value);
    printf("\nEnter the position\n");
    scanf("%d", &position);
    insert_at_position(position, value);
    printf("\nTraversing forward\n");
    forward_traverse();

    printf("\nEnter a value to search it from List\n");
    scanf("%d", &value);
    search(value);

    printf("\nEnter a value to delete from list\n");
    scanf("%d", &value);
    delete_node(value);
    printf("\nTraversing forward\n");
    forward_traverse();

    return 0;
}

void create() {
    int value;

    while(1) {
        printf("Input a value, Enter -1 to exit\n");
        scanf("%d", &value);

        if (value == -1) {
            break;
        }

        insert_at_last(value);
    }
}

void insert_at_first(int value) {
	node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->data = value;
	temp->prev = NULL;
	temp->next = front;

	if(front == NULL) {
		end = temp;
	} else {
		front->prev = temp;
	}

	front = temp;
}

void insert_at_last(int value) {
	node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->data = value;
	temp->prev = end;
	temp->next = NULL;

	if(end == NULL) {
		front = temp;
	} else {
		end->next = temp;
	}

	end = temp;
}

void insert_at_position(int position, int value) {
	node *temp_node = front;
	node *new_node = (node*)malloc(sizeof(node));
	new_node->data = value;

	for (int i = 0; i < (position - 1); i++) {
		temp_node = temp_node->next;
	}

	if (temp_node == NULL) {
		printf("\nThis position is too far\n");
		return;
	}


	new_node->next = temp_node->next;
	new_node->prev = temp_node;
	temp_node->next = new_node;
}

void search(int value) {
    node *temp_node = front;
    int flag = 0;

    while (temp_node != NULL) {
        if (temp_node->data == value) {
            printf("%d is present in this list. Memory address is %p\n", value, temp_node);
            flag = 1;
            break;
        } else {
            temp_node = temp_node->next;
        }
    }

    if (flag == 0) {
        printf("Item not found\n");
    }
}

void delete_node(int value) {
	node *temp_node = front;
	int flag = 0;

    while (temp_node != NULL) {
        if (temp_node->data == value) {
            if (temp_node->prev == NULL) {
                front = temp_node->next;
                front->prev = NULL;
            } else if (temp_node->next == NULL) {
            	end = temp_node->prev;
            	end->next = NULL;
            } else {
            	temp_node->prev->next = temp_node->next;
            	temp_node->next->prev = temp_node->prev;
            }

            free(temp_node);
            printf("%d is deleted from list\n", value);
            flag = 1;
            break;
        }

        temp_node = temp_node->next;
    }

    if (flag == 0) {
        printf("%d is not in the list!\n", value);
    }
}

void forward_traverse() {
	node *temp = front;

	while(temp != NULL) {
		printf("\t%d", temp->data);
		temp = temp->next;
	}

	printf("\n");
}

void backward_traverse() {
	node *temp = end;

	while(temp != NULL) {
		printf("\t%d", temp->data);
		temp = temp->prev;
	}

	printf("\n");
}


