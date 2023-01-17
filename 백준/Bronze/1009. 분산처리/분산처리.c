#include<stdio.h>

#include<stdlib.h> 



main(){

	int i,j,t;

	int *a,*b,*tmp;

	

	scanf("%d",&t);



	a=(int*)malloc(sizeof(int)*t);

	b=(int*)malloc(sizeof(int)*t);

	tmp=(int*)malloc(sizeof(int)*t);

	

	for(i=0;i<t;i++){

		scanf("%d %d",&a[i],&b[i]);

		tmp[i]=1;

		for(j=0;j<b[i];j++){

			tmp[i]*=a[i];

			if(tmp[i]>10)

				tmp[i]%=10;

		}

		if(tmp[i]==0){

			tmp[i] = 10; 

		}

	}

	for(i=0;i<t;i++)

		printf("%d\n",tmp[i]);

		

	free(tmp);	

	free(b);

	free(a);

}
