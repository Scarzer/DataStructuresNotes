#include <stdio.h>

int main(){
	double array[30];
	int sizeArray = 0;
	int arrayPtr = 0;

	array[0] = 0.1;
	sizeArray++;
	arrayPtr++;
	array[1] = 0.2;
	sizeArray++;
	arrayPtr++;
	array[2] = 0.4;
	sizeArray++;
	arrayPtr++;
	array[3] = 0.6;
	sizeArray++;
	arrayPtr++;

	for(arrayPtr = 0; arrayPtr < sizeArray; arrayPtr++){
		printf("The size is: %d  The pointer is: %d The array is: ", sizeArray, arrayPtr);
		printf("%f\n",array[arrayPtr]);
	}

	printf("%s\n","=======================" );
	printf("%s\n","We're going to be shifting a value now" );
	printf("%s\n", "We're going to insert 0.5 between 0.4 and 0.5");

	arrayPtr = 3; //Get the array pointer to where we want it. So that we could eventually move it down
		for( int newSize = sizeArray + 1; newSize > arrayPtr; newSize--){
		for(int i = 0; i < sizeArray; i++){
			printf("The index is: %d The array is: ", i);
			printf("%f\n",array[i]);
		}
		printf("=============================\n");
		array[newSize] = array[newSize - 1];
	}
	sizeArray++;
	array[arrayPtr] = 0.5;

	for(int i = 0; i < sizeArray; i++){
		printf("The index is: %d The array is: ", i);
		printf("%f\n",array[i]);
	}

	printf("Now we want to remove an element from the array\n");

	for (int newPos = arrayPtr + 1; newPos < sizeArray; newPos++){
		for(int i = 0; i < sizeArray; i++){
			printf("The index is: %d The array is: ", i);
			printf("%f\n",array[i]);
		}
		printf("============================\n");
		array[arrayPtr] = array[newPos];
		arrayPtr++;
	}
	sizeArray--;
	for(int i = 0; i < sizeArray; i++){
		printf("The index is: %d The array is: ", i);
		printf("%f\n",array[i]);
	}
}