#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define FILE_NAME "tasks.txt"

void add_task();
void view_tasks();
void delete_task();

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- TO DO LIST MANAGER ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
            add_task();
        else if (choice == 2)
            view_tasks();
        else if (choice == 3)
            delete_task();
        else if (choice == 4)
            break;
        else
            printf("Invalid choice!\n");
    }
    return 0;
}

void add_task()
{
    FILE *file = fopen(FILE_NAME, "a");
    char task[MAX];

    if (file == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    printf("Enter task: ");
    fgets(task, MAX, stdin);
    fprintf(file, "%s", task);

    fclose(file);
    printf("Task added successfully!\n");
}

void view_tasks()
{
    FILE *file = fopen(FILE_NAME, "r");
    char task[MAX];
    int count = 1;

    if (file == NULL)
    {
        printf("No tasks found.\n");
        return;
    }

    printf("\nYour Tasks:\n");
    while (fgets(task, MAX, file))
    {
        printf("%d. %s", count++, task);
    }

    fclose(file);
}

void delete_task()
{
    FILE *file = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    int delete_num, count = 1;
    char task[MAX];

    if (file == NULL)
    {
        printf("No tasks to delete.\n");
        return;
    }

    printf("Enter task number to delete: ");
    scanf("%d", &delete_num);

    while (fgets(task, MAX, file))
    {
        if (count != delete_num)
            fputs(task, temp);
        count++;
    }

    fclose(file);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    printf("Task deleted successfully!\n");
}