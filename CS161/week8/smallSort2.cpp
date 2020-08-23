/*********************************************************************
** Author: Hailey Wilder
** Date: 11/12/16
** Description: Sort 3 ints in ascending order using pointers.
*********************************************************************/

#include <iostream>

using namespace std;

void smallSort(int*, int*, int*);

/*********************************************************************
** Description: Gets user inputs and calls sort function
** Parameters: Takes none, Returns none. 
*********************************************************************/
int main()
{
    int num1, num2, num3;  // declare int variables 
	// get ints from user
    cout << "Please enter the first number" << endl;
    cin >> num1;
    cout << "Please enter the second number" << endl;
    cin >> num2;
    cout << "Please enter the third number" << endl;
    cin >> num3;
    cout << "Now sorting:" << endl;

    smallSort(&num1, &num2, &num3);

    return 0;
}

/*********************************************************************
** Description: Sorts inputs in ascending order. 
** Parameters: Takes 3 ints, returns none.
*********************************************************************/

void smallSort(int *pnt1, int *pnt2, int *pnt3)
{
    int nums[3] = {*pnt1,*pnt2,*pnt3};
	int temp;

    for(int i = 0; i <= 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			if(nums[j] > nums[j+1])
			{
				temp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = temp;
			}
		}
	}

	for(int k = 0; k < 3; k++)
	{
	cout << nums[k] << ", ";
	}
}