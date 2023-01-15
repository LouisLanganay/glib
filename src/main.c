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
    rpg_s *rpg = malloc(sizeof(rpg_s));
    rpg->window = gl_create_window(1920, 1080, "My window", 60);
    rpg->events = NULL;
    rpg->buttons = NULL;
    gl_create_event(544, sfEvtClosed, event_window_close, &rpg->events);
    gl_create_event(888, sfEvtKeyPressed, event_window_close, &rpg->events);



    buttons_l *my_btn = malloc(sizeof(buttons_l));
    my_btn->id = 0;
    my_btn->pos = (sfVector2f){0, 0};
    my_btn->sprite = sfSprite_create();
    my_btn->texture = sfTexture_createFromFile("assets/btn/t.png", NULL);
    my_btn->rect = (sfIntRect){0, 0, 100, 100};
    my_btn->call_action = test;
    my_btn->s_hover = sfMusic_createFromFile("assets/btn/button1.ogg");
    gl_create_button(&rpg->buttons, my_btn);



    while (sfRenderWindow_isOpen(rpg->window->window)) {
        gl_draw_button(0, &rpg->buttons, rpg->window);
        gl_buttons_hovered(&rpg->buttons, rpg->window);
        gl_check_events(rpg->window, rpg->events);
        sfClock_restart(rpg->window->clock);

        sfRenderWindow_display(rpg->window->window);
        sfRenderWindow_clear(rpg->window->window, sfBlack);
    }
}
