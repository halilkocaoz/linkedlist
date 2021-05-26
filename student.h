typedef struct student
{
    int Id;
    char *FullName;

    struct student *next;
} Student;

void insertOrdered(int id, char *fullName);
Student *findById(int id);
int deleteById(int id);
void printStudents();