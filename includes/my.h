/*
** EPITECH PROJECT, 2022
** MY_H
** File description:
** desc
*/

#ifndef MY_H_
    # define MY_H_

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>
    #include "struct.h"
    #include <stdio.h>

    #define sfCf sfTexture_createFromFile
    #define sfWc sfRenderWindow_create
    #define WINDOW ALL->settings.window
    #define EVENT ALL->settings.event
    #define IMG ALL->pictures

    void game_function(GLOBAL_T *ALL);
    void init (GLOBAL_T *ALL);

#endif
