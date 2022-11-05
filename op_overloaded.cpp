#include <iostream>
#include <stack>
#include <vector>


using namespace std;
template<class T> class Stack;

//requires: two stacks as arguments
//effects: a stack that has the elements of the two other stacks

template<class T>
Stack<T> operator+( Stack<T>& s1,  Stack<T>& s2){
    Stack<T> res = s1;
     for(int i = 0; i < s1.items.size(); ++i){
        res.items.push_back(s2.items[i]);}
    return res;
}

template<class T>
class Stack{
    friend Stack<T> operator+<>( Stack<T>& s1, Stack<T>& s2);
    vector<T> items;
    public:
        void push(const T &item){
            items.push_back(item);
        }
        T pop(){
            T item = items.back();
            items.pop_back();
            return item;
        }
        bool empty()
        {
            return items.empty();
        }
        
};

//testing our stack
int main(void)
{
    Stack<int> a;
    Stack<int> b;
    a.push(1);
    a.push(2);
    b.push(3);
    b.push(4);
    Stack<int> c = a + b;

    Stack<char> d;
    Stack<char> e;
    d.push('a');
    d.push('b');
    e.push('c');
    e.push('d');
    Stack<char> f = d + e;
    
//printing out the new stack to check 
    while(!c.empty()) {
        cout << c.pop() << "\n";
    }
    cout<<endl;
    while(!f.empty()) {
        cout << f.pop() << "\n";
    }
    return 0;
}