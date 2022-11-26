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
        dooblist()
        {
            if (Elements > 0)
            {
                point = new Node;
                point->head = nullptr;
                
                Node* link{ point };
                for (int i{}; i < Elements; i++)
                {
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
        
        dooblist (const std::initializer_list<T>& init)
        {
            if (Elements > 0)
            {
                point = new Node;
                point->head = nullptr;
                
                Node* link{ point };
                for (int i{}; i < Elements; i++)
                {
                    point = new Node;
                    link->tail = point;
                    point->head = link;
                    link = link->tail;
                }
                
                point->tail = nullptr;
                
                while (point->head != nullptr)
                    point = point->head;
                    
                for (auto data : init)
                {
                    point->data = data;
                    point = point->tail;
                }
            }
            else
                point = nullptr;
                
            return;
        }
        
        int size()
        {
            int nodes{};
            while (point->head != nullptr)
                point = point->head;
                
            while (point->tail != nullptr)
            {
                point = point->tail;
                nodes++;
            }
            
            return nodes;
        }
        
        T& operator[] (const int& node)
        {
            while (point->head != nullptr)
                point = point->head;
                
            for (int i{}; i < node; i++)
                point = point->tail;
                
            return point->data;
        }
        
        ~dooblist()
        {
            while (point != nullptr)
                point = point->tail;
                
            while (point != nullptr)
            {
                point = point->tail;
                delete point->head;
            }
            
            delete point;
            return;
        }
    };
}
