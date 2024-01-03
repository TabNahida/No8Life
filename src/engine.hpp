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
    FloatRect detectBox;
    function<void()> hover;
    function<void()> press;
    bool isHover(Vector2f input);
    bool isPress(Vector2f input);
};


struct Div
{
    ConvexShape div;
    Text text;
};

class DivBox
{
protected:
    Div obj;
    float margin = 0;
public:
    void setColor(Color color);
    void setTexture(Texture* texture);
    void setMargin(float margin);
    void setString(char32_t* string);
    void setFont(Font* font);
    void setFontSize(float size);
    void setFontColor(Color color);
    ConvexShape* getDiv();
    Text* getText();
    DivBox();
    ~DivBox();
};

class DivBoxButton : public DivBox
{
protected:
    DetectionObj buttonBox;
public:
    function<void()> runFuc;
    DivBoxButton();
    DivBoxButton(Vector2f pos, Vector2f size);
    ~DivBoxButton();
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
    void buttonDetect(Vector2f input);
    void hoverDetect(Vector2f input);
    GalPage();
    ~GalPage();
};

class GalEngine
{
private:
    RenderWindow* mainWin;
    thread* mainWinThr;
    thread* mainDetectThr;
    void RunWindow();
    void RunDetection();
public:
    list<GalPage*> renderPage;
    unordered_map<string,Font*> fontList;
    unordered_map<string,GalPage*> pageList;
    void OpenWindow();
    void OpenWindow(VideoMode winSize, char32_t* name, Uint32 style  = Style::Default);
    void setWindowSize(Vector2u winSize);
    void setTitle(char32_t* name);
    void WaitEnd();
    RenderWindow* getMainWindow();
    GalEngine();
    ~GalEngine();
};
