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
    function<void(RenderWindow*)> draw;
};

struct DetectionObj
{
    
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

class DivBoxButton : public DivBox
{
protected:
    
public:
    DivBoxButton();
    DivBoxButton(Vector2f pos, Vector2f size);
};

}

class GalPage
{
private:

public:
    unordered_map<string,Texture*> textureList;
    map<string,list<GalObject::RenderObj>> renderList;
    map<string,GalObject::DetectionObj> detectionList;
    void draw(RenderWindow* win);
    GalPage();
    ~GalPage();
};

class GalEngine
{
private:
    RenderWindow* mainWin;
    list<GalPage*> renderPage;
    float unit;
    thread* mainThr;
    void RunWindow();
    void RunDetection();
public:
    unordered_map<string,Font> fontList;
    unordered_map<string,GalPage*> pageList;
    inline void OpenWindow();
    inline void OpenWindow(VideoMode winSize, char32_t* name, Uint32 style = Style::Default);
    inline void setWindowSize(Vector2u winSize);
    inline void setTitle(char32_t* name);
    inline RenderWindow* getMainWindow();
    GalEngine(float unit);
    ~GalEngine();
    
};
