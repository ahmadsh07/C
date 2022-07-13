// 212478994 Ahmad Shamasnah
#include <stdio.h>
#include <stdlib.h>
#include "StudentList.h"
StudentList *FileToList() {
    FILE *file = fopen("StudentsGrades.txt", "r");
    StudentList *list = (StudentList *) malloc(sizeof(StudentList));
    list = createList();
    while (!feof(file)) {
        int id;
        int m1;
        int m2;
        Student *tmpst = (Student *) malloc(sizeof(Student));
        StudentNode *tmpnode = (StudentNode *) malloc(sizeof(StudentNode));
        fscanf(file, "%d %d %d", &id, &m1, &m2);
        tmpst->id = id;
        tmpst->grade1 = m1;
        tmpst->grade2 = m2;
        tmpnode->st = tmpst;
        tmpnode->next = NULL;
        addToList(list, tmpst);
    }
    fclose(file);
    return list;
}
void Report(StudentList *list) {
    StudentNode *tmp = (StudentNode *) malloc(sizeof(StudentNode));
    tmp = list->head;
    int stnum = 0;
    int firstexam = 0;
    int non = 0;
    double am = 0;
    double bm = 0;
    int suma = 0;
    int sumb = 0;
    int max = 0;
    int min = 1000;
    int stmax=0;
    int stmin=0;
    int A=0;
    int B=0;
    while (tmp != NULL) {
        if ((tmp->st->grade1 == -1 && tmp->st->grade2 != -1) ||
            (tmp->st->grade1 != -1 && tmp->st->grade2 == -1))
            firstexam++;
        if (tmp->st->grade1 == -1 && tmp->st->grade2 == -1)
             non++;
        if (tmp->st->grade1 < 60 && tmp->st->grade1 != -1) 
             am++;
        if (tmp->st->grade2 < 60 && tmp->st->grade2 != -1)
             bm++;
        if (tmp->st->grade1 > max&&tmp->st->grade1!=-1) {
            stmax = tmp->st->id;
            max = tmp->st->grade1;
        }
        if (tmp->st->grade2 > max&&tmp->st->grade2!=-1) {
            stmax = tmp->st->id;
            max = tmp->st->grade2;
        }
        if (tmp->st->grade1 < min&&tmp->st->grade1!=-1) {
            min = tmp->st->grade1;
            stmin = tmp->st->id;
        }
        if (tmp->st->grade2 < min&&tmp->st->grade2!=-1) {
            min = tmp->st->grade2;
            stmin = tmp->st->id;
        }
        if(tmp->st->grade1!=-1){
            A++;
            suma += tmp->st->grade1;
         }   
    if(tmp->st->grade2!=-1){
        sumb += tmp->st->grade2;
        B++;   
    }
        stnum++;
        tmp = tmp->next;
    }
    double prcA=(am/A)*100.00;
    double prcB=(bm/B)*100.00;
    int avrgA=0,avrgB=0;
    if(A!=0)
     avrgA=(suma/A);
    if(B!=0)
     avrgB=(sumb/B);
    FILE *FR=fopen("Report.txt","w");
    fputs("All students number: ",FR);
    fprintf(FR,"%d\n",stnum);
    fputs("Students who entered to one exam : ",FR);
    fprintf(FR,"%d\n",firstexam);
    fputs("Students who don't entered to any exams: ",FR);
    fprintf(FR,"%d\n",non);
    fputs("Fault percentage of students in exam A: ",FR);
    fprintf(FR,"%.2f\n",prcA);
    fputs("Fault percentage of Students in exam B: ",FR);
    fprintf(FR,"%.2f\n",prcB);
    fputs("Averag marks in exam A: ",FR);
    fprintf(FR,"%d\n",avrgA);
    fputs("Averag marks in exam B: ",FR);
    fprintf(FR,"%d\n",avrgB);
    fputs("Highest mark student : ",FR);
    fprintf(FR,"%d\n",stmax);
    fputs("lowest mark student : ",FR);
    fprintf(FR,"%d\n",stmin);
    fclose(FR);
}