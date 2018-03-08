#include <iostream>

template <class T>
class Node {
  private:
    T value;
    Node<T>* next;

  public:
    Node(T value);
    T getValue();
    void setValue(T value);
    Node<T>* getNext();
    void setNext(Node<T>* next);
};

template <class T>
Node<T>::Node(T value) {
  Node<T>::value = value;
  Node<T>::next = NULL;
}

template <class T>
T Node<T>::getValue() {
  return Node<T>::value;
}

template <class T>
void Node<T>::setValue(T value) {
  Node<T>::value = value;
}

template <class T>
Node<T>* Node<T>::getNext() {
  return Node<T>::next;
}

template <class T>
void Node<T>::setNext(Node<T>* next) {
  Node<T>::next = next;
}
