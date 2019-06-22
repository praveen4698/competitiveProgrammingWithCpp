#include<stdio.h>
#include<stdlib.h>

    struct node
    {
        int data;
        struct node* next;
    };
    void push(struct node **head_ref,int data)
    {
       struct node *new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = *head_ref;
        *head_ref = new_node;

    }
    void deleteNode(struct node **head_ref)
    {
        struct node *temp = *head_ref;
        *head_ref = temp->next;
        free(temp);
    }
    void printList(struct node *head)
    {
        while (head != NULL)
        {
            printf(" %d ", head->data);
            head = head->next;
        }
    }
    int main()
    {
    /* Start with the empty list */
        struct node *head = NULL;

        push(&head, 7);
        push(&head, 1);
        push(&head, 3);
        push(&head, 2);

        puts("Created Linked List: ");
        printList(head);
        deleteNode(&head);
        puts("\nLinked List after Deletion of 1: ");
        printList(head);
        return 0;
    }
