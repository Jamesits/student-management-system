//
//  organization_list.c
//  JStudentManager
//
//  Created by James Swineson on 1/2/16.
//  Copyright © 2016 James Swineson. All rights reserved.
//

#include "organization_list.h"

void org_list_data_init(list this)
{
    this->data_size = 0;
    this->actionset[ACTION_INIT] = org_list_data_init;
    this->actionset[ACTION_NODE_INIT] = org_list_node_data_init;
    this->actionset[ACTION_NODE_FREE] = org_list_node_data_free;
    this->actionset[ACTION_NODE_DATA_SERIALIZE] = org_list_node_data_serialize;
    this->actionset[ACTION_DATA_SERIALIZE] = org_list_data_serialize;
};


void org_list_node_data_init(list_node this)
{
    this->data = NULL;
};

void org_list_node_data_free(list_node this)
{
    // nothing to do
};

string org_list_node_data_serialize(list_node this)
{
    return "org node";
};

string org_list_data_serialize(list this)
{
    string s = org_list_node_data_serialize(this->first_node);
    free(s);
    return "org list";
}
