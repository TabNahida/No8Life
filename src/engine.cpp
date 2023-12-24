#include "engine.hpp"
using namespace GalObject;

GalEngine::GalEngine(float unit)
{
    this->unit = unit;
}

GalEngine::~GalEngine()
{
    delete mainWin;
}

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



GalPage::GalPage()
{

}

GalPage::~GalPage()
{

}