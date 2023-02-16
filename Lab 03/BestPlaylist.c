#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node_t
{
    int data;
    struct Node_t *next;
    struct Node_t *prev;
};
typedef struct Node_t Node;

// Creates a new node with given value and returns a pointer to it
Node *createNode(int value)
{
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Creates a new node with given value and adds it to
// the back of the given singly linked list,
// returns a pointer to the newly created node
Node *addToList(Node *head, int val)
{
    Node *newNode = createNode(val);
    if (head == NULL)
    {
        return newNode;
    }
    Node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newNode;
    newNode->prev = cur;
    return newNode;
}

// Creates a singly linked list by reading input and
// returns a pointer the head of the newly created linked list
Node *readList()
{
    int n;
    scanf("%d", &n);
    Node *head = NULL;
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        if (head == NULL)
        {
            head = addToList(head, x);
        }
        else
        {
            addToList(head, x);
        }
    }
    return head;
}

// Prints the values stored in the nodes of the given singly linked list
void printList(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}

// Frees the memory dynamically allocated to
// all the nodes of the given singly linked list
void freeList(Node *head)
{
    Node *cur, *nxt;
    cur = head;
    while (cur != NULL)
    {
        nxt = cur->next;
        free(cur);
        cur = nxt;
    }
}

int countList(Node *head)
{
    Node *ptr = head;
    int c = 0;
    while (ptr != NULL)
    {
        c++;
        ptr = ptr->next;
    }
}

void printCur(Node *cur)
{
    printf("%d\n", cur->data);
}

Node *playNext(Node *cur)
{
    if (cur->next != NULL)
        cur = cur->next;
    return cur;
}

Node *playPrev(Node *cur)
{
    if (cur->prev != NULL)
        cur = cur->prev;
    return cur;
}

// Function definition goes here
int main(void)
{
    Node *head = readList();
    Node *cur = head;
    int choice;
    do
    {
        scanf("%d", &choice);
        if (choice == 1)
        {
            int n;
            scanf("%d", &n);
            addToList(head, n);
        }
        else if (choice == 2)
        {
            printCur(cur);
        }
        else if (choice == 3)
        {
            cur = playNext(cur);
        }
        else if (choice == 4)
        {
            cur = playPrev(cur);
        }
    } while (choice != 5);

    freeList(head);

    return 0;
}