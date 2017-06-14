#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conio.h"

struct todo {
  int id;
  char *name;
  int due_date;
  char *description;
};

char *line = "______________________________________________\n";
char *hash = "//////////////////////////////////////////////\n";

struct todo *todo_Create(int id, char *name, int due_date, char *description)
{
  struct todo *who = malloc(sizeof(struct todo));

  who->id          = id;
  who->name        = strdup(name);
  who->due_date    = due_date;
  who->description = strdup(description);

  return (who);
}

void todo_Delete(struct todo *who)
{
  free(who->name);
  free(who->description);
  free(who);
}

void todo_Print(struct todo *who)
{
  printf("%s", line);
  printf("%s", hash);
  printf("id: %d\n", who->id);
  printf("\tname:\t\t %s", who->name);
  printf("\tdue date:\t %d\n", who->due_date);
  printf("\tdescription:\t %s", who->description);
}

void todo_PrintFile(struct todo *who, FILE *fp)
{
  fprintf(fp, "%s", line);
  fprintf(fp, "%s", hash);
  fprintf(fp, "id: %d\n", who->id);
  fprintf(fp, "\tname:\t\t %s", who->name);
  fprintf(fp, "\tdue date:\t %d\n", who->due_date);
  fprintf(fp, "\tdescription:\t %s", who->description);
}
