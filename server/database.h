//
// Created by willwang on 19-9-1.
//

#ifndef LINPOP_DATABASE_H
#define LINPOP_DATABASE_H

#endif //LINPOP_DATABASE_H

#include <stdlib.h>
#include <stdio.h>
#include <mysql/mysql.h>

MYSQL* connect_db (void);
int isuser (const int id, const char passwd[]);
int adduser (const char nick[], const char passwd[]);