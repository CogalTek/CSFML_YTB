/*
** EPITECH PROJECT, 2022
** my main
** File description:
** desc
*/

#include <unistd.h>
#include "../includes/my.h"

static void if_click(GLOBAL_T *ALL)
{
    int i = 0;
    sfVector2i mouse = sfMouse_getPosition(WINDOW);

    if (mouse.x >= 816 && mouse.x <= 1062)
        if (mouse.y >= 526 && mouse.y <= 594)
            i = 1;
    if (EVENT.type == sfEvtMouseButtonPressed && i)
        game_function(ALL);
}

static void play (GLOBAL_T *ALL)
{
    while (sfRenderWindow_isOpen(WINDOW)) {
        while (sfRenderWindow_pollEvent(WINDOW, &EVENT)) {
            if (EVENT.type == sfEvtClosed) {
                sfRenderWindow_close(WINDOW);
            }
        }
        sfRenderWindow_clear(WINDOW, sfBlack);
        sfRenderWindow_drawSprite(ALL->settings.window, ALL->pictures[0].sprite, NULL);
        sfRenderWindow_drawSprite(WINDOW, IMG[1].sprite, NULL);
        sfRenderWindow_display(WINDOW);

        if_click(ALL);
    }
}

int main (void)
{
    GLOBAL_T ALL;

    init(&ALL);
    play(&ALL);
    return 0;
}

