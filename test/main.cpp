#include "/home/michal/Pulpit/projekt_cpp_gra/src/dataStructures/linkedList.cpp"
#include <iostream>
#include<string.h>

struct ObiektTestowy
{
    int width;
    int height;
    //char text[3];
};

int main()
{
    ObiektTestowy obiektTestowy = {0};
    SingleLinkedList<ObiektTestowy> LinkedList;


    for(int i = 0; i<2; i++)
    {
        obiektTestowy.height = i + 1;
        obiektTestowy.width = i + 10;
        //obiektTestowy.text[0] = 48 + i;

        LinkedList.push(obiektTestowy);
    }

    for(int i = 0; i<2; i++)
    {
        obiektTestowy = LinkedList.getElement();
        std::cout<<"Numer: "<< i << ", wartość height: " << obiektTestowy.height << std::endl;
        std::cout<<"Numer: "<< i << ", wartość width: " << obiektTestowy.width << std::endl;
       // std::cout<<"Numer: "<< i << ", wartość text: " << obiektTestowy.text << std::endl;
    }

    LinkedList.deleteList();

    return 0;
}