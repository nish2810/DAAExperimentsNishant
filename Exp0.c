#include<stdio.h>
#include<math.h>

//To implement the various functions e.g. linear, non-linear, quadratic, exponential etc.

//(3/2)^n
void function1()
{
    for(int n = 0; n <= 100; n = n+10)
    {
        printf("%d : %f\n", n , pow(1.5,n));
    }
}

//n^3
void function2()
{
    for(int n = 0; n <= 100; n=n+10)
    {
        printf("%d : %d\n",n,n*n*n);   
    }
}

//2^(2^n)
void function3()
{
    for(int n = 0; n <= 100; n = n+10)
    {
        printf("%u : %f\n",n, 2*(pow(2,n)));
    }
}

//log2(n)
void function4()
{
    for(int n = 0; n <= 100; n=n+10)
    {
        printf("%d : %f\n", n ,log2(n));   
    }
}

//2^(log2(n))
void function5()
{
    for(int n = 0; n <= 100; n= n+10)
    {
        printf("%d : %f\n",n,pow(2,(log2(n))));
    }
}

//n
void function6()
{
    for(int n = 0; n <= 100; n = n+10)
    {
        printf("%d : %d\n",n,n);
    }
}

//2^n
void function7()
{
    for (int n = 0; n <= 100; n = n+10)
    {
        printf("%d : %f\n",n,pow(2,n));
    }
    
}

//nlog2(n)
void function8()
{
    for(int n = 0; n <= 100; n = n+10)
    {
        printf("%d : %f\n",n,n*log2(n));
    }
}

//2^((2^n)+1)
void function9()
{
    for(int n =0; n <= 100; n = n+10)
    {
        printf("%d : %f\n",n,pow(2,pow(2,n+1)));
    }
}

//lnln(n)
void function10()
{
    for(int n = 0; n <= 100; n = n+10)
    {
        printf("%d : %f\n",n,log(log(n)));
    }
}

//n!
void function11()
{
    for(int n = 0; n <= 20; n = n+2)
    {
        double fact = 1;
        for(int i = 1; i <= n; i++)
        {
            fact = fact*i;
        }
        printf("%d : %f\n",n,fact);
    }

}
int main()
{
    printf("Press 1 : Function1 (3/2)*n\n");
    printf("Press 2 : Function2 n^3\n");
    printf("Press 3 : Function3 2^(2^n)\n");
    printf("Press 4 : Function4 log2(n)\n");
    printf("Press 5 : Function5 2^(log2(n))\n");
    printf("Press 6 : Function6 n\n");
    printf("Press 7 : Function7 2^n\n");
    printf("Press 8 : Function8 nlog2(n)\n");
    printf("Press 9 : Function9 2^((2^n)+1)\n");
    printf("Press 10 : Function10 lnln(n)\n");
    printf("Press 11 : Function11 n!\n");
    printf("Press 12 : Exit\n");

    int option;
    while (option != 12)
    {
        printf("Enter your choice : ");
        scanf("%d" ,&option);
        switch (option)
        {
        case 1:
        printf("Function1 (3/2)*n : \n");
        function1();
            break;

        case 2:
        printf("Function2 n^3 : \n");
        function2();
            break;

        case 3:
        printf("Function3 2^(2^n) : \n");
        function3();
            break;
        
        case 4:
        printf("Function4 log2(n) : \n");
        function4();
            break;

        case 5:
        printf("Function5 2^(log2(n)) : \n");
        function5();
            break;

        case 6:
        printf("Function6 n : \n");
        function6();
            break;

        case 7:
        printf("Function7 2^n : \n");
        function7();
            break;

        case 8:
        printf("Function8 nlog2(n) : \n");
        function8();
            break;

        case 9:
        printf("Function9 2^((2^n)+1) : \n");
        function9();
            break;

        case 10:
        printf("Function10 lnln(n) : \n");
        function10();
            break;

        case 11:
        printf("Function11 n! : \n");
        function11();
            break;
        }
    }
}
