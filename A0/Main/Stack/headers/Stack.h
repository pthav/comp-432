#ifndef STACK_H
#define STACK_H

// this is the node class used to build up the LIFO stack
template <class Data>
class Node
{
private:
    Data holdMe;
    Node* next;

public:
    ~Node() = default;

    Node(const Data& holdMe) : holdMe(holdMe), next(nullptr)
    {
    }

    void SetNext(Node* n)
    {
        next = n;
    }

    Node* GetNext()
    {
        return next;
    }

    Data GetData()
    {
        return holdMe;
    }
};

// a simple LIFO stack
template <class Data>
class Stack
{
    Node<Data>* head;

public:
    // destroys the stack
    ~Stack()
    {
        while (head != nullptr)
        {
            Node<Data>* curr = head;
            head = head->GetNext();
            delete curr;
        }
    }

    // creates an empty stack
    Stack() : head{nullptr}
    {
    }

    // adds pushMe to the top of the stack
    void push(const Data& d)
    {
        Node<Data>* newNode = new Node<Data>(d);
        newNode->SetNext(head);
        head = newNode;
    }

    // return true if there are not any items in the stack
    bool isEmpty() { return head == nullptr; }

    // pops the item on the top of the stack off, returning it...
    // if the stack is empty, the behavior is undefined
    Data pop()
    {
        if (isEmpty())
        {
            return Data{};
        }

        Node<Data>* nextNode = head->GetNext();
        head->SetNext(nullptr);
        Data d = head->GetData();
        delete head;
        head = nextNode;
        return d;
    }
};

#endif
