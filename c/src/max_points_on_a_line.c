#include "max_points_on_a_line.h"

#include <stdbool.h>
#include <stdlib.h>

#define M_DBL_MAX (1.7976931348623158e+308)

typedef struct {
    int delta_x;
    int delta_y;
} slope;

static slope *scale_create(struct Point *p1, struct Point *p2) {
    slope *s = (slope *) malloc(sizeof(slope));
    s->delta_x = p1->x - p2->x;
    s->delta_y = p1->y - p2->y;
    return s;
}

static bool slope_equals(slope *s1, slope *s2) {
    int64_t tmp1 = (int64_t) s1->delta_x * s2->delta_y;
    int64_t tmp2 = (int64_t) s1->delta_y * s2->delta_x;
    return tmp1 == tmp2;
}

static int slope_hash(slope *key) {
    double val;
    val = key->delta_x == 0 ? M_DBL_MAX : (double) key->delta_y / key->delta_x;
    u_int64_t bits = ((u_int64_t *) &val)[0];
    return (int) (bits ^ (bits >> 32));
}

static void slope_free(slope *s) {
    free(s);
}

#define HASH_MAP_SIZE 256

typedef struct Entry {
    void *key;
    int value;
    struct Entry *next;
} entry;

typedef struct {
    entry table[HASH_MAP_SIZE];

    int (*hash_code)(void *);

    bool (*key_equals)(void *, void *);
} hashmap;

static hashmap *hashmap_create(int hash(void *), bool equals(void *, void *)) {
    hashmap *map = (hashmap *) malloc(sizeof(hashmap));
    entry *e = map->table;
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        (e + i)->next = NULL;
    }
    map->hash_code = hash;
    map->key_equals = equals;
    return map;
}

static int hashmap_increase(hashmap *map, void *key) {
    int index = slope_hash(key) & (HASH_MAP_SIZE - 1);
    entry *h = map->table + index, *e = h->next;
    while (e != NULL) {
        if (map->key_equals(e->key, key))
            return ++e->value;
        e = e->next;
    }
    e = (entry *) malloc(sizeof(entry));
    e->key = key;
    e->value = 1;
    e->next = h->next;
    h->next = e;
    return 1;
}

static void hashmap_clear(hashmap *map, void operate(void *)) {
    entry *h, *tmp;
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        h = map->table + i;
        while (h->next != NULL) {
            tmp = h->next;
            h->next = tmp->next;
            operate(tmp->key);
            free(tmp);
        }
    }
}

static void hashmap_free(hashmap *map, void operate(void *)) {
    hashmap_clear(map, operate);
    free(map);
}

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxPoints_149_1(struct Point *points, int pointsSize) {
    if (points == NULL || pointsSize < 0) return -1;
    if (pointsSize < 3) return pointsSize;

    hashmap *map = hashmap_create((int (*)(void *)) slope_hash, (bool (*)(void *, void *)) slope_equals);

    int max = 1;
    for (int i = 0; i < pointsSize - 1; ++i) {
        int point_max = 1;
        int same_point = 0;
        for (int j = i + 1; j < pointsSize; ++j) {
            slope *s = scale_create(points + i, points + j);
            if (s->delta_x == 0 && s->delta_y == 0) {
                ++same_point;
                slope_free(s);
            } else {
                int count = hashmap_increase(map, s);
                point_max = MAX(point_max, count + 1);
            }
        }
        point_max += same_point;
        max = MAX(max, point_max);
        hashmap_clear(map, (void (*)(void *)) slope_free);
    }

    hashmap_free(map, (void (*)(void *)) slope_free);
    return max;
}
