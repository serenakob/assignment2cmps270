#include <iostream>
#include <string>
#include <vector>

using namespace std;
template <class T>
class Stack{
private:
    vector<T> arr;
public:
    void push(T k);
    bool pop();
    T top();
    bool empty();
    T size();
    Stack<T> operator+(Stack<T> stack2);
};
int main()
{
    Stack<int> stack;
    Stack<int> stack2;
    stack.push(4);
    stack.push(3);
    std::cout << stack.top();
    std::cout << "\n";
    stack2.push(3);
    stack2.push(4);
    stack2.pop();
    stack2.push(6);
    stack2.pop();
    std::cout << stack.top();
    std::cout << "\n";
    Stack<int> a = stack + stack2;
    std::cout << a.top();
    return 0;
}

//requires: nothing
//effects: add item to the stack
template <class T>
void Stack<T>::push(T k)
{
    arr.push_back(k);
}

//requires: nothing
//effects: check if stack is empty
template <class T>
bool Stack<T>::empty(){
    return arr.size() == 0;
}

//requires: nothing
//effects: check if stack is empty and removes the most-recently-added item from the stack is not
template <class T>
bool Stack<T>::pop()
{
    if (empty() == true)
        return false;
    arr.pop_back();
    return true;
}

//requires: nothing
//effects: finds size of stack
template <class T>
T Stack<T>::size(){
    return arr.size();
}
//requires: nothing
//effects: returns a reference to the most-recently-added item
template <class T>
T Stack<T>::top(){
    return arr[arr.size() - 1];
}
//requires: nothing
//effects: adds two stacks together
template <class T>
Stack<T> Stack<T>::operator+(Stack<T> stack2){
    Stack<T> news;
    vector<T> temp;
    int stackSize = Stack<T>::size(),stack2Size = stack2.size();
    for (int i = 0; i < stack2Size; i++){
        temp.push_back(stack2.top());
        stack2.pop();
    }
    for (int i = 0; i < stackSize; i++){
        temp.push_back(Stack<T>::top());
        Stack<T>::pop();
    }
    int size = temp.size();
    for (int i = 0; i < size; i++){
        news.push(temp.back());
    std:
        temp.pop_back();
    }
    return news;
}

