#include <iostream>

template<typename MyStruct>
class SingleLinkedList
{
    private:
        struct ListElement_s
        {
            MyStruct userObject;

            unsigned int index;
            ListElement_s *next;
        }*ListElement = nullptr;


        void getTail(ListElement_s *&tail);
        void getTail(ListElement_s *&tail, ListElement_s *prevTail);
        void getByIndex(ListElement_s *node, unsigned int index);

        unsigned int index;

    public:
        ~SingleLinkedList();
        //void insertElement(MyStruct myObject, unsigned int index);
        //void deleteElement(unsigned int index);
        void deleteList();
        void push(MyStruct myObject);
        void pop();
        MyStruct getElement();
        MyStruct getElement(unsigned int index);
};



/*********Private methods**********/
template<typename MyStruct>
void SingleLinkedList<MyStruct>::getTail(ListElement_s *&tail)
{
    tail = ListElement;

    while(tail->next != nullptr)
    {
        tail = tail->next;
    }
}

template<typename MyStruct>
void SingleLinkedList<MyStruct>::getTail(ListElement_s *&tail, ListElement_s *prevTail)
{
    tail = ListElement;
    while(tail->next != nullptr)
    {
        prevTail = tail;
        tail = tail->next;
    }
}

template<typename MyStruct>
void SingleLinkedList<MyStruct>::getByIndex(ListElement_s *node, unsigned int index)
{
    node = ListElement;
    while((node->next != nullptr) && (node->index != index))
    {
        node = node->next;
    }
    if(node->index != index)
    {
        node = nullptr;
    }
}


/*********Constructors and descrutors**********/

template<typename MyStruct>
SingleLinkedList<MyStruct>::~SingleLinkedList()
{
    deleteList();
}

/*********Public API**********/

template <typename MyStruct>
void SingleLinkedList<MyStruct>::push(MyStruct myObject)
{
    if(ListElement == nullptr)
    {
        ListElement = new ListElement_s;

        ListElement->userObject = myObject;
        ListElement->next = nullptr;
        ListElement->index = 0;
        index = 0;
    }else
    {
        ListElement_s *tail, *newNode;
        getTail(tail);
        newNode = new ListElement_s;
        index++;
        newNode->userObject = myObject;
        newNode->index = index;
        newNode->next = nullptr;
        tail->next = newNode;
    }
}

template <typename MyStruct>
void SingleLinkedList<MyStruct>::pop()
{
    ListElement_s *tail, *prevTail;

    getTail(tail, prevTail);
    if(tail != nullptr)
    {
        delete tail;
        prevTail->next = nullptr;
        index--;
    }
}

template <typename MyStruct>
void SingleLinkedList<MyStruct>::deleteList()
{
    if(ListElement != nullptr)
    {
        while(ListElement->next != nullptr)
        {
            pop();
            std::cout<<"POP\n";
        }
        delete ListElement;
        ListElement = nullptr;
        index = 0;
    }
}

template <typename MyStruct>
MyStruct SingleLinkedList<MyStruct>::getElement()
{
    ListElement_s *tail;

    getTail(tail);
    std::cout<<tail->userObject.width<<std::endl;

    return tail->userObject;
}

template <typename MyStruct>
MyStruct SingleLinkedList<MyStruct>::getElement(unsigned int index)
{
    ListElement_s *node;

    getByIndex(node, index);

    return node.userObject;
}