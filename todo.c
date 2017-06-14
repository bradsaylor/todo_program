#include "todo.h"

int main(int argc, char *argv[])
{
  FILE *fp;
  fp = fopen("output.txt", "w");
  struct todo **todos;

  int count = 0;
  char go = '\0';

  char name[20];
  char s_due_date[6];
  int due_date;
  char description[80];

  while(1){
    printf("\n");
    printf("continue?: ");
    go = getch();
    printf("\r          ");
    printf("\r");
    if(go == 27) break;

    printf("name?:\t\t ");
    fgets(name, 20, stdin);

    printf("due date?:\t ");
    scanf("%s", s_due_date);
    due_date = atoi(s_due_date);

    printf("description?:\t ");
    getchar();
    fgets(description, 80, stdin);

    count++;
    todos[count] = todo_Create(count, name, due_date, description); 
  }

  for(int i = 1; i < (count + 1); i++) {
    todo_Print(todos[i]);
    todo_PrintFile(todos[i], fp);
    todo_Delete(todos[i]);
  }

  fclose(fp);

  printf("\n\n");

  return 0;
}
