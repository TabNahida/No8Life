#include "engine.hpp"

GalEngine::GalEngine(float unit)
{
    this->unit = unit;
}

GalEngine::~GalEngine()
{
    delete mainWin;
}
