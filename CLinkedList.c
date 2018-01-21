#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

//linked list
struct node
{
    int data;
    struct node *next; 
};

void push(struct node** head_ref, int new_data)
{
    //allocate memory
    struct node* new_node = (struct node*)malloc(sizeof (struct node));

    //set data
    new_node->data = new_data;

    //make next of new_node as head
    new_node->next = (*head_ref);

    //head points to the new_node
    (*head_ref) = new_node;
}

void sort(struct node *start) //bubblesort
{
    int i, is_swapped;
    struct node *ptr1;
    struct node *lptr = NULL;

    //if empty
    if(start == NULL)
    {
        return;
    }

    do{
        is_swapped = 0;
        ptr1 = start;

        while(ptr1->next != lptr)
        {
            if(ptr1->data > (ptr1->next)->data) //if current data is larger than the next node's data
            {
                //swap
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                is_swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }while(is_swapped);

}

void print(struct node *node1)
{
  while (node1 != NULL)
  {
     printf("%d ", node1->data);
     node1 = node1->next;
  }
  printf("\n");
}

void main()
{
    /*
    int num;
    char name[100];

    printf("What is your name? ");
    fgets(name, 100, stdin);

    name[strlen(name)-1] = '\0'; //removes trailing newline from fgets

    printf("What number do you like? ");
    scanf("%d", &num);

	printf("Hi %s!\n", name);
	printf("You favorite number is %d\n", num);
    */

    struct node* head = NULL;

    push(&head, 6);
    push(&head, 9);
    push(&head, 7);
    push(&head, 3);
    push(&head, 5);
    sort(head);
    print(head);

}