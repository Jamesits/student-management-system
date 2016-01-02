//
//  organization_list.h
//  JStudentManager
//
//  Created by James Swineson on 1/2/16.
//  Copyright © 2016 James Swineson. All rights reserved.
//

#ifndef org_list_h
#define org_list_h

#include "list.h"

typedef list org_list;

void org_list_data_init(list);
void org_list_node_data_init(list_node);
void org_list_node_data_free(list_node);
string org_list_node_data_serialize(list_node);
string org_list_data_serialize(list);

#endif /* org_list_h */
