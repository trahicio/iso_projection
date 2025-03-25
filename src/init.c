/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** .
*/

#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Graphics/VertexArray.h>
#include <SFML/System/Vector3.h>
#include <math.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../include/my.h"

sfVector3f project_iso_point(int x, int y, int z)
{
    sfVector3f vector;
    double my_z = z;

    vector.x = cos(45 * M_PI / 180) * x - cos(45 * M_PI / 180) * y;
    vector.y = sin(35 * M_PI / 180) * y + sin(35 * M_PI / 180) * x - my_z / 3;
    vector.x *= 150 * 0.7;
    vector.y *= 150 * 0.7;
    vector.x += 640;
    vector.y += 125;
    vector.z = z;
    return vector;
}

sfVector3f **creat2dmap(int **map3d, int size)
{
    sfVector3f **vector_table = malloc(sizeof(sfVector3f *)* (size +1));

    for (int i = 0; i != size; i++) {
        vector_table[i] = malloc(sizeof(sfVector3f) * (size + 1));
        for (int u = 0; u != size; u++)
            vector_table[i][u] = project_iso_point(i, u, map3d[i][u]);
    }
    return vector_table;
}

sfVertexArray *create_line(sfVector3f *point1, sfVector3f *point2,
    sfVector3f *point3, sfVector3f *point4)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position.x = point1->x, .position.y = point1->y,
        .color = my_color(point1->z)};
    sfVertex vertex2 = {.position.x = point2->x, .position.y = point2->y,
        .color = my_color(point2->z)};
    sfVertex vertex3 = {.position.x = point3->x, .position.y = point3->y,
        .color = my_color(point3->z)};
    sfVertex vertex4 = {.position.x = point4->x, .position.y = point4->y,
        .color = my_color(point4->z)};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_setPrimitiveType(vertex_array, sfTrianglesStrip);
    return (vertex_array);
}

static sfVertexArray *build_line(int i, int u, int size, sfVector3f **map_2d)
{
    if (u + 1 <= size - 1 && i + 1 <= size - 1)
        return create_line(&map_2d[i][u], &map_2d[i][u + 1],
            &map_2d[i + 1][u], &map_2d[i + 1][u + 1]);
    else
        return create_line(&map_2d[i][u], &map_2d[i][size - 1],
            &map_2d[i][size - 1], &map_2d[size - 1][size - 1]);
}

sfVertexArray **draw_2d_map(sfRenderWindow *window, sfVector3f **map_2d,
    int size, int **array)
{
    sfVertexArray **lines = malloc(sizeof(sfVertexArray *) *(size * size + 1));

    for (int i = 0; i != size; i++)
        for (int u = 0; u != size; u++)
            lines[i * size + u] = build_line(i, u, size, map_2d);
    return lines;
}

int **set_int(int size)
{
    int **array = NULL;
    int h = 5;

    if (!size || size <= 0)
        size = 8;
    array = malloc(sizeof(int *) * (size + 1));
    for (int i = 0; i != size; i++) {
        array[i] = malloc(sizeof(int) * (size + 1));
        for (int u = 0; u != size; u++)
            array[i][u] = rand() % (h);
    }
    return array;
}
