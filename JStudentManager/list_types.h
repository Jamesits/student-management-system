//
//  student_list.h
//  JStudentManager
//
//  Created by James Swineson on 1/2/16.
//  Copyright © 2016 James Swineson. All rights reserved.
//

#ifndef student_list_h
#define student_list_h

#include "common.h"

#define list_data_init(X) _Generic((X), \
    student_list: student_list_data_init, \
    org_list: org_list_data_init, \
    default: null_list_data_init \
)(X)

#define list_node_data_init(X) _Generic((X), \
    student_list: student_list_node_data_init, \
    org_list: org_list_node_data_init, \
    default: null_list_node_data_init \
)(X)

#define list_node_data_free(X) _Generic((X), \
    student_list: student_list_node_data_free, \
    org_list: org_list_node_data_free, \
    default: null_list_node_data_free \
)(X)

#define list_node_data_serialize(X) _Generic((X), \
    student_list: student_list_node_data_serialize, \
    org_list: org_list_node_data_serialize, \
    default: null_list_node_data_serialize \
)(X)

#define list_data_serialize(X) _Generic((X), \
    student_list: student_list_data_serialize, \
    org_list: org_list_data_serialize, \
    default: null_list_data_serialize \
)(X)

typedef struct list *student_list;
typedef struct list *org_list;

void student_list_data_init(list);
void student_list_node_data_init(list_node);
void student_list_node_data_free(list_node);
string student_list_node_data_serialize(list_node);
string student_list_data_serialize(list);

void org_list_data_init(list);
void org_list_node_data_init(list_node);
void org_list_node_data_free(list_node);
string org_list_node_data_serialize(list_node);
string org_list_data_serialize(list);

#endif /* student_list_h */
