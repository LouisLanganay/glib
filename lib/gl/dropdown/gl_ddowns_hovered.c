/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_ddowns_hovered
*/

#include "../gl.h"

static sfBool gl_ddown_is_hovered(dropdown_t *ddown, sfVector2i posM)
{
    sfVector2f posB = ddown->pos;
    if (posM.x >= posB.x && posM.x <= posB.x + 10 &&
    posM.y >= posB.y && posM.y <= posB.y + 10) {
        return sfTrue;
    }
    return sfFalse;
}

static void gl_ddown_hovered(dropdown_t *tmp, void *main, GLib_t *glib)
{
    if (tmp->hovered != sfTrue) {
        tmp->hovered = sfTrue;
    }
    if (tmp->call_action != NULL && sfMouse_isButtonPressed(sfMouseLeft)) {
        tmp->call_action(tmp->id, main);
    }
}

static void gl_ddowns_not_hovered(dropdown_t *tmp, GLib_t *glib)
{
    tmp->hovered = sfFalse;
}

void gl_ddowns_hovered(GLib_t *glib, window_t *window, void *main)
{
    dropdown_t *tmp = glib->ddowns;
    sfVector2i posM = sfMouse_getPositionRenderWindow(window->window);
    while (tmp != NULL) {
        if (tmp->disabled == sfTrue) {
            tmp = tmp->next;
            continue;
        }
        if (gl_ddown_is_hovered(tmp, posM) == sfTrue)
            gl_ddown_hovered(tmp, main, glib);
        else
            gl_ddowns_not_hovered(tmp, glib);
        tmp = tmp->next;
    }
}
