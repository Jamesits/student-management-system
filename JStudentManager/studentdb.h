//
//  studentdb.h
//  JStudentManager
//
//  Created by James Swineson on 12/30/15.
//  Copyright © 2015 James Swineson. All rights reserved.
//

#pragma once
#ifndef studentdb_h
#define studentdb_h
#include "common.h"

void database_initialize();
void database_close();
void database_query_all_orgs();
void database_query_all_students();
void database_to_org_list();

void list_print_all_orgs();
#endif /* studentdb_h */
