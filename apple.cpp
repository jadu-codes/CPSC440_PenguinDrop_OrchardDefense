#include "apple.h"
#include <allegro5/allegro_primitives.h>
#include <cmath>

Apple::Apple()
{
    x = 0;
    y = 0;
    dx = 0;
    dy = 0;
    live = false;
    speed = 11;
    bound = 16;

    image = al_create_bitmap(32, 32);
    al_set_target_bitmap(image);
    al_clear_to_color(al_map_rgba(0, 0, 0, 0));

    al_draw_filled_circle(16, 18, 12, al_map_rgb(220, 0, 0));
    al_draw_filled_rectangle(15, 3, 18, 12, al_map_rgb(90, 50, 20));
    al_draw_filled_ellipse(22, 8, 8, 4, al_map_rgb(0, 180, 40));
}

Apple::~Apple()
{
    al_destroy_bitmap(image);
}

void Apple::fire(Cannon& cannon)
{
    if (!live)
    {
        x = cannon.getX();
        y = cannon.getY() - 55;

        float angle = cannon.getAngle() - 1.57f;

        dx = cos(angle) * speed;
        dy = sin(angle) * speed;

        live = true;
    }
}

void Apple::update()
{
    if (live)
    {
        x += dx;
        y += dy;

        if (x < 0 || x > 900 || y < 0 || y > 800)
            live = false;
    }
}

void Apple::draw()
{
    if (live)
        al_draw_bitmap(image, x - 16, y - 16, 0);
}

void Apple::collideRaccoon(Raccoon raccoons[], int size, int& score)
{
    if (!live)
        return;

    for (int i = 0; i < size; i++)
    {
        if (raccoons[i].getLive())
        {
            if (x > raccoons[i].getX() &&
                x < raccoons[i].getX() + raccoons[i].getBoundX() &&
                y > raccoons[i].getY() &&
                y < raccoons[i].getY() + raccoons[i].getBoundY())
            {
                live = false;
                raccoons[i].setLive(false);
                score++;
            }
        }
    }
}

bool Apple::getLive()
{
    return live;
}