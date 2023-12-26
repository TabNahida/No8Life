#include "pch.hpp"

int main()
{
    Font font;
    font.loadFromFile("resource/Font/SmileySans-Oblique.ttf");
    Text text((uint32_t*)(U"老八人生"),font);
    text.setPosition(100,100);
    text.setFillColor(Color::White);
    RenderWindow window(VideoMode(800,600),(uint32_t*)(U"老八人生"),Style::Default);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;
            
            default:
                break;
            }
        }
        window.clear();
        window.draw(text);
        window.display();
    }
    
    return 0;
}