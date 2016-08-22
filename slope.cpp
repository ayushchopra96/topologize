#include <bits/stdc++.h>
using namespace std;
#include "header.h"
float dp(struct arr *X,int m,struct arr *Y, int n,float t)
{
   float L[m+1][n+1];
   int i, j;
 
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (abs(X[i-1].slope-Y[j-1].slope)<=t)
       {
         L[i][j] = L[i-1][j-1] + X[i-1].len;
       }
 
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}
float getdist(struct point p1,struct point p2)
{
  float x1=(p1.x-p2.x);
  float y1=(p1.y-p2.y);
  float z1=(p1.z-p2.z);
  return x1*x1+y1*y1+z1*z1;
}
float getslope(point &a,point &b)
{
    float delx=a.x-b.x;
    float dely=a.y-b.y;
    float delz=a.z-b.z;

    float rise=delz;
    float inter=delx*delx+dely*dely;
    float run=pow(inter,0.5);
    float ans=rise/run;
    return ans;
}
