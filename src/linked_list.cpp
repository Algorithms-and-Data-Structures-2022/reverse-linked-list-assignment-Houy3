#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    if (size_ == 0) {
        return;
    }
    Node* prev = nullptr;
    Node* curr = front_;
    Node* next = front_->next;
    for (int i = 1; i < size_ - 1; i++) {
      prev = curr;
      curr = next;
      next = curr->next;
      curr->next = prev;
    }
    back_->next = curr;
    front_->next = nullptr;

    Node* newFront = back_;
    Node* newBack = front_;
    front_ = newFront;
    back_ = newBack;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    if (size_ == 0) {
      return;
    }
    reverse_recursive_helper(front_->next, front_);

    Node* newFront = back_;
    Node* newBack = front_;
    front_ = newFront;
    back_ = newBack;
    back_->next = nullptr;
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if (curr == nullptr) {
      return;
    }
    Node* next = curr->next;
    curr->next = prev;
    reverse_recursive_helper(next,curr);
  }

}  // namespace assignment
