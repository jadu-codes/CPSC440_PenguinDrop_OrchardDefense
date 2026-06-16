#include "cannon.h"
#include <allegro5/allegro_primitives.h>

Cannon::Cannon()
{
    x = 450;
    y = 720;
    angle = 0;

    image = al_create_bitmap(90, 90);
    al_set_target_bitmap(image);
    al_clear_to_color(al_map_rgba(0, 0, 0, 0));

    al_draw_filled_rectangle(38, 10, 52, 55, al_map_rgb(120, 80, 30));
    al_draw_filled_circle(45, 60, 28, al_map_rgb(90, 50, 20));
    al_draw_filled_circle(45, 60, 18, al_map_rgb(160, 90, 30));
}

Cannon::~Cannon()
{
    al_destroy_bitmap(image);
}

void Cannon::rotateLeft()
{
    angle -= 0.03f;

    if (angle < -1.05f)
        angle = -1.05f;
}

void Cannon::rotateRight()
{
    angle += 0.03f;

    if (angle > 1.05f)
        angle = 1.05f;
}

void Cannon::draw()
{
    al_draw_rotated_bitmap(image, 45, 60, x, y, angle, 0);
}

float Cannon::getX()
{
    return x;
}

float Cannon::getY()
{
    return y;
}

float Cannon::getAngle()
{
    return angle;
}