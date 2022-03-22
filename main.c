#include <stdio.h>
#include <stdlib.h>

typedef struct tagSingleLinkedList {
    int data; 
    struct tagSingleLinkedList* next;
}SLLI; 


SLLI* AddItemToFront(SLLI* head, int dataToAdd);

SLLI* AddItemToEnd(SLLI* head, int dataToAdd);
void PrintList(SLLI* head);

SLLI* DeleteFromList(SLLI* head, int dataToRemove);

void PrintListReverse(SLLI* head);
void PrintListRecursive(SLLI* head);

SLLI* ReverseList(SLLI* head);
SLLI* DestructivelyReverseList(SLLI* head);


SLLI* AddItemToEnd(SLLI* head, int dataToAdd)
{
    SLLI* last;


    SLLI* pItem = (SLLI*) malloc(sizeof(SLLI));
    if (NULL == pItem) {
        printf("Cannot allocate memory for the new item!!!\n");
        exit(1);
    }

    pItem->data = dataToAdd;

    pItem->next = NULL;

    if (NULL == head)
        return pItem;

	last = head;
	while (NULL != last->next)
        last = last->next;

    last->next = pItem;

    return head;
}

void PrintList(SLLI* head)
{
    while(NULL != head) {
        printf("Data : %d\n", head->data);
        head = head->next;
    }

}

void PrintListRecursive(SLLI* head)
{
    if (NULL != head) {
        printf("(PrintListRecursive) Data : %d\n", head->data);
        PrintListRecursive(head->next);
    }
}

void PrintListReverse(SLLI* head)
{
    if (NULL == head) 
        return;
    PrintListReverse(head->next);
    printf("(PrintListReverse) Data : %d\n", head->data);

SLLI* ReverseList(SLLI* head)
{
    if (NULL == head)
        return head;
  
    SLLI* temp = ReverseList(head->next);
    return AddItemToEnd(temp, head->data);
}
SLLI* AddItemToFront(SLLI* head, int dataToAdd)
{
    SLLI* pItem = (SLLI*) malloc(sizeof(SLLI));
    if (NULL == pItem) {
        printf("Cannot allocate memory for the new item!!!\n");
        exit(1);
    }

    pItem->data = dataToAdd;
    pItem->next = head;
    return pItem;
}


SLLI* AddNewItemToFront(SLLI* head, SLLI* pItem)
{
    pItem->next = head;

    return pItem;
}

SLLI* ReverseListUsignAddItemToFront(SLLI* head)
{

    SLLI* newHead = NULL;

    while (NULL != head) {
        SLLI* next = head->next;
        head->next = NULL;
        newHead = AddNewItemToFront(newHead, head);
        head = next;
    }
    return newHead;
}

SLLI* DeleteFromList(SLLI* head, int dataToRemove)
{
    if (NULL != head) {
        SLLI* temp = head;
        SLLI* prev = NULL;
        while (NULL != temp && temp->data != dataToRemove) {
            prev = temp;
            temp = temp->next;
        }
        if (NULL == temp)
            return head;
        else {

            if (temp == head) {
                SLLI* newHead = temp->next;
                free(temp);
                return newHead;
            } else {
                prev->next = temp->next;
                free(temp);

                return head;
            }

        }
    }

    return head;
}



int main(int argc, char** argv)
{
    SLLI* head = NULL; 
    int i;

    for (i = 10; i > 0; --i)
        head = AddItemToEnd(head, i);

    printf("Print list...\n");
    PrintList(head);

    printf("----------------------------------\n");
  
    head = ReverseListUsignAddItemToFront(head);
    printf("Print list after REVERSE operation...\n");
    PrintList(head);


//     printf("Print list in REVERSE ORDER...\n");
//     PrintListReverse(head);

//     head = AddItemToFront(head, 10);
//     PrintList(head);

//     printf("Remove the last item\n");
//     head = DeleteFromList(head, 1);
//     PrintList(head);
//
//     printf("Remove the first item\n");
//     head = DeleteFromList(head, 10);
//     PrintList(head);
//
//
//     printf("Remove an inner item\n");
//     head = DeleteFromList(head, 5);
//     PrintList(head);
//
//
//     printf("Remove an item whish is NOT in the list\n");
//     head = DeleteFromList(head, 15);
//     PrintList(head);

}
