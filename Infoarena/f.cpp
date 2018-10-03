double s(double a[10][10],int n, int m)
{
    double x=0.0;
    for(int i=0;i<min(n,m);++i)
    {
        int nr=(int)a[i][i];
        if(nr%5==0 && nr-a[i][i]==0)
            x+=a[i][i];
    }
    return x;
}
