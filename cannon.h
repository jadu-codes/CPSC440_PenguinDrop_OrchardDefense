#ifndef CANNON_H
#define CANNON_H

#include <allegro5/allegro.h>

class Cannon
{
public:
    Cannon();
    ~Cannon();

    void rotateLeft();
    void rotateRight();
    void draw();

    float getX();
    float getY();
    float getAngle();

private:
    float x;
    float y;
    float angle;
    ALLEGRO_BITMAP* image;
};

#endif