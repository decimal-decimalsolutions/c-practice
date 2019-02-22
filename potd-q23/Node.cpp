#include "Node.h"
#include "iostream"

using namespace std;

Node *listSymmetricDifference(Node *first, Node *second) {
    // your code here
    Node *firstHead = first;
    Node *secondHead= second;

    if (first == NULL && second == NULL) {
        return NULL;
    }






//remove duplicates from first
    Node *uniqFirst = NULL;
    Node *uniqFirstHead = NULL;
    //remove duplicates
    if (first != NULL) {
        Node *temp = new Node();
        temp->data_ = first->data_;
        temp->next_ = NULL;
        uniqFirst = temp;
        uniqFirstHead = uniqFirst;
        bool found = false;

        while (first != NULL) {
            found = false;
            uniqFirst = uniqFirstHead;
            while (uniqFirst != NULL) {
                if (uniqFirst->data_ == first->data_) {
                    //cout << uniqFirst->data_ << "--" << first->data_ << endl;
                    found = true;
                    break;
                } else {
                    uniqFirst = uniqFirst->next_;
                }
            }
            //cout << "found at end is " << found << endl;

            if (!found) {
                //cout << "in found true" << endl;
                Node *temp = new Node();
                temp->data_ = first->data_;
                temp->next_ = NULL;

                Node *tt = NULL;

                tt = uniqFirstHead;
                //cout << "before tt is now null" << endl;
                if (tt != NULL)
                    //cout << "tt is now null" << endl;
                while (tt->next_ != NULL) {
                    //cout << "while t loop" << endl;
                    tt = tt->next_;
                }

                tt->next_ = temp;
            }
            //cout << "after found true" << endl;
            first = first->next_;
        }
    }


    first = uniqFirstHead;
    while (first != NULL) {
//        cout << "uniqFirst:" << first->data_ << endl;
        first = first->next_;
    }



//remove duplicates from second
    Node *uniqSecond = NULL;
    Node *uniqSecondHead = NULL;
    //remove duplicates
    if (second != NULL) {
        Node *temp = new Node();
        temp->data_ = second->data_;
        temp->next_ = NULL;
        uniqSecond = temp;
        uniqSecondHead = uniqSecond;
        bool found = false;

        while (second != NULL) {
            found = false;
            uniqSecond = uniqSecondHead;
            while (uniqSecond != NULL) {
                if (uniqSecond->data_ == second->data_) {
                    //cout << uniqSecond->data_ << "--" << second->data_ << endl;
                    found = true;
                    break;
                } else {
                    uniqSecond = uniqSecond->next_;
                }
            }
            //cout << "found at end is " << found << endl;

            if (!found) {
                //cout << "in found true" << endl;
                Node *temp = new Node();
                temp->data_ = second->data_;
                temp->next_ = NULL;

                Node *tt = NULL;

                tt = uniqSecondHead;
                //cout << "before tt is now null" << endl;
                if (tt != NULL)
                    //cout << "tt is now null" << endl;
                while (tt->next_ != NULL) {
                    //cout << "while t loop" << endl;
                    tt = tt->next_;
                }

                tt->next_ = temp;
            }
            //cout << "after found true" << endl;
            second = second->next_;
        }
    }


    second = uniqSecondHead;
    while (second != NULL) {
//        cout << "uniqSecond:" << second->data_ << endl;
        second = second->next_;
    }
//----------------

    second = uniqSecondHead;
    first = uniqFirstHead;

    if (first == NULL && second != NULL) {
        Node *head(second);
        return head;
    }


    if (first != NULL && second == NULL) {
        Node *head(first);
        return head;
    }

    --------------------------

    second = uniqSecondHead;
    first = uniqFirstHead;

    Node *foundlist = NULL;
    bool found = false;
    while (first != NULL) {
        ////cout << "If Loop first :" << first->data_ << endl;
        second = secondHead;
        while (second != NULL) {
            if (first->data_ == second->data_) {
                ////cout << "found:" << first->data_ << " == " << second->data_ << endl;
                Node *temp = new Node();
                temp->data_ = first->data_;
                temp->next_ = NULL;
                if (foundlist != NULL) {
                    Node *t = foundlist;
                    while (t->next_ != NULL)
                        t = t->next_;

                    t->next_ = temp;
                } else {
                    foundlist = temp;
                }
                break;
            }
            ////cout << "Not found:" << first->data_ << " != " << second->data_ << endl;
            second = second->next_;
        }
        first = first->next_;
    }

    while (second != NULL) {
        ////cout << "If Loop second :" << second->data_ << endl;
        first = firstHead;
        while (first != NULL) {
            if (second->data_ == first->data_) {
                ////cout << "found:" << first->data_ << " == " << second->data_ << endl;
                Node *temp = new Node();
                temp->data_ = first->data_;
                temp->next_ = NULL;
                if (foundlist != NULL) {
                    Node *t = foundlist;
                    while (t->next_ != NULL)
                        t = t->next_;

                    t->next_ = temp;
                } else {
                    foundlist = temp;
                }
                break;
            }
            ////cout << "Not found:" << first->data_ << " != " << second->data_ << endl;
            first = first->next_;
        }
        second = second->next_;
    }

    Node * foundListHead;
    foundListHead = foundlist;
    Node * notFoundListHead;
    Node *notFoundList= NULL;
    //////cout << " found at the end is:" << found << endl;
    first = firstHead;
    second = secondHead;
    found = false;
    if (foundlist!=NULL) {
        while (first != NULL) {
            found = false;
            foundlist = foundListHead;
            ////cout << "If Loop of first not Found List:" << first->data_ << endl;
            while (foundlist != NULL) {
                if (first->data_ == foundlist->data_) {
                    ////cout << "found:" << first->data_ << " == " << foundlist->data_ << endl;
                    found = true;
                    break;
                }
                ////cout << "Not found:" << first->data_ << " != " << foundlist->data_ << endl;
                foundlist = foundlist->next_;
            }
            ////cout << " value of found at the end is:" << found << endl;
            if(!found){
                Node *temp = new Node();
                temp->data_ = first->data_;
                temp->next_ = NULL;
                if (notFoundList != NULL) {
                    Node *t = notFoundList;
                    while (t->next_ != NULL)
                        t = t->next_;

                    t->next_ = temp;
                } else {
                    notFoundList = temp;
                    notFoundListHead = notFoundList;
                }
            }
            first = first->next_;
        }

        while (second != NULL) {
            found = false;
            foundlist = foundListHead;
            ////cout << "If Loop of second  not Found list :" << second->data_ << endl;
            while (foundlist != NULL) {
                if (second->data_ == foundlist->data_) {
                    ////cout << "found:" << second->data_ << " == " << foundlist->data_ << endl;
                    found = true;
                }
                ////cout << "Not found:" << second->data_ << " != " << foundlist->data_ << endl;
                foundlist = foundlist->next_;
            }
            ////cout << " value of found at the end is:" << found << endl;
            if(!found){
                Node *temp = new Node();
                temp->data_ = second->data_;
                temp->next_ = NULL;
                if (notFoundList != NULL) {
                    Node *t = notFoundList;
                    while (t->next_ != NULL)
                        t = t->next_;

                    t->next_ = temp;
                } else {
                    notFoundList = temp;
                    notFoundListHead = notFoundList;
                }
            }
            second = second->next_;
        }

    }
    if (notFoundList != NULL) {
        while (notFoundList != NULL) {
            //////cout << notFoundList->data_ << endl;
            notFoundList = notFoundList->next_;
        }
    }else {
        //////cout << "Head is null" << endl;
    }
    notFoundList = notFoundListHead;
    return notFoundList;

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
