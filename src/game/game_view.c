/*
** EPITECH PROJECT, 2022
** game_function
** File description:
** desc
*/

#include <unistd.h>
#include "../../includes/my.h"

void draw(GLOBAL_T *ALL)
{
    sfRenderWindow_clear(WINDOW, sfBlue);
    sfRenderWindow_drawSprite(WINDOW, IMG[2].sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, IMG[3].sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, IMG[4].sprite, NULL);
    sfRenderWindow_display(WINDOW);
}

static void jump (GLOBAL_T *ALL)
{
    if (EVENT.type == sfEvtMouseButtonPressed && IMG[4].pos.y == 750) {
        IMG[4].pos.y = 500;
        sfSprite_setPosition(IMG[4].sprite, IMG[4].pos);
    } else if (IMG[4].pos.y != 750) {
        IMG[4].pos.y += 2;
        sfSprite_setPosition(IMG[4].sprite, IMG[4].pos);
    }
}

static void floor_animation(GLOBAL_T *ALL)
{
    IMG[2].pos.x -= 2;
    IMG[3].pos.x = IMG[3].pos.x - 2;
    sfSprite_setPosition(IMG[2].sprite, IMG[2].pos);
    if (IMG[2].pos.x <= -2100)
        IMG[2].pos.x = 2100;
    sfSprite_setPosition(IMG[3].sprite, IMG[3].pos);
    if (IMG[3].pos.x <= -2100)
        IMG[3].pos.x = 2100;
}

void game_function(GLOBAL_T *ALL)
{
    float orientation = 35;
    sfWindow_setFramerateLimit(WINDOW, 100);

    while (sfRenderWindow_isOpen(WINDOW)) {
        while (sfRenderWindow_pollEvent(WINDOW, &EVENT)) {
            if (EVENT.type == sfEvtClosed) {
                sfRenderWindow_close(WINDOW);
            }
        }
        orientation++;
        sfSprite_setRotation(IMG[4].sprite, orientation);
        draw(ALL);
        jump(ALL);
        floor_animation(ALL);
    }
}
