#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack
{
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int val)
    {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }
    void pop() 
    {
        if (isEmpty()) 
        {
            cout << "Stack is empty!Cannot remove element" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    bool isEmpty() 
    {
        return top == nullptr;
    }
    int peek()
    {
        if (isEmpty()) 
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }
    void display() 
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* current = top;
        cout << "Stack elements : ";
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.display();

    cout << "Top of the stack : " << stack.peek() << endl;

    stack.pop();

    stack.display();

    return 0;
}
