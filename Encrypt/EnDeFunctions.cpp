#include "EnDeFunctions.h"
#define EXP_STL

Matrix Create3x3(double input[9])
{
	Matrix tmp;

	tmp.noCols = 3;
	tmp.noRows = 3;

	

	for (int i = 0; i < 9; i++)
	{
		tmp.theData.push_back(input[i]);
	}

	return tmp;
}

Matrix multiplyMatrix(Matrix a, Matrix b)
{
	if (a.noCols == b.noRows)
	{
		double column, row;
		vector<double> data;
		//how many times?
		for (int i = 0; i < (a.noRows * b.noCols); i++)
		{
			column = floor((double)i / a.noRows) + 1;
			row = (i % a.noRows) + 1;

			double solution = 0;

			for (int j = 0; j < a.noCols; j++)
			{
				solution += GetFromMPosition(row, j+1, a) * GetFromMPosition(j+1, column, b);
			}


			data.push_back(solution);
		}

		return Create3xX(data);
	}
}

Matrix Create3xX(vector<double> input)
{
	Matrix tmp;
	if ((input.size() % 3) != 0)
	{
		for (int add = 3 - (input.size() % 3); add != 0; add--)
		{
			input.push_back(0);
		}
	}

	tmp.noCols = ceil( input.size() / 3.0 );
	tmp.noRows = 3;
	tmp.theData = input;

	return tmp;
}

double GetFromMPosition(int row, int col, Matrix tmp)
{
	if (tmp.noCols < col || tmp.noRows < row)
	{
		return 0;
	}
	else
	{
		return tmp.theData[(row - 1) + (col - 1)*(tmp.noRows)];
	}
}

string outputMatrix(Matrix tmp)
{
	int width = 9;
	int cols = tmp.noCols;

	stringstream temp;
	temp.setf(ios::left);

	for (int i = 1; i <= tmp.noRows; i++)
	{
		for (int j = 1; j <= tmp.noCols; j++)
		{
			//temp << setw (width) << i << "," << j << "       ";
			temp << setw (width) << GetFromMPosition(i, j, tmp);
		}
		temp << endl;
	}

	return temp.str();
}
string outputMatrix(Matrix tmp, int width)
{
	int cols = tmp.noCols;

	stringstream temp;
	temp.setf(ios::left);

	for (int i = 1; i <= tmp.noRows; i++)
	{
		for (int j = 1; j <= tmp.noCols; j++)
		{
			//temp << setw (width) << i << "," << j << "       ";
			temp << setw (width) << GetFromMPosition(i, j, tmp);
		}
		temp << endl;
	}

	return temp.str();
}

string outputString(Matrix tmp)
{
	stringstream output;
	for (int i = 0; i < tmp.theData.size(); i++)
	{
		output << fixed << setprecision(0) << tmp.theData[i] << " ";
	}

	return output.str();
}

Matrix createEncryptionMatrix(int a, int b, int c)
{
	//this is our unity determinant simple matrix with three user inputted numbers
	double data[9] = {1,0,0,a,1,0,b,c,1};
	
	//scrambler: We complicate our matrix, to make a force decryption harder
	// 1: Move row 1 onto row 2 (a*b) times
	data[1] += (data[0] * (a));
	data[4] += (data[3] * (a));
	data[7] += (data[6] * (a));

	// 2: Move row 2 onto row 3 (a*c) times
	data[2] += (data[1] * (c));
	data[5] += (data[4] * (c));
	data[8] += (data[7] * (c));

	// 2: Move row 3 onto row 1 (b*c) times
	data[0] += (data[2] * (b));
	data[3] += (data[5] * (b));
	data[6] += (data[8] * (b));
				
	return Create3x3(data);
}

Matrix CreateMInverse(Matrix tmp)
{
	Matrix inverse;

	double cofacdata[9] = {		( (GetFromMPosition(2, 2, tmp) * GetFromMPosition(3, 3, tmp)) - (GetFromMPosition(2, 3, tmp) * GetFromMPosition(3, 2, tmp)) ),
							-	( (GetFromMPosition(1, 2, tmp) * GetFromMPosition(3, 3, tmp)) - (GetFromMPosition(3, 2, tmp) * GetFromMPosition(1, 3, tmp)) ),
								( (GetFromMPosition(1, 2, tmp) * GetFromMPosition(2, 3, tmp)) - (GetFromMPosition(2, 2, tmp) * GetFromMPosition(1, 3, tmp)) ),

							-	( (GetFromMPosition(2, 1, tmp) * GetFromMPosition(3, 3, tmp)) - (GetFromMPosition(3, 1, tmp) * GetFromMPosition(2, 3, tmp)) ),
								( (GetFromMPosition(1, 1, tmp) * GetFromMPosition(3, 3, tmp)) - (GetFromMPosition(3, 1, tmp) * GetFromMPosition(1, 3, tmp)) ),
							-	( (GetFromMPosition(1, 1, tmp) * GetFromMPosition(2, 3, tmp)) - (GetFromMPosition(2, 1, tmp) * GetFromMPosition(1, 3, tmp)) ),

								( (GetFromMPosition(2, 1, tmp) * GetFromMPosition(3, 2, tmp)) - (GetFromMPosition(2, 2, tmp) * GetFromMPosition(3, 1, tmp)) ),
							-	( (GetFromMPosition(1, 1, tmp) * GetFromMPosition(3, 2, tmp)) - (GetFromMPosition(3, 1, tmp) * GetFromMPosition(1, 2, tmp)) ),
								( (GetFromMPosition(1, 1, tmp) * GetFromMPosition(2, 2, tmp)) - (GetFromMPosition(2, 1, tmp) * GetFromMPosition(1, 2, tmp)) )
	
	};

	double inversedata[9] = {	(cofacdata[0]) ? cofacdata[0] : 0,
								(cofacdata[3]) ? cofacdata[3] : 0,
								(cofacdata[6]) ? cofacdata[6] : 0,
								(cofacdata[1]) ? cofacdata[1] : 0,
								(cofacdata[4]) ? cofacdata[4] : 0,
								(cofacdata[7]) ? cofacdata[7] : 0,
								(cofacdata[2]) ? cofacdata[2] : 0,
								(cofacdata[5]) ? cofacdata[5] : 0,
								(cofacdata[8]) ? cofacdata[8] : 0
	};

	return Create3x3(inversedata);

}

double Add(double a, double b)
{
    return a + b;
}

double Multiply(double a, double b)
{
	return a*b;
}