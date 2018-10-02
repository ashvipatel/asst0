#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct _Record
{
    void *key;
    struct _Record* next;
} Record;

int type;


Record* Compare(Record* first, Record* second);

void Divide(Record* source, Record** frontRef, Record** backref);

void MergeSort(Record** headRef) {

    Record *head = *headRef;
    Record * first;
    Record *second;


    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    Divide(head, &first, &second);

    MergeSort(&first);
    MergeSort(&second);

    *headRef = Compare(first, second);
}




Record* Compare(Record* first, Record* second){

    if(type == 2) {

        Record *result = NULL;
        if (first == NULL)
            return (second);
        else if (second == NULL)
            return (first);

        char *stringOne = (char *) first->key;
        char *stringTwo = (char *) second->key;

        int i;
        if (strlen(stringOne) <= strlen(stringTwo)) {
            for (i = 0; i < strlen(stringOne); i++) {
                if (stringOne[i] < stringTwo[i]) {
                    result = first;
                    result->next = Compare(first->next, second);
                    break;
                } else if (stringOne[i] > stringTwo[i]) {
                    result = second;
                    result->next = Compare(first, second->next);
                    break;
                }


            }
        }

        if (strlen(stringOne) > strlen(stringTwo)) {
            for (i = 0; i < strlen(stringTwo); i++) {
                if (stringOne[i] < stringTwo[i]) {
                    result = first;
                    result->next = Compare(first->next, second);
                    break;
                } else if (stringOne[i] > stringTwo[i]) {
                    result = second;
                    result->next = Compare(first, second->next);
                    break;
                }


            }
        }

        return (result);

    }

    if(type ==0){

        Record* result = NULL;



        if (first == NULL)
            return (second);
        else if (second == NULL)
            return (first);

        if (first->key <= second->key) {
            result = first;
            result->next = Compare(first->next, second);
        } else {
            result = second;
            result->next = Compare(first, second->next);
        }
        return (result);
    }

    

}







int Length(Record* head){
    int count = 0;
    Record* current = head;
    while(current != NULL){
        count++;
        current = current->next;
    }
    return count;
}


void Divide(Record* start, Record** frontPtr, Record** backPtr) {
        int len = Length(start);
         if (len < 2) {
           *frontPtr = start;
           *backPtr = NULL;
           return;
          }

          Record *current = start;
          int newCount = (len - 1) / 2;
          for (int i = 0; i < newCount; i++)
                current = current->next;

        *frontPtr = start;
        *backPtr = current->next;
        current->next = NULL;


}

void printList(Record *node) {
    while (node != NULL) {
        printf("%s ", node->key);
        node = node->next;
    }
}

void push (Record ** head_ref, void* new_key) {
    Record *new_node = (Record *) malloc(sizeof(Record));
    new_node->key = new_key;
    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

    int main(){

    Record* first = NULL;

        push(&first,  "bye");

        push(&first, "aashvi");
        push(&first,  "Cheese");
        push(&first, "aaaas");
        push(&first,  "1000 movie1hello");


        MergeSort(&first);

    printf("Sorted linked List is: \n");
    printList(first);
    return 0;


}
