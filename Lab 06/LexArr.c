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

int front(Node *head)
{
    if (head)
        return head->data;
    return -1;
}

Node *push_back(Node *tail, int x)
{
    Node *ptr = createNode(x);
    tail->next = ptr;
    ptr->prev = tail;
    tail = ptr;
    return tail;
}

Node *push_front(Node *head, int x)
{
    Node *ptr = createNode(x);
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
    return head;
}

Node *returnTail(Node *head)
{
    Node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    return ptr;
}

// Function definition goes here
int main(void)
{
    // Function calls go here
    Node *head = readList();

    Node *newHead = NULL;
    newHead = addToList(newHead, head->data);
    Node *newTail = returnTail(newHead);
    Node *ptr = head->next;
    while (ptr != NULL)
    {
        if (ptr->data > newHead->data)
            newTail = push_back(newTail, ptr->data);
        else
            newHead = push_front(newHead, ptr->data);

        ptr = ptr->next;
    }

    printList(newHead);
    freeList(head);
    freeList(newHead);

    return 0;
}