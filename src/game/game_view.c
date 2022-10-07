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
    int x_floor = 0;
    sfTexture *floor_t = sfTexture_createFromFile("./content/floor.png", NULL);
    sfSprite *floor_s = sfSprite_create();
    sfVector2f floor_scale = {3, 3};
    sfVector2f floor_pos = {x_floor, 800};

    sfSprite_setTexture(floor_s, floor_t, sfTrue);
    sfSprite_setScale(floor_s, floor_scale);
    sfSprite_setPosition(floor_s, floor_pos);

    int x_floor02 = 2100;
    sfTexture *floor02_t = sfTexture_createFromFile("./content/floor.png", NULL);
    sfSprite *floor02_s = sfSprite_create();
    sfVector2f floor02_scale = {3, 3};
    sfVector2f floor02_pos = {x_floor02, 800};

    sfSprite_setTexture(floor02_s, floor02_t, sfTrue);
    sfSprite_setScale(floor02_s, floor02_scale);
    sfSprite_setPosition(floor02_s, floor02_pos);

    sfTexture *player_t = sfTexture_createFromFile("./content/tourelle.png", NULL);
    sfSprite *player_s = sfSprite_create();
    sfVector2f player_scale = {1.5, 1.5};
    int x = 170;
    int y = 750;
    sfVector2f player_pos = {x, y};
    sfVector2f player_origin = {50, 50};
    float orientation = 35;

    sfSprite_setTexture(player_s, player_t, sfTrue);
    sfSprite_setScale(player_s, player_scale);
    sfSprite_setPosition(player_s, player_pos);
    sfSprite_setOrigin(player_s, player_origin);
    sfWindow_setFramerateLimit(window, 100);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        orientation += 1;
        sfSprite_setRotation(player_s, orientation);
        sfRenderWindow_clear(window, sfBlue);
        sfRenderWindow_drawSprite(window, floor_s, NULL);
        sfRenderWindow_drawSprite(window, floor02_s, NULL);
        sfRenderWindow_drawSprite(window, player_s, NULL);
        sfRenderWindow_display(window);

        if (event.type == sfEvtMouseButtonPressed && y == 750) {
            y = 500;
            sfVector2f player_pos = {x, y};
            sfSprite_setPosition(player_s, player_pos);
        } else if (y != 750) {
            y = y + 2;
            sfVector2f player_pos = {x, y};
            sfSprite_setPosition(player_s, player_pos);
        }
        x_floor = x_floor - 2;
        x_floor02 = x_floor02 - 2;
        sfVector2f floor_pos = {x_floor, 800};
        sfSprite_setPosition(floor_s, floor_pos);
        if (x_floor <= -2100)
            x_floor = 2100;
        sfVector2f floor02_pos = {x_floor02, 800};
        sfSprite_setPosition(floor02_s, floor02_pos);
        if (x_floor02 <= -2100)
            x_floor02 = 2100;
        if (event.type == sfEvtMouseButtonPressed) {
            printf("floor01 : %d\n", x_floor);
            printf("floor02 : %d\n", x_floor02);
        }
    }
}
