#include "Node.h"
#include <iostream>

/** Create a new node and add it to the list, while keeping the list sorted.
*/
Node *insertSorted(Node *first, int data){
    // your code here
    //std::cout << "Line#:" << __LINE__ << " Data is " << data << std::endl;
//    //std::cout << first->data_ << std::endl;

//    Node *firstTemp = first->next_;
    //create a node with data
    Node *dataNode = new Node();
    dataNode->data_ = data;
    dataNode->next_ = NULL;

    ////std::cout << __LINE__ << std::endl;
    if (first == NULL) {
        //std::cout << "Line#:" << __LINE__ << " first is null " << std::endl;
        first = dataNode;
        return first;
    }

    //First isnot null so moving to real logic
    if (first->next_ != NULL) {
        //if(first->data_ <= data && first->next_->data_ >= data)
        if (data == first->data_) {
            //std::cout << "Line#:" << __LINE__ << " Not added it is same [ " << data << "==" << first->data_ << "]"<<std::endl;
            return first;
        }
        if (data < first->data_) {
            //std::cout << "Line#:" << __LINE__ << " data is smaller than current node.. inserting here " << std::endl;
            dataNode->next_ = first->next_;
            first->next_ = dataNode;
            //std::cout << "Line#:" << __LINE__ << " Inserted before this [" << first->data_ << "] node " << std::endl;
            return first;
        } else {
            //std::cout << "Line#:" << __LINE__ << " data is greater than current node.. calling recursively "<< std::endl;
            insertSorted(first->next_, data);
            //std::cout << __LINE__ << std::endl;
        }
    } else {
        //std::cout << "Line#:" << __LINE__ << " first->next is null, so last node so adding here if not same "<< std::endl;
        if (data == first->data_) {
            //std::cout << "Line#:" << __LINE__ << " Not added it same [ " << data << "==" << first->data_ << std::endl;
            return first;
        } else if (data < first->data_) {
            //std::cout << "Line#:" << __LINE__ << " last Node data is smaller . inserting before the last node "<< std::endl;
            first->next_ = dataNode;
            return first;
        } else {
            //std::cout << "Line#:" << __LINE__ << " data is greater addied ahere as last node " << std::endl;
            first->next_ = dataNode;
            //std::cout << __LINE__ << std::endl;
        }

        return first;
    }

    return first;
}

/** Creates a new list (containing new nodes, allocated on the heap)
	that contains the set union of the values in both lists.
*/
Node *listUnion(Node *first, Node *second){
    Node *out = NULL;

    // out = insertSorted(first, 2);
    // out = insertSorted(first, 3);
    // out = insertSorted(first, 4);        
    //while (first != NULL) {
    // your code here
    // hint: call insertSorted and update l1
    while (first != NULL) {
        out = insertSorted(out, first->data_);
        first = first->next_;
    }

    while (second != NULL) {
        out = insertSorted(out, second->data_);
        second = second->next_;
    }

    return out;
}

Node::Node(){
    numNodes++;
}

Node::Node(const Node &other){
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node(){
    numNodes--;
}

int Node::numNodes = 0;
