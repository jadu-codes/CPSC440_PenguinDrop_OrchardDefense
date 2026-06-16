#include "raccoon.h"
#include <allegro5/allegro_primitives.h>
#include <cstdlib>

Raccoon::Raccoon()
{
    x = 0;
    y = 0;
    speed = 1 + rand() % 3;
    live = false;
    boundx = 50;
    boundy = 50;

    image = al_create_bitmap(50, 50);
    al_set_target_bitmap(image);
    al_clear_to_color(al_map_rgba(0, 0, 0, 0));

    al_draw_filled_circle(25, 25, 22, al_map_rgb(120, 120, 120));
    al_draw_filled_circle(15, 18, 5, al_map_rgb(0, 0, 0));
    al_draw_filled_circle(35, 18, 5, al_map_rgb(0, 0, 0));
    al_draw_filled_rectangle(10, 13, 40, 23, al_map_rgb(40, 40, 40));
    al_draw_filled_triangle(5, 10, 15, 0, 20, 15, al_map_rgb(90, 90, 90));
    al_draw_filled_triangle(45, 10, 35, 0, 30, 15, al_map_rgb(90, 90, 90));
}

Raccoon::~Raccoon()
{
    al_destroy_bitmap(image);
}

void Raccoon::start(int width)
{
    if (!live)
    {
        if (rand() % 120 == 0)
        {
            live = true;
            x = rand() % (width - boundx);
            y = -boundy;
            speed = 1 + rand() % 3;
        }
    }
}

void Raccoon::update(int height, int basketY, int& landed)
{
    if (live)
    {
        y += speed;

        if (y + boundy >= basketY)
        {
            live = false;
            landed++;
        }

        if (y > height)
            live = false;
    }
}

void Raccoon::draw()
{
    if (live)
        al_draw_bitmap(image, x, y, 0);
}

int Raccoon::getX()
{
    return x;
}

int Raccoon::getY()
{
    return y;
}

int Raccoon::getBoundX()
{
    return boundx;
}

int Raccoon::getBoundY()
{
    return boundy;
}

bool Raccoon::getLive()
{
    return live;
}

void Raccoon::setLive(bool status)
{
    live = status;
}