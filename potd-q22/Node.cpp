#include "Node.h"
#include <iostream>

using namespace std;

Node *listIntersection(Node *first, Node *second){
    // your code here

    if (first == NULL && second == NULL) {
        return NULL;
    }


    if (first == NULL && second != NULL) {
        Node *head(second);
        return head;
    }


    if (first != NULL && second == NULL) {
        Node *head(first);
        return head;
    }

    Node *head = NULL;
    Node *result = NULL;

    Node *copyOfFirst(first);
    int x = 0;
    while (copyOfFirst != NULL) {
        copyOfFirst = copyOfFirst->next_;
        x = x + 1;
    }
    int firstSize = x;
    Node *copyOfSecond(second);
    int y = 0;
    while (copyOfSecond != NULL) {
        copyOfSecond = copyOfSecond->next_;
        y = y + 1;
    }
    int secondSize = y;
    //cout << firstSize << " ---" << secondSize << endl;

//    int smallSize = 0;
//    int bigSize = 0;

    Node *small = NULL;
    Node *big = NULL;
    if (firstSize <= secondSize) {
        small = first;
        big = second;
        //cout << "Small:" << firstSize << " Big:" << secondSize << endl;
    } else {
        small = second;
        big = first;
        //cout << "Small:" << firstSize << " Big:" << secondSize << endl;
    }

    Node *smallHead = small;
    Node *smallPrev= NULL;
//    for(int i=0;i<bigSize || big!=NULL; i++) {
    while (big != NULL) {
        //cout << "If Loop Big :" << big->data_ << endl;
        bool found = false;
        small = smallHead;
        smallPrev= NULL;
//        for (int j = 0; j < smallSize || small != NULL; j++) {
        while (small != NULL) {
            if (big->data_ == small->data_) {
//                cout << "found:" << big->data_ << " == " << small->data_ << endl;
                found = true;
                if(smallPrev==NULL){
//                    cout << "Deleting..1";

                    smallHead = small->next_;
                    smallPrev = NULL;

                    Node *deleteIt = small;
                    deleteIt->next_=NULL;
                    deleteIt = NULL;

                    small = smallHead;
//                    cout << "Deleting..1";
                }else{
//                    cout << "Deleting..else";
                    smallPrev->next_ = small->next_;
//                    cout << "Deleting..2";
                    Node *deleteIt = small;
//                    cout << "Deleting..2";
                    deleteIt->next_=NULL;
//                    cout << "Deleting..2";
                    small = smallHead;
//                    cout << "Deleting..2";
                    deleteIt=NULL;
                }
                break;
            }
            found = false;
//            cout << "Not found:" << big->data_ << " != " << small->data_ << endl;
            smallPrev = small;
            small = small->next_;
        }
        //cout << " found at the end is:" << found << endl;
        if (found) {
            if (head == NULL) {
//                cout << " first found0" << endl;
                Node *temp = new Node();
                temp->data_=big->data_;
                temp->next_ = NULL;
//                cout << " temp"<<temp->data_ << endl;
//                if(big->next_!=NULL)
//                cout << " first found1 big" << endl;
                result = temp;
//                if(result->next_!=NULL)
                //cout << " first found2" << endl;
                head = result;
//                if(head->next_!=NULL)
//                //cout << " first found3" << endl;
//                result->next_=NULL;
//                if(big->next_!=NULL)
//                //cout << " first found4" << endl;
            } else {
//                cout << " second found" << endl;
                Node *temp = new Node();
                temp->data_=big->data_;
                temp->next_ = NULL;

                result->next_ = temp;
                result = temp;
            }
            big = big->next_;
//            if(big!=NULL)
//            cout << " found incrementing  big it will nbe " << big->data_ << endl;

        } else {
            big = big->next_;
//            if(big!=NULL)
//            cout << " Not found incrementing big it will nbe " << big->data_ << endl;
        }
    }
//    if (head != NULL) {
//        while (head != NULL) {
//            //cout << head->data_ << endl;
//            head = head->next_;
//        }
//    }else {
//        //cout << "Head is null" << endl;
//    }

        return head;

}

Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
