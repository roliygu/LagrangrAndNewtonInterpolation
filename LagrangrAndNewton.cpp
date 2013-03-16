double Lagrange(double A[][n+5],int n,double x)
{
	double sum=0,tot;
	for(int i=1;i<=n;++i)
	{
		tot=1.0;
		for(int k=0;k!=i&&k<=n;++k)
		{
			tot *= (x-A[0][k])/(A[0][i]-A[0][k]);
		}
		sum += tot*A[1][i];
	}
	return sum;
}
double Newton(double X[],double A[][n+5],int n,double x)
{
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
		{
			A[i][j]=(A[i-1][j]-A[i-1][j-1])/(X[j]-X[0]);
		}
	}
	double sum=0,tot;
	for(int i=1;i<=n;++i)
	{
		tot=1.0;
		for(int k=1;k<=i;++k)
		{
			tot *= (x-X[k]);
		}
		sum += A[i][i]*tot;
	}
	return sum;
}