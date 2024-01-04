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
    bgmList["Erquan"]->openFromFile("resource/Music/二泉映月.ogg");
    bgmList["Erquan"]->setLoop(true);
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
    map<string,RectangleShape*> rect;
}EnterPage;


void setupEnterPage()
{
    auto& rect = EnterPage.rect;
    rect["bgImage"] = new RectangleShape();
}

void drawEnterPage()
{

}

void detectEnterPage(Event event)
{

}

int main()
{
    window = new RenderWindow(VideoMode(800,600),(uint32_t*)(U"八号人生"));
    draw = drawEnterPage;
    detect = detectEnterPage;
    setupBGMList();
    setupTextureList();
    setupEnterPage();
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