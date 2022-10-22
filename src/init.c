/*
** EPITECH PROJECT, 2022
** init
** File description:
** desc
*/

#include <unistd.h>
#include "../includes/my.h"
#define WIN ALL->settings.window
#define MODE ALL->settings.mode
#define nb ALL->settings.img_n


void init_window(GLOBAL_T *ALL)
{
    printf("init Window\n");
    MODE.bitsPerPixel = 64;
    MODE.height = 1080;
    MODE.width = 1920;
    WIN = sfRenderWindow_create(MODE, "My Runner", sfResize | sfClose, NULL);
}

void create_obj(GLOBAL_T *ALL, char* str, double sx, double sy, double px, double py)
{
    ALL->pictures[nb].texture = sfTexture_createFromFile(str, NULL);
    ALL->pictures[nb].sprite = sfSprite_create();
    ALL->pictures[nb].scale.x = sx;
    ALL->pictures[nb].scale.y = sy;
    ALL->pictures[nb].pos.x = px;
    ALL->pictures[nb].pos.y = py;
    nb++;
}

void init_sprite(GLOBAL_T *ALL)
{
    nb = 0;
    ALL->pictures = malloc(sizeof(ALL->pictures->sprite) * 100);

    // MAIN MENU 0

    create_obj(ALL, "./content/main-menu.png", 1.12, 1.12, 0, 0);
    create_obj(ALL, "./content/start-button.png", 10, 10, 800, 500);
    create_obj(ALL, "./content/floor.png", 3, 3, 0, 800);
    create_obj(ALL, "./content/floor.png", 3, 3, 2100, 800);

    ALL->pictures[nb].texture = sfTexture_createFromFile("./content/tourelle.png", NULL);
    ALL->pictures[nb].sprite = sfSprite_create();
    ALL->pictures[nb].scale.x = 1.5;
    ALL->pictures[nb].scale.y = 1.5;
    ALL->pictures[nb].pos.x = 170;
    ALL->pictures[nb].pos.y = 750;
    ALL->pictures[nb].origin.x = 50;
    ALL->pictures[nb].origin.y = 50;
}

void applied(GLOBAL_T *ALL)
{
    for (int i = 0; i <= nb; i++) {
        sfSprite_setPosition(ALL->pictures[i].sprite, ALL->pictures[i].pos);
        sfSprite_setScale(ALL->pictures[i].sprite, ALL->pictures[i].scale);
        sfSprite_setOrigin(ALL->pictures[i].sprite, ALL->pictures[i].origin);
        sfSprite_setTexture(ALL->pictures[i].sprite, ALL->pictures[i].texture, sfTrue);
        printf("sprite:%d:%f:%f:applied\n", i, ALL->pictures[i].pos.x, ALL->pictures[i].pos.y);
    }
}

void init (GLOBAL_T *ALL)
{
    init_window(ALL);
    init_sprite(ALL);
    applied(ALL);
}

