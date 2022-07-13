//תעודת זהות: 212478994
#include <stdio.h>
#include <string.h>

void addBigNumbers (char[], char[], char[]);

int MaxNumber (char first[], char second[]);

void sortBigNumbers (char *bigNumbers[], int N);

void reverse (unsigned char *str);
int main (){
    char a[100], b[100], c[200];
    printf ("Please enter the first number:\n");
    scanf ("%s", a);
    printf ("now enter the second number:\n");
    scanf ("%s", b);
    addBigNumbers (a, b, c);
    printf ("The result is: %s   \n", c);
    char *bigNumbers[5] = { "345778", "7865549", "1198076", "5437", "32456" };
    sortBigNumbers (bigNumbers, 5);
    printf ("the numbers after sorting is: ");
    for (int i = 0; i < 5; i++)
    {
        printf ("= %s", bigNumbers[i]);
    }
}
void addBigNumbers (char first[], char second[], char result[]){
    reverse (first); //getting the arry from the last element to the first "revers"
    reverse (second);
    int i = 0;
    int j = 0;
    int Max = 0, Min = 0;
    if (strlen (first) < strlen (second)){
        Min = strlen (first);
    }
    else
        Min = strlen (second);
    char carry = 0;
    char sum = 0;
    for (i = 0; i < Min; i++, j++){
        if (first[i] < '0' || first[i] > '9' || second[i] < '0' || second[i] > '9') {
            strcpy (result, "error");
            return;
        }
        sum = ((first[i] - '0') + (second[i] - '0') + carry); 
        result[j] = sum % 10 + '0';
        carry = sum / 10;
    } 
    while (i < strlen (first)){
        if (carry + '0' != 0){
            sum = (first[i] - '0') + carry;
            result[j] = sum % 10 + '0';
            carry = sum / 10;
        }
        else
            result[j] = first[i];
        i++;
        j++;
    }
    while (i < strlen (second)){
        if (carry + '0' != 0){
            sum = (second[i] - '0') + carry;
            result[j] = sum % 10 + '0';
            carry = sum / 10;
        }
        else
            result[j] = second[i];
        j++;
        i++;
    }
    if (carry + '0' != '0'){
        result[j] = carry + '0'; 
    }
    i = 0;
    while (i < strlen (result)){
        if (result[i] < '0' || result[i] > '9'){
            result[i] = '\0';
            break;
        }
        i++;
    }
    reverse (result);
}

void sortBigNumbers (char *bigNumbers[], int N){//a method to sort the givven numbers
    char *temp;
    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            if (MaxNumber (*(bigNumbers + i), *(bigNumbers + j)) == 0){
                temp = *(bigNumbers + i);
                *(bigNumbers + i) = *(bigNumbers + j);
                *(bigNumbers + j) = temp;
            }
        }
    }
}

int MaxNumber (char first[], char second[]){//getting the max number.
    if (strlen (first) > strlen (second)){
        return 0;
}
    else if (strlen (second) > strlen (first)){
        return 1;
}
    else{
        for (int i = 0; i < strlen (first); i++){
            if (first[i] > second[i])
                return 0;
            if (first[i] < second[i])
                return 1;
        }
    }
    return 0;
}

void reverse (unsigned char *str){
    int i;
    int j;
    unsigned char a;
    unsigned len = strlen ((const char *) str);
    for (i = 0, j = len - 1; i < j; i++, j--){
        a = str[i];
        str[i] = str[j];
        str[j] = a;
    }
}
