  //AITKEN.C
  //Aitken������
  #include  <math.h>
  #include  <stdio.h>
  double aitken(x, eps, f)
  double  x, eps, (*f)(double);
  { 
	  int flag = 0, k = 0;
      double u, v;
      while ((flag == 0) && (k <= 100))
      { 
		  k = k + 1; 
          u = (*f)(x);  v = (*f)(u);
          if (fabs(u-v)<eps) { x = v;  flag = 1; }
          else x = v - (v - u)*(v - u)/(v - 2.0*u + x);
      }
	  if (k > 100) printf("��������100��,���ܲ�����!\n");
      return(x);
  }

  //�������ļ�AITKEN.C��
  main()
  { 
      double x, f(double);
      x = aitken(0.5 ,0.0000001, f);
      printf("x=%f\n", x);
  }

  double f(double x)
  {  return(6.0-x*x); }