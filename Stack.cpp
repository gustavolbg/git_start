#include "Stack.h"

struct Node {
  unsigned elem;
  Node* next;
};

Stack::Stack() {
  _top = nullptr;
  _count = 0;
}


void Stack::push(unsigned elem) {
  Node *novo_elemento = new Node;
  novo_elemento->elem = elem;
  if (_top == nullptr)
  {
    _top = novo_elemento;
    novo_elemento->next = nullptr;
    _count = _count + 1;
  }
  else
  {
    novo_elemento->next = _top;
    _top = novo_elemento;
    _count = _count + 1;
  }

}

void Stack::pop() {
  if (_top == nullptr)
  {
    throw EmptyException{};
  }
  else
  {
    Node* aux;
    aux = _top;
    _top = _top->next;
    delete aux;
    _count = _count - 1;
  }
}

unsigned Stack::top() const {
  if (_top == nullptr)
  {
    throw EmptyException{};
  }
  else
  {
    return _top->elem;
  }
  
}

unsigned Stack::count() const {return _count;}