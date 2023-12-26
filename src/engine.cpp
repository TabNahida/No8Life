#include "engine.hpp"
using namespace GalObject;

//GalEngine

GalEngine::GalEngine(float unit)
{
    this->unit = unit;
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

        mainWin->display();
    }
}

void GalEngine::RunDefection()
{
    Event event;
    while (mainWin->pollEvent(event))
    {
        switch (event.type)
        {
        case Event::Closed:
            mainWin->close();
            break;
        case Event::MouseButtonPressed:

            break;
        case Event::KeyPressed:

            break;
        default:
            break;
        }
    }
    if (mainWin->isOpen())
    {
        return RunDefection();
    }
}

inline void GalEngine::OpenWindow()
{
    mainWin = new RenderWindow;
}

inline void GalEngine::OpenWindow(VideoMode winSize, char32_t* name, Uint32 style)
{
    mainWin = new RenderWindow(winSize,(uint32_t*)(name),style);
}

inline void GalEngine::setWindowSize(Vector2u winSize)
{
    mainWin->setSize(winSize);
}

inline void GalEngine::setTitle(char32_t* name)
{
    mainWin->setTitle((uint32_t*)(name));
}

inline RenderWindow* GalEngine::getMainWindow()
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
}

RenderObj::RenderObj(Text* in)
{
    type = text;
    object.text = in;
}

//DivBox

DivBox::DivBox()
{
    obj.div.setPointCount(4);
}

DivBox::DivBox(Vector2f pos,Vector2f size)
{
    obj.div.setPointCount(4);
}

DivBox::~DivBox()
{   

}

inline void DivBox::setColor(Color color)
{
    obj.div.setFillColor(color);
}

inline void DivBox::setUnit(float* unit)
{
    obj.unit = unit;
}

inline void DivBox::setSize(Vector2f size)
{
    auto unit = *obj.unit;
    obj.div.setPoint(0,Vector2f(0,0));
    obj.div.setPoint(1,Vector2f(size.x,0));
    obj.div.setPoint(2,Vector2f(size.x*unit,size.y*unit));
    obj.div.setPoint(3,Vector2f(0,size.y*unit));
}

inline void DivBox::setPosition(Vector2f pos)
{
    auto unit = *obj.unit;
    obj.div.setPosition(Vector2f(pos.x*unit,pos.y*unit));
    obj.text.setPosition(Vector2f((pos.x+margin)*unit,(pos.y+margin)*unit));
}

inline void DivBox::setTexture(Texture* texture)
{
    obj.div.setTexture(texture);
}

inline void DivBox::setMargin(float margin)
{
    this->margin = margin;
}

inline void DivBox::setString(char32_t* string)
{
    obj.text.setString((uint32_t*)(string));
}

inline void DivBox::setFont(Font* font)
{
    obj.text.setFont(*font);
}

inline void DivBox::setFontSize(float size)
{
    auto unit = *obj.unit;
    obj.text.setCharacterSize(unit*size);
}

inline void DivBox::setFontColor(Color color)
{
    obj.text.setFillColor(color);
}

inline ConvexShape* DivBox::getDiv()
{
    return &obj.div;
}

inline Text* DivBox::getText()
{
    return &obj.text;
}

void GalPage::draw(RenderWindow* win)
{
    for (auto rax : renderList)
    {
        for (auto rbx : rax.second)
        {
            
        }
    }
}

GalPage::GalPage()
{
    
}

GalPage::~GalPage()
{

}