/*
FILENAME: "ListItr.cpp"

Author: Samuel Campbell


Lab 2 Post-Lab

*/

#include "ListItr.h"

using namespace std;

ListItr::ListItr() {
    current = NULL; //new ListNode();
}

ListItr::ListItr(ListNode* theNode) {
    current = theNode;
}

// Returns true if the iterator is currently pointing past the end position
// in the list (i.e., it's pointing to the dummy tail), else false
bool ListItr::isPastEnd() const {
    if (current->next == NULL) {
        return true;
    } else {
        return false;
    }
}

// Returns true if the iterator is currently pointing past (before) the first position
// in list (i.e., it's pointing to the dummy head), else false
bool ListItr::isPastBeginning() const {
    if (current->previous == NULL) {
        return true;
    } else {
        return false;
    }
}
// Advances `current` to the next position in the list (unless already past the end of the list)
void ListItr::moveForward() {
    if (current->next != NULL) {
        current=current->next;
    }
}

// Moves `current` back to the previous position in the list (unless already past the beginning of the list)
void ListItr::moveBackward() {
    if (current->previous != NULL) {
        current=current->previous;
    }
}

int ListItr::retrieve() const {
    if (current == NULL) {
        return 1;
    }
    if (current != NULL) {
        return current->value;   // Accessing val from theNode
    }
    return 1;
}

