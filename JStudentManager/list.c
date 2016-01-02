//
//  immutable_list.c
//  JStudentManager
//
//  Created by James Swineson on 1/2/16.
//  Copyright © 2016 James Swineson. All rights reserved.
//

#include "list.h"

void list_node_free(list_node node)
{
    free(node->data);
    free(node);
}

list list_new(list *this, list_type_specific_initializer_type init)
{
    *this = (list)malloc(sizeof(struct list));
    (*this)->length = 0;
    (*this)->first_node = NULL;
    init(*this);
    return *this;
};

void list_delete(list this)
{
    list_node temp;
    while (this->length) {
        temp = this->first_node->next_node;
        list_node_free(this->first_node);
        this->first_node = temp;
        this->length--;
    }
    free(this);
};

list list_append(list this, list_node new_node)
{
    if (this->length)
    {
        list_node last = this->first_node;
        while (last->next_node) last = last->next_node;
        last->next_node = new_node;
    } else {
        this->first_node = new_node;
    }
    this->length++;
    return this;
};

list list_remove(list this, list_node node)
{
    if (!(this->first_node == node)) {
        // not the first one
        list_node before = this->first_node;
        while (before->next_node) {
            if (before->next_node == node) {
                before->next_node = node->next_node;
                break;
            }
        }
    } else {
        this->first_node = node->next_node;
    }
    list_node_free(node);
    return this;
};

list list_search(list, list_type_specific_search_compare_function_type, void*);
void list_foreach(list, list_type_specific_enumerator_yield_callback_function_type);
void list_qsort(list, list_type_specific_sort_compare_function_type);
void list_serialize(list, list_type_specific_node_serializer_type);