//二分查找片段代码 
Position BinarySearch( List L, ElementType X )
{
	if(L==NULL)
	{
		return NotFound;
	}
	int low=1,high=L->Last;
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(L->Data[mid]==X)
			return mid;
		else if(L->Data[mid]>X)
			high=mid-1;
		else
			low=mid+1;
	}
	return NotFound;
}
