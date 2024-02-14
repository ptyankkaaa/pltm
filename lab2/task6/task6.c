#include <iostream>
using namespace std;

const int MAX_SIZE = 10; // максимальный размер стека

struct Node {
    int value;
    Node* prev;
};

class Stack {
private:
    Node* top; // указатель на вершину стека
    int size; // текущий размер стека
public:
    Stack() {
        top = nullptr;
        size = 0;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    bool isFull() {
        return size == MAX_SIZE;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Стек переполнен" << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->value = value;
        newNode->prev = top;
        top = newNode;
        size++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Стек пуст" << endl;
            return -1;
        }
        Node* temp = top;
        int value = temp->value;
        top = top->prev;
        delete temp;
        size--;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Стек пустой" << endl;
            return -1;
        }
        return top->value;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(25);
    s.push(0);
    cout << "Верхний элемент: " << s.peek() << endl;

    cout << s.pop() << " Извлечён из стека" << endl;
    cout << s.pop() << " Извлечён из стека" << endl;

    cout << "Верхний элемент: " << s.peek() << endl;

    s.push(40);

    cout << "Верхний элемент: " << s.peek() << endl;

    return 0;
}
