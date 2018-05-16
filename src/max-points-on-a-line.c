#include <max-points-on-a-line.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
} scale;

static scale *scale_create(int a, int b) {
    scale *s = (scale *) malloc(sizeof(scale));
    s->a = a;
    s->b = b;
    return s;
}

static bool scale_equal(scale *s1, scale *s2) {
    int64_t tmp1 = (int64_t) s1->a * (int64_t) s2->b;
    int64_t tmp2 = (int64_t) s1->b * (int64_t) s2->a;
    return tmp1 == tmp2;
}

static void scale_free(scale *s) {
    free(s);
}

#define HASH_MAP_SIZE 256

#define M_DBL_MAX (1.7976931348623158e+308)

typedef struct Entry {
    scale *key;
    int value;
    struct Entry *next;
} entry;

typedef struct {
    entry entries[HASH_MAP_SIZE];
} hashmap;

static int hash_code(scale *key) {
    double val;
    if (key->b == 0) {
        val = M_DBL_MAX;
    } else {
        val = (double) key->a / (double) key->b;
    }
    u_int64_t bits = ((u_int64_t *) &val)[0];
    return (int) (bits ^ (bits >> 32));
}

static hashmap *hashmap_create() {
    hashmap *map = (hashmap *) malloc(sizeof(hashmap));
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        (map->entries + i)->next = NULL;
    }
    return map;
}

static void hashmap_increase(hashmap *map, scale *key) {
    int index = hash_code(key) & (HASH_MAP_SIZE - 1);
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (scale_equal(e->next->key, key)) {
            ++(e->next->value);
            return;
        }
        e = e->next;
    }
    entry *new = (entry *) malloc(sizeof(entry));
    new->key = key;
    new->value = 1;
    new->next = NULL;
    e->next = new;
}

static int hashmap_get(hashmap *map, scale *key) {
    int index = hash_code(key) & (HASH_MAP_SIZE - 1);
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (scale_equal(e->next->key, key)) {
            return e->next->value;
        }
        e = e->next;
    }
    return 0;
}

static void hashmap_clear(hashmap *map, void operate(scale *)) {
    entry *e, *tmp;
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        e = map->entries + i;
        while (e->next != NULL) {
            tmp = e->next;
            e->next = tmp->next;
            operate(tmp->key);
            free(tmp);
        }
    }
}

static void hashmap_free(hashmap *map, void operate(scale *)) {
    hashmap_clear(map, operate);
    free(map);
}

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxPoints_149(struct Point *points, int pointsSize) {
    if (points == NULL || pointsSize < 0) return -1;
    if (pointsSize < 3) return pointsSize;

    hashmap *map = hashmap_create();

    int max = 1;
    for (int i = 0; i < pointsSize - 1; ++i) {
        int point_max = 1;
        int same_point = 0;
        for (int j = i + 1; j < pointsSize; ++j) {
            scale *s = scale_create(points[j].y - points[i].y, points[j].x - points[i].x);
            if (s->a == 0 && s->b == 0) {
                ++same_point;
                ++point_max;
            } else {
                hashmap_increase(map, s);
                int count = hashmap_get(map, s);
                point_max = MAX(point_max, count + 1 + same_point);
            }
        }
        hashmap_clear(map, scale_free);
        max = MAX(max, point_max);
    }

    hashmap_free(map, scale_free);
    return max;
}
