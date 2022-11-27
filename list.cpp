#include <iostream>

namespace tds
{
    template<typename T, std::size_t Elements>
    class dooblist
    {
    private:
        struct Node
        {
            T data;
            Node* head;
            Node* tail;
        };
        
        Node* point;
        
    public:
        dooblist (void) // EX: tds::dooblist<int, 1> fib;
        {
            if (Elements > 0) {
                point = new Node;
                point->head = nullptr;
                
                Node* link{ point };
                for (int i{}; i < Elements; i++) {
                    point = new Node;
                    link->tail = point;
                    point->head = link;
                    link = link->tail;
                }
                
                point->tail = nullptr;
            }
            else
                point = nullptr;
                
            return;
        }
        
        dooblist (const std::initializer_list<T>& init) // tds::dooblist<int, 1> fib{ 1 };
        {
            if (Elements > 0) {
                point = new Node;
                point->head = nullptr;
                
                Node* link{ point };
                for (int i{}; i < Elements; i++) {
                    point = new Node;
                    link->tail = point;
                    point->head = link;
                    link = link->tail;
                }
                
                point->tail = nullptr;
                
                while (point->head != nullptr)
                    point = point->head;
                    
                for (auto data : init) {
                    point->data = data;
                    point = point->tail;
                }
            }
            else
                point = nullptr;
                
            return;
        }
        
        T& operator[] (const int& node) // Allows for use of grabbing and setting values using []
        {
            while (point->head != nullptr)
                point = point->head;
                
            for (int i{}; i < node; i++)
                point = point->tail;
                
            return point->data;
        }
        
        int size (void) // Returns size of list, EX: list.size() - has value of int
        {
            int nodes{};
            while (point->head != nullptr)
                point = point->head;
                
            while (point->tail != nullptr) {
                point = point->tail;
                nodes++;
            }
            
            return nodes;
        }
        
        ~dooblist() // Deconstructs list when finished
        {
            while (point != nullptr)
                point = point->tail;
                
            while (point != nullptr) {
                point = point->tail;
                delete point->head;
            }
            
            delete point;
            return;
        }
    };
}

int main() // Quick Test
{
    tds::dooblist<int, 3> fib{ 0, 1 };
    for (int i{}; i < 10; i++) {
        fib[2] = fib[0] + fib[1];
        std::cout << fib[0];
        
        fib[0] = fib[1];
        fib[1] = fib[2];
        
        if (i != 9)
            std::cout << ", ";
    }
    
    std::cout << std::endl;
    tds::dooblist<int, 3> foo{ fib };
    
    for (int i{}; i < foo.size(); i++)
        std::cout << foo[i] << ", ";
    
    return 0;
}
