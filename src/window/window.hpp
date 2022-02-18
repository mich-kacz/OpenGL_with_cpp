#include <GLFW/glfw3.h>
#include <string>

class Window
{
    public:
        struct windowParameters_s
        {
            int height;
            int width;
            std::string name;
            GLFWwindow* window;
        }*windowParameters;

    public:
        Window(int height, int width, std::string name);
        ~Window();

        void startLoop();

    private:
        static void resizeCallback(GLFWwindow* window, int width, int height);
        windowParameters_s* createNewWindow(int width, int height, std::string name);
};