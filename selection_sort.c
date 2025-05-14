// Program 1 b

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i,j,n,a[100],emp;
	printf("enter the number of elements : ");
	scanf("%d",&n);
	for (i=0;i<n;i++){
		  int ele;
	    printf("enter the elements :");
	    scanf("%d",&a[i]);
  }
  printf("array : ");
	for (i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	for (i=0;i<n;i++){
		for( j=i+1;j<n;j++){
			if(a[i]>a[j]){
				emp=a[i];
				a[i]=a[j];
				a[j]=emp;
			}else{
				continue;
			}
		}	
	}
	printf("\nsorted array : ");
	for (i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
