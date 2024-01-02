#include "engine.hpp"
using namespace GalObject;

//GalEngine

GalEngine::GalEngine()
{
    
}

GalEngine::~GalEngine()
{
    delete mainWin;
}

void GalEngine::RunWindow()
{
    while (mainWin->isOpen())
    {
        mainWin->clear();
        if (renderPage.size() == 0)
        {
            mainWin->display();
            continue;
        }
        for (auto& rax : renderPage)
        {
            rax->draw(mainWin);
        }
        mainWin->display();
    }
}

void GalEngine::RunDetection()
{
    while (mainWin->isOpen())
    {
    Event event;
    while (mainWin->pollEvent(event))
    {
        auto rax = Mouse::getPosition(*mainWin);
        switch (event.type)
        {
        case Event::Closed:
            mainWin->close();
            break;
        case Event::MouseButtonPressed:
            if (renderPage.size() == 0)
            {
                break;
            }
            renderPage.back()->buttonDetect(Vector2f(rax.x,rax.y));
            break;
        case Event::KeyPressed:

            break;
        case Event::MouseMoved:
            if (renderPage.size() == 0)
            {
                break;
            }
            renderPage.back()->hoverDetect(Vector2f(rax.x,rax.y));
            break;
        default:
            break;
        }
    }
    }
}

 void GalEngine::OpenWindow()
{
    mainWin = new RenderWindow;
    mainWin->setFramerateLimit(60);
    mainWinThr = new thread(&GalEngine::RunWindow,this);
    mainDetectThr = new thread(&GalEngine::RunDetection,this);
}

 void GalEngine::OpenWindow(VideoMode winSize, char32_t* name, Uint32 style)
{
    mainWin = new RenderWindow(winSize,(uint32_t*)(name),style);
    mainWin->setFramerateLimit(60);
    mainWinThr = new thread(&GalEngine::RunWindow,this);
    mainDetectThr = new thread(&GalEngine::RunDetection,this);
}

 void GalEngine::setWindowSize(Vector2u winSize)
{
    mainWin->setSize(winSize);
}

 void GalEngine::setTitle(char32_t* name)
{
    mainWin->setTitle((uint32_t*)(name));
}

void GalEngine::WaitEnd()
{
    mainWinThr->join();
    mainDetectThr->join();
}

 RenderWindow* GalEngine::getMainWindow()
{
    return mainWin;
}

//RenderObj

RenderObj::operator ConvexShape*()
{
    if (type == convex)
    {
        return object.convex;
    }
    else
    {
        return nullptr;
    }
}

RenderObj::operator Text*()
{
    if (type == text)
    {
        return object.text;
    }
    else
    {
        return nullptr;
    }
}

RenderObj::RenderObj(ConvexShape* in)
{
    type = convex;
    object.convex = in;
    draw = [&](RenderWindow* win){win->draw(*object.convex);};
}

RenderObj::RenderObj(Text* in)
{
    type = text;
    object.text = in;
    draw = [&](RenderWindow* win){win->draw(*object.text);};
}

//DetectionObj

 bool DetectionObj::isHover(Vector2f input)
{
    if (detectBox.contains(input))
    {
        hover();
        return true;
    }
    return false;
}

 bool DetectionObj::isPress(Vector2f input)
{
    if (detectBox.contains(input))
    {
        press();
        return true;
    }
    return false;
}

//DivBox

DivBox::DivBox()
{
    obj.div.setPointCount(4);
}

DivBox::~DivBox()
{   

}

 void DivBox::setColor(Color color)
{
    obj.div.setFillColor(color);
}

 void DivBox::setTexture(Texture* texture)
{
    obj.div.setTexture(texture);
}

 void DivBox::setMargin(float margin)
{
    this->margin = margin;
}

 void DivBox::setString(char32_t* string)
{
    obj.text.setString((uint32_t*)(string));
}

 void DivBox::setFont(Font* font)
{
    obj.text.setFont(*font);
}

 void DivBox::setFontSize(float size)
{
    obj.text.setCharacterSize(size);
}

 void DivBox::setFontColor(Color color)
{
    obj.text.setFillColor(color);
}

 ConvexShape* DivBox::getDiv()
{
    return &obj.div;
}

 Text* DivBox::getText()
{
    return &obj.text;
}

//GalPage

void GalPage::draw(RenderWindow* win)
{
    for (auto& rax : renderList)
    {
        for (auto& rbx : rax.second)
        {
            rbx.draw(win);
        }
    }
}

void GalPage::buttonDetect(Vector2f input)
{
    for (auto& rax : detectionList)
    {
        if (rax.second.isPress(input))
        {
            rax.second.press();
            return;
        }
    }
}

void GalPage::hoverDetect(Vector2f input)
{
    for (auto& rax : detectionList)
    {
        if (rax.second.isHover(input))
        {
            rax.second.hover();
            return;
        }
    }
}

GalPage::GalPage()
{
    
}

GalPage::~GalPage()
{

}