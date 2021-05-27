#include "student.c"

void actionChoice(int *choice)
{
}

int main(int argc, char const *argv[])
{
    int userActionChoice = 0, id = 0;
    char fullName[25];
    Student *found = NULL;

    printf("Enter a action choice::\n"
           "   0::  to end the program\n"
           "   1::  to insert a new student\n"
           "   2::  to remove a student by id\n"
           "   3::  to find and print a student by id\n"
           "   4::  to print all students\n");
actionSelect:
    printf("Your choice: ");
    scanf("%d", &userActionChoice);

    switch (userActionChoice)
    {
    case 0:
        return 0;
    case 1:
        printf("Enter a student:\nId: ");
        scanf("%d", &id);
        printf("Name surname: ");
        scanf("%s", fullName);
        insertOrdered(id, fullName);
        break;
    case 2:
        if (head != NULL)
        {
            printf("Enter a student id number to be deleted: ");
            scanf("%d", &id);
            if (deleteById(id) > 0)
                printf("Student(#%d) deleted.\n", id);
            else
                printf("Not found a student with id %d\n", id);
        }
        else
            printf("Node is empty.\n\n");
        break;
    case 3:
        printf("Enter a student id number to find: ");
        scanf("%d", &id);
        found = findById(id);
        if (found != NULL)
            printf("#%d - %s\n", found->Id, found->FullName);
        else
            printf("Not found a student with id %d\n\n", id);
        break;
    case 4:
        printStudents();
        break;
    default:
        printf("Undefined action choice.\n");
    }

    goto actionSelect;
}
