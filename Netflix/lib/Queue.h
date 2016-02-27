#ifndef Queue_H_
#define Queue_H_


template <class T>
struct QueueItem
{
  T val;
  QueueItem<T> *prev, *next;
  
};
template <class T>
class Queue {
  public:

  Queue(); // constructor
  
  ~Queue();// distructor



    void enqueue (const T & item);
      /* adds the item to the end of the queue.
         The same item may be added many times. */

    void dequeue (); 
      /* removes the front element of the queue. 
         Throws an EmptyQueueException when called on an empty queue.
         EmptyQueueException should inherit from std::exception. */

    const T & peekFront ();
      /* returns the front element of the queue. 
         Throws an EmptyQueueException when called on an empty queue.
         EmptyQueueException should inherit from std::exception. */

    bool isEmpty ();
      /* returns whether the queue is empty. */
    int size();


  private:
  QueueItem<T> *front, *back;
  int count;
};
#include "Queue.cpp"
#endif
