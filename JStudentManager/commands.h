//
//  commands.h
//  JStudentManager
//
//  Created by James Swineson on 12/30/15.
//  Copyright © 2015 James Swineson. All rights reserved.
//

#pragma once
#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#define COMMAND(X) int X(char *args)

COMMAND(sqlite_load);
COMMAND(sqlite_save);
COMMAND(sqlite_query_all_orgs);
COMMAND(sqlite_query_all_students);
COMMAND(sqlite_to_list);
COMMAND(sqlite_from_list);

#endif