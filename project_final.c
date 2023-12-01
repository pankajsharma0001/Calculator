#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
void temp();
void currency();
void mass();
void length();
void num();
char hex[100];
int d;
void readMatrix(int array[10][10], int rows, int colums);  
void printMatrix(int array[10][10], int rows, int colums);  
void matrixAddSub(int arrayone[10][10], int arraytwo[10][10], int rows, int colums, int mul);  
void matrixScalarMultiply(int array[10][10], int scalar, int rows, int colums);  
void matrixMultiply(int arrayone[10][10], int arraytwo[10][10], int rowsA, int columsA, int columsB); 
int matrixDet(int arrayone[10][10], int rows, int colums);
int main() {
    char category;
    int ch;
    printf("\t\tWelcome to Unit Converter and Matrix Calculator! \n");
    a:
    printf("\t\t\t1.  Unit Converter\n\t\t\t2.  Matrix Calculator \n");
    printf("\t\tEnter your choice: ");
    scanf("%d",&ch);
    if(ch == 1)
    {
        printf("\t\tHere is a list of conversion you can do :\n");
        printf("\t\t\t\tT:  Temperature \n\t\t\t\tC:   Currency \n\t\t\t\tM:   Mass \n\t\t\t\tL:   Length \n\t\t\t\tN:   Number System \n");
        printf("\n\t\tPlease enter the letter you want to convert.");
        a1:
        fflush(stdin);
        scanf("%c",&category);
        switch(category)
        {
            case 'T':
                temp();
                break;
            case 'C':
                currency();
                break;
            case 'M':
                mass();
                break;
            case 'L':
                length();
                break;
            case 'N':
                num();
                break;
            default:
                fflush(stdin);
                printf("\n\t\tYou have entered wrong letter!! \n\t\tPlease select again:");
                goto a1;
        }
    }
    else if(ch == 2)
    {
        int i, j, k; //used in for loops  
        int matrixA[10][10], matrixB[10][10];
        int rowA, colA;  
        int rowB, colB;  
        int operation;//used in swtich statements  
        char again = 'Y';  
        int scalar = 0;  
        int add = 1;  
        int sub = -1;
        FILE *pt;
        while (again == 'Y'){  
            //this is the operation menu just type A, B, C or D to calculate  
            printf("\n\t\t\tOperation Menu\n");  
            printf("\t\t\t\t1. to Add\n");  
            printf("\t\t\t\t2. to Subtract\n");  
            printf("\t\t\t\t3. to Scalar Multiply\n");  
            printf("\t\t\t\t4. to Multiply two matrices\n");  
            printf("\\t\t\tt5. to find Determinant\n"); 
            printf("\t\t\tEnter your choice: ");  
            scanf(" %d", &operation);
            switch (operation){  
            case 1:  
                printf("\n\t\tEnter the #rows and #cols for matrix A: ");  
                scanf("%d%d", &rowA, &colA);  
                printf("\n\t\tMatrix Addition, Matrix Subtraction, Matrix Scalar Multiplication, Matrix Multiplication, Determinant of a Matrix, etc.​Enter the #rows and #cols for matrix B: ");  
                scanf("%d%d", &rowB, &colB);  
                while ((rowA != rowB) && (colA != colB)){  
                    printf("\n\t\tMatrices must be the same size\n");  
                    printf("\n\t\tEnter the #rows and #cols for matrix A: ");  
                    scanf("%d%d", &rowA, &colA);  
                    printf("\n\t\tEnter the #rows and #cols for matrix B: ");  
                    scanf("%d%d", &rowB, &colB);  
                } 
                pt = fopen("record.txt","a");
                fprintf(pt,"User is adding two matrix\n");
                fclose(pt);
                printf("\n\t\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA); // with the %d we remember the user the dimensions of the array  
                readMatrix(matrixA, rowA, colA);  
                printf("\n\t\t\tMatrix A\n\n");  
                printMatrix(matrixA, rowA, colA);
                printf("\n\t\tEnter elements of Matrix B a %d x %d matrix.\n", rowB, colB); // with the %d we remember the user the dimensions of the array  
                readMatrix(matrixB, rowB, colB);  
                printf("\n\t\t\tMatrix B\n\n");  
                printMatrix(matrixB, rowB, colB);  
                printf("\n\t\tThe Sum of matrixA + matrixB is : \n");  
                matrixAddSub(matrixA, matrixB, rowA, colA, add);  
                break;
            case 2:  
                printf("\n\t\tEnter the #rows and #cols for matrix A: ");  
                scanf("%d%d", &rowA, &colA);  
                printf("\t\tEnter the #rows and #cols for matrix B: ");  
                scanf("%d%d", &rowB, &colB);  
                while ((rowA != rowB) && (colA != colB)){  
                    printf("\n\t\tMatrices must be the same size\n");  
                    printf("\n\t\tEnter the #rows and #cols for matrix A: ");  
                    scanf("%d%d", &rowA, &colA);  
                    printf("\t\tEnter the #rows and #cols for matrix B: ");  
                    scanf("%d%d", &rowB, &colB);  
                }
                pt = fopen("record.txt","a");
                fprintf(pt,"User is Subtracting two matrix\n");
                fclose(pt);
                printf("\n\t\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA); // with the %d we remember the user the dimensions of the array  
                readMatrix(matrixA, rowA, colA);  
                printf("\n\t\t\tMatrix A\n\n");  
                printMatrix(matrixA, rowA, colA);  
                printf("\n\t\tEnter elements of Matrix B a %d x %d matrix.\n", rowB, colB); // with the %d we remember the user the dimensions of the array  
                readMatrix(matrixB, rowB, colB);  
                printf("\n\t\t\tMatrix B\n\n");  
                printMatrix(matrixB, rowB, colB);  
                printf("\n\t\tThe difference between matrixA - matrixB is : \n");  
                matrixAddSub(matrixA, matrixB, rowA, colA, sub);  
                break;
            case 3:  
                pt = fopen("record.txt","a");
                fprintf(pt,"\nUser is multiplying a  matrix by a scalar ");
                printf("\n\t\t\tEnter the scalar: ");  
                scanf("%d", &scalar);  
                fprintf(pt,"%d:\n",scalar);
                printf("\n\t\t\tThe scalar is: %d ", scalar); 
                fclose(pt); 
                printf("\n\t\tEnter the #rows and #cols for matrix A: ");  
                scanf("%d%d", &rowA, &colA);
                printf("\n\t\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA); // with the %d we remember the user the dimensions of the array  
                readMatrix(matrixA, rowA, colA);  
                printf("\n\t\t\tMatrix A\n\n");  
                printMatrix(matrixA, rowA, colA);  
                printf("\n\t\tThe scalar multiplication between matrixA * %d is: \n", scalar);  
                matrixScalarMultiply(matrixA, scalar, rowA, colA);  
                break;
            case 4:  
                //when multiplying arrays matrixA column # has to equal matrixB row #  
                printf("\n\t\tEnter the #rows and #cols for matrix A: ");  
                scanf("%d%d", &rowA, &colA);  
                printf("\t\tEnter the #rows and #cols for matrix B: ");  
                scanf("%d%d", &rowB, &colB);  
                // Column of first matrix should be equal to column of second matrix and  
                while (colA != rowB)  
                {  
                    printf("\n\n\t\tError! column of first matrix not equal to row of second.\n\n");  
                    printf("\n\t\tEnter the #rows and #cols for matrix A: ");  
                    scanf("%d%d", &rowA, &colA);  
                    printf("\t\tEnter the #rows and #cols for matrix B: ");  
                    scanf("%d%d", &rowB, &colB);  
                }
                pt = fopen("record.txt","a");
                fprintf(pt,"User is Multiplying two matrices\n");
                fclose(pt);
                // Storing elements of first matrix.  
                printf("\n\t\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA); // with the %d we remember the user the dimensions of the array  
                readMatrix(matrixA, rowA, colA);  
                printf("\n\t\t\tMatrix A\n\n");  
                printMatrix(matrixA, rowA, colA);  
                // Storing elements of second matrix.  
                printf("\n\t\tEnter elements of Matrix B a %d x %d matrix.\n", rowB, colB); // with the %d we remember the user the dimensions of the array  
                readMatrix(matrixB, rowB, colB);  
                printf("\n\t\t\tMatrix B\n\n");  
                printMatrix(matrixB, rowB, colB);  
                //multiplyng arrays  
                matrixMultiply(matrixA, matrixB, rowA, colA, colB);  
                break;
            case 5:
                printf("\n\t\tEnter the #rows and #cols for square matrix: ");  
                scanf("%d%d", &rowA, &colA); 
                while (rowA != colA)  
                {  
                    printf("\n\n\t\tError! row and column of matrix does not match.\n\n");  
                    printf("\n\t\tEnter the #rows and #cols for matrix: ");  
                    scanf("%d%d", &rowA, &colA); 
                }
                pt = fopen("record.txt","a");
                fprintf(pt,"\nUser is finding the determinant of matrix\n");
                fclose(pt);
                printf("\n\t\tEnter elements of Matrix a %d x %d matrix.\n", rowA, colA); // with the %d we remember the user the dimensions of the array  
                readMatrix(matrixA, rowA, colA);  
                printf("\n\t\t\tMatrix \n\n");  
                printMatrix(matrixA, rowA, colA);
                d = matrixDet(matrixA, rowA, colA);
                printf("\n\t\t\tDeterminant:%d",d);
                break;
            default:  
                printf("\n\t\tIncorrect option! Please choose a number 1-5.");  
            }
            printf("\n\n\t\tDo you want to calculate again? Y/N\n");  
            scanf(" %c", &again);  
            again = toupper(again);
        }
        exit(0);
    }
    else{
        printf("\n\t\t\t\tEnter a valid option!\n");
        goto a;
    }
    getchar();
    return 0;
}
void temp()
{
    FILE *pt;
    int tempChoice; 
    float userinput;
    float fahrenheitToCelcius, celciusToFahrenheit, kelvinToCelcius, celciusToKelvin, fahrenheitToKelvin, kelvinToFahrenheit; 
    char choice;
    printf("\n\t\tWelcome to Temperature Converter! \n");
    printf("\t\tHere is a list of conversations to choose from: \n");
    pt = fopen("record.txt","a");
    a2:
    printf("\t\t\tEnter 1 for Fahrenheit to Celsius. \n");
    printf("\t\t\tEnter 2 for Celsius to Fahrenheit. \n");
    printf("\t\t\tEnter 3 for Fahrenheit to Kelvin. \n");
    printf("\t\t\tEnter 4 for Kelvin to Fahrenheit. \n");
    printf("\t\t\tEnter 5 for Celsius to Kelvin. \n");
    printf("\t\t\tEnter 6 for Kelvin to Celsius. \n");
    scanf("%d",&tempChoice);
    if(tempChoice == 1){
        printf("\t\tPlease enter the Fahrenheit degree: \n");
        scanf("%f",&userinput);
        fahrenheitToCelcius =  ((userinput-32) * (5.0/9.0));
        fprintf(pt, "\nUser is converting Fahrenheit to Celcius: %.2f F = %.2fC",userinput,fahrenheitToCelcius);
        printf("\t\t\tCelcius: %.2f",fahrenheitToCelcius);
        fflush(stdin);
        printf("\n\t\tDo you want convert again?(y/n):");
        scanf("%c",&choice);
        if(choice == 'y')
            goto a2;
    }
    else if(tempChoice == 2){
        printf("\t\tPlease enter the Celcius degree: \n");
        scanf("%f",&userinput);
        celciusToFahrenheit = ((9.0/5.0)*userinput + 32);
        fprintf(pt, "\nUser is converting Celcius to Fahrenheit: %.2f C = %.2fF",userinput,celciusToFahrenheit);
        printf("\t\t\tFahrenheit: %.2f",celciusToFahrenheit);
        fflush(stdin);
        printf("\n\t\tDo you want convert again?(y/n):");
        scanf("%c",&choice);
        if(choice == 'y')
            goto a2;
    }
    else if(tempChoice == 3){
        printf("\t\tPlease enter the Fahrenheit degree: \n");
        scanf("%f",&userinput);
        fahrenheitToKelvin = (userinput - 32) * 5/9 + 273;
        fprintf(pt, "\nUser is converting Fahrenheit to Kelvin: %.2fF = %.2fK",userinput,fahrenheitToKelvin);
        printf("\t\t\tKelvin: %.2f",fahrenheitToKelvin);
        fflush(stdin);
        printf("\n\t\tDo you want convert again?(y/n):");
        scanf("%c",&choice);
        if(choice == 'y')
            goto a2;
    }
    else if(tempChoice == 4){
        printf("\t\tPlease enter the Kelvin : \n");
        scanf("%f",&userinput);
        kelvinToFahrenheit = (userinput - 273) * 9/5 +32;
        fprintf(pt, "\nUser is converting Kelvin to Fahrenheit: %.2f K = %.2fF",userinput,kelvinToFahrenheit);
        printf("\t\t\tFahrenheit: %.2f",kelvinToFahrenheit);
        fflush(stdin);
        printf("\n\t\tDo you want convert again?(y/n):");
        scanf("%c",&choice);
        if(choice == 'y')
            goto a2;
    }
    else if(tempChoice == 5){
        printf("\t\tPlease enter the Celcius degree: \n");
        scanf("%f",&userinput);
        celciusToKelvin = userinput + 273;
        fprintf(pt, "\nUser is converting Celcius to Kelvin: %.2f C = %.2fK",userinput,celciusToKelvin);
        printf("\t\t\tKelvin: %.2f",celciusToKelvin);
        fflush(stdin);
        printf("\n\t\tDo you want convert again?(y/n):");
        scanf("%c",&choice);
        if(choice == 'y')
            goto a2;
    }
    else if(tempChoice == 6){
        printf("\t\tPlease enter the Kelvin : \n");
        scanf("%f",&userinput);
        kelvinToCelcius = userinput - 273;
        fprintf(pt, "\nUser is converting Fahrenheit to Celcius: %.2f K = %.2fC",userinput,kelvinToCelcius);
        printf("\t\t\tCelcius: %.2f",kelvinToCelcius);
        fflush(stdin);
        printf("\n\t\tDo you want convert again?(y/n):");
        scanf("%c",&choice);
        if(choice == 'y')
            goto a2;
    }
    else
        printf("\t\tPlease enter the correct choice:");
    fclose(pt);
    exit(0);
}
void currency()
{
    FILE *pt;
    int currencyChoice, c;
    char choice;
    float userInput, USDtoRS, INRtoRS, EUROtoRS, AUDtoRS, DINARtoRS, RMtoRS;
    printf("\t\t\tWelcome to Currency Converter! \n");
    printf("\t\t\tEnter your Choice:\n");
    pt = fopen("record.txt","a");
    a3:
    printf("\n1. Nepali Currency to Other Currency.\n");
    printf("2. Other Currency to Nepali Currency.\n");
    scanf("%d",&c);
    if(c == 1){
        printf("\t\t\tEnter 1 for NPR to USD. \n");
        printf("\t\t\tEnter 2 for NPR to INR. \n");
        printf("\t\t\tEnter 3 for NPR to EURO. \n");
        printf("\t\t\tEnter 4 for NPR to AUD. \n");
        printf("\t\t\tEnter 5 for NPR to DINAR. \n");
        printf("\t\t\tEnter 6 for NPR to RM. \n");
        scanf("%d",&currencyChoice);
        printf("\t\tPlease enter the amount: \n");
        scanf("%f",&userInput);
        if(currencyChoice == 1){
            USDtoRS = userInput / 132.87;
            fprintf(pt, "\nUser is converting Nepali Rupees to US Dollar: NPR %.2f = USD %.2f",userInput,USDtoRS);
            printf("Rs: %.2f",USDtoRS);
            fflush(stdin);
            printf("\n\t\tDo you want convert again?(y/n):");
            scanf("%c",&choice);
            if(choice == 'y')
                goto a3;
        }
        else if(currencyChoice == 2){
            INRtoRS = userInput / 1.6;
            fprintf(pt, "\nUser is converting Nepali rupees to INR rupees: NPR %.2f = INR %.2f",userInput,INRtoRS);
            printf("\t\t\tRs: %.2f",INRtoRS);
            fflush(stdin);
            printf("\n\t\tDo you want convert again?(y/n):");
            scanf("%c",&choice);
            if(choice == 'y')
                goto a3;
        }
        else if(currencyChoice == 3) {
            EUROtoRS = userInput / 144.81;
            fprintf(pt, "\nUser is converting Nepali rupees to EURO: NPR %.2f = EURO %.2f",userInput,EUROtoRS);
            printf("\t\t\tRs: %.2f",EUROtoRS);
            fflush(stdin);
            printf("\n\t\tDo you want convert again?(y/n):");
            choice=getchar();
            if(choice == 'y')
                goto a3;
        }
        else if(currencyChoice == 4) {
            AUDtoRS = userInput / 85.22;
            fprintf(pt, "\nUser is converting Nepali rupees to Austrilian Dollar: NPR %.2f = AUD %.2f",userInput,AUDtoRS);
            printf("\t\t\tRs: %.2f",AUDtoRS);
            fflush(stdin);
            printf("\n\t\tDo you want convert again?(y/n):");
            choice=getchar();
            if(choice == 'y')
                goto a3;
        }
        else if(currencyChoice == 5) {
            DINARtoRS = userInput / 431.27;
            fprintf(pt, "\nUser is converting Nepali rupees to Kuwiat dinar: NPR %.2f = DINAR %.2f",userInput,DINARtoRS);
            printf("\t\t\tRs: %.2f",DINARtoRS);
            fflush(stdin);
            printf("\n\t\tDo you want convert again?(y/n):");
            choice=getchar();
            if(choice == 'y')
                goto a3;
        }
        else if(currencyChoice == 6) {
            RMtoRS = userInput / 28.58;
            fprintf(pt, "\nUser is converting Nepali rupees to Malayasian Ringgit: NPR %.2f = RM %.2f",userInput,RMtoRS);
            printf("\t\t\tRs: %.2f",RMtoRS);
            fflush(stdin);
            printf("\n\t\tDo you want convert again?(y/n):");
            choice=getchar();
            if(choice == 'y')
                goto a3;
        }
        else{
            printf("\t\tPlease enter correct choice. \n");
            goto a3;}
    }
    else if(c == 2){
        printf("\t\tHere is a list of conversations to choose from: \n");
        printf("\t\t\tEnter 1 for USD to NPR. \n");
        printf("\t\t\tEnter 2 for INR to NPR. \n");
        printf("\t\t\tEnter 3 for EURO to NPR. \n");
        printf("\t\t\tEnter 4 for AUD to NPR. \n");
        printf("\t\t\tEnter 5 for DINAR to NPR. \n");
        printf("\t\t\tEnter 6 for RM to NPR. \n");
        scanf("%d",&currencyChoice);
        printf("\t\tPlease enter the amount: \n");
        scanf("%f",&userInput);
        if(currencyChoice == 1){
            USDtoRS = userInput * 132.87;
            fprintf(pt, "\nUser is converting US Dollar to NPR: USD %.2f = NPR %.2f",userInput,USDtoRS);
            printf("\t\t\tRs: %.2f",USDtoRS);
            fflush(stdin);
            printf("\n\t\tDo you want convert again?(y/n):");
            scanf("%c",&choice);
            if(choice == 'y')
                goto a3;
        }
        else if(currencyChoice == 2){
            INRtoRS = userInput * 1.6;
            fprintf(pt, "\nUser is converting INR rupee to NPR: INR %.2f = NPR %.2f",userInput,INRtoRS);
            printf("\t\t\tRs: %.2f",INRtoRS);
            fflush(stdin);
            printf("\n\t\tDo you want convert again?(y/n):");
            scanf("%c",&choice);
            if(choice == 'y')
                goto a3;
        }
        else if(currencyChoice == 3) {
            EUROtoRS = userInput * 144.81;
            fprintf(pt, "\nUser is converting EURO to NPR: EURO %.2f = NPR %.2f",userInput,EUROtoRS);
            printf("\t\t\tRs: %.2f",EUROtoRS);
            fflush(stdin);
            printf("\n\t\tDo you want convert again?(y/n):");
            choice=getchar();
            if(choice == 'y')
                goto a3;
        }
        else if(currencyChoice == 4) {
            AUDtoRS = userInput * 85.22;
            fprintf(pt, "\nUser is converting Austrilian Dollar to NPR: AUD %.2f = NPR %.2f",userInput,AUDtoRS);
            printf("\t\t\tRs: %.2f",AUDtoRS);
            fflush(stdin);
            printf("\n\t\tDo you want convert again?(y/n):");
            choice=getchar();
            if(choice == 'y')
                goto a3;
        }
        else if(currencyChoice == 5) {
            DINARtoRS = userInput * 431.27;
            fprintf(pt, "\nUser is converting Kuwiat dinar to NPR: DINAR %.2f = NPR %.2f",userInput,DINARtoRS);
            printf("\t\t\tRs: %.2f",DINARtoRS);
            fflush(stdin);
            printf("\n\t\tDo you want convert again?(y/n):");
            choice=getchar();
            if(choice == 'y')
                goto a3;
        }
        else if(currencyChoice == 6) {
            RMtoRS = userInput * 28.58;
            fprintf(pt, "\nUser is converting Malayasian Ringgit to NPR: RM %.2f = NPR %.2f",userInput,RMtoRS);
            printf("\t\t\tRs: %.2f",RMtoRS);
            fflush(stdin);
            printf("\n\t\tDo you want convert again?(y/n):");
            choice=getchar();
            if(choice == 'y')
                goto a3;
        }
        else{
            printf("\t\tPlease enter correct choice. \n");
            goto a3;}
    }
    else{
        printf("\t\tPlease enter correct choice. \n");
        goto a3;}
    fclose(pt);
    exit(0);
}
void mass()
{
    FILE *pt;
    int massChoice,c;
    float userInput, KGtoG, KGtoLB, KGtoOZ, GtoKG, LBtoKG, OZtoKG;
    char choice;
    printf("\t\tWelcome to Mass Converter! \n");
    printf("\t\tEnter a choice:\n");
    pt = fopen("record.txt","a");
    a4:
    printf("\n\t\t\t1.Kilogram to Other units.\n");
    printf("\t\t\t2.Other units to Kilogram.\n");
    scanf("%d",&c);
    if(c == 1){
        printf("\t\tHere is a list of conversations to choose from: \n");
        printf("\t\t\tEnter 1 for Kilogram to Gram. \n");
        printf("\t\t\tEnter 2 for kilogram to Pounds. \n");
        printf("\t\t\tEnter 3 for Kilogram to Ounce. \n");
        scanf("%d",&massChoice);
        switch(massChoice)
        {
            case 1:
                printf("\t\tPlease enter the amount: \n");
                scanf("%f",&userInput);
                KGtoG = userInput * 1000;
                fprintf(pt, "\nUser is converting Kilogram to Gram: %.2f Kg = %.2f g",userInput,KGtoG);
                printf("\t\t\t%.2f g",KGtoG);
                fflush(stdin);
                printf("\n\t\tDo you want convert again?(y/n):");
                choice=getchar();
                if(choice == 'y')
                    goto a4;
                break;
            case 2:
                printf("\t\tPlease enter the amount: \n");
                scanf("%f",&userInput);
                KGtoLB = userInput * 2.205;
                fprintf(pt, "\nUser is converting Kilogram to Pound: %.2f Kg = %.2f lbs",userInput,KGtoLB);
                printf("\t\t\t%.2f lbs",KGtoLB);
                fflush(stdin);
                printf("\n\t\tDo you want convert again?(y/n):");
                choice=getchar();
                if(choice == 'y')
                    goto a4;
                break;
            case 3:
                printf("\t\tPlease enter the amount: \n");
                scanf("%f",&userInput);
                KGtoOZ = userInput * 35.274;
                fprintf(pt, "\nUser is converting Kilogram to Ounce: %.2f Kg = %.2f Oz",userInput,KGtoOZ);
                printf("\t\t\t%.2f Oz",KGtoOZ);
                fflush(stdin);
                printf("\n\t\tDo you want convert again?(y/n):");
                choice=getchar();
                if(choice == 'y')
                    goto a4;
                break;
            default:
                printf("\n\t\tEnter a valid number!!");
                goto a4;
        }
    }
    else if(c == 2){
        printf("\t\tHere is a list of conversations to choose from: \n");
        printf("\t\t\tEnter 1 for Gram to Kilogram. \n");
        printf("\t\t\tEnter 2 for Pounds to Kilogram. \n");
        printf("\t\t\tEnter 3 for Ounce to Kilogram. \n");
        scanf("%d",&massChoice);
        switch(massChoice){
            case 1:
                printf("\t\tPlease enter the amount: \n");
                scanf("%f",&userInput);
                GtoKG = userInput / 1000;
                fprintf(pt, "\nUser is converting Gram to Kilogram: %.2f G = %.2f Kg",userInput,GtoKG);
                printf("\t\t\t%.2f Kg",GtoKG);
                fflush(stdin);
                printf("\n\t\tDo you want convert again?(y/n):");
                choice=getchar();
                if(choice == 'y')
                    goto a4;
                break;
            case 2:
                printf("\t\tPlease enter the amount: \n");
                scanf("%f",&userInput);
                LBtoKG = userInput / 2.205;
                fprintf(pt, "\nUser is converting Pound to Kilogram: %.2f lbs = %.2f kg",userInput,LBtoKG);
                printf("\t\t\t%.2f Kg",LBtoKG);
                fflush(stdin);
                printf("\n\t\tDo you want convert again?(y/n):");
                choice=getchar();
                if(choice == 'y')
                    goto a4;
                break;
            case 3:
                printf("\t\tPlease enter the amount: \n");
                scanf("%f",&userInput);
                OZtoKG = userInput / 35.274;
                fprintf(pt, "\nUser is converting Ounce to Kilogram: %.2f Oz = %.2f Kg",userInput,OZtoKG);
                printf("\t\t\t%.2f Kg",OZtoKG);
                fflush(stdin);
                printf("\n\t\tDo you want convert again?(y/n):");
                choice=getchar();
                if(choice == 'y')
                    goto a4;
                break;
            default:
                printf("\n\t\tEnter a valid number!!");
                goto a4; 
        }
    }
    else{
        printf("\n\t\tEnter a valid number!!");
        goto a4; 
    }
    fclose(pt);
    exit(0);
}
void num()
{
    FILE *pt;
    int numChoice, userInput, num[32];
    int i,index,c;
    char choice;
    printf("\t\tWelcome to Number System Converter! \n");
    printf("\t\tEnter your choice:\n");
    pt = fopen("record.txt","a");
    a5:
    printf("\n\t\t\t1. Decimal to Other System.\n");
    printf("\t\t\t2. Other System to Decimal.\n");
    scanf("%d",&c);
    if(c == 1){
        printf("\t\tHere is a list of conversations to choose from: \n");
        printf("\t\t\tEnter 1 for Decimal to Binary. \n");
        printf("\t\t\tEnter 2 for Decimal to Octal. \n");
        printf("\t\t\tEnter 3 for Decimal to Hexadecimal. \n");
        scanf("%d",&numChoice);
        switch(numChoice)
        {
            case 1:
                printf("\n\t\tPlease enter the decimal number: ");
                scanf("%d",&userInput);
                int decimal = userInput;
                index = 0;
                if(decimal == 0)
                    printf("\t\t\tBinary:0\n");
                while(decimal > 0)
                    {
                        num[index] = decimal % 2;
                        decimal /= 2;
                        index++;
                    }
                fprintf(pt, "\nUser is converting Decimal to Binary: %d = ",userInput);
                printf("\t\t\tBinary:");
                for(i=index-1; i>=0; i--){
                    fprintf(pt, "%d",num[i]);
                    printf("\t\t\t%d",num[i]);}
                fflush(stdin);
                printf("\n\t\tDo you want convert again?(y/n):");
                choice=getchar();
                if(choice == 'y')
                    goto a5;
                break;
            case 2:
                printf("\n\t\tPlease enter the decimal number: ");
                scanf("%d",&userInput);
                decimal = userInput;
                index = 0;
                if(decimal == 0)
                    printf("\t\t\tOctal:0\n");
                while(decimal > 0)
                    {
                        num[index] = decimal % 8;
                        decimal /= 8;
                        index++;
                    }
                fprintf(pt, "\nUser is converting Decimal to Octal: %d = ",userInput);
                printf("\t\t\tOctal:");
                for(i=index-1; i>=0; i--){
                    fprintf(pt, "%d",num[i]);
                    printf("\t\t\t%d",num[i]);}
                fflush(stdin);
                printf("\n\t\tDo you want convert again?(y/n):");
                choice=getchar();
                if(choice == 'y')
                    goto a5;
                break;
            case 3:
                printf("\n\t\tPlease enter the decimal number:");
                scanf("%d",&userInput);
                decimal = userInput;
                char hexadecicmal[64];
                index = 0;
                if(decimal == 0)
                    printf("\t\t\tHexadecimal: 0\n");
                while(decimal > 0)
                    {
                        int remainder = decimal % 16;
                        if (remainder < 10) {
                            hexadecicmal[index] = remainder + '0';
                        } else {
                            hexadecicmal[index] = remainder - 10 + 'A';
                        }
                        decimal /= 16;
                        index++;
                    }
                fprintf(pt, "\nUser is converting Decimal to Hexadecimal: %d = ",userInput);
                printf("\n\t\t\tHexadecimal:");
                for(i=index-1; i>=0; i--){
                    fprintf(pt, "%c",hexadecicmal[i]);
                    printf("\t\t\t%c",hexadecicmal[i]);}
                fflush(stdin);
                printf("\n\t\tDo you want convert again?(y/n):");
                choice=getchar();
                if(choice == 'y')
                    goto a5;
                break;
            default:
                printf("\n\t\tEnter a valid number!!");
                goto a5;
        }
    } 
    else if( c ==2 ){
        printf("\t\tHere is a list of conversations to choose from: \n");
        printf("\t\t\tEnter 1 for Binary to Decimal. \n");
        printf("\t\t\tEnter 2 for Octal to Decimal. \n");
        printf("\t\t\tEnter 3 for Hexadecimal to Decimal. \n");
        scanf("%d",&numChoice);
        switch(numChoice){
            case 1:
                printf("\n\t\tPlease enter the binary number: ");
                scanf("%d",&userInput);
                int binary = userInput, power = 0, digit;
                int decimal = 0;
                while(binary > 0)
                    {
                        digit = binary %10;
                        decimal += digit * pow(2, power);
                        power++;
                        binary /= 10;
                    }
                fprintf(pt, "\nUser is converting Binary to Decimal: %d = %d",userInput, decimal);
                printf("\t\t\tDecimal: %d", decimal);
                fflush(stdin);
                printf("\n\t\tDo you want convert again?(y/n):");
                choice=getchar();
                if(choice == 'y')
                    goto a5;
                break;
            case 2:
                printf("\n\t\tPlease enter the Octal number: ");
                scanf("%d",&userInput);
                int octal = userInput;
                power = 0;
                decimal = 0;
                while(octal > 0)
                    {
                        digit = octal % 10;
                        decimal += digit * pow(8, power);
                        power++;
                        octal /= 10;
                    }
                fprintf(pt, "\nUser is converting Octal to Decimal: %d = %d",userInput, decimal);
                printf("\t\t\tDecimal: %d", decimal);
                fflush(stdin);
                printf("\n\t\tDo you want convert again?(y/n):");
                choice=getchar();
                if(choice == 'y')
                    goto a5;
                break;
            case 3:
                printf("\n\t\tEnter a hexadecimal number: ");
                scanf("%s", hex);
                int length = strlen(hex);
                decimal = 0;
                for (i = length - 1, power = 0; i >= 0; i--, power++) {
                    int decimalValue;
                    if (hex[i] >= '0' && hex[i] <= '9') {
                        decimalValue = hex[i] - '0';
                    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
                        decimalValue = 10 + hex[i] - 'A';
                    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
                        decimalValue = 10 + hex[i] - 'a';
                    } else {
                        printf("\n\t\tInvalid hexadecimal digit: %c\n", hex[i]);
                        exit(0);
                    }
                    decimal += decimalValue * pow(16, power);
                }
                fprintf(pt, "\nUser is converting Hexadecimal to Decimal: %s = %d",hex, decimal);
                printf("\n\t\t\tDecimal: %d", decimal);
                fflush(stdin);
                printf("\n\t\tDo you want convert again?(y/n):");
                choice=getchar();
                if(choice == 'y')
                    goto a5;
                break;
            default:
                printf("\n\t\tEnter a valid number!!");
                goto a5;
        }
    }  
    else{
        printf("\n\t\tEnter a valid number!!");
        goto a5;
    }         
    fclose(pt);
    exit(0);
}
void length()
{
	FILE *pt;
	int lengthchoice, c1;
    char choice;
	float userinput,kmtom,mtokm,inchtom,mtoinch,foottom,mtofoot,mtocm,cmtom;
	printf("\t\tWelcome to length converter! \n");
	printf("\t\tHere is the list of converstions to choose from:\n");
	pt=fopen("record.txt","a");
    a3:
	printf("\n\t\t1. Do you want to compute Km, Inch, Foot or Cm to M : \n");
	printf("\t\t2. Do you want to compute M to Km, Inch, Foot or Cm:\n");
	printf("\t\tYour choice:");
	scanf("%d",&c1);
	if(c1==1){
		printf("\t\t\tEnter 1 to convert from Km to M. \n");
		printf("\t\t\tEnter 2 to convert from Inch to M. \n");
		printf("\t\t\tEnter 3 to convert from Foot to M. \n");
		printf("\t\t\tEnter 4 to convert from Cm to M. \n");
		scanf("%d",&lengthchoice);
		printf("\t\tPlease enter the length to convert: \n");
		scanf("%f",&userinput);
		if(lengthchoice == 1)
		{
			kmtom=userinput * 1000;
			fprintf(pt,"\nUser is converting KM to M: %.2f Km =%.2f M",userinput,kmtom);
			printf("\t\t\t%.2f M",kmtom);
			fflush(stdin);
			printf("\n\t\tDo you want to continue?(y/n)");
			choice = getchar();
			if(choice == 'y')
			    goto a3;
		}
		else if(lengthchoice==2)
		{
			inchtom=userinput/0.0254;
			fprintf(pt,"\nUser is converting Inch to M: %.2f Inch =%.2f M",userinput,inchtom);
			printf("\t\t\t%.2f M",inchtom);
			fflush(stdin);
			printf("\n\t\tDo you want to continue?(y/n)");
			scanf("%c",&choice);
			if(choice=='y')
			    goto a3;
		}
		else if(lengthchoice==3)
		{
			foottom=userinput/3.281;
			fprintf(pt,"\nUser is converting Foot to M: %.2f Foot =%.2f M",userinput,foottom);
			printf("\t\t\t%.2f M",foottom);
			fflush(stdin);
			printf("\n\t\tDo you want to continue?(y/n)");
			scanf("%c",&choice);
			if(choice=='y')
			    goto a3;
		}
		else if(lengthchoice==4)
		{
			cmtom=userinput/100;
			fprintf(pt,"\nUser is converting CM to M: %.2f Cm =%.3f M",userinput,cmtom);
			printf("\t\t\t%.2f M",cmtom);
			fflush(stdin);
			printf("\n\t\tDo you want to continue?(y/n)");
			scanf("%c",&choice);
			if(choice=='y')
			    goto a3;
		}
		else{
			printf("\n\t\tPlease enter correct choice");
		}
    }
	else if(c1 == 2){
		printf("\t\t\tEnter 1 to convert from M to Km. \n");
		printf("\t\t\tEnter 2 to convert from M to Inch. \n");
		printf("\t\t\tEnter 3 to convert from M to Foot. \n");
	    printf("\t\t\tEnter 4 to convert from M to Cm \n");
		scanf("%d",&lengthchoice);
	    printf("\t\tPlease enter the length to convert: \n");
		scanf("%f",&userinput);
		if(lengthchoice==1)
		{
			mtokm=userinput/1000;
			fprintf(pt,"\nUser is converting M to KM: %.2f M =%.2f Km",userinput,mtokm);
			printf("\t\t\t%.2f Km",mtokm);
			fflush(stdin);
			printf("\n\t\tDo you want to continue?(y/n)");
			scanf("%c",&choice);
			if(choice=='y')
			goto a3;
		}
		else if(lengthchoice==2)
		{
			mtoinch=userinput*39.37;
			fprintf(pt,"\nUser is converting M to INCH: %.2f M =%.2f Inch",userinput,mtoinch);
			printf("\t\t\t%.2f Inch",mtoinch);
			fflush(stdin);
			printf("\n\t\tDo you want to continue?(y/n)");
			scanf("%c",&choice);
			if(choice=='y')
			goto a3;
		}
		else if(lengthchoice==3)
		{
			mtofoot=userinput*3.281;
			fprintf(pt,"\nUser is converting M to Foot: %.2f M =%.2f Foot",userinput,mtofoot);
			printf("\t\t\t%.2f Foot",mtofoot);
			fflush(stdin);
			printf("\n\t\tDo you want to continue?(y/n)");
			scanf("%c",&choice);
			if(choice=='y')
			goto a3;
		}
		else if(lengthchoice==4)
		{
			mtocm=userinput*100;
			fprintf(pt,"\nUser is converting M to CM: %.2f M =%.3f Cm",userinput,mtocm);
			printf("\t\t\t%.3f Cm",mtocm);
			fflush(stdin);
			printf("\n\t\tDo you want to continue?(y/n)");
			scanf("%c",&choice);
			if(choice=='y')
			goto a3;
		}
		else{
			printf("\n\t\tPlease enter correct choice");
		}
    }
    else
        printf("\n\t\tPlease enter correct choice");
	fclose(pt);
    exit(0);
}
void readMatrix(int array[10][10], int rows, int colums){  
    int i, j;  
    for (i = 0; i < rows; i++){  
        printf("\t%d entries for row %d: ", colums, i + 1);  
        for (j = 0; j < colums; j++){  
            scanf("%d", &array[i][j]);  
        }  
    }    
}
void printMatrix(int array[10][10], int rows, int colums){  
    int i, j;  
    FILE *pt;
    pt = fopen("record.txt","a");
    fprintf(pt,"\nMatrix:\n");
    for (i = 0; i < rows; i++) {  
        for (j = 0; j < colums; j++){ 
            fprintf(pt,"%d\t",array[i][j]); 
            printf("\t\t%d", array[i][j]);  
        }  
        printf("\n");  
        fprintf(pt,"\n");
    }  
    fclose(pt);
}
void matrixAddSub(int arrayone[10][10], int arraytwo[10][10], int rows, int colums, int mul){  
    int i, j;  
    int sumM[10][10];  
    int scaM[10][10];  
    FILE *pt;
    pt = fopen("record.txt","a");
    for (i = 0; i < rows; i++){  
        for (j = 0; j < colums; j++){  
            scaM[i][j] = mul * arraytwo[i][j];  
            }  
        }  
  
    if(mul == 1)
        fprintf(pt,"\nSum:\n");
    else
        fprintf(pt,"\nDifference:\n");    
    for (i = 0; i < rows; i++){  
        for (j = 0; j < colums; j++){  
            sumM[i][j] = arrayone[i][j] + scaM[i][j];
            fprintf(pt,"%d\t",sumM[i][j]);  
            printf("\t\t%d", sumM[i][j]);  
        }  
        printf("\n"); 
        fprintf(pt,"\n"); 
    }  
    fclose(pt);
}
void matrixScalarMultiply(int array[10][10], int scalar, int rows, int colums){  
    int i, j;  
    int scaM[10][10]; 
    FILE *pt;
    pt = fopen("record.txt","a"); 
    fprintf(pt,"\nScalar Multiplicaton:\n");
    for (i = 0; i < rows; i++){  
        for (j = 0; j < colums; j++){  
            scaM[i][j] = scalar * array[i][j]; 
            fprintf(pt,"%d\t",scaM[i][j]);  
            printf("\t\t%d", scaM[i][j]);  
        }  
        printf("\n");  
        fprintf(pt,"\n");
    }  
  
} 
void matrixMultiply(int arrayone[10][10], int arraytwo[10][10], int rowsA, int columsA,int columsB){  
    int i, j, k;  
    int mulM[10][10];  
    FILE *pt;
    pt = fopen("record.txt","a"); 
    fprintf(pt,"\nMatrix Multiplicaton:\n");
    // Initializing all elements of result matrix to 0  
    for (i = 0; i<rowsA; ++i)  
        for (j = 0; j<columsB; ++j)  
        {  
            mulM[i][j] = 0;  
        }  
  
    // Multiplying matrices a and b and  
    // storing result in result matrix  
    for (i = 0; i<rowsA; ++i)  
        for (j = 0; j<columsB; ++j)  
            for (k = 0; k<columsA; ++k)  
            {  
                mulM[i][j] += arrayone[i][k] * arraytwo[k][j];  
            }  
    printf("\nOutput Matrix:\n");  
    for (i = 0; i<rowsA; ++i){  
        for (j = 0; j<columsB; ++j)  
        {  
            printf("\t\t%d ", mulM[i][j]); 
            fprintf(pt,"%d\t",mulM[i][j]); 
            if (j == columsB - 1)  
                printf("\n\n");  
        } 
        fprintf(pt,"\n");  
    }
}
int matrixDet(int arrayone[10][10], int rows, int colums)
{
    int i,j,k,d,matrix[10][10],product,plusSUM=0, minusSUM=0;
    if( rows == 2)
        d = arrayone[0][0]*arrayone[1][1]-arrayone[0][1]*arrayone[1][0];
    else{
        for(i=0; i<rows; i++)
        {
            for(j=0; j<rows; j++)
                matrix[i][j] = arrayone[i][j];
        }
        for(i=0; i<rows; i++)
        {
            for(j=rows; j<(2*rows-1); j++)
                matrix[i][j] = arrayone[i][j-rows];
        }
        for(i=0; i<rows; i++){
            product =1 ;
            for(j=0; j<rows; j++)
                product = product*matrix[j][i+j];
            plusSUM += product;
        }
        for(i=rows-1; i<(2*rows-1); i++){
            product =1 ;
            for(j=0; j<rows; j++)
                product *= matrix[j][i-j];
            minusSUM += product;
        }
        d = plusSUM - minusSUM;
    }
    return d;
}