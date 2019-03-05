/*
 * queue.h
 *
 *  Created on: 2018
 *      Author: Antonio Francesco Fiore
 */

#ifndef QUEUE_H_
#define QUEUE_H_

template <class value_type>
class queue;

template <class value_type>
class node{
	friend class queue<value_type>;
	private:
		value_type value;
		node* previous;
		node* next;
};

template<class value_type>
class queue{
	public:
    	queue();
    	~queue ();
    	void clear();
    	bool empty() const;
    	int size() const;
    	value_type front() const;
    	value_type back() const;
    	void push(value_type v);
    	void pop();
	private:
    	node<value_type>* head;
    	node<value_type>* tail;
    	int length;
};

template<class value_type>
queue<value_type>::queue(){
	head = nullptr;
	tail = nullptr;
	length = 0;
};

template<class value_type>
queue<value_type>::~queue(){
	clear();
}

template<class value_type>
void queue<value_type>::clear(){
	while(!empty())
		pop();
}

template <class value_type>
bool queue<value_type>::empty() const{
	return head==nullptr && length==0;
}

template <class value_type>
int queue<value_type>::size() const{
	return length;
}

template <class value_type>
value_type queue<value_type>::front() const{
		return head->value;
}

template <class value_type>
value_type queue<value_type>::back() const{
		return tail->value;
}

template <class value_type>
void queue<value_type>::push(value_type elem){
	node<value_type>* temp = new node<value_type>();
	if(empty())
		head = tail = temp;
	else
		tail->next = temp;
	temp->next = nullptr;
	temp->previous = tail;
	temp->value = elem;
	tail=temp;
	length++;
}

template <class value_type>
void queue<value_type>::pop(){
	if(!empty()){
		node<value_type>* temp = head;
		head = head->next;
		delete temp;
		length--;
	}
}

#endif /* QUEUE_H_ */
