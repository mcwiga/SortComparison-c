/*
Name : Michael McGloin
ID : 18357636
Email : m.mcgloin2@nuigalway.ie


A program that will generate a random list and then check how many swaps was carried out
when trying to arrange the list in ascending order by using both a bubble swap and a linear sort algorithm

The linear sort works by :
1 - Looking at the first element in the list and then iterating through the list, swapping the position of
    the first element with any element smaller than it

2 - When it has compared the first element to all the elements in the list and made necessary swaps
    it will move onto the second element and repeat this process i.e. checks if any element after
    the 2nd element is smaller than it.
3 - It does this for every element in the list until it compares the second last element to the last
    by which time your list should be sorted

The bubble sort works by :
1 - Compares a0 to a1 , then a1 to a2 .... until a(n-1) a(n) swapping the position any time a(n-1) is bigger than a(n)
2 - It repeats this process, on the first iteration the biggest element will bubble to the back of the list
    on the second iteration the 2nd biggest element will have bubbled to the back of the list and so on until
    it can be assured that the list is ordered in ascending order.
    (It basically orders the list backwards and after nth iterations at worst the nth largest number
     should be nth from last in the list)


This program also contains a swap function Swap() that swaps the position of items in a list.

*/


#include <stdio.h>
#include <stdlib.h>
void swap(int *i, int *j);
int LinearSort(int *myList , int n);
int BubbleSort(int *myList, int n);
int main(void){
int noElements;
printf("How many elements do you want in your list? \n");
do{
    scanf("%d", &noElements);
}
while ( (noElements<1) || (noElements>30) );
printf("What is the maximum value you want each number in list to be? \n");
int max;
scanf("%d", &max);

int myList[noElements];
int myList2[noElements];
int i;
printf("\nYour list is :\n ");
for (i=0; i<noElements; i++)
  {
    myList[i] = rand()%max;
    myList2[i] = myList[i];
    printf("%8d", myList[i]);
  }
int countsLinear = LinearSort(myList, noElements);
int countsBubble = BubbleSort(myList2, noElements);
printf("\n\nNo of swaps in Linear sort : %d\n\n", countsLinear);
printf("No of swaps in Bubble sort : %d\n", countsBubble);

return 0;
}


int LinearSort(int *myList , int n){
printf("\n\n \t\t\t\t\tLinear Sort\n\n");
int i,j;
int noSwaps = 0;
  printf("\n");

for (i=0; i<(n-1); i++){
    for (j=i+1; j<n; j++){
      if (myList[j] < myList[i]){
        swap( &myList[i], &myList[j]);
        noSwaps ++;
        }
    }
}
for (i=0; i<n; i++)
    printf("%8d", myList[i]);

return noSwaps;
}



int BubbleSort(int *myList ,int n){
    printf("\n \n\t\t\t\t\tBubble Sort\n\n");
int i,j;
int BubbleSwaps = 0;

for(i=0; i<=(n-1) ; i++){
    for(j=0;j<=n-i-1 ; j++){
        if (myList[j+1]<myList[j]){
            swap(&myList[j],&myList[j+1]);
            BubbleSwaps++;
        }
    }
}

for (i=0; i<n; i++)
    printf("%8d", myList[i]);


return BubbleSwaps;
}

void swap(int *i, int *j)
{
  int tmp;
  tmp = *i;
  *i = *j;
  *j = tmp;
}

