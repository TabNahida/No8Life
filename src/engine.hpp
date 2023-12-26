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
    union
    {
        ConvexShape* convex;
        Text* text;
    }object;
    operator ConvexShape*();
    operator Text*();
    RenderObj(ConvexShape* in);
    RenderObj(Text* in);
};

struct Div
{
    ConvexShape div;
    Text text;
    float* unit;
    
};

class DivBox
{
protected:
    Div obj;
    float margin = 0; 
public:
    inline void setColor(Color color);
    inline void setUnit(float* unit);
    inline void setSize(Vector2f size);
    inline void setPosition(Vector2f pos);
    inline void setTexture(Texture* texture);
    inline void setMargin(float margin);
    inline void setString(char32_t* string);
    inline void setFont(Font* font);
    inline void setFontSize(float size);
    inline void setFontColor(Color color);
    inline ConvexShape* getDiv();
    inline Text* getText();
    DivBox();
    DivBox(Vector2f pos,Vector2f size);
    ~DivBox();
};

}

class GalPage
{
private:
    unordered_map<string,Texture*> textureList;
    unordered_map<string,pair<size_t,list<GalObject::RenderObj>>> renderList; 
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
    unordered_map<string,Font> fontList;
    float unit;
    void RunWindow();
public:
    inline void OpenWindow();
    inline void OpenWindow(VideoMode winSize, char32_t* name, Uint32 style = Style::Default);
    inline void setWindowSize(Vector2u winSize);
    inline void setTitle(char32_t* name);
    inline RenderWindow* getMainWindows();
    GalEngine(float unit);
    ~GalEngine();
    
};
