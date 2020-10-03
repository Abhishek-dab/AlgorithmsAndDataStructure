#include <cstdlib>
#include <iostream>

using namespace std;
float W[5], B[5], X[5], RW, TB = 0;
int i, j;

int main(int argc, char *argv[])
{

	//input total weight of the knapsack    
	cout << "Enter the current weight: ";
	cin >> RW;
	cout << endl;

	//input the weight and benefit of each item
	for (i = 0; i < 5; i++)
	{
		cout << "Weight item " << i + 1 << "= ";
		cin >> W[i];
		cout << "Benefit item " << i + 1 << "= ";
		cin >> B[i];


		//Calculate value of X
		X[i] = B[i] / W[i];
		cout << "Value of item " << i + 1 << "= " << X[i];
		cout << endl;
		cout << endl;

	}

	//descending bubble sort to find the largest number of X
	float temp;
	float temp1; // to make W follow X
	float temp2; // to make B follow X

	for (i = 0; i <= 4; i++)
	{
		for (j = 0; j < 4; j++)
			if (X[j] < X[j + 1])
			{
				temp = X[j];
				temp1 = W[j];
				temp2 = B[j];

				X[j] = X[j + 1];
				W[j] = W[j + 1];
				B[j] = B[j + 1];

				X[j + 1] = temp;
				W[j + 1] = temp1;
				B[j + 1] = temp2;
			}
	}

	/*
	for(i=0;i<5;i++){
	cout<<"X= "<<X[i]<<" "<<endl;
	cout<<"W= "<<W[i]<<" "<<endl;
	cout<<"B= "<<B[i]<<" "<<endl; }
	*/


	for (i = 0; i < 5; i++) {
		if (RW >= 0)
		{
			//cout<<"Weight = "<<W[i]<<" "<<endl;  
			//cout<<"TB = "<<TB<<" "<<endl;                        
			RW = RW - W[i];
			TB = TB + B[i];

			//If Remaining weight is negative, remove parts of the benefits
			if (RW < 0)
			{
				//cout<<"X= "<<X[i]<<" "<<endl;         
				TB = TB + RW * X[i];
			}
		}
	}

	//output
	cout << "The total benefit is: " << TB << endl;
	//cout<<"RW: "<<RW<<endl;

	return 0;

}