#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int Id;
    char *FullName;

    struct student *next;
} Student;

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

int deleteById(int id)
{
    Student *toBeDeleted = findById(id);
    if (toBeDeleted == NULL)
    {
        return 0;
    }

    if (toBeDeleted->Id == head->Id)
    {
        head = toBeDeleted->next;
        free(toBeDeleted);
    }
    else
    {
        prevtoCurrent = head;
        current = head->next;
        while (current != NULL && current->Id != id)
        {
            prevtoCurrent = current;
            current = current->next;
        }

        if (current != NULL)
        {
            toBeDeleted = current;
            prevtoCurrent->next = current->next;
            free(toBeDeleted);
        }
    }

    return toBeDeleted->Id;
}

int length()
{
    int length = 0;
    for (current = head; current != NULL; current = current->next)
        length++;

    return length;
}

void printStudents()
{
    current = head;
    
    if (current == NULL)
        printf("Node is empty.\n\n");
    else
    {
        printf("List of student(%d): \n", length());
        while (current != NULL)
        {
            printf("#%d - %s\n", current->Id, current->FullName);
            current = current->next;
        }
    }
}
