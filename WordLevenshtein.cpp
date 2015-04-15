#include "WordLevenShtein.h"
 
double result[100][100];
int ArrayLenth;
 
/*计算相似度*/
double GetLevenshteinRadio(string a, string b)
{
    int lena = a.length();
    int lenb = b.length();
    int i, j;
    int **c = NULL;
    int Distance = 0; //求得的 Levenshtein 距离
    double  LevenshteinRadio = 0.0; //求得的相似度 
     
    /*初始化动态数组*/
    c=(int **)malloc(sizeof(int *)*(lena+1));
    if (c==NULL)
    {
        return ERROR;
    }
    for (i=0;i<=lena;i++)
    {
        c[i]=(int *)malloc(sizeof(int)*(lenb+1));
        if (c[i]==NULL)
        {
            for (j=0;j<i;i++)
                free(c[i]);
            free(c);
            return ERROR;
        }
    }
 
    if ((lena == lenb) &&(lena == 0)) //两个空串认为是相同的，返回1 
        return 1.00;
 
    for(i=0; i <= lena; i++)
        c[i][0] = i;    
    for(i=0; i <= lenb; i++)
        c[0][i] = i;
    for(i = 1; i <= lena; i++)
        for(j=1; j <= lenb; j++)
            c[i][j] = GetMinValue(c[i-1][j]+1, c[i][j-1]+1, c[i-1][j-1]+IsNotSame(a[i-1], b[j-1]));
     
    Distance = c[lena][lenb];
    LevenshteinRadio = 1 - (double)Distance / (double)GetMaxValue(lena, lenb);//相似度 =  Levenshtein 距离 / MAX(a.lenth,b.lenth) 
    LevenshteinRadio = (double)((int)(LevenshteinRadio*100))/100; //保留2位小数
     
    for(i=0;i<=lena;i++)
        free(c[i]);
    free(c);
 
    return LevenshteinRadio;
}
 
int CalWordArrayRadio(string Word[],int n)
{
    int i=0,j=0;
    double OneCalResult = 0.0;
     
    ArrayLenth = n;//字符串个数
 
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            OneCalResult = GetLevenshteinRadio(Word[i],Word[j]);
            if(OneCalResult < 0)
            {
                return -1;
            }
            result[i][j] = OneCalResult;
        }
    }
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            result[i][j] = result[j][i];
     
    /*
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<i<<","<<j<<":"<<result[i][j]<<"    ";
        cout<<endl;
    }
    */
    return 0;
}
 
/*
int main(void)
{
    string a[20]={
                    "Child2",
                    "Child1",
                    "MotherPlutar",
                    "Mme,Huchel",
                    "Courfeyrac",
                    "Feuily",
                    "Prouvaire",
                    "Combeferre",
                    "Enjairas",
                    "Mabeuf",
                    "Marius",
                    "Gavroche",
                    "Bossuel",
                    "Joly",
                    "Grantaire",
                    "Bahorel",
                    "Mme.Burgon",
                    "Jondrette",
                    "Bouiatruelle",
                    "Mile.Voubols"
                    };
 
    CalWordArrayRadio(a,20);
    return 0;
}
*/
