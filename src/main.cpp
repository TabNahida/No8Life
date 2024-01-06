#include "pch.hpp"
//#include "EasyRender.hpp"
//#include "engine.hpp"

unordered_map<string,Music*> bgmList;
unordered_map<string,Texture*> textureList;
RenderWindow* window;
function<void()> draw;
function<void(Event event)> detect;

void setupTextureList()
{
    auto& texture = textureList;
    texture["WC"] = new Texture;
    texture["WC"]->loadFromFile("resource/Image/厕所.jpg");
    texture["Street"] = new Texture;
    texture["Street"]->loadFromFile("resource/Image/大街.jpg");
    texture["KneelNo8"] = new Texture;
    texture["KneelNo8"]->loadFromFile("resource/Image/跪八.png");
    texture["ChopNo8"] = new Texture;
    texture["ChopNo8"]->loadFromFile("resource/Image/砍八.png");
    texture["VomitNo8"] = new Texture;
    texture["VomitNo8"]->loadFromFile("resource/Image/呕八.png");
    texture["NormalNo8"] = new Texture;
    texture["NormalNo8"]->loadFromFile("resource/Image/平八.png");
    texture["Tsuchiya"] = new Texture;
    texture["Tsuchiya"]->loadFromFile("resource/Image/土屋.jpg");
    texture["Building"] = new Texture;
    texture["Building"]->loadFromFile("resource/Image/住宅楼.jpg");
}

void cleanupTextureList()
{
    if (textureList.size() == 0)
    {
        return;
    }
    for (auto& rax : textureList)
    {
        delete rax.second;
    }
}

void setupBGMList()
{
    bgmList["Sad"] = new Music;
    bgmList["Sad"]->openFromFile("resource/Music/悲伤.ogg");
    bgmList["Sad"]->setLoop(true);
    bgmList["Groaning"] = new Music;
    bgmList["Groaning"]->openFromFile("resource/Music/病中吟.ogg");
    bgmList["Groaning"]->setLoop(true);
    bgmList["Erpquan"] = new Music;
    bgmList["Erpquan"]->openFromFile("resource/Music/二泉映月.ogg");
    bgmList["Erpquan"]->setLoop(true);
    bgmList["Satisfy"] = new Music;
    bgmList["Satisfy"]->openFromFile("resource/Music/双脚踏上幸福路.ogg");
    bgmList["Satisfy"]->setLoop(true);
    bgmList["Heart"] = new Music;
    bgmList["Heart"]->openFromFile("resource/Music/追梦赤子心.ogg");
    bgmList["Heart"]->setLoop(true);
}

void cleanupBGM()
{
    if (bgmList.size() == 0)
    {
        return;
    }
    for (auto& rax : bgmList)
    {
        delete rax.second;
    }
}

struct
{
    list<RectangleShape*> rectList;
    map<string,RectangleShape*> rect;

void setupEnterPage()
{
    RectangleShape* rax;
    rax = new RectangleShape;
    rax->setPosition(Vector2f(0,0));
    rax->setSize(Vector2f(1080,720));
    rax->setTexture(textureList["WC"]);
    rax->setTextureRect(IntRect(0,0,960,540));
    rectList.push_back(rax);
    rax = new RectangleShape;
    rax->setPosition(Vector2f(300,270));
    rax->setSize(Vector2f(450,480));
    rax->setTexture(textureList["NormalNo8"]);
    rax->setTextureRect(IntRect(0,0,750,800));
    rect["No8"] = rax;
    rectList.push_back(rax);
}

void cleanupEnterPage()
{
    for (auto& rax : rectList)
    {
        delete rax;
    }
}

void drawEnterPage()
{
    for (auto& rax : rectList)
    {
        window->draw(*rax);
    }
}

void detectEnterPage(Event event)
{
    switch (event.type)
    {
    case Event::Closed:
        window->close();
        break;
    case Event::MouseButtonPressed:

        break;
    case Event::MouseMoved:

        break;
    default:
        break;
    }
}

}EnterPage;

int main()
{
    window = new RenderWindow(VideoMode(1080,720),(uint32_t*)(U"八号人生"));
    draw = []{EnterPage.drawEnterPage();};
    detect = [](Event event){EnterPage.detectEnterPage(event);};
    setupBGMList();
    setupTextureList();
    EnterPage.setupEnterPage();
    window->setFramerateLimit(60);
    while (window->isOpen())
    {
        Event event;
        while (window->pollEvent(event))
        {
            detect(event);
        }
        
        window->clear();
        draw();
        window->display();
    }
    
    cleanupBGM();
    cleanupTextureList();
    return 0;
}