// 212478994 Ahmad Shamasnah
#include <stdio.h>
#include <stdlib.h>
#include "StudentList.h"
#include "GradesOperations.h"
int main() {
    StudentList* lst=FileToList();
    Report(lst);
    printStudentList(lst);
    deleteList(lst);
}
