/*
** EPITECH PROJECT, 2022
** my main
** File description:
** desc
*/

#include <unistd.h>
#include "../includes/my.h"

void if_click(sfRenderWindow* window, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    if (mouse.x >= 816 && mouse.x <= 1062) {
        if (mouse.y >= 526 && mouse.y <= 594) {
            if (event.type == sfEvtMouseButtonPressed)
                game_function(window, event);
        }
    }
}

int main (void)
{
    sfVideoMode mode = {1920, 1080, 64};
    sfRenderWindow* window;
    sfEvent event;

    sfTexture *texture = sfTexture_createFromFile("./content/main-menu.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfTexture *texture02 = sfTexture_createFromFile("./content/start-button.png", NULL);
    sfSprite *button = sfSprite_create();

    sfVector2f scale = {1.12, 1.12};
    sfVector2f scale_button = {10, 10};

    sfVector2f pos_button = {800, 500};


    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);

    sfSprite_setTexture(button, texture02, sfTrue);
    sfSprite_setScale(button, scale_button);
    sfSprite_setPosition(button, pos_button);

    window = sfRenderWindow_create(mode, "My Runner", sfResize | sfClose, NULL);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }

        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, button, NULL);
        sfRenderWindow_display(window);

        if_click(window, event);
    }

    return 0;
}

