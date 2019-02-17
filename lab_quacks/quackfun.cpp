#include <iostream>
/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 * stacks and queues portion of the lab.
 */

namespace QuackFun {

/**
 * Sums items in a stack.
 *
 * **Hint**: think recursively!
 *
 * @note You may modify the stack as long as you restore it to its original
 * values.
 *
 * @note You may use only two local variables of type T in your function.
 * Note that this function is templatized on the stack's type, so stacks of
 * objects overloading the + operator can be summed.
 *
 * @note We are using the Standard Template Library (STL) stack in this
 * problem. Its pop function works a bit differently from the stack we
 * built. Try searching for "stl stack" to learn how to use it.
 *
 * @param s A stack holding values to sum.
 * @return  The sum of all the elements in the stack, leaving the original
 *          stack in the same state (unchanged).
 */
    template<typename T>
    T sum(stack<T> &s){
//        std::cout<< "Size:"<<s.size()<<std::endl;
        if (s.size() == 1) {
            T temp = s.top();
//            std::cout<< "Size:"<<s.size()<<std::endl;
            return temp;
        } else {
            T t;
            t = s.top();
            s.pop();
            // Your code here
            T tSum = t + sum(s);
            s.push(t);
//            std::cout<< "Now Size:"<<s.size()<<std::endl;
            return tSum;
        }

    }

/**
 * Checks whether the given string (stored in a queue) has balanced brackets.
 * A string will consist of square bracket characters, [, ], and other
 * characters. This function will return true if and only if the square bracket
 * characters in the given string are balanced. For this to be true, all
 * brackets must be matched up correctly, with no extra, hanging, or unmatched
 * brackets. For example, the string "[hello][]" is balanced, "[[][[]a]]" is
 * balanced, "[]]" is unbalanced, "][" is unbalanced, and "))))[cs225]" is
 * balanced.
 *
 * For this function, you may only create a single local variable of type
 * `stack<char>`! No other stack or queue local objects may be declared. Note
 * that you may still declare and use other local variables of primitive types.
 *
 * @param input The queue representation of a string to check for balanced brackets in
 * @return      Whether the input string had balanced brackets
 */
    bool isBalanced(queue<char> input){

        stack<char> s;
        while(!input.empty()){
            char cc = input.front();
            input.pop();
            if(cc=='[' )
                s.push(cc);
            if(cc==']' && s.size()>0)
                s.pop();
            else if(cc==']' && s.size()==0){
                return false;
            }
        }

        if(s.empty())
            return true;
        else
            return false;



        // @TODO: Make less optimistic
        return true;
    }

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 *
 * **Hint**: You'll want to make a local stack variable.
 *
 * @note Any "leftover" numbers should be handled as if their block was
 * complete.
 *
 * @note We are using the Standard Template Library (STL) queue in this
 * problem. Its pop function works a bit differently from the stack we
 * built. Try searching for "stl stack" to learn how to use it.
 *
 * @param q A queue of items to be scrambled
 */
    template<typename T>
    void scramble(queue <T> &q){
        stack<T> s;
        queue<T> q2;
        if (!q.empty()) {
            int even = 2;
            int odd = 1;
            int count = 1;//q.size();
            bool evendone = true;
            bool odddone = false;
            while (q.size() > 0) {
//            std::cout<<q.front()<<" count:"<<count<<std::endl;
                if (!evendone) {
                    int c = 0;
                    while (!q.empty() && c < even) {
//                    std::cout<<__LINE__<<std::endl;
                        s.push(q.front());
                        q.pop();
                        c++;
                    }
                    while (!s.empty()) {
                        q2.push(s.top());
                        s.pop();
                        count++;
                    }
                    even = even + 2;
                    evendone = true;
                    odddone = false;
//                std::cout<<" q size:"<<q.size()<<std::endl;
//                std::cout<<" if count:"<<count<<std::endl;
                } else if (!odddone) {
                    int c = 0;
                    while (!q.empty() && c < odd) {
//                      std::cout<<__LINE__<<std::endl;

                        q2.push(q.front());
                        q.pop();
                        c++;
                        count++;
                    }
                    odd = odd + 2;
                    evendone = false;
                    odddone = true;
//                std::cout<<" q size:"<<q.size()<<std::endl;
//                std::cout<<" else count:"<<count<<std::endl;
                }
//            std::cout<<" q size:"<<q.size()<<std::endl;
            }
        }
        q = q2;
    }

/**
 * Checks if the parameter stack and queue are the same. A stack and a queue
 * are considered to the "the same" if they contain only elements of exactly
 * the same values in exactly the same order.
 *
 * @note You may assume the stack and queue contain the same number of items!
 *
 * @note The back of the queue corresponds to the top of the stack!
 *
 * @note There are restrictions for writing this function.
 * - Your function may not use any loops
 * - In your function you may only declare ONE local boolean variable to use in
 *   your return statement, and you may only declare TWO local variables of
 *   parametrized type T to use however you wish.
 * - No other local variables can be used.
 * - After execution of verifySame, the stack and queue must be unchanged. Be
 *   sure to comment your code VERY well.
 *
 * @param s The stack to compare
 * @param q The queue to compare
 * @return  true if the stack and the queue are the same; false otherwise
 */
    template<typename T>
    bool verifySame(stack <T> &s, queue <T> &q){
        bool retval = true; // optional
       // std::cout << __LINE__ << " Start Size is " << s.size() << " " << q.size() << std::endl;
        if (s.size() != q.size()) {
            std::cout << __LINE__ << std::endl;
            return !retval;
        }

        if (s.empty() || q.empty()) {
            //std::cout << __LINE__ << std::endl;
            return retval;
        } else if (s.size() == 1) {
            //std::cout << __LINE__ << "Size is 1" << std::endl;
            if (s.top() == q.back())
                return retval;
            else
                return !retval;
        } else {
            //std::cout << __LINE__ << " Size is " << s.size() << std::endl;
            T stackTop = s.top();
            s.pop();

            //std::cout << __LINE__ << " Q Front is (before reversing)" << q.front() << std::endl;
            //---reverse the queue
            int qsize = q.size();
            // T backelement = T();
            for (int i = 0; i < qsize-1; i++) {
                // backelement = q.back();
                T frontelement = q.front();
                q.pop();
                q.push(frontelement);
            }//----end of the reverse

            T frontOfReverseQ = q.front();
            q.pop();
            //std::cout << __LINE__ << " Q Front is (after reversing)" << frontOfReverseQ << std::endl;
            //---start reverse the queue ( make it the way ot was)
            qsize = q.size();
            // T backelement = T();
            for (int i = 0; i < qsize; i++) {
                // backelement = q.back();
                T frontelement = q.front();
                q.pop();
                q.push(frontelement);
            }//----end -- everse the queue ( make it the way ot was)

//            std::cout << __LINE__ << " Equal size but Size is " << s.size() << std::endl;
            bool temp = (stackTop == frontOfReverseQ) & verifySame(s, q);

            q.push(frontOfReverseQ);
            s.push(stackTop);
            return temp;
        }
        std::cout << __LINE__ << "End " << std::endl;
        return retval;
    }
}