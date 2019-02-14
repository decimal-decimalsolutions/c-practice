#include "potd.h"
#include <iostream>

void insertSorted(Node **head, Node *insert)
{
//    std::cout<<insert->data_<< std::endl;
    Node *ptr2Head = *head;

//    Node *ptr2Head = *head;
    if (*head == NULL) {
        *head = insert;
    } else if (ptr2Head->data_ >= insert->data_) {
//        std::cout<< ptr2Head->data_<<insert->data_<< std::endl;
        insert->next_ = ptr2Head;
        ptr2Head = insert;
    } else {
        // we have already compared head lets start with next
        //we need track one previous and one next node
        // it is better to have previous node and point to next with cptr->next
        //so cPtr is previous and cPtr->next is next
        Node *cPtr = ptr2Head;
        //comparing second with new node with second node
        while (cPtr->next_ != NULL && cPtr->next_->data_ <= insert->data_) {
            cPtr = cPtr->next_;
        }
// Now we are pointing at the node that is greater than new node
        insert->next_ = cPtr->next_;
        cPtr->next_ = insert;
    }

}