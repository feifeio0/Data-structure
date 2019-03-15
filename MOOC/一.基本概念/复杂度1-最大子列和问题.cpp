#include<stdio.h> 
int Max3(int A,int B,int C)
{
	return A>B?A>C?A:C:B>C?B:C;
}

int DivideAndConquer(int List[], int left, int right)
{
	int MaxLeftSum,MaxRightSum;
	int MaxLeftBorderSum,MaxRightBorderSum;
	int LeftBorderSum,RightBorderSum;
	int center,i;
	if(left == right)
	{
		if(List[left] > 0)
		{
			return List[left];
		}
		else
		{
			return 0;
		}
	}
	center = (left+right)/2;
	//printf("%d",center);
	MaxLeftSum = DivideAndConquer( List, left, center );
	MaxRightSum = DivideAndConquer( List, center+1, right );
	
	MaxLeftBorderSum = 0; 
	LeftBorderSum = 0;
	for(i=center;i>=left;i--)
	{
		LeftBorderSum += List[i];
		if( LeftBorderSum > MaxLeftBorderSum )
		{
			MaxLeftBorderSum = LeftBorderSum;
		}
	}
	MaxRightBorderSum = 0;
	RightBorderSum = 0;
	for(i=center+1;i<=right;i++)
	{
		RightBorderSum += List[i];
		if( RightBorderSum > MaxRightBorderSum )
		{
			MaxRightBorderSum = RightBorderSum;
		}
	}
	
	return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}
int main()
{
	int a[100000];
	int k,i;
	int Max;
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		scanf("%d",&a[i]);
		//printf("%d ",a[i]); 
	}
	Max = DivideAndConquer(a,0,k-1);
	printf("%d",Max);
	return 0;
}
