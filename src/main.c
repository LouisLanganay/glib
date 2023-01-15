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

int main(void)
{
    rpg_s *rpg = malloc(sizeof(rpg_s));
    rpg->window = gl_create_window(800, 600, "My window", 60);
    rpg->events = NULL;
    rpg->sprites = NULL;
    rpg->texts = NULL;
    gl_create_event(544, sfEvtClosed, event_window_close, &rpg->events);
    gl_create_event(888, sfEvtKeyPressed, event_window_close, &rpg->events);

    sprite_t *sprite = malloc(sizeof(sprite_t));
    sprite->id = 1;
    sprite->pos = (sfVector2f){0, 0};
    sprite->scale = (sfVector2f){1, 1};
    sprite->texture = sfTexture_createFromFile("/home/peron/glib/src/cross.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->call_action = NULL;
    sprite->next = NULL;
    gl_create_sprite(&rpg->sprites, sprite);
    sprite_t *sprite2 = malloc(sizeof(sprite_t));
    sprite2->id = 2;
    sprite2->pos = (sfVector2f){100, 100};
    sprite2->scale = (sfVector2f){1, 1};
    sprite2->texture = sfTexture_createFromFile("/home/peron/glib/src/cross.png", NULL);
    sprite2->sprite = sfSprite_create();
    sprite2->call_action = NULL;
    sprite2->next = NULL;
    gl_create_sprite(&rpg->sprites, sprite2);
    text_t *text = malloc(sizeof(text_t));
    text->id = 1;
    text->pos = (sfVector2f){0, 0};
    text->scale = (sfVector2f){1, 1};
    text->color = sfWhite;
    text->font = sfFont_createFromFile("/home/peron/glib/src/OpenSans-Regular.ttf");
    text->text = sfText_create();
    text->string = "Hello world";
    text->next = NULL;
    gl_create_text(&rpg->texts, text);
    while (sfRenderWindow_isOpen(rpg->window->window)) {
        gl_check_events(rpg->window, rpg->events);
        sfRenderWindow_clear(rpg->window->window, sfBlack);
        gl_draw_sprites(rpg->window, rpg->sprites);
        gl_draw_texts(rpg->window, rpg->texts);
        sfRenderWindow_display(rpg->window->window);
        sfClock_restart(rpg->window->clock);
    }

}
