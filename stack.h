/*
 * stack.h
 *
 *  Created on: 2018
 *      Author: Antonio Francesco Fiore
 */

#ifndef STACK_H_
#define STACK_H_

template <class value_type>
class stack;

template <class value_type>
class node{
	friend class stack<value_type>;
	private:
		value_type value;
		node* previous;
};

template <class value_type>
class stack{
	public:
		stack();
		~stack();
		void clear();
		bool empty() const;
		int size() const;
		value_type top() const;
		void push(value_type v);
		void pop();
	private:
		node<value_type>* head;
		int length;
};

template <class value_type>
stack<value_type>::stack(){
	head = nullptr;
	length = 0;
}

template <class value_type>
stack<value_type>::~stack(){
	clear();
}

template <class value_type>
void stack<value_type>::clear(){
	while(!empty())
		pop();
}

template <class value_type>
bool stack<value_type>::empty() const{
	return head == nullptr && length == 0;
}

template <class value_type>
int stack<value_type>::size() const{
	return length;
}

template <class value_type>
value_type stack<value_type>::top() const{
	return head->value;
}

template <class value_type>
void stack<value_type>::push(value_type v){
	node<value_type>* temp = new node<value_type>();
	temp->value = v;
	temp->previous = head;
	head = temp;
	length++;
}

template <class value_type>
void stack<value_type>::pop(){
	if (!empty()){
		node<value_type>* temp = head;
		head=head->previous;
		delete temp;
		length--;
	}
}

#endif /* STACK_H_ */

