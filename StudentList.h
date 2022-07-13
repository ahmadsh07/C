// 212478994 Ahmad Shamasnah
#ifndef UNTITLED1_STUDENTLIST_H
#define UNTITLED1_STUDENTLIST_H
typedef struct {
    int id;
    int grade1, grade2;
}Student;
typedef struct StudentNode {
    Student* st;
    struct StudentNode* next;
}StudentNode;
typedef struct StudentList {
    struct StudentNode* head;
}StudentList;
StudentList* createList();
void deleteList(StudentList*);
void printStudentNode(StudentNode* const);
void printStudentList(StudentList* const);
void addToList(StudentList*, Student*);
#endif
