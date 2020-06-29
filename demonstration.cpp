#include <iostream>
#include<Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
	// define 3x3 matrix of floats and set its entries to zero -explicit declaration
	Matrix <float, 3, 3> matrixA;
	matrixA.setZero();
	cout << matrixA <<endl;

	//define 3x3 matrix of floats and set its entries to zero -typedef declaration
	Matrix3f matrixA1;
	matrixA1.setZero();
	cout <<"\n"<<matrixA1<<endl;

	// define a dynamic matrix, explicit declaration
	Matrix <float, Dynamic, Dynamic> matrixB; 

	//define a dynamic matrix, typedef declaration
	MatrixXf matrixB1;

	//constructor, allocate memory, but do not initialize
	MatrixXd matrixC(10, 10);

	// assigning matrix entries 
	MatrixXd matrixC1(2, 2);
	matrixC1(0, 0) = 1 ;
	matrixC1(0, 1) = 2;
	matrixC1(1, 0) = 3;
	matrixC1(1, 1) = 4;
	cout << endl<<matrixC1 << endl;

	// fill-in the matrix entries using comma separated values and print the matrix
	Matrix4f matrixD;
	matrixD << 1,   2,  3,  4,
 	    	5,   6,  7,  8,
		    9,  10, 11, 12,
		    13, 14, 15, 16;
	cout << endl<<  matrixD << endl;

	// define a dynamic matrix, resize it to a 3x3 matrix, 
	// and set its entries to zero, and print the matrix
	Matrix3f matrixD1;
	matrixD1.resize(3, 3);
	matrixD1.setZero(3, 3);
	cout <<endl<< matrixD1;

	// setting matrix entries - two approaches
	int rowNumber = 5;
	int columnNumber= 5;

	// matrix of zeros
	MatrixXf matrix1zeros;
	matrix1zeros = MatrixXf::Zero(rowNumber, columnNumber);
	cout << "\n \n"<< matrix1zeros<<endl;
	// another option:
	MatrixXf matrix1zeros1;
	matrix1zeros1.setZero(rowNumber, columnNumber);
	cout << "\n \n" << matrix1zeros1 << endl;

	//matrix of ones
	MatrixXf matrix1ones;
	matrix1ones = MatrixXf::Ones(rowNumber, columnNumber);
	cout << "\n \n" << matrix1ones << endl;
	//another option
	MatrixXf matrix1ones1;
	matrix1ones1.setOnes(rowNumber, columnNumber);
	cout << "\n \n" << matrix1ones1 << endl;

	//matrix of constants
	float value = 1.1;
	MatrixXf matrix1const;
	matrix1const = MatrixXf::Constant(rowNumber, columnNumber,value);
	cout << "\n \n" << matrix1const << endl;
	//another option
	MatrixXf matrix1const1;
	matrix1const1.setConstant(rowNumber, columnNumber, value);
	cout << "\n \n" << matrix1const1 << endl;

	

	//identity matrix, two approaches

	rowNumber = 10;
	columnNumber = 10;
	
	MatrixXd matrixIdentity;
	matrixIdentity = MatrixXd::Identity(rowNumber,columnNumber);
	cout << "\n \n" << matrixIdentity << endl;
	
	MatrixXd matrixIdentity1;
	matrixIdentity1.setIdentity(rowNumber, columnNumber);
	cout << "\n \n" << matrixIdentity1 << endl;


	//accessing matrix blocks
	MatrixXd matrixV(4,4);
	matrixV << 101, 102, 103, 104,
		105, 106, 107, 108,
		109, 110, 111, 112,
		113, 114, 115, 116;
	//access the matrix composed of 1:2 rows and 1:2 columns of matrixV
	MatrixXd matrixVpartition = matrixV.block(0, 0, 2, 2);
	cout << "\n \n" << matrixVpartition << endl;
	
	MatrixXd matrixVpartition2 = matrixV.block(1,1, 2, 2);
	cout << "\n \n" << matrixVpartition2 << endl;


	//accessing columns and rows of a matrix

	cout<<"\n\n"<<"Row 1 of matrixV is \n "<<matrixV.row(0);
	cout << "\n\n" << "Column 1 of matrixV is \n" << matrixV.col(0);

	//create a diagonal matrix out of a vector
	Matrix <double, 3, 1> vector1;
	vector1 << 1, 2, 3;
	MatrixXd diagonalMatrix;
	diagonalMatrix = vector1.asDiagonal();
	cout << " Diagonal matrix is \n\n" << diagonalMatrix;

	// basic matrix operations
	//matrix addition
	MatrixXd A1(2, 2);
	MatrixXd B1(2, 2);

	A1 << 1, 2,
		3, 4;
	B1 << 3, 4,
		5, 6;
	MatrixXd C1 = A1 + B1;
	cout << " \n\n The sum of A1 and B1 is\n\n" << C1 << endl;
	// similarly you can subtract A1 and B1

	//matrix multiplication
	MatrixXd D1 = A1*B1;
	cout << " \n\n The matrix product of A1 and B1 is\n\n" << D1 << endl;

	//multiplication by a scalar
	int s1 = 2;
	MatrixXd F1;
	F1 = s1 * A1;
	cout << " \n\n The matrix product of the scalar 2 and the matrix A1 is\n\n" << F1 << endl;

	//matrix transpose
	MatrixXd At;
	MatrixXd R1;
	// we can obain a transpose of A1 as follows
	At = A1.transpose();
	cout << "\n\n Original matrix A1\n\n" << A1;
	cout << "\n\n Its transpose\n\n " << At;

	// we can use a transpose operator in expressions
	R1 = A1.transpose() + B1;
	cout << "\n\n Matrix R1=A1^{T}+B1 is\n\n" << R1;

	// here we should be careful, the operation .transpose() might lead to unexpected results in this scenarios
    //	A1 = A1.transpose();
	// cout << " \n\n This should be a transpose of the matrix A1\n\n" << A1 << endl;

	// the correct and safe way to do the matrix transpose is the following
	 A1.transposeInPlace();
	cout << " \n\n This should be a transpose of the matrix A1\n\n" << A1 << endl;
	//restore A1 matrix to its original state
	A1.transposeInPlace();
	// matrix inverse
	MatrixXd G1;
	G1 = A1.inverse();
	cout << "\n\n The inverse of the matrix A1 is\n\n" << G1;
	cout << "\n\n Double check A1^{-1}*A1=\n\n" << G1*A1;
	   	  
}


