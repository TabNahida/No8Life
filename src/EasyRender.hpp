#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <chrono>
#include <thread>
#include <tuple>
#include <variant>
#include <utility>
#include <memory>
using namespace std;

#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

namespace EasyRender
{
    class EasyWindow
    {
    private:
        RenderWindow* win;
    public:
        operator RenderWindow*();
        EasyWindow();
        ~EasyWindow();
    };

    class EasyPage
    {
    private:
        
    public:
        EasyPage();
        ~EasyPage();
    };

}