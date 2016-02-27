class NoSuchElementException{}; // Name of exception

template <class keyType, class valueType>
Map<keyType, valueType>::Map()
{
	head = NULL;
	tail = NULL;
}
//deep copy constructor
template <class keyType, class valueType>
Map<keyType, valueType>::Map(const Map<keyType, valueType> & other)
{
	head = NULL;
	tail = NULL;
	MapItem<keyType, valueType> *p = other.head;
	while (p != NULL)
	{
		this->add(p->key, p->value);
		p = p->next;
	}
			 
}
//end of copy constructor
template <class keyType, class valueType>
Map<keyType, valueType>::~Map()
{
	while ( head != NULL)
	{
		MapItem<keyType, valueType> *p = head;
		p = p -> next;
		delete head;
		head = p;
	}
}


//start overload the asssignmen t operator
template <class keyType, class valueType>
Map<keyType, valueType>& Map<keyType, valueType>::operator = (const Map<keyType, valueType> & other)
{
	if ( this != &other)
	{
		while ( head != NULL)
		{
			MapItem<keyType, valueType> *p = head;
			p = p -> next;
			delete head;
			head = p;
		}

		MapItem<keyType, valueType> *p = other.head;
		this->head = NULL;
		this->tail = NULL;

		while (p != NULL)
		{
			this->add(p->key, p->value);
			p = p->next;
		}	
	}
	
	return *this;
}
//end of operator

template <class keyType, class valueType>
int Map<keyType, valueType>::size() const
{
	int count = 0;
	MapItem<keyType, valueType> *p = head;
	while ( p != NULL)
	{
		p = p->next;
	    	count++;	
	}
	return count;
}

template <class keyType, class valueType>
void Map<keyType, valueType>::add(const keyType & key, const valueType & value)//void Map<keyType, valueType>::add(keyType key, valueType value)
{
	
	MapItem<keyType, valueType> *newElement = new MapItem<keyType, valueType>;
	newElement->key = key; 
	newElement->value = value;
	newElement->next = NULL;
	newElement->prev = NULL;


	
	try {
		get(newElement->key);
	}
	catch (NoSuchElementException &e)
	{
		
		if (head == NULL)
		{
				head = newElement;
				tail = head;
		}
		else
		{
				tail -> next = newElement;
				newElement -> next = NULL;
				newElement -> prev = tail;
				tail = newElement;
		}		
	}

	


}

template <class keyType, class valueType>
void Map<keyType, valueType>::remove(keyType key) // doubly linked list
{
	
	
	MapItem<keyType, valueType> *p = head;
	while (p != NULL)
	{
	
		if( p->key == key )
		{
			if(p == head)
			{
				head = p -> next;
				head -> prev = NULL;
				delete p;
			}	
			else if(p == tail)
			{
				tail = p -> prev;
				tail -> next = NULL;
				delete p;
			}
			else
			{
				p -> prev -> next = p -> next;
				p -> next -> prev = p -> prev;
				delete p;
			}
		}
		else
		{
			p = p->next;
		}

	}	
}

template <class keyType, class valueType>
const valueType & Map<keyType, valueType>::get(const keyType & key) const 
{

	MapItem<keyType, valueType> *p = head;
	
	
	while (p != NULL)
	{
		if( p->key == key )
		{			
			return p->value;
		}
		else
		{
			p = p->next; 
		}
	}
		throw NoSuchElementException();		
	
		
}

template <class keyType, class valueType>
void Map<keyType, valueType>::merge(const Map<keyType, valueType> & other)
{
	MapItem<keyType, valueType> *q = other.head;
	while(q != NULL)
	{
		add(q->key, q->value);
		q = q->next;
	}

}

// first and second
/*
template <class keyType, class valueType>
void Map<keyType, valueType>::first()
{
	// list is not empty
	if (head != NULL)
	{
		current = head;
	} 
	else 
		throw NoSuchElementException();

}

template <class keyType, class valueType>
void Map<keyType, valueType>::next()
{

	if (current != NULL && current->next != NULL)
	{
		current = current->next;
	} 
	else 
		throw NoSuchElementException();
}
//end of first and second

//getcurrent key and vlaue

template <class keyType, class valueType>
const keyType & Map<keyType, valueType>::getCurrentKey()
{
	return current->key;
}
template <class keyType, class valueType>
const valueType & Map<keyType, valueType>::getCurrentValue()
{
	return current->value;
}
*/

template <class keyType, class valueType>
bool Map<keyType, valueType>::contains(const keyType & key) const // add someting in there.// future
{
	bool success;
	try {			
		get(key);
		success = true;
	}
	catch (NoSuchElementException &e)
	{
		success = false;
	} 
	return success;
}



template <class keyType, class valueType>
Map<keyType,valueType>::Iterator::Iterator()
{
	whoIBelongTo = NULL;
	current = NULL;
}
template <class keyType, class valueType>
Map<keyType,valueType>::Iterator::~Iterator()
{

}
template <class keyType, class valueType>
Pair<keyType, valueType> Map<keyType, valueType>::Iterator::operator* () const
{	
	Pair<keyType, valueType> temp(current->key, current->value);
	return temp;
}

template<class keyType, class valueType>
typename Map<keyType,valueType>::Iterator Map<keyType,valueType>::Iterator::operator++ ()
{
	current = current -> next;
	return *this;
}

template<class keyType, class valueType>
typename Map<keyType,valueType>::Iterator Map<keyType,valueType>::Iterator::operator++ (int dummy)
{
	current = current -> next;
	return *this;
}

template<class keyType, class valueType>
typename Map<keyType,valueType>::Iterator Map<keyType,valueType>::Iterator::operator= (const Map<keyType, valueType>::Iterator & other)
{	
	if (this != &other)
	{
		this->whoIBelongTo = other.whoIBelongTo;
		this->current = other.current;	
	}	
	return *this;
}

template <class keyType, class valueType>
bool Map<keyType, valueType>::Iterator::operator== (const Map<keyType, valueType>::Iterator & other) const
{
	return (this->current == other.current && this->whoIBelongTo == other.whoIBelongTo);
}

template <class keyType, class valueType>
bool Map<keyType, valueType>::Iterator::operator!= (const Map<keyType, valueType>::Iterator & other) const
{
	return (!(this->current == other.current) || !(this->whoIBelongTo == other.whoIBelongTo));
	//return (!(*this == other));
}


template <class keyType, class valueType>
typename Map<keyType, valueType>::Iterator Map<keyType, valueType>::begin () const
{
	return Map<keyType, valueType>::Iterator(this, head);
}


template <class keyType, class valueType>
typename Map<keyType, valueType>::Iterator Map<keyType, valueType>::end () const
{
	return Map<keyType, valueType>::Iterator(this, NULL);
}






