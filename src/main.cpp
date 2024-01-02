#include "pch.hpp"
#include "engine.hpp"

GalEngine game;
GalPage enter;
unordered_map<string,Music*> bgmList;
unordered_map<string,Texture*> textureList;

void setupTextureList()
{
    auto& texture = textureList;
    texture["WC"] = new Texture;
    texture["WC"]->loadFromFile("resource/Image/厕所.jpg");
    texture["Street"] = new Texture;
    texture["Street"]->loadFromFile("resource/Image/大街.jpg");
    texture["KneelNo8"] = new Texture;
    texture["KneelNo8"]->loadFromFile("resource/Image/跪八.png");

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
    bgmList["Sad"]->openFromFile("resource/Music/悲伤.wav");
    bgmList["Sad"]->setLoop(true);
    
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

void setupEnterPage()
{
    using namespace GalObject;
    auto& texture = enter.textureList;
    auto& render = enter.textureList;
    auto& detect = enter.detectionList;
    texture["WC"] = textureList["WC"];
    
}

int main()
{
    game.fontList["index"] = new Font;
    game.fontList["index"]->loadFromFile("resource/Font/SmileySans-Oblique.ttf");
    game.pageList["enter"] = &enter;
    setupBGMList();
    setupTextureList();
    setupEnterPage();
    game.OpenWindow(VideoMode(800,600),U"八号人生");

    game.WaitEnd();
    cleanupBGM();
    cleanupTextureList();
    return 0;
}