/*
** EPITECH PROJECT, 2022
** my main
** File description:
** desc
*/

#include <unistd.h>
#include "../includes/my.h"

int main (void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfEvent event;

    sfTexture *texture = sfTexture_createFromFile("./content/main-menu.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfVector2f scale = {1.12, 1.12};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);

    window = sfRenderWindow_create(mode, "My Runner", sfResize | sfClose, NULL);
    
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }

    return 0;
}

