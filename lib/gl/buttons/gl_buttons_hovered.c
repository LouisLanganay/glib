/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_buttons_hovered
*/

#include "../gl.h"

static sfBool gl_button_in_hovered(buttons_l *button, sfVector2i posM)
{
    sfVector2f posB = sfSprite_getPosition(button->sprite);
    if (posM.x >= posB.x && posM.x <= posB.x + button->rect.width &&
    posM.y >= posB.y && posM.y <= posB.y + button->rect.height) {
        return sfTrue;
    }
    return sfFalse;
}

static void gl_button_hovered(buttons_l *tmp)
{
    if (tmp->hovered != sfTrue) {
        tmp->hovered = sfTrue;
        if (tmp->s_hover != NULL) {
            sfMusic_setPlayingOffset(tmp->s_hover, sfSeconds(0));
            sfMusic_play(tmp->s_hover);
        }
    }
    tmp->rect.left = tmp->rect.width;
    if (tmp->call_action != NULL && sfMouse_isButtonPressed(sfMouseLeft))
        tmp->call_action(tmp->id);
}

static void gl_button_not_hovered(buttons_l *tmp)
{
    tmp->hovered = sfFalse;
    tmp->rect.left = 0;
}

void gl_buttons_hovered(buttons_l **buttons, window_s *window)
{
    buttons_l *tmp = *buttons;
    sfVector2i posM = sfMouse_getPositionRenderWindow(window->window);
    while (tmp != NULL) {
        sfVector2f posB = sfSprite_getPosition(tmp->sprite);
        if (gl_button_in_hovered(tmp, posM) == sfTrue)
            gl_button_hovered(tmp);
        else
            gl_button_not_hovered(tmp);
        tmp = tmp->next;
    }
}