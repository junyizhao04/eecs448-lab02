/**
*	@author Junyi Zhao
*	@date Feb 6 2022
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	return m_size;//just return size, did not check, but should done in other functions
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;

	while (!isFound && temp != nullptr){
		isFound = (value == temp -> getValue());//check through all linkedlist pointers until find one true or touched end, touched end and not found means false
		temp = temp -> getNext();

	}

	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	if(m_size == 1){
		lastNode = m_front;
		delete lastNode;
		m_size = 0;
		return true;
	}

	if(!isEmpty()){
		lastNode = m_front -> getNext();
		secondintoLast = m_front;
		for(int i = 0; i < m_size - 2; ++i){//move nodes
			lastNode = lastNode -> getNext();
			secondintoLast = secondintoLast -> getNext();
		}
		delete lastNode;//delete last node
		secondintoLast->setNext(nullptr);//set next of last but one node to null pointer
		m_size--;//minus m size
		isRemoved = true;//set removed to true
	}

	return(isRemoved);//return true if removed
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
