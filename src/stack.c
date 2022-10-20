#include "stack.h"

void initialize(stack* s){
  //implement initialize here
  s->head = NULL; //The first element of the stack is designated as an element that does not have a value, this will make it easier to determine if the stack is empty.
}

void push(int x, stack* s){
    //implement push here

    /*If the current stack element is the first to be pushed in to the stack, then it is simply given a value, and the next value (being the head of the stack) is thus NULL*/
    if (s->head == NULL){
      s->head = (node *) malloc(sizeof(node));
      s->head->next = NULL;
      s->head->data = x;
    }
    else{
      node *temp = s->head; //Temporary node pointer, that is set to be a copy of the node in the stack element.

      /*This moves the copy of the stack element (temp) to the front of the stack.
      This makes it so that the stack elements will point "upwards", with the bottom most element
      being the first element put into the stack, and the top most element being the latest
      element to be put into the stack, where the top element will always point to a NULL head element*/
      while (temp->next != NULL){
        temp = temp->next;
      }

      /*Makes the place right before the head into a node pointer itself,
      thus it can be given data, which is the x value given, and it can
      be set so that the element after (being the head element) will be
      given the value NULL again.*/
      temp->next = (node*) malloc(sizeof(node));
      temp->next->next = NULL;
      temp->next->data = x;
    }
    //Previous attempts of making a bottom up stack, where the last element input
    //would point to the earlier input element, and thus the first element input
    //is the one that points at the NULL head.
    /*else{
      stack * top = malloc(sizeof(stack));
      node * top_check = malloc(sizeof(node));

      top = s->head;
      top_check = s->head->next;

      while (top != top_check){
        s->head->next = s->head;
        top = s->head->next;
        top_check = s->head;
      }

      top->head->data = x;
      top->head->next = s->head;
    }
*/
/*
    node *temp = malloc(sizeof(node));


    temp->data = x;
    temp->next = s->head;
    s->head = temp;

    */
}

int pop(stack* s){
    // implement pop here
    /*Make two different pointers, one that copies the node element of the stack element
    that we want to pop and one that holds the value of the previous node element checked.*/
    node *temp = malloc(sizeof(node));
    temp = s->head;
    node *prev_temp;

    /*Makes it so that the top most element is "temp", as the value after temp being NULL
    means that it is pointing to the head element. The loop updates by giving the value just
    checked to prev_temp and then updates the temp element, to be the next element in the stack
    thus it moves through all the stack elements, to the top element, which is the last element input,
    which is the one we want, as that is the only element that can be popped.*/
    while (temp->next != NULL){
      prev_temp = temp;
      temp = temp->next;
    }
    /*Store the data that we want popped in an integer*/
    int popped_data = temp->data;

    /*Makes it so that the element that is popped becomes NULL, thus making it the new head of the stack*/
    if (temp == s->head){
      s->head = NULL;
    }
    else{
      prev_temp->next = NULL;
    }

    /*Free memory allocated to the copy element*/
    free(temp);
    /*Return the data that we wanted popped*/
    return popped_data;
    /*
    if (s->head->next == NULL){
      printf("The stack is empty, cannot pop data.");
    }
    else{
      stack *l = malloc(sizeof(stack));
      node *p = malloc(sizeof(node));

    l->head = s->head;
    p->data = l->head->data;
    s->head = s->head->next;
    free(l);
  return p->data;*/
  

      /*stack *temp = malloc(sizeof(stack));
      temp = s;
      s->head = s->head->next;
      free(temp);
      return temp->head->data;*/

      /*stack * temp = s;
      int x = temp->head->data;
      int f = x;
      s->head = temp->head->next;
      return 5;*/
    }
    


bool empty(stack* s)
{
  //implement empty here
  /*Checks if the next element in the list is NULL, if it is
  then it is because there are no elements in the stack*/
  if (s->head->next == NULL){
    return true;
  }
  return false;
  }


bool full(stack* s) {
    //implement full here
    /*Cannot be implemented*/
  return false;
}
