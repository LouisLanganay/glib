/*
** EPITECH PROJECT, 2023
** glib
** File description:
** main
*/

#include "main.h"
#include "gl.h"

void event_window_close(window_s *window)
{
    sfRenderWindow_close(window->window);
}

void test(int id)
{
    printf("test\n");
}

int main(void)
{
    GLib_t *glib = malloc(sizeof(GLib_t));
    glib->window = gl_create_window(1920, 1080, "My window", 60);
    glib->events = NULL;
    glib->buttons = NULL;
    gl_create_event(glib, 544, sfEvtClosed, event_window_close);
    gl_create_event(glib, 888, sfEvtKeyPressed, event_window_close);



    buttons_l *my_btn = malloc(sizeof(buttons_l));
    my_btn->id = 1;
    my_btn->pos = (sfVector2f){0, 0};
    my_btn->sprite = sfSprite_create();
    my_btn->texture = sfTexture_createFromFile("assets/btn/t.png", NULL);
    my_btn->rect = (sfIntRect){0, 0, 100, 100};
    my_btn->call_action = test;
    my_btn->sb_hover = sfSoundBuffer_createFromFile("assets/btn/button1.ogg");
    my_btn->sb_click = sfSoundBuffer_createFromFile("assets/btn/button1.ogg");
    gl_create_button(glib, my_btn);
    gl_create_scene(glib, 1);
    gl_add_button_to_scene(glib, 1, 1);

    while (sfRenderWindow_isOpen(glib->window->window)) {
        gl_draw_scene(glib, 1);
        gl_buttons_hovered(glib->buttons, glib->window);
        gl_check_events(glib->window, glib->events);
        sfClock_restart(glib->window->clock);

        sfRenderWindow_display(glib->window->window);
        sfRenderWindow_clear(glib->window->window, sfBlack);
    }
}
