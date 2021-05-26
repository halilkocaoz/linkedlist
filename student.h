#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int Id;
    char *FullName;

    struct student *next;
} Student;

Student *findById(int id);
void insertOrdered(int id, char *fullName);
int deleteById(int id);
void printStudents();

Student *head = NULL;

Student *prevtoCurrent = NULL;
Student *current = NULL;

Student *findById(int id)
{
    current = head;
    while (current != NULL)
    {
        if (current->Id == id)
            return current;

        current = current->next;
    }

    return NULL;
}

void insertOrdered(int id, char *fullName)
{
    if (id < 1)
    {
        printf("Id must be greater than 0\n");
        return;
    }
    if (findById(id) != NULL)
    {
        printf("There is already a student with student id: %d\n", id);
        return;
    }

    Student *new = malloc(sizeof(Student));

    if (new != NULL)
    {
        new->FullName = strdup(fullName);
        new->Id = id;
        current = head;

        while (current != NULL && id > current->Id)
        {
            prevtoCurrent = current;
            current = current->next;
        }
        if (prevtoCurrent == NULL)
        {
            new->next = head;
            head = new;
        }
        else
        {
            prevtoCurrent->next = new;
            new->next = current;
        }
    }
    else
        printf("No memory available to insert a new student.\n");
}