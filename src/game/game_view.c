/*
** EPITECH PROJECT, 2022
** game_function
** File description:
** desc
*/

#include <unistd.h>
#include "../../includes/my.h"

void game_function(sfRenderWindow* window, sfEvent event)
{
    sfTexture *floor_t = sfTexture_createFromFile("./content/floor.png", NULL);
    sfSprite *floor_s = sfSprite_create();
    sfVector2f floor_scale = {3, 3};
    sfVector2f floor_pos = {0, 800};

    sfSprite_setTexture(floor_s, floor_t, sfTrue);
    sfSprite_setScale(floor_s, floor_scale);
    sfSprite_setPosition(floor_s, floor_pos);

    sfTexture *player_t = sfTexture_createFromFile("./content/tourelle.png", NULL);
    sfSprite *player_s = sfSprite_create();
    sfVector2f player_scale = {1.5, 1.5};
    sfVector2f player_pos = {100, 670};

    sfSprite_setTexture(player_s, player_t, sfTrue);
    sfSprite_setScale(player_s, player_scale);
    sfSprite_setPosition(player_s, player_pos);



    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }

        sfRenderWindow_clear(window, sfBlue);
        sfRenderWindow_drawSprite(window, floor_s, NULL);
        sfRenderWindow_drawSprite(window, player_s, NULL);
        sfRenderWindow_display(window);
    }
}
