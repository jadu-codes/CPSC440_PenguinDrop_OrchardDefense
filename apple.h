#ifndef APPLE_H
#define APPLE_H

#include <allegro5/allegro.h>
#include "raccoon.h"
#include "cannon.h"

class Apple
{
public:
    Apple();
    ~Apple();

    void fire(Cannon& cannon);
    void update();
    void draw();
    void collideRaccoon(Raccoon raccoons[], int size, int& score);

    bool getLive();

private:
    float x;
    float y;
    float dx;
    float dy;
    bool live;
    float speed;
    int bound;
    ALLEGRO_BITMAP* image;
};

#endif