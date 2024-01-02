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