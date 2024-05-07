#include "dorm.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct dorm_t create_dorm(char *input)
{
  struct dorm_t drm;
  strcpy(drm.name, strtok(NULL, "#"));
  drm.capacity = atoi(strtok(NULL, "#"));
  char *gend = strtok(NULL, "#");
  if (strcmp(gend, "male\n") == 0)
  {
    drm.gender = GENDER_MALE;
  }
  else if (strcmp(gend, "female\n") == 0)
  {
    drm.gender = GENDER_FEMALE;
  }
  drm.residents_num=0;
  return drm;
}

void print_dorm(struct dorm_t drm)
{
  if (drm.gender == GENDER_MALE)
  {
  printf("%s|%hu|male\n", drm.name, drm.capacity);
  }
  else if (drm.gender == GENDER_FEMALE)
  {
  printf("%s|%hu|female\n", drm.name, drm.capacity);
  }
}

void print_dorm_detail(struct dorm_t drm)
{
  if (drm.gender == GENDER_MALE)
  {
  printf("%s|%hu|male|%hu\n", drm.name, drm.capacity, drm.residents_num);
  }
  else if (drm.gender == GENDER_FEMALE)
  {
  printf("%s|%hu|female|%hu\n", drm.name, drm.capacity, drm.residents_num);
  }
}

int find_dorm(char *asrama, int jmlhdrm, struct dorm_t *drm)
{
  int find_dorm;
  for (int m = 0; m < jmlhdrm; m++)
  {
    if (strcmp(asrama, drm[m].name)==0)
    {
      find_dorm=m;
    }
  }
  return find_dorm;
}