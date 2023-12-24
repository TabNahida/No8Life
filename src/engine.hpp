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
    float margin = 0; 
public:
    inline void setColor(Color color);
    inline void setUnit(float* unit);
    inline void setSize(Vector2f size);
    inline void setPosition(Vector2f pos);
    inline void setTexture(Texture* texture);
    inline void setFont(Font* font);
    inline void setFontSize(float size);
    DivBox();
    DivBox(Vector2f pos,Vector2f size);
    ~DivBox();
};

}

class GalPage
{
private:
    unordered_map<string,Texture*> textureList;
    map<string,list<RenderObj>> renderList;
    Color indexTextColor;
    Color indexDivColor;
    Color indexBackgoundColor;
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
