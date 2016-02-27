template <class T>
Set<T>::Set()
{

}

// deep copy constructor
template <class T>
Set<T>::Set(const Set<T> & other)
{
	this->internalStorage = other.internalStorage;
}

template <class T>
Set<T>::~Set()
{

}

template <class T>
Set<T>& Set<T>::operator = (const Set<T> & other)
{
	if(this != &other)
	{
	this->internalStorage = other.internalStorage;
	}

return *this;
}

template <class T>
int Set<T>::size () const
{
	return internalStorage.size();
}

template <class T>
void Set<T>::add(const T & object) //void Set<T>::add(const T & object)
{
	internalStorage.add(object, object);
}
 

template <class T>
void Set<T>::remove(const T & object)      
{
	internalStorage.remove(object);
}

template <class T>
bool Set<T>::contains(const T & object) const // add someting in there.// future
{
	bool success;
	try {			
	internalStorage.get(object);
		success = true;
	}
	catch (NoSuchElementException &e)
	{
		success = false;
	} 
	return success;
}

template <class T>
void Set<T>::merge(const Set<T> & other)
{
	internalStorage.merge(other.internalStorage);
}
/*
template <class T>
void Set<T>::next()
{
	internalStorage.next();
}
template <class T>
void Set<T>::first()
{
	internalStorage.first();
}
template <class T>
const T & Set<T>::getCurrent()
{
	return internalStorage.getCurrentKey();
}
*/
 

template <class T>
Set<T> Set<T>:: setUnion(const Set<T> & other) const
{
	Set<T> newSet;	
	newSet.merge(*this); //* is de reference.	
	newSet.merge(other);

   return newSet;

}
    
template <class T>
Set<T> Set<T>:: setIntersection(const Set<T> & other) const
{
	
	Set<T> newSet(*this);
	
	try{
		newSet.first();
		while(true)
		{

		if(!other.contains(newSet.getCurrent()))
		{
	                newSet.remove(newSet.getCurrent());
			newSet.first();
		}
		      newSet.next();
		}

	   }
	catch(NoSuchElementException &e)
	{
		
	}	

	return newSet;
}

//start iterator!
template<class T>
Set<T>::Iterator::Iterator()
{	
	
}
template<class T>
Set<T>::Iterator::~Iterator()
{	
	
}
template<class T>
T Set<T>::Iterator::operator* () const
{
	T val = (*(this->internalIterator)).second;
	return val;
	
}

template<class T>
typename Set<T>::Iterator Set<T>::Iterator::operator++ ()
{
	this->internalIterator++; 
	return *this;
}
 
template<class T>
typename Set<T>::Iterator Set<T>::Iterator::operator++ (int dummy)
{
	this->internalIterator++;
	return *this;
} 

template<class T>
typename Set<T>::Iterator Set<T>::Iterator::operator= (const Set<T>::Iterator & other)
{
	if (this != &other)
	{
		this->internalIterator = other.internalIterator;
	}
	return *this;
}

template<class T>
bool Set<T>::Iterator::operator== (const Set<T>::Iterator & other) const
{
	return (this->internalIterator == other.internalIterator);
}

template<class T>
bool Set<T>::Iterator::operator!=(const Set<T>::Iterator & other) const
{
	return (!(this->internalIterator == other.internalIterator));
}

template<class T>
typename Set<T>::Iterator Set<T>::begin() const
{
	Set<T>::Iterator temp;
	temp.internalIterator = internalStorage.begin();
	return temp;
}

template<class T>
typename Set<T>::Iterator Set<T>::end() const
{
	Set<T>::Iterator temp;
	temp.internalIterator = internalStorage.end();
	return temp;
}
