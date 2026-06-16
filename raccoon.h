#ifndef RACCOON_H
#define RACCOON_H

#include <allegro5/allegro.h>

class Raccoon
{
public:
    Raccoon();
    ~Raccoon();

    void start(int width);
    void update(int height, int basketY, int& landed);
    void draw();

    int getX();
    int getY();
    int getBoundX();
    int getBoundY();
    bool getLive();
    void setLive(bool status);

private:
    int x;
    int y;
    int speed;
    int boundx;
    int boundy;
    bool live;
    ALLEGRO_BITMAP* image;
};

#endif