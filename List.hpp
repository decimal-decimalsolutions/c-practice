/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */


#include "List.h"
template <class T>
List<T>::List() {
  // @TODO: graded in MP3.1
     head_ = NULL;
     tail_ = NULL;
     length_ = 0;
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1

  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(tail_->next);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
   ListNode * curr = head_;
 // iterate down the parameter list
   while (curr != NULL)
   {
     curr = head_->next;
     delete head_;
     head_ = curr;
   }
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  // @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
//  newNode->data_ = ndata;

  if(head_ == NULL)
   {
       head_ = newNode;
       tail_ = newNode;
       newNode->prev = NULL;
       newNode->next = NULL;

   }
   else
   {
       head_->prev = newNode;
       newNode->next = head_;
       newNode->prev = NULL;
       head_ = newNode;
      // tail_ = newNode;
   }
   length_++;
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1

      ListNode* newNode = new ListNode(ndata);
      if(tail_ == NULL)
      {
          head_ = newNode;
          tail_ = newNode;
          newNode->prev = NULL;
          newNode->next = NULL;
      }
      else
      {
          tail_->next = newNode;
          newNode->prev = tail_;
          newNode->next = NULL;
          tail_ = newNode;

      }

      length_++;
  }
/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1
  ListNode * cur = start;

  for (int i = 0; i < splitPoint && cur != NULL; i++) {
    cur = cur->next;
  }

  if (cur != NULL) {

      cur->prev->next = NULL;
      cur->prev = NULL;
  }

  return cur;
}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <typename T>
void List<T>::waterfall() {
  /// @todo Graded in MP3.1
   // std::cout << __LINE__  << " " << std::endl;
    ListNode *cur = head_;

  //  std::cout << __LINE__  << " " << std::endl;
    while(cur->next != tail_)
    {
        ListNode *temp = cur->next;
       // std::cout << __LINE__  << " " << std::endl;
       cur->next = temp->next;
       temp->next->prev = cur;
     //   std::cout << __LINE__  << " " << std::endl;
       tail_ -> next = temp;
     //   std::cout << __LINE__  << " " << std::endl;
       temp -> prev = tail_;
       temp -> next = NULL;
     //   std::cout << __LINE__  << " " << std::endl;
       tail_ = temp;
       cur = cur->next;
     //   std::cout << __LINE__  << " " << std::endl;
//     if(temp->next != NULL)
//     {
//         cur = cur->next;
//         //  std::cout << __LINE__  << " " << std::endl;
//         temp = cur->next->next;
//     }
//     else
//         break;
       // std::cout << __LINE__  << " " << std::endl;
    }

}

/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.2
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.2
}


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2
  return NULL;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
  return NULL;
}
