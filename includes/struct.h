/*
** EPITECH PROJECT, 2022
** STRUCT_H_
** File description:
** desc
*/

#ifndef STRUCT_H_
    # define STRUCT_H_

    // structure
    typedef struct PARAMETER {
        sfVideoMode mode;
        sfRenderWindow* window;
        sfEvent event;
        int img_n;
    } PARAMETER_T;

    typedef struct IMG {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f scale;
        sfVector2f pos;
        sfVector2f size;
        sfVector2f origin;
    } IMG_T;

    typedef struct GLOBAL {
        PARAMETER_T settings;
        IMG_T *pictures;
    } GLOBAL_T;

#endif
