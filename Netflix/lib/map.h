#ifndef map_H_
#define map_H_

using namespace std;

template <class FirstType, class SecondType> 
struct Pair {
   FirstType first;
   SecondType second;

   Pair (FirstType first, SecondType second)
      { this->first = first; this->second = second; }
   // we're very nice and give you this piece of difficult code for free :-P
};

template <class keyType, class valueType>
struct MapItem
{
  keyType key;
  valueType value;
  MapItem<keyType, valueType> *prev, *next;
};


template <class keyType, class valueType>
class Map
{
  public:
    Map ();  // constructor for a new empty map

    Map(const Map<keyType, valueType> & other);// deep copy constructor

    ~Map (); // destructor

    Map<keyType, valueType>& operator = (const Map<keyType, valueType> & other);

    int size () const; // returns the number of key-value pairs

    void add (const keyType & key, const valueType & value); 
      /* Adds a new association between the given key and the given value.
         If the key already has an association, it should do nothing.
      */

    void remove (keyType key);
     /* Removes the association for the given key.
        If the key has no association, it should do nothing. */

    const valueType & get(const keyType & key) const;
     /* Returns the value associated with the given key.
        If the key existed in the map, success should be set to true.
        If the key has no association, it should set success to false. */

    void merge (const Map<keyType, valueType> & other);
     /* Adds all the key-value associations of other to the current map.
        If both maps (this and other) contain an association for the same
        key, then the one of this is used. */

/*
    void first();
    void next();
    const keyType & getCurrentKey();
    const valueType & getCurrentValue();
*/
    bool contains(const keyType & key) const;

  private:
     /* The head and tail of the linked list you're using to store
        all the associations. */

     MapItem <keyType, valueType> *head, *tail;

     /* If you like, you can add further data fields and private
        helper methods. */

public:
     class Iterator {
         /* add any constructors that you feel will be helpful,
            and choose whether to make them public or private. */

         public:
	   friend class Map<keyType, valueType>;

	   Iterator (); 
	   ~Iterator ();	   

           Pair<keyType, valueType> operator* () const;
              // return the current (key, value) pair the iterator is at

           Map<keyType,valueType>::Iterator operator++ ();
              // advances the iterator (pre-increment)

	   Map<keyType,valueType>::Iterator operator++ (int dummy);
	      // advances the iterator (post-increment)

           Map<keyType,valueType>::Iterator operator= (const Map<keyType,valueType>::Iterator & other);
              // assigns the other iterator to this iterator and returns this

           bool operator== (const Map<keyType,valueType>::Iterator & other) const;
              // returns whether this iterator is equal to the other iterator

           bool operator!= (const Map<keyType,valueType>::Iterator & other) const;
              // returns whether this iterator is not equal to the other iterator

           /* Optionally, if you think that it makes your code easier to write,
              you may also overload other operators: */

           /* You may define a public copy constructor and/or default constructor
              if you think it would be helpful. */
	 private:
		MapItem <keyType, valueType> *current;
		const Map<keyType, valueType> *whoIBelongTo;

		Iterator(const Map<keyType, valueType> *s, MapItem <keyType, valueType> *p)
		{
			whoIBelongTo = s;
			current = p;
		} 

     };

     Map<keyType,valueType>::Iterator begin () const;
       // returns an iterator initialized to the first element

     Map<keyType,valueType>::Iterator end () const;
       /* returns an iterator initialized past the last element,
          to designate that the end of the map has been reached. */



};

#include "mapIm.cpp"
#endif	
