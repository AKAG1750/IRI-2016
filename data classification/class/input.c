#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#include "input.h"
int i, j, k;

double Lagrange(double *x, double *y, int N, double var)
{

    //////////////////////////////////////
    ///// Lagrangian interpolation ///////
    //////////////////////////////////////

    static double fff;
    double ff = 0, z, ztemp;
    for (j = 0; j < N; j++)
    {
        z = 1;

        for (i = 0; i < N; i++)
        {
            if (i != j)
                ztemp = (var - x[i]) / (x[j] - x[i]);
            else
                ztemp = y[j];

            z = z * ztemp;
         }

        ff = ff + z;
    }
    fff = ff;
    return fff;
}

double *FunLagran(double *x, int N, int v1, int v2)
{

    ///////////////////////////////////////////////////////////////
    ////// Lagrange interpolation of data form v1 and v2 columns ///
    ////////// of the matrix[sizeM,len] form by values  ////////////
    ////////////////////////////////////////////////////////////////

    static double y[4];
    int n = 101;
    int sizeM = 467;
    int len = 17;

    // i=0 ;
    // j=0 ;
    char ch;

    FILE *fp = fopen("tableW.txt", "r");
    double values[len * (sizeM)];

    for (i = 0; i < len * (sizeM); ++i)
    {
        fscanf(fp, "%lf", &values[i]);
    }
    pclose(fp);

    int *MI;
    double M[sizeM];
    for (i = 0; i < sizeM; i++)
    {
        M[i] = values[i * len + v1];
    }
    MI = sortIindex(M, sizeM);

    int ii = 0;
    double value1[sizeM];
    double value2[sizeM];
    double temp1, temp2;
    i = 0;
    value1[i] = values[MI[i] * len + v1];
    value2[i] = values[MI[i] * len + v2];
    temp1 = value1[i];

    for (i = 1; i < sizeM; i++)
    {
        temp2 = values[MI[i] * len + v1];
        if (fabs(temp1 - temp2) > 0.000001)
        {
            value1[ii] = temp2;
            value2[ii] = values[MI[i] * len + v2];
            temp1 = temp2;
            ii++;
        }
    }
    k = 0;
    while (k < N)
    {
        y[k] = Lagrange(value1, value2, ii, x[k]);
        k++;
    }

    return y;
}

void GetNumData(int n)
{
    ////////////////////////////////////////////////
    /// Extract numerical values from the table  ///
    ////////////////////////////////////////////////

    // i=0 ;
    // j=0 ;

    char ch;
    char ch1 = '-';
    FILE *fp0 = fopen("AU930_ROAM.TXT", "r");
    FILE *temp0 = fopen("tableW.txt", "w");

    while ((ch = fgetc(fp0)) != EOF)
    {
        if (i > n)
        {

            if ((ch == '-') && (ch1 != '-'))
                fprintf(temp0, "0.000"), ch1 = ch;

            if ((ch == ':') != (ch == '-') != (ch == '(') != (ch == ')'))
                fprintf(temp0, " ");

            else
                fprintf(temp0, "%c", ch), ch1 = ch;
        }
        i++;
    }
    fclose(temp0);
    fclose(fp0);
}

int *sortIindex(double *M, int sizeM)
{
    static int MI[467];
    // sort time
    // i=0 ;
    // j=0 ;
    k = 0;
    double m1, m2;
    int mi1;
    int mi2;
    // double M[sizeM];
    // int   MI[sizeM];

    for (i = 0; i < sizeM; i++)
    {
        MI[i] = i;
        //      M[i] =1440*(values[ i*len+2])+60*values[ i*len+3]+values[ i*len+4];
    }

    while (k < sizeM * sizeM)
    {
        for (i = 1; i < sizeM; i++)
        {
            m1 = M[i - 1];
            mi1 = MI[i - 1];
            m2 = M[i];
            mi2 = MI[i];
            if (m1 > m2)
            {
                M[i - 1] = m2;
                MI[i - 1] = mi2;
                M[i] = m1;
                MI[i] = mi1;
            }
        }
        k++;
    }
    //    for(i=0;i<sizeM;i++) {
    // printf("%lf"      "%d\n",M[i], MI[i] ) ;
    //}

    return MI;
}

void sortTable(double *values, int sizeM, int len, int n, int *MI)
{

    //////////////////////////////////////////////////////////////////
    //         Sort the table from oldest date to the newest        //
    /////////////////////////////////////////////////////////////////

    // sort time
    // i=0 ;
    // j=0 ;
    // k =0 ;
    // double m1 , m2 ;
    // int   mi1;
    // int   mi2 ;
    // double M[sizeM];
    // int   MI[sizeM];

    //     for(i=0;i<sizeM;i++) {
    //      M[i] =1440*(values[ i*len+2])+60*values[ i*len+3]+values[ i*len+4];
    //   }

    // MI = sortIindex( M, sizeM  );

    // while (k<sizeM*sizeM){
    // for(i=1;i<sizeM;i++) {
    //     m1 = M[i-1] ;
    //    mi1 =MI[i-1];
    //   m2 = M[i] ;
    //  mi2 =MI[i];
    //     if (m1> m2){
    //  M[i-1]=m2;
    //  MI[i-1]=mi2;
    //  M[i] = m1;
    //  MI[i] = mi1;
    //   }
    //    }
    // k++;
    //   }

    // sort the whole table
    int ind;
    double doubch;
    int intch;
    FILE *temp = fopen("tableSorted.txt", "w");
    FILE *fp1 = fopen("AU930_ROAM.TXT", "r");
    char ch;
    i = 0;
    while (((ch = fgetc(fp1)) != EOF) && (i <= n))
    {
        fprintf(temp, "%c", ch);
        i++;
    }
    fclose(fp1);

    fprintf(temp, "%c"
                  "  ",
            '\n');

    for (j = 0; j < sizeM; j++)
    {
        fprintf(temp, "%c"
                      "  ",
                '\n');
        ind = MI[j];
        for (i = 0; i < len; i++)
        {
            k = i + (ind)*len + 1;
            doubch = values[ind * len + i];
            intch = doubch;
            if (i == 0)
                fprintf(temp, "%0.2f"
                              ".",
                        doubch);
            else

                if (i == 1)
            {
                intch = 100 * doubch;
                if (intch < 10)
                    fprintf(temp, "%c%d"
                                  " ",
                            '0', intch);
                else
                    fprintf(temp, "%d"
                                  " ",
                            intch);
            }
            else

                if (i == 2)
            {
                if (intch < 10)
                    fprintf(temp, "%c%c%c%d%c"
                                  " ",
                            '(', '0', '0', intch, ')');
                else
                    fprintf(temp, "%c%c%d%c"
                                  " ",
                            '(', '0', intch, ')');
            }
            else

                if ((i == 3) != (i == 4))
            {
                if (intch < 10)
                    fprintf(temp, "%c%d"
                                  ":",
                            '0', intch);
                else
                    fprintf(temp, "%d"
                                  ":",
                            intch);
            }
            else if (i == 5)
            {
                if (intch < 10)
                    fprintf(temp, "%c%d"
                                  "\t",
                            '0', intch);
                else
                    fprintf(temp, "%d"
                                  "\t",
                            intch);
            }
            else if (i == 6)
            {
                if (intch < 10)
                    fprintf(temp, "%c%d"
                                  " ",
                            '0', intch);
                else
                    fprintf(temp, "%d"
                                  " ",
                            intch);
            }

            else if (((i > 6) && (i < 11)) != (i == 17))
            {
                if (intch == 0)
                    fprintf(temp, "  --- ");
                else

                    fprintf(temp, "%0.3f"
                                  " ",
                            doubch);
            }

            else if (intch == 0)
                fprintf(temp, "    --- ");
            else

                fprintf(temp, "%0.3f"
                              " ",
                        doubch);
        }
    }

    fclose(temp);

    // return 0;
}
