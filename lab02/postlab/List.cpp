/*
FILENAME: "List.cpp"

Author: Samuel Campbell
Date: 09/07/2022

Lab 2 Post-Lab

*/
#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"

using namespace std;

List::List()
{
    head = new ListNode();
    tail = new ListNode();

    head->next = tail;
    // head->previous=NULL;
    tail->previous = head;
    // tail->next=NULL;

    count = 0;
}

List::List(const List &source)
{ // Copy Constructor
    head = new ListNode();
    tail = new ListNode();

    head->next = tail;
    tail->previous = head;
    count = 0;

    ListItr iter(source.head->next);

    while (!iter.isPastEnd())
    { // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List::~List()
{
    makeEmpty();
    delete head;
    delete tail;
}

List &List::operator=(const List &source)
{ // Equals operator
    if (this == &source)
    {
        return *this;
    }
    else
    {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd())
        {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}
/*
 makeEmpty should clear the list of all elements (isEmpty should return true after calling makeEmpty). It should also make sure that head and tail no longer point to those deleted elements (what should they point to instead in an empty list?).
 Since we have been dynamically allocating ListNodes, we must also be responsible for deleting them to ensure we do not leak memory. There are multiple ways to iterate through the list and delete each ListNode – experiment and see what makes the most sense to you.
 Important: once you delete a ListNode, you can no longer reliably access any of its data, such as its next or previous pointers! To make sure you don’t do this accidentally, we recommend setting each ListNode to NULL as soon as you delete it.

 The destructor should delete all dynamically-allocated memory, as we no longer need this List instance. Thus, it makes sense that we should delete all the elements we inserted (hint: do we already have a method for that?). However, what else do we dynamically allocate that we need to delete?
 */
bool List::isEmpty() const
{
    if (head->next == tail && tail->previous == head)
    { // changed >> if (count == 0) {
        return true;
    }
    else
    {
        return false;
    }
}

void List::makeEmpty() {

    ListItr li;

    li.current = head->next;

    while (li.current != tail) 
    {

        li.moveForward();
        
        delete (li.current)->previous;
       
    }
    head->next = tail;
    tail->previous = head;

}



ListItr List::first()
{
    ListItr lp(head->next);
    return lp;
}

ListItr List::last()
{
    ListItr lp(tail->previous);
    return lp;
}

void List::insertAfter(int x, ListItr position)
{
    ListNode *newNode = new ListNode();
    ListNode *curr = position.current;
    curr->next->previous = newNode;
    newNode->next = curr->previous;
    curr->next = newNode;
    newNode->previous = curr;
    count++;
}
// Inserts x before current iterator position
void List::insertBefore(int x, ListItr position)
{
    ListNode *newNode = new ListNode();
    ListNode *curr = position.current;
    curr->previous->next = newNode;
    newNode->previous = curr->previous;
    curr->previous = newNode;
    newNode->next = curr;
    count++;
}

void List::insertAtTail(int x)
{
    ListNode *newNode = new ListNode();

    newNode->value = x;
    //tail->previous->next = newNode;
    newNode->previous = tail->previous;
    tail->previous->next = newNode;
    newNode->next = tail;
    
    tail->previous = newNode;

    count++;
}

ListItr List::find(int x)
{
    ListItr li(head->next);
    while (li.isPastEnd() == false)
    {
        if (li.current->value == x)
        {
            return li;
        }
        else
        {
            li.moveForward();
        }
    }

    return li;
}

// Removes the first occurrence of x
void List::remove(int x)
{
    ListItr li;
    li = find(x);

    li.current->next->previous = li.current->previous;
    // delete li.current;
    li.current->previous->next = li.current->next;

    count--;
}

int List::size() const
{
    ListItr li;
    li.current = head;
    int size = 0;
    while (li.current != tail)
    {
        size = size + 1;
        li.current = li.current->next;
    }
    return size - 1;
}


void printList(List &source, bool forward)
{
    ListItr li;
    if (forward == true)
    {
        li = source.first();
        while (li.isPastEnd() == false)
        {
            cout << li.retrieve() << " ";
            li.moveForward();
        }
    }else{
        li = source.last();
        while(li.isPastBeginning()==false){
            cout << li.retrieve() << " ";
            li.moveBackward();
        }
        cout<<endl;

    }
}
