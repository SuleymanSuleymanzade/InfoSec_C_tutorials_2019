#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* create(int n){
	struct node *nn = (struct node*) malloc(sizeof(struct node));
	nn->next = NULL;
	nn->data = n;
	return nn;
}

void append(struct node **head, int data){
	struct node *nn = create(data);
	if(*head == NULL){
		*head = nn;
		return;
	}
	struct node *temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = nn;
}

void traverse(struct node *head){
	struct node* temp = head;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");

}
void traverse_rec(struct node* head){
    if (head == NULL){
        printf("\n");
        return;
    }
    printf("%d ", head->data);
    traverse_rec(head->next);
}

void push(struct node **head, int item){
	struct node *nn = create(item);
	if(*head == NULL){
		(*head)->next = nn;
		return;
	}
	nn->next = *head;
	*head = nn;
}

void delete_node(struct node **head, int item){
	struct node *temp = *head;
    if(temp->data == item){
        *head = (*head)->next;
        free(temp);
        return;
    }
	while(temp->next->data != item && temp->next != NULL){
		temp = temp->next;
	}
	if(temp->next == NULL)
		return;
	struct node* r_temp = temp->next;
	temp->next = temp->next->next;
	free(r_temp);
}

void delete_by_pos(struct node **head, int pos){
    
    struct node* temp = *head;
    struct node *prev = NULL;

    if(pos == 0){
        *head = (*head)->next;
        free(temp);
        return;
    }
    while(pos-- && temp != NULL){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;

    prev->next = temp->next;
    free(temp);
    
}


int main(){
    
	struct node* head = NULL;
	append(&head, 23);
	append(&head, 43);
	append(&head, 129);
	push(&head, 333);
	push(&head, 111);
	traverse_rec(head);

	delete_node(&head, 43);
	traverse_rec(head);
    delete_by_pos(&head, 2);
    traverse(head);

return 0;
}



