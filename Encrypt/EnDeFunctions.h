// -------------------------------------------
// EnDeFunctions.h


// Provide the storage class specifier (extern for an .exe file, null
// for DLL) and the __declspec specifier (dllimport for .an .exe file,
// dllexport for DLL).
// You must define EXP_STL when compiling the DLL.
// You can now use this header file in both the .exe file and DLL - a
// much safer means of using common declarations than two different
// header files.

#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

typedef struct 
{
     int noRows;
     int noCols;
     vector<double> theData; 
} Matrix;

#ifdef EXP_STL
#    define DECLSPECIFIER __declspec(dllexport)
#    define EXPIMP_TEMPLATE
#else
#    define DECLSPECIFIER __declspec(dllimport)
#    define EXPIMP_TEMPLATE extern
__declspec(dllexport) Matrix Create3x3(double input[9]);
__declspec(dllexport) double GetFromMPosition(int row, int col, Matrix tmp);
__declspec(dllexport) Matrix CreateMInverse(Matrix tmp);
__declspec(dllexport) string outputMatrix(Matrix tmp);
__declspec(dllexport) string outputMatrix(Matrix tmp, int width);
__declspec(dllexport) string outputString(Matrix tmp);
__declspec(dllexport) Matrix Create3xX(vector<double> input);
__declspec(dllexport) Matrix multiplyMatrix(Matrix a, Matrix b);
__declspec(dllexport) Matrix createEncryptionMatrix(int a, int b, int c);
#endif


/*
#ifdef__cplusplus
extern "C" {
#endif
    __declspec(dllexport) double Add(double a, double b);
	#define DLLExport   __declspec( dllexport )
#ifdef__cplusplus
}
#endif*/