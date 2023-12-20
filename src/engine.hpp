#include "pch.hpp"



class GalEngine
{
private:
    RenderWindow* mainWin;
    map<string,Font> fontList;
    list<Texture*> textureList;
    float unit;
public:
    GalEngine(float unit);
    ~GalEngine();
    
};
