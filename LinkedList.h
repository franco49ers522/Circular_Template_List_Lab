#ifndef CIRCULARTEMPLATEDLIST_LINKEDLIST_H
#define CIRCULARTEMPLATEDLIST_LINKEDLIST_H

#include <iostream>
#include <memory>

template <typename T>
struct Node {
    T* data;
    Node* next;
};

template <typename Pointer>
class LinkedList;

template <typename T>
class LinkedList<T*> {
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    Node<T>* current = nullptr;

public:
    LinkedList() = default;
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    ~LinkedList() {
        if (tail) {
            tail->next = nullptr;  // Break the circle before deleting nodes.
        }
        while (head) {
            Node<T>* next = head->next;
            delete head->data;
            delete head;
            head = next;
        }
    }

    // Each inserted item belongs to this list.
    void insert(T* item) {
        if (!item) return;
        std::unique_ptr<T> owner(item);
        Node<T>* node = new Node<T>{item, head};
        owner.release();
        if (!head) {
            head = current = node;
        } else {
            tail->next = node;
        }
        tail = node;
        tail->next = head;
    }

    void displayList() const {
        if (!head) {
            std::cout << "[Playlist is empty.]\n";
            return;
        }
        const Node<T>* node = head;
        int index = 1;
        std::cout << "\n--- Current Playlist ---\n";
        do {
            std::cout << index++ << ". " << node->data->toString() << '\n';
            node = node->next;
        } while (node != head);
    }

    void playCurrent() const {
        if (current) {
            current->data->play();
        } else {
            std::cout << "[Playlist is empty. Nothing to play.]\n";
        }
    }

    void playNext() {
        if (current) current = current->next;
        playCurrent();
    }
};

#endif
