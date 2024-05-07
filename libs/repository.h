#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "gender.h"
#include "dorm.h"
#include "student.h"

struct dorm_t create_dorm_repository(char *input);
struct student_t create_student_repository(char *input);


#endif