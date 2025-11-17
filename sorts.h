#ifndef SORTS_H
#define SORTS_H
#include <stddef.h>
typedef struct { long long steps_cmp, steps_swap; } Metrics;
void reset_metrics(Metrics *m);
void insertion_sort(int *v, size_t n, Metrics *m);
void merge_sort(int *v, size_t n, Metrics *m);
void quick_sort(int *v, size_t n, Metrics *m);
#endif