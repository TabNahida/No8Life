#include "pch.hpp"

namespace GalObject
{

struct RenderObj
{
    enum
    {
        convex = 0, text = 1
    };
    size_t type = convex;
    union object
    {
        ConvexShape* convex;
        Text* text;
    };
    
};

struct Div
{
    ConvexShape div;
    Text text;
    float* unit;
};

class DivBox
{
private:
    Div obj;
public:
    inline void setUnit(float* unit);
    inline void setSize(Vector2f size);
    inline void setPosition(Vector2f pos);
    DivBox();
    ~DivBox();
};

}

class GalPage
{
private:
    list<Texture*> textureList;
    list<RenderObj> renderList;
public:
    GalPage();
    ~GalPage();
};

class GalEngine
{
private:
    RenderWindow* mainWin;
    map<string,Font> fontList;
    float unit;
public:
    void OpenWindow();
    GalEngine(float unit);
    ~GalEngine();
    
};
