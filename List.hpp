#include "Node.hpp"

template <class T>
class List {
private:
  Node<T>* head;
  Node<T>* tail;
  long currentSize;
  List(List<T>* otherList);

public:
  List();
  void append(T value);
  void appendAt(long index, T value);
  bool removeAt(long index);
  bool remove(T value);
  long size();
  void print();
  void toArray(T* array);
  List<T> operator +(List<T> otherList);
};

template <class T>
List<T>::List(List<T>* otherList) {
  if(otherList -> size() == 0) return;
  Node<T>* currentNode = otherList -> head;
  while(currentNode != NULL) {
    this -> append(currentNode -> getValue());
    currentNode = currentNode -> getNext();
  }
}

template <class T>
List<T>::List() {
  List<T>::head = NULL;
  List<T>::tail = NULL;
  List<T>::currentSize = 0;
}

template <class T>
void List<T>::append(T value) {
  Node<T>* node = new Node<T>(value);
  if(List<T>::head == NULL) List<T>::head = node;
  else List<T>::tail -> setNext(node);
  List<T>::tail = node;
  List<T>::currentSize++;
}

template <class T>
void List<T>::appendAt(long index, T value) {
  if(index < 0) return;
  if(index >= List<T>::currentSize) {
    List<T>::append(value);
    return;
  }
  Node<T>* node = new Node<T>(value);
  if(index == 0) {
    node -> setNext(List<T>::head);
    List<T>::head = node;
    return;
  }
  long currentIndex = 0;
  Node<T>* currentNode = List<T>::head;
  while(currentIndex < index - 1) {
    currentNode = currentNode -> getNext();
    currentIndex++;
  }
  node -> setNext(currentNode -> getNext());
  currentNode -> setNext(node);
}

template <class T>
bool List<T>::removeAt(long index) {
  long currentIndex = 0;
  Node<T>* previousNode = NULL;
  Node<T>* currentNode = List<T>::head;
  while(currentNode != NULL) {
    Node<T>* nextNode = currentNode -> getNext();
    if(currentIndex == index) {
      if(previousNode != NULL) previousNode -> setNext(nextNode);
      else List<T>::head = nextNode;
      if(currentNode == List<T>::tail) List<T>::tail = previousNode;
      List<T>::currentSize--;
      return true;
    }
    previousNode = currentNode;
    currentNode = nextNode;
    currentIndex++;
  }
  return false;
}

template <class T>
bool List<T>::remove(T value) {
  Node<T>* previousNode = NULL;
  Node<T>* currentNode = List<T>::head;
  while(currentNode != NULL) {
    Node<T>* nextNode = currentNode -> getNext();
    if(currentNode -> getValue() == value) {
      if(previousNode != NULL) previousNode -> setNext(nextNode);
      else List<T>::head = nextNode;
      if(currentNode == List<T>::tail) List<T>::tail = previousNode;
      List<T>::currentSize--;
      return true;
    }
    previousNode = currentNode;
    currentNode = nextNode;
  }
  return false;
}

template <class T>
long List<T>::size() {
  return List<T>::currentSize;
}

template <class T>
void List<T>::print() {
  Node<T>* node = List<T>::head;
  std::cout << "[ ";
  while(node != NULL) {
    std::cout << node -> getValue() << " ";
    node = node -> getNext();
  }
  std::cout << "]\n";
}

template <class T>
void List<T>::toArray(T* array) {
  Node<T>* node = List<T>::head;
  long index = 0;
  while(node != NULL) {
    array[index++] = node -> getValue();
    node = node -> getNext();
  }
}

template <class T>
List<T> List<T>::operator +(List<T> otherList) {
  List<T> baseListCopy = List<T>(this);
  List<T> otherListCopy = List<T>(otherList);
  baseListCopy.tail -> setNext(otherListCopy.head);
  baseListCopy.currentSize += otherListCopy.currentSize;
  return baseListCopy;
}
