#include <iostream>

template <typename T>
class node
{
public:
	T item;
	node* next;
	node* previous;
	int id;

	node(){
		next = NULL;
	}
};

template <typename T>
class list
{
public:
	int cont;
	node<T>* first;
	node<T>* last;

	list(){
		first = new node<T>();
		first->previous = NULL;
		

		last = new node<T>();
		last->next = NULL;
		last->previous = first;
		first->next = last;

		cont = 0;

		last->id = cont;
	}

	void insert(T);
	void remove(T);
	void show();
	T get(int);
	int size();
	node<T>* at(int);
	node<T>* prev(node<T>*);
	void destroy();
};

template <typename T>
void list<T>::insert(T item)
{
	last->item = item;

	last->next = new node<T>();
	last->next->previous = last;
	last = last->next;
	last->next = NULL;	

	cont++;

	last->id = cont;
}

/*
template <typename T>
void list<T>::remove(T item)
{
	node<T>* nod = search(item);
	if((first == last) || (nod == NULL) || (nod == first))
		std::cout<<"NAO ROLA\n";
	else{
		node<T>* p = nod->previous;
		
		p->next = nod->next;
		
		if (p->next == NULL)
			last = p;
		else
			nod->next->previous = p;

		delete nod;
	}
}

template <typename T>
node<T>* list<T>::prev(node<T>* nod)
{
	node<T>* n = first;
	while(n->next != nod)
		n = n->next;
	return n;
}
*/
template <typename T>
node<T>* list<T>::at(int ind)
{
	node<T>* n = first->next;
	while((n!=last)&&(n->id != ind))
		n = n->next;
	return n;
}


template <typename T>
void list<T>::show()
{
	if(last->id == 0)
		std::cout<<"LISTA VAZIA\n";
	else{
		node<T>* nod = first->next;
		while(nod->next!=NULL){
			if(nod->next!=NULL)
				std::cout << nod->item << "\t";
			nod = nod->next;
		}
		std::cout << std::endl;
	}
}

template <typename T>
T list<T>::get(int i)
{
    int c = 0;
    node<T>* nod = first->next;
	while(nod!=NULL){
        if(c==i){
            return nod->item;
        }
		if(nod!=NULL)
			c++;
		nod = nod->next;
	}
	return NULL;
}

template <typename T>
int list<T>::size()
{
	return cont;
}

template <typename T>
void list<T>::destroy()
{
	node<T>* nod = first;
	while(nod!=NULL){
		node<T>* n = nod;
		nod = nod->next;
		delete n;
	}

	first = new node<T>();
	first->next = NULL;
	last = first;

//	std::cout << "LISTA APAGADA\n";
}

