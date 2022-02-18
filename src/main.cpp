#include <iostream>
#include <thread>

#include "window.hpp"


int main(int argc, char **argv)
{
    std::cout<<"HELLO\n";

    windowCreator myWindow(640, 480, "OKNO");


    std::thread th1(&windowCreator::startLoop, &myWindow);
    
    std::cout<<"THREAD START\n";

    th1.join();

    std::cout<<"BYE BYE\n";
    
    return 0;
}