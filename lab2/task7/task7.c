#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;

const int MAX_SIZE = 100; // максимальный размер стека

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
            return -1;
        }
        return top->value;
    }
};

int main() {
    int result = 0;
    Stack s;

    ifstream inputFile("input.txt");
    if (!inputFile) {
        cout << "Failed to open input file." << endl;
        return 1;
    }

    string expression;
    getline(inputFile, expression);
    inputFile.close();

    for (char& c : expression) {
        if (isdigit(c)) {
            s.push(int(c) - 48);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int operand2 = s.peek();
            s.pop();
            int operand1 = s.peek();
            s.pop();

            switch (c) {
                case '+':
                    s.push(operand1 + operand2);
                    break;
                case '-':
                    s.push(operand1 - operand2);
                    break;
                case '*':
                    s.push(operand1 * operand2);
                    break;
                case '/':
                    s.push(operand1 / operand2);
                    break;
            }
        }
    }
    cout << "Получилось: " << s.peek() << endl;
    return 0;
}
