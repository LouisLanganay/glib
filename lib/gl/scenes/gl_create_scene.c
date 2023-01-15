/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_create_scene
*/

#include "../gl.h"

static int handle_error(int id)
{
    if (id < 0)
        return write(2, "(gl_create_scene) Scene id must be positive\n", 44);
    return (0);
}

static int gl_create_scene_check_id(scenes_t *scenes, int id)
{
    scenes_t *tmp = scenes;
    while (tmp != NULL) {
        if (tmp->id == id)
            return write(2, "(gl_create_scene) Scene id already exist\n", 41);
        tmp = tmp->next;
    }
    return (0);
}

int gl_create_scene(scenes_t **scenes, int id)
{
    if (handle_error(id) != 0)
        return (84);
    if (gl_create_scene_check_id(*scenes, id) != 0)
        return (84);
    scenes_t *tmp = malloc(sizeof(*tmp));
    if (tmp == NULL)
        return write(2, "(gl_create_scene) Malloc failed\n", 32);
    tmp->id = id;
    tmp->buttons = NULL;
    tmp->texts = NULL;
    tmp->sprites = NULL;

    tmp->next = *scenes;
    *scenes = tmp;
    return (0);
}