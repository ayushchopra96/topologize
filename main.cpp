#include <bits/stdc++.h>
using namespace std;
#include "header.h"
//3 single  bond hai to 109.5
//1 double bond 120
// 1 triple bond  180
void get_slope_dist(struct pdb pdbfile[],int file_length,vector<struct arr> &v)
{
   v.clear();
   for(int i=0,j=1;i<file_length && j<file_length;i++,j++)
   {
      struct point p1;
      p1.x=pdbfile[i].x2;
      p1.y=pdbfile[i].y2;
      p1.z=pdbfile[i].z2;

      struct point p2;
      p2.x=pdbfile[j].x2;
      p2.y=pdbfile[j].y2;
      p2.z=pdbfile[j].z2;
      float s=getslope(p1,p2);
      float d=getdist(p1,p2);
      struct arr temp;
      temp.slope=s;temp.len=d;
      v.push_back(temp);
   }
}
float alignment(vector<struct arr> &v,vector<struct arr> &v1,float threshold)
{
  struct arr a[10000],b[10000];
  int n1=v.size(),n2=v1.size();
  float len=0,len1=0;
  int i=0;
  for(vector<struct arr> :: iterator it=v.begin();it!=v.end();it++,i++)
  {
       a[i].slope=it->slope;
       a[i].len=it->len;
       len+=it->len;
  }
  i=0;
  for(vector<struct arr> :: iterator it=v1.begin();it!=v1.end();it++,i++)
  {
       b[i].slope=it->slope;
       b[i].len=it->len;
       len1+=it->len;
  }
  float ans;
  if(len<len1)
  {
    ans=dp(a,v.size(),b,v1.size(),threshold);
    ans=ans/len;
  }
  else
  {
    ans=dp(b,v.size(),a,v1.size(),threshold);
      ans=ans/len1;
  }
  return ans;
}

int main(int argc,char *argv[])
{
    struct pdb pdbfile1[3000],pdbfile2[3000];
    int filelength1=0,filelength2=0;
    read_rr(argc,argv,1,pdbfile1,filelength1);
    read_rr(argc,argv,2,pdbfile2,filelength2);
    vector<struct arr> v2,v1;v1.clear();v2.clear();
    get_slope_dist(pdbfile1,filelength1,v1);
    get_slope_dist(pdbfile2,filelength2,v2);
    float max1;
    float threshold = 0.5;
    max1=alignment(v1,v2,threshold);
    cout<<max1;
    max1=-1;
    for(int i=0,k=1;i<filelength1 && k<filelength1;i++,k++)
    {
      struct point p1,p2;
      struct vectr r;
      p1.x=pdbfile1[i].x2;
      p1.y=pdbfile1[i].y2;
      p1.z=pdbfile1[i].z2;

      p2.x=pdbfile1[k].x2;
      p2.y=pdbfile1[k].y2;
      p2.z=pdbfile1[k].z2;

      //considering forward alignment..
      r.x=p1.x-p2.x;r.y=p1.y-p2.y;r.z=p1.z-p2.z;
      for(int j=0;j<filelength2;j++)
      {
    //    printf("i==%d j==%d k==%d\n",i,j,k);
          if(i!=j)
            continue;
        traslate_all_point(pdbfile2,filelength2,p1);
        rotate_all_point(pdbfile2,filelength2,r);
        get_slope_dist(pdbfile2,filelength2,v2);
        float x=alighnment(v1,v2,threshold);
        if(x>max1)
           max1=x;
      }
      //Now considering reverse alignment..
      r.x=p2.x-p1.x;r.y=p2.y-p1.y;r.z=p2.z-p1.z;
      for(int j=0;j<filelength2;j++)
      {
    //    printf("i==%d j==%d k==%d\n",i,j,k);
          if(i!=j)
            continue;
        //traslate_all_point(pdbfile2,filelength2,p1);
        rotate_all_point(pdbfile2,filelength2,r);
        get_slope_dist(pdbfile2,filelength2,v2);
        float x=alighnment(v1,v2,.20);
        if(x>max1)
           max1=x;
      }
    }
    printf("Structural similarity is %f\n",max1);
}
