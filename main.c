#include "student.h"

int main(int argc, char const *argv[])
{
    printStudents();
    insertOrdered(1, "Test test");
    insertOrdered(2, "Test2 test2");
    printStudents();
    deleteById(2);
    printStudents();
    return 0;
}
