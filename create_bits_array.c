#include<stdio.h>
#include<stdlib.h>

typedef unsigned char BYTE;

BYTE * createBitsArray(int arr[], int size, int * bitArrSize);
int countSetBits(BYTE * bitsArr, int size);
int getMax(int arr[], int size);
BYTE setBit( BYTE ch, int i);

void main()
{
	int arr[] = {0, 5, 3, 12, 36};
	BYTE * bitsArr;
	int count;
	int size;

	bitsArr = createBitsArray(arr, sizeof(arr)/sizeof(int), &size);
	count = countSetBits(bitsArr, size);

	free(bitsArr);
}

BYTE * createBitsArray(int arr[], int size, int * bitArrSize)
{
	int i;
	BYTE * bitsArr;
	int max = getMax(arr, size);
	int bitsSize = max/8 + 1;	//the bits arr size in bytes

	bitsArr = (BYTE *)malloc(sizeof(BYTE) * bitsSize);
	
	for(i = 0; i < bitsSize; i++)	//set all bits to 0
		bitsArr[i]=0;

	for (i = 0; i < size; i++)	//set the relevant bits to 1
		bitsArr[arr[i]/8] = setBit(bitsArr[arr[i]/8], 7-arr[i]%8);
	
	*bitArrSize = bitsSize;
	return bitsArr;
}

int countSetBits(BYTE * bitsArr, int size)
{
	int i, j;
	int count = 0;

	for (i = 0; i < size; i++)
	{
		for( j = 0; j < 8; j++)
			count += bitsArr[i]>>j & 0x01;
	}
	return count;
}

int getMax(int arr[], int size)
{
	int i;
	int max = arr[0];
	
	for( i=1; i<size; i++)
	{
		if(arr[i] > max)
			max = arr[i];
	}

	return max;
}

BYTE setBit( BYTE ch, int i ) 
{
  BYTE mask = 1 << i;
  return ch | mask;
}

