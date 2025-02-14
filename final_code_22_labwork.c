#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> // to do
// directives preprocesing 
double  error =  0.0000001;

// обьявление ф-ий
double MyAbs(double num);
double CheckIsCorrect(int positeve);
double InputLikeNumberToAnswer(int positeve);
double Integral(double E, double a, double b);
double InfiniteRow(double E);


// int for two problems
int main()
{
    double E, a, b, Itgral, Infrow;
    printf("*** Нахождение интеграла ***\n");
    printf("Введите погрешность\n");
    E = InputLikeNumberToAnswer(1);
    printf("Введите a\n");
    a = InputLikeNumberToAnswer(0);
    printf("Введите b\n");
    b = InputLikeNumberToAnswer(0);
    // two
    Itgral = Integral(E, a, b);
    printf(">>> %f\n", Itgral);
    printf("*** Нахождение суммы бесконечного ряда ***\n");
    printf("Введите погрешность\n");
    E = InputLikeNumberToAnswer(1);
    Infrow = InfiniteRow(E);
    printf(">>> %f\n", Infrow);
    return 0;
}


double MyAbs(double num)
{
    // not need function 
    return fabs(num);
}

double CheckIsCorrect(int positeve)
{

    char InputToCheckCorrect[30];
    double Flag = 0;
    fgets(InputToCheckCorrect, 30, stdin);
    fflush(stdin);
    // check is flat
    for (int i = 0; i <= strlen(InputToCheckCorrect); i++)
    {
        if (InputToCheckCorrect[i] == '.')
        {
            Flag++;
        }
        // to do optimize code with  using of isdigit
        if (positeve == 1)
        {
            if (InputToCheckCorrect[i] == '-')
            {
                printf("Некоректные данные\n");
                return error;   // return error
            }
        }

        if (isalpha(InputToCheckCorrect[i]) || (InputToCheckCorrect[i] == '-' && i != 0) || Flag > 1)   // check if input is a number
        {
            // number check 
            printf("Некоректные данные\n");
            return error;   // return error
            
        }
    }


    return atof(InputToCheckCorrect);
}


double InputLikeNumberToAnswer(int positeve)
{
    double answer = error;
    

    while (answer == error)
    {
        printf("Введите число: ");
        // printf("Enter: ")
        answer = CheckIsCorrect(positeve);
    }
    return answer;
}


double Integral(double E, double a, double b)
{

    int N = 1;
    double h, x, Sumi, Sum, ProizvSumm = 0;
    while (1)
    {
        Sum = 0;
        N = N * 2;
        h = (b - a) / N;
        x = a;
        for (int i = 0; i < N; i++)
        {
            x += h;
            // to do  need function of log e = 10
            Sumi = h * (log(x) + log(x - h)) / 2;
            Sum += Sumi;
        }
        if (MyAbs(ProizvSumm - Sum) <= E)
        {
            return Sum;
            break;
        }
        ProizvSumm = Sum;
    }
}


double InfiniteRow(double E)
{ 

    float num = 1;
    double FirstIteration = 1, currentIteration = 0, summary = 0, prevSummary;
    prevSummary = FirstIteration;
    while (1)
    {
        num++;
        currentIteration = 1 / num;
        summary = prevSummary + currentIteration;
        if ((summary - prevSummary) <= E)
        {
            // to do replace return
            return summary;
            break;
        }
        prevSummary = summary;
        FirstIteration = currentIteration;
    }
    return 0;
}