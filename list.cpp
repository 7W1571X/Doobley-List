#include <iostream>

namespace dl
{
    template <typename T>
    class list
    {
    private:
        struct Node
        {
            T data;
            Node* head;
            Node* tail;
        };
        
        Node* point{ new Node };
        
        void setNode (int node)
        {
            while (point->head != nullptr)
                point = point->head;
                
            for (int i{}; i < node; i++)
            {
                if (point->tail != nullptr)
                    point = point->tail;
                else
                {
                    std::cout << "ERROR: Cannot exceed list limit.\n";
                    break;
                }
            }
                
            return;
        }
        
    public:
        list (int nodes)
        {
            Node* link{ point };
            point->head = nullptr;
            
            for (int i{}; i <= nodes -2; i++)
            {
                point = new Node;
                link->tail = point;
                point->head = link;
                link = link->tail;
            }
            
            point->tail = nullptr;
            return;
        }
        
        list (const list& copy)
        {
            Node* temp = copy.point;
            Node* link{ point };
            
            while (temp->head != nullptr)
                temp = temp->head;
                
            while (temp->tail != nullptr)
            {
                point->data = temp->data;
                point = new Node;
                link->tail = point;
                point->head = link;
                temp = temp->tail;
            }
            
            point->tail = nullptr;
            return;
        }
        
        ~list()
        {
            while (point->head != nullptr)
            {
                point = point->head;
                delete point->tail;
            }
            
            delete point;   
            return;
        }
        
        void setData (int node, T data)
        {
            setNode(node);
            point->data = data;
            return;
        }
        
        T grabData (int node)
        {
            setNode(node);
            return point->data;
        }
        
        void print ()
        {
            setNode(0);
            while (point->tail != nullptr)
            {
                std::cout << point->data << "\n";
                point = point->tail;
            }
            
            std::cout << point->data << "\n";
            return;
        }
        
        void print (int node)
        {
            setNode(node);
            std::cout << point->data;
            return;
        }
    };
}

int main()
{
    dl::list<int> list{ 3 };
    list.setData(0, 0);
    list.setData(1, 1);

    for (int i{}; i < 10; i++)
    {
        list.setData(2, list.grabData(0) + list.grabData(1));
        list.print(0);
        
        list.setData(0, list.grabData(1));
        list.setData(1, list.grabData(2));
        
        if (i < 9)
            std::cout << ", ";
    }

    return 0;
}
