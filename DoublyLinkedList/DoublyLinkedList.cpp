#include <iostream>


class DoublyLinkedList {
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };
private:
    Node* list = nullptr;
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    void Head()
    {
        Node* current = list;
        while (current->prev != nullptr)
        {
            current = current->prev;
        }
        head = current;
    }

    void Tail()
    {
        Node* current = list;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        tail = current;
    }

    void push_back(int data)
    {
        if (list == nullptr)
        {
            list = new Node{ data, nullptr, nullptr };
            return;
        }
        Tail();
        Node* current = tail;
        current->next = new Node{ data, nullptr, current };

    }

    void push_front(int data)
    {
        if (list == nullptr)
        {
            list = new Node{ data, nullptr, nullptr };
            return;
        }
        Head();
        Node* current = head;
        current->prev = new Node{ data, current, nullptr };
    }

    void display()
    {
        if (list == nullptr)
        {
            std::cout << "list is empty\n";
            tail = nullptr;
            head = nullptr;
            return;
        }
        Head();
        Node* current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";

    }
    void pop_back()
    {
        if (list == nullptr)
        {
            std::cout << "list is empty\n";
            return;
        }
        Head();
        Node* current = head;
        if (current->next == nullptr && current->prev == nullptr)
        {
            list = nullptr;
            return;
        }
        while (current->next->next != nullptr)
        {
            current = current->next;
        }
        list = current;
        current->next = nullptr;

    }

    void pop_front()
    {
        if (list == nullptr)
        {
            std::cout << "list is empty\n";
            return;
        }
        Tail();
        Node* current = tail;
        if (current->next == nullptr && current->prev == nullptr)
        {
            list = nullptr;
            return;
        }
        while (current->prev->prev != nullptr)
        {
            current = current->prev;
        }
        list = current;
        current->prev = nullptr;
    }

    void sort() {
        if (list == nullptr) {
            std::cout << "Пустой лист" << std::endl;
            tail = nullptr;
            head = nullptr;
        }
        else {
            Node* current = head->next;

            Node* end = nullptr;
            while (current != end)
            {
                if (current->data < current->prev->data)
                {
                    int data = current->prev->data;
                    current->prev->data = current->data;
                    current->data = data;

                }
                if (current->next == end)
                {
                    end = current;
                    current = head;

                }
                current = current->next;
            }
        }
    }

    void remove_duplicates()
    {
        if (head == nullptr) return; //список пустой - ничего не делаем

        Node* curr = head; //присваиваем текущему элементу голову списка

        while (curr != nullptr) { //пока текущий эл. не пустой / конец списка
            Node* sled = curr->next; //указатель, который является значением следующего элемента

            while (sled != nullptr) { //если не конец списка, то проверяем на ноличие клона -_-
                if (curr->data == sled->data) { //если текущий эл. равен следующему, то О УЖАС

                    Node* dupl = sled; //запомниаем указатель на дубликат (Большой босс следит за ним)
                    sled->prev->next = sled->next; //меняем указатель предыдущего элемента на следующий, чтобы при удалениии не было пустых (чего? ячеек?)
                    if (sled->next != nullptr) { //если не конец списка
                        sled->next->prev = sled->prev; //меняем указатель следующего элемента на предыдущий
                    }
                    sled = sled->next; //проверяем след. эл.
                    dupl = nullptr; //удаляем дубликат
                }
                else {
                    sled = sled->next; //переход к след. узлу  для проверки наличия дубликата, если не найден дубль
                }
            }
            curr = curr->next; //переход к след. узлу, который будет проверяться на дубликат
        }
    }

    };

    int main()
    {
        DoublyLinkedList list;
        std::cout << "List of Doubly Linked List Functions\n\n1. Add element to beginning.\n2. Add element to end.\n3. Delete element from beginning.\n4. Delete element from end.\n5. Display list.\n6. Sort list.\n7. Remove duplicates.\n8. Exit\n";
        bool enabled = true;
        while (enabled)
        {
            int chosed;
            int elem;
            std::cout << "Enter the doubly linked list function number\n";
            std::cin >> chosed;
            switch (chosed)
            {
            case 1:

                std::cout << "Enter the value\n";
                std::cin >> elem;
                list.push_front(elem);
                break;

            case 2:

                std::cout << "Enter the value\n";
                std::cin >> elem;
                list.push_back(elem);
                break;
            case 3:
                list.pop_front();
                break;
            case 4:
                list.pop_back();
                break;
            case 5:
                list.display();
                break;
            case 6:
                list.sort();
                break;
            case 7:
                list.remove_duplicates();
                break;
            case 8:
                enabled = false;
                break;
            default:
                std::cout << "There is no such function in the program.\n";
                std::cout << "List of Doubly Linked List Functions\n\n1. Add element to beginning.\n2. Add element to end.\n3. Delete element from beginning.\n4. Delete element from end.\n5. Display list.\n6. Sort list.\n7. Remove duplicates.\n8. Exit\n";
                break;
            }
        }
    }

