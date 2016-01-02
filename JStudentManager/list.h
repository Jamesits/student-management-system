//
//  immutable_list.h
//  JStudentManager
//
//  Created by James Swineson on 1/2/16.
//  Copyright © 2016 James Swineson. All rights reserved.
//

#ifndef immutable_list_h
#define immutable_list_h

#include "common.h"
#include "organization_list.h"
#include "student_list.h"

#define new_list(X) _Generic((x), \
                                student_list: new_student_list \
                                organization_list: new_organization_list \
                                )(X)

typedef struct list_node {
    struct list_node *next_node;
    void *data;
} *list_node;


typedef struct list {
    long length;
    size_t data_size;
    struct list_actionset {
        struct list (*action_new)(struct list*, void(*list_type_specific_initializer_type)(struct list));
        void (*list_delete)(struct list);
        struct list (*list_append)(struct list, list_node);
        struct list (*list_remove)(struct list, list_node);
        struct list (*list_search)(struct list, bool(*list_type_specific_search_compare_function_type)(struct list, void*), void*);
        void (*list_foreach)(struct list, void(*list_type_specific_enumerator_yield_callback_function_type)(list_node));
        void (*list_qsort)(struct list, int(*list_type_specific_sort_compare_function_type)(list_node, list_node));
        void (*list_serialize)(struct list, string(*list_type_specific_node_serializer_type)(list_node));
    } actionset;
    list_node first_node;
} *list;

typedef void(*list_type_specific_initializer_type)(list);
typedef bool(*list_type_specific_search_compare_function_type)(list, void*);
typedef void(*list_type_specific_enumerator_yield_callback_function_type)(list_node);
typedef int(*list_type_specific_sort_compare_function_type)(list_node, list_node);
typedef string(*list_type_specific_node_serializer_type)(list_node);

list list_new(list*, list_type_specific_initializer_type);
void list_delete(list);
list list_append(list, list_node);
list list_remove(list, list_node);
list list_search(list, list_type_specific_search_compare_function_type, void*);
void list_foreach(list, list_type_specific_enumerator_yield_callback_function_type);
void list_qsort(list, list_type_specific_sort_compare_function_type);
void list_serialize(list, list_type_specific_node_serializer_type);

#endif /* immutable_list_h */
