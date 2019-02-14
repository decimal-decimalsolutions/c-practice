#include "Node.h"
#include <iostream>
using namespace std;

void sortList(Node **head) {
    // your code here!

    /*
    Selection sort:
    Repeatedly moving the minimum node
    to the beginning
    */


    // Some variables you probably will need
    Node *minNode = NULL;
    Node *minPrev = NULL;

    if (*head == NULL)
        return;

    int minData = (*head)->data_;
    Node *tmp = *head;
    Node *prev = NULL;
    minNode = tmp;
//    std::cout<<"before MinData is "<<tmp->data_<< std::endl;
    while ( tmp != NULL ) {
        // TODO: Find the minimum node

//        std::cout << "In while Loop  " << tmp->data_ << std::endl;
        //comparing second with new node with second node
        if (minData > tmp->data_) {
            minNode = tmp;
            minData = minNode->data_;
            minPrev = prev;
            prev = tmp;
            tmp = tmp->next_;
//            if(tmp!= NULL)
//             std::cout <<"minData is " <<minData<< " In If Now tmp is " << tmp->data_ << std::endl;
        } else {
            prev = tmp;
            tmp=tmp->next_;
//            if(tmp!= NULL)
//                std::cout << "minData is " <<minData<< " In else  Now tmp is " << tmp->data_ << std::endl;
        }
    }
//    std::cout<<" After MinData is  "<<minNode->data_<< std::endl;
    if (minPrev != NULL && minNode != NULL) {
        // TODO: Move the minimum node to the beginning
      minPrev->next_ = minNode->next_;
      minNode->next_=*head;
     *head = minNode;
    }

    // Recurse on the rest of the list
    sortList(& (*head)->next_);
}

Node::Node() {
    numNodes++;
}

Node::Node(const Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
