 do
    {
        temperror = 0;
        for(i = 1; i <= limit; i++) //accessing row //limit = number of equations
        {
            sum = 0;
            for(j = 1; j <= limit; j++)//sccessing column
            {
                if(j != i)//avoid diagonal elements
                {
                    sum = sum + a[i][j] * x[j];
                }
            }
            temp[i] = (a[i][limit + 1] - sum) / a[i][i];
            error = fabs(x[i] - temp[i]);
            if(error > temperror)
            {
                temperror = error;
            }
            //x[i] = temp;

        }
        for(i=1;i<=limit;i++)
        {
            x[i] = temp[i];
        }
        //printf("%lf\n", temp);
        //x[i] = temp;

    }while(temperror >= allowed_error);



