#include "Node.h"
#include <iostream>


void mergeList(Node *first, Node *second) {
	////std::cout << __LINE__ << //std::endl;
	if(first == NULL && second == NULL)
		return;
		////std::cout << __LINE__ << //std::endl;
	if(first != NULL && second != NULL)
	{
		// if(first==NULL)
		// 	return;

		// if(second== NULL)
		// 	return;
		////std::cout << __LINE__ << //std::endl;	
		Node *firstTemp = NULL;
		Node *secondTemp = NULL;
		////std::cout << __LINE__ << //std::endl;
		if(first->next_ != NULL && second->next_ != NULL)
		{
			//std::cout << __LINE__ << //std::endl;
			firstTemp = first->next_;
			first->next_ = second;
			secondTemp = second->next_;
			second->next_ = firstTemp;
			//std::cout << __LINE__ << //std::endl;
		}else if(first->next_ == NULL && second->next_ != NULL){
			//std::cout << __LINE__ << //std::endl;
			firstTemp = NULL;
			first->next_ = second;
			secondTemp = NULL;
		}else if(first->next_ != NULL && second->next_ == NULL){
			//std::cout << __LINE__ << //std::endl;
			firstTemp = first->next_;
			first->next_ = second;
			secondTemp = NULL;
			second->next_ = firstTemp;
		}else if(first->next_ == NULL && second->next_ == NULL){
			//std::cout << __LINE__ << //std::endl;
			firstTemp = NULL;
			first->next_ = second;
			secondTemp = NULL;
		}

		
		////std::cout << __LINE__ << //std::endl;		
		////std::cout << second->next_->data_ << " " << secondTemp->next_->data_<< //std::endl;
		mergeList(firstTemp, secondTemp);
		////std::cout << __LINE__ << //std::endl;
}

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
