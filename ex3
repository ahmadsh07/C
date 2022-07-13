//תעודת זהות: 212478994
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int n = 20;
typedef struct recommender{ //Defining the struct recommender.
    char FirstName [20];
    char LastName [20];
    char Email [20];
}recommender;
typedef struct developer { //Defining the struct developer.
    char FirstName [20];
    char LastName [20];
    char Degree [20];
    struct recommender *rec1;
    struct recommender *rec2;
    struct developer *dev3;
    struct developer *dev4;
}developer;
void opt1(developer *candidates[],int CIndex); //Defining option 1 in the menu of the customer.
void opt2(developer *employees[],int EIndex); //Defining option 2 in the menu of the customer.
void opt3(developer *candidates[],developer *employees[],int CIndex,int); //Defining option 3 in the menu of the customer.
void opt4(developer *pDeveloper[],developer *pDeveloper1[],int ,int); //Defining option 4 in the menu of the customer.
int main() { //The main function.
    struct developer *employees[n], *candidates[n];
    int CIndex=0,EIndex=0;
    int d=0;
    while(d!=5) {
        printf("Welcome, What do you want to do?\n");
        printf("1. Print candidates.\n");
        printf("2. Print workers.\n");
        printf("3. Insert new Candidate.\n");
        printf("4. Hire candidate.\n");
        printf("5. Exit.\n");
        scanf("%d", &d);
        if (d == 1)
            opt1(candidates,CIndex);
        else if (d == 2)
            opt2(employees,EIndex);
        else if (d == 3) {
            opt3(candidates, employees, CIndex,EIndex);
            CIndex++;
        }
        else if (d == 4) {
            opt4(candidates, employees,CIndex,EIndex);
            EIndex++;
            CIndex--;
        }
    }
    if(d==5){
        for(int i=0; i<CIndex; i++) {
            free(candidates[i]->rec1);
            free(candidates[i]->rec2);
            free(candidates[i]->dev3);
            free(candidates[i]->dev4);
            free(candidates[i]);
        }
            for(int i=0; i<EIndex; i++)
                free(employees[i]);
            printf("Thanks for using our system");
    }
}
void opt1(developer *candidates[],int CIndex){ //Printing the already candidates for the company.
    for(int i=0; i<CIndex; i++){
        printf("Name: %s %s \n",candidates[i]->FirstName,candidates[i]->LastName);
        printf("Degree: %s\n",candidates[i]->Degree);
        if(candidates[i]->rec2!=NULL){
            printf("Recommender %d\n",i+1);
            printf("Name: %s %s\n",candidates[i]->rec2->FirstName,candidates[i]->rec2->LastName);
            printf("Email: %s\n",candidates[i]->rec2->Email);
        }
        if(candidates[i]->rec1!=NULL){
            printf("Recommender %d\n",i+1);
            printf("Name: %s %s\n",candidates[i]->rec1->FirstName,candidates[i]->rec1->LastName);
            printf("Email: %s\n",candidates[i]->rec1->Email);
        }
        if(candidates[i]->dev3!=NULL){
            printf("Recommender %d\n",i+1);
            printf("Name: %s %s\n",candidates[i]->dev3->FirstName,candidates[i]->dev3->LastName);
        }
        if(candidates[i]->dev4!=NULL){
            printf("Recommender %d\n",i+1);
            printf("Name: %s %s\n",candidates[i]->dev4->FirstName,candidates[i]->dev4->LastName);
        }
    }
    if(CIndex==0)
        printf("There is no any candidates! \n");
}
void opt2(developer *employees[],int EIndex){ //Printing the already workers in the company.
    for(int i=0; i<EIndex; i++)
        printf("%s %s \n",employees[i]->FirstName,employees[i]->LastName);
    if(EIndex==0)
        printf("There is no any workers! \n");
}
void opt3(developer *candidates[],developer *employees[],int CIndex,int EIndex) { //A registration for a new candidates.
    char d[20];
    candidates[CIndex] = (developer *) malloc(sizeof(developer));
    recommender *rec1, *rec2;
    printf("Please enter the candidate's first name: \n");
    scanf("%s", candidates[CIndex]->FirstName, "\n");
    printf("Now please enter the candidate's last name: \n");
    scanf("%s", candidates[CIndex]->LastName, "\n");
    printf("finally enter the candidate's degree: \n");
    scanf("%s", candidates[CIndex]->Degree, "\n");
    printf("Is there a recommender for your candidate inside the company? \n");
    printf("Answer with yes/no!\n");
    scanf("%s", d);
    if (strcmp(d, "yes") == 0) {
        int num = 0;
        printf("How many is there ? (maximum 2)\n");
        scanf("%d", &num);
        if(EIndex==0)
            printf("there is no employees in the company!\n");
        else {
            for (int i = 1; i <= num; i++) {
                if (i == 1) {
                    char a[20], b[20];
                    int found = 0;
                    printf("Then enter his first name of the first person please: \n");
                    scanf("%s", a);
                    printf("Now enter his last name of the first person please: \n");
                    scanf("%s", b);
                    for (int j = 0; j < CIndex; j++) {
                        if (strcmp(employees[j]->FirstName, a) == 0 && strcmp(employees[j]->LastName, b) == 0) {
                            found = 1;
                            candidates[CIndex]=(developer*) malloc(sizeof (developer));
                            *candidates[CIndex]->dev3->FirstName = a;
                            *candidates[CIndex]->dev3->LastName = b;
                        }
                        if (found == 0)
                            printf("the recommender doesn't work in the company!");
                    }
                }
                if (i == 2) {
                    int found = 0;
                    char c[20], d[20];
                    printf("Then enter his second name please: \n");
                    scanf("%s", c);
                    printf("Now enter his last name please: \n");
                    scanf("%s", d);
                    for (int j = 0; j < EIndex; j++) {
                        if (strcmp(employees[j]->FirstName, c) == 0 && strcmp(employees[j]->LastName, d) == 0) {
                            candidates[CIndex]=(developer*) malloc(sizeof (developer));
                            *candidates[CIndex]->dev4->FirstName = c;
                            *candidates[CIndex]->dev4->LastName = d;
                            found = 1;
                        }
                    }
                    if (found == 0)
                        printf("the recommender doesn't work in the company!");
                }
            }
        }
    }
            char q[20];
            printf("Is there a recommender for your candidates outside the company? \n");
            printf("Answer with yes/no!\n");
            scanf("%s", q);
            if (strcmp(q, "yes") == 0) {
                int num = 0;
                printf("How many is there ? (maximum 2)\n");
                scanf("%d", &num);
                for (int i = 1; i <= num; i++) {
                    if (i == 1) {
                        rec1 = (recommender *) malloc(sizeof(recommender));
                        printf("Then enter his first name please: \n");
                        scanf("%s", rec1->FirstName);
                        printf("Now enter his last name please: \n");
                        scanf("%s", rec1->LastName);
                        printf("Finally please enter the recommender's email: \n");
                        scanf("%s", rec1->Email);
                        candidates[CIndex]->rec1 = rec1;
                    }
                    if (i == 2) {
                        rec2 = (recommender *) malloc(sizeof(recommender));
                        printf("Then enter his first name please: \n");
                        scanf("%s", rec2->FirstName);
                        printf("Now enter his last name please: \n");
                        scanf("%s", rec2->LastName);
                        printf("Finally please enter the recommender's email: \n");
                        scanf("%s", rec2->Email);
                        candidates[CIndex]->rec2 = rec2;
                    }
                }
            }
            printf("Done!\n");
    }
void opt4(struct developer *candidates[], struct developer *employees[],int CIndex,int EIndex) { //Hiring a new worker for the candidates list.
    char a[20],b[20];
    printf("To hire a candidate please enter his first name: \n");
    scanf("%s", a);
    printf("And now enter his last name: \n");
    scanf("%s", b);
    for (int i = 0; i < CIndex; i++) {
        if (strcmp(candidates[i]->FirstName, a) == 0 &&
            strcmp(candidates[i]->LastName, b) == 0) {
            employees[EIndex]=(developer*) malloc(sizeof (developer));
            strcpy(employees[EIndex]->FirstName,a);
            strcpy(employees[EIndex]->LastName,b);
            employees[EIndex]->rec1=NULL;
            employees[EIndex]->rec2=NULL;
            employees[EIndex]->dev4=NULL;
            employees[EIndex]->dev3=NULL;
            for(int j=0;j<i-1;j++)
                candidates[j]=candidates[j+1];
        }
    }
    printf("done!\n");
}
