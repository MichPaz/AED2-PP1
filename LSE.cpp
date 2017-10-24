#include <iostream>

template <typename T>
class node
{
public:
	T item;
	node* next;

	node(){
		next = NULL;
	}
};

template <typename T>
class list
{
public:
	node<T>* first;
	node<T>* last;

	list(){
		first = new node<T>();
		first->next = NULL;
		last = first;
	}

	void insert(T);
	void remove(T);
	void show();
	T get(int);
	int size();
	node<T>* search(T);
	node<T>* prev(node<T>*);
	void destroy();
};

template <typename T>
void list<T>::insert(T item)
{
	last->next = new node<T>();
	last = last->next;
	last->next = NULL;
	last->item = item;
}

template <typename T>
void list<T>::remove(T item)
{
	node<T>* nod = search(item);
	if((first == last) || (nod == NULL) || (nod == first))
		std::cout<<"NAO ROLA\n";
	else{
		node<T>* p = prev(nod);
		p->next = nod->next;
		if (p->next == NULL)
			last = p;
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

template <typename T>
node<T>* list<T>::search(T item)
{
	node<T>* n = first->next;
	while((n!=NULL)&&(n->item!=item))
		n = n->next;
	return n;
}

template <typename T>
void list<T>::show()
{
	if(first==last)
		std::cout<<"LISTA VAZIA\n";
	else{
		node<T>* nod = first->next;
		while(nod!=NULL){
			if(nod!=NULL)
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
    int c = 0;
    node<T>* nod = first->next;
	while(nod!=NULL){
		if(nod!=NULL)
			c++;
		nod = nod->next;
	}
	return c;
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

	std::cout << "LISTA APAGADA\n";
}
