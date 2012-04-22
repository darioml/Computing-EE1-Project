#include "EnDeFunctions.h"
#include <Windows.h>
#include <LMCons.h>
#include "engine.h"

HANDLE  hConsole;														//hConsole is used to change the colour of the console text
void compareMatrixMATLAB(Matrix a, Matrix b, string title);
void checkUnityMATLAB(Matrix input);

//To clean up main, and reduce repitition, common functions are stored in the CConsoleClass. I have decided to use a class to organize the functions together.
//This is a static class, meaning you don't need to initialise it to use it!
class CConsoleClass
{
public:
	static void startFuncHelp();
	static void startEncrypt(string encryptText);
	static void startDecrypt(string encryptText);
	static void saveFile(string input);
};

bool useMatlab;			//Are we going ot use Matlab to validate our data?


int main()
{
	useMatlab = false;									//default, do not use MATLAB!
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);			//initliase our hConsole, so we can start playing with the colours!

	TCHAR name [ UNLEN + 1 ];			//Get windows login name (Source: Microsoft documentation)
	DWORD size = UNLEN + 1;
	GetUserName( (TCHAR*)name, &size );
	
	string input;						//used for a lot of using input from console.

	cout << "\nThank you for using Dario's encrypt/decrypt tool.\nThis tool is provided as is.\nShould you require help in using the commands, please type \"help\"\nin the console window.\n\n";

	while (true)
	{
		SetConsoleTextAttribute(hConsole, 10);	//change colour to yellow
		if (useMatlab)							//show the user if he's using matlab or not
		{
			cout << "MATLABY ";
		}
		else
		{
			cout << "MATLABN ";
		}
		wcout << name << L"> ";
		SetConsoleTextAttribute(hConsole, 7);	//Ok, input's over, back to grey!!

		getline(cin, input);					//check what the "bash" input was, and act accordingly.




		//input:		quit || exit
		//function:		A nice exit to the bash scheme, rather than Xing the screen! 
		if (input == "quit" || input == "exit" || input == "die")
		{
			wcout << "\n\nPress any key to quit... ";
			cin.get();
			break;
		}



		//input:		help
		//function:		Displays the functions you can call from the console window.
		else if (input == "help")
		{
			CConsoleClass::startFuncHelp();
		}




		//input:		matlab on
		//function:		enables use of MATLAB to check decryption key
		else if (input == "matlab on")
		{
			useMatlab = true;
		}




		//input:		matlab off
		//function:		disables the use of MATLAB to check decryption key (it's pretty good already!)
		else if (input == "matlab off")
		{
			useMatlab = false;
		}





		//input:		encrypt text || et
		//function:		USER input it encrypted, and optionally saved
		else if (input == "encrypt text" || input == "et")
		{
			string encryptText = "";
			wcout << "Please input the text you want to encrypt. To stop inputting, type \"END;\":" << endl;
			
			SetConsoleTextAttribute(hConsole, 14);
			while (true)
			{
				getline(cin, input);
				if (input == "END;")
				{
					break;
				}
				encryptText += input + "\n";
			}
			SetConsoleTextAttribute(hConsole, 7);

			if (encryptText.length() > 1)
			{
				CConsoleClass::startEncrypt(encryptText);
				cout << endl;
			}


		}




		//input:		encrypt file || ef
		//function:		FILE input it encrypted, and optionally saved
		else if (input == "encrypt file" || input == "ef")
		{
			string encryptText;

			do
			{
				cout << "Please specify the file you want to encrypt: ";
				SetConsoleTextAttribute(hConsole, 14);
				getline(cin, input);
				SetConsoleTextAttribute(hConsole, 7);
				
				//check that the file exists:
				ifstream Ifile (input);
				if (Ifile.is_open())
				{
					while (Ifile.eof() != true)
					{
						getline(Ifile, input);
						encryptText += input + "\n";
					}
					break;
				}
				SetConsoleTextAttribute(hConsole, 7);

				cout << "Invalid file - ";
			} while(true);


			if (encryptText.length() > 1)
			{
				CConsoleClass::startEncrypt(encryptText);
				cout << endl;
			}
		}





		//input:		decrypt text || dt
		//function:		USER input is decrypted according to the given password
		//MATLAB:		Used to check investion
		else if (input == "decrypt text" || input == "dt")
		{
			string encryptText = "";
			wcout << "Please input the code you want to decrypt. To stop inputting, type \"END;\"\nPlease note that only numbers are valid input!:" << endl;
			
			SetConsoleTextAttribute(hConsole, 14);
			while (true)
			{
				getline(cin, input);
				if (input == "END;")
				{
					break;
				}
				encryptText += input + "\n";
			}
			SetConsoleTextAttribute(hConsole, 7);

			if (encryptText.length() > 1)
			{
				CConsoleClass::startDecrypt(encryptText);
				cout << endl;
			}

		}





		//input:		decrypt file || df
		//function:		FILE input is decrypted according to the given password
		//MATLAB:		Used to check investion
		else if (input == "decrypt file" || input == "df")
		{
			string encryptText;

			do
			{
				cout << "Please specify the file you want to decrypt: ";
				SetConsoleTextAttribute(hConsole, 14);
				getline(cin, input);
				
				//check that the file exists:
				ifstream Ifile (input);
				SetConsoleTextAttribute(hConsole, 7);
				if (Ifile.is_open())
				{
					while (Ifile.eof() != true)
					{
						getline(Ifile, input);
						encryptText += input + "\n";
					}
					break;
				}

				cout << "Invalid file - ";
			} while(true);

			if (encryptText.length() > 1)
			{
				CConsoleClass::startDecrypt(encryptText);

				cout << endl;
			}

		}

		else
		{
			cout << "Command not found. Try typing \"help\"." << endl;
		}

	}

    return 0;
}


/*

#############################################
#######  CLASS FUNCTION DEFINITIONS!  #######
#############################################

These functions belong to the CConsoleClass, which is the driver behind this Console Application

*/



// Description:			Shows a list of what you can do, and what the commands for them are. No real
//						detail is explained, since it's pretty self explanitory.
//
void CConsoleClass::startFuncHelp()
{
	cout << endl << endl << "Dario's Encrypt / Decrypt Bash shell-like help:" << endl << endl;
	cout << "Useable functions:\n ->Text encryption (\"encrypt text\" or \"et\")\n ->File encryption (\"encrypt file\" or \"ef\")\n ->Text decryption (\"decrypt text\" or \"dt\")\n ->File decryption (\"decrypt file\" or \"df\")";
	cout << endl << " ->Help - this here (\"help\")\n ->Exiting the Program (\"quit\" or \"exit\" or \"die\")\n ->Enable matlab (\"matlab on\")\n ->Disable matlab (\"matlab off\")" << endl << endl;
}



// Description:			Does the encryption, outputs it, and asks to save it. Works on the
//						string encryptText input, which is given by main (either file or input)
//
void CConsoleClass::startEncrypt(string encryptText)
{
	string input;
	int a,b,c;
	while (true)
	{
		cout << "Please provide three random password integers: " << endl;
		
		SetConsoleTextAttribute(hConsole, 14);
		getline(cin, input);
		stringstream reader(input);
		SetConsoleTextAttribute(hConsole, 7);
				
		if (reader >> a >> b >> c)
		{
			break;
		}
		cout << "Invalid input - ";
		SetConsoleTextAttribute(hConsole, 7);
	}
	cout << "Encrypting...";
	vector<double> inputData;
	for(int i = 0; i < (encryptText.length() - 1); i++)
	{
		inputData.push_back((int)encryptText[i]);
	}
	Matrix dataMatrix = Create3xX(inputData);
			
	Matrix encryMatrix = createEncryptionMatrix(a, b, c);
			
	Matrix multiply = multiplyMatrix(encryMatrix, dataMatrix);
	
	cout << endl << endl <<"Encryption successful!\n\n   Your encryption matrix was:" << endl << endl << outputMatrix(encryMatrix) << "\n   ";
	if (multiply.theData.size() < 50)
	{
		cout << "Your encryption is:\n\n" << outputString(multiply);
	}
	else
	{
		cout << "Your encryption is too long to show.";
	}
	cout << endl << endl;
	
	do
	{
		cout << "Do you wish to save this to a file? (Y/N): ";
		getline(cin, input);
	}
	while (input != "y" && input != "Y" && input != "n" && input != "N");
	
	if (input == "Y" || input == "y")
	{
		CConsoleClass::saveFile(outputString(multiply));
	}
}



// Description:			Does the decryption, outputs it, and asks to save it. Works on the
//						string encryptText input, which is given by main (either file or input)
//
void CConsoleClass::startDecrypt(string encryptText)
{
	string input;
	stringstream test (encryptText);
	double inputNum;
	vector<double> decrypt;
	while (test >> input) //if there is some text to read...
	{
		stringstream two (input);
		if (two >> inputNum) //and if it is a number...
		{
			decrypt.push_back(inputNum);
		}
	}

	//Now we have our input, let's get the password...
	int a,b,c;
	while (true)
	{
		cout << "Please provide the three password integers: " << endl;
		
		SetConsoleTextAttribute(hConsole, 14);
		getline(cin, input);
		stringstream reader(input);
		SetConsoleTextAttribute(hConsole, 7);
		
		if (reader >> a >> b >> c)
		{
			break;
		}
		cout << "Invalid input - ";
		SetConsoleTextAttribute(hConsole, 7);
	}
	cout << "Decrypting...";
	Matrix dataMatrix = Create3xX(decrypt);
	Matrix encryMatrix = createEncryptionMatrix(a, b, c);
	Matrix decryMatrix = CreateMInverse(encryMatrix);

	if (useMatlab)
	{
		Matrix unity = multiplyMatrix(encryMatrix, decryMatrix);
		cout << endl << "Using MATLAB to verify decryption matrix was generated successfully. You should see a perfect sin wave. If not, there was an error in the decryption (Are you sure your passwords are correct?)" << endl;

		checkUnityMATLAB(unity);
	}

	Matrix multiply = multiplyMatrix(decryMatrix, dataMatrix);

	//now, foreach value in theData...
	string output;
	for (int i = 0; i < multiply.theData.size(); i++)
	{
		output += (char)multiply.theData[i];
	}
	
	//cout << endl << endl <<"Encryption successful!\n\n   Your encryption matrix was:" << endl << endl << outputMatrix(encryMatrix) << "\n   Your encryption is:\n\n" << outputString(multiply) << endl << endl;

	cout << endl << endl <<"Decryption with given passwords successful!\n\n   Encryption Matrix was:" << endl << endl;
	cout << outputMatrix(encryMatrix) << "\n   Decryption Matrix was: "<< endl << endl << outputMatrix(decryMatrix) << "\n   Decrypted text is:\n\n" << output << endl << endl;
	do
	{
		cout << "Do you wish to save this to a file? (Y/N): ";
		getline(cin, input);
	}
	while (input != "y" && input != "Y" && input != "n" && input != "N");
	
	if (input == "Y" || input == "y")
	{
		CConsoleClass::saveFile(output);
	}
}


// Description:			Saves a file, defaulting to default.txt, from the saveInput string given
//
void CConsoleClass::saveFile(string saveInput)
{
	string input;
	cout << "Please enter a filename (or leave blank for default.txt): ";
	getline(cin, input);
	if (input == "") {input = "default.txt";}
	
	ofstream fOutput (input);
	if (fOutput.is_open())
	{
		fOutput << saveInput;
		fOutput.close();
			cout << "Saved to " << input;
	}
	else
	{
		cout << "Error saving file - make sure it is accessible! ";
	}
}


/*

#############################################
#######  OTHER FUNCTION DEFINITIONS!  #######
#############################################

These functions are not part of the CConsoleClass, but are needed at occasion (e.g. MATLAB)

*/


//Description:
//					Takes two 3*3 matrixes, and splits each one up into 3 linear equaions, and plots them.
//					Also takes "title", which is the title of the figure produced.
void compareMatrixMATLAB(Matrix a, Matrix b, string title)
{
	//b = CreateMInverse(b);
	if (a.noCols != 3 || a.noRows != 3 || b.noCols != 3 || b.noRows != 3)
	{
		cout << "MATLAB CHECK: Can only operate on 3x3 matrix!" << endl;
		return;
	}

	Engine *ep;
	mxArray *I = NULL;
	cout << "Starting MATLAB... May take up to 2 minutes... " << endl;
	

	if (!(ep = engOpen("\0")))
	{
		cout << "Can't start MATLAB engine" << endl;
	}
	else
	{
		stringstream titlestream;
		titlestream << "title(' " + title + "');";

		engEvalString(ep, titlestream.str().c_str());
		//engEvalString(ep, "xlabel('Current(amps)')");
		//engEvalString(ep, "ylabel('Velocity(volts)');");

		engEvalString(ep, "x = 0:10;");

		
		//Default them to empty
		engEvalString(ep, "y0 = 0;");
		engEvalString(ep, "y1 = 0;");
		engEvalString(ep, "y2 = 0;");


		//First draw matrix a
		for (int i = 0; i < 3; i++)
		{
			if (a.theData[i] != 0)
			{
				stringstream formatter;
				formatter << "y" << i << " = (1 / " << a.theData[i] << ") * ((" << a.theData[i + 3] << "*x) + " << a.theData[i + 6] << ")";
				engEvalString(ep, formatter.str().c_str());
			}
		}
		engEvalString(ep, "hold all");
		

		engEvalString(ep, "plot(x,y0)");
		engEvalString(ep, "plot(x,y1)");
		engEvalString(ep, "plot(x,y2)");

		
		//First draw matrix b
		engEvalString(ep, "z0 = 0;");				//Default them to empty
		engEvalString(ep, "z1 = 0;");
		engEvalString(ep, "z2 = 0;");

		for (int i = 0; i < 3; i++)  //create matlab commands to populate the values
		{
			if (b.theData[i] != 0)
			{
				stringstream formatter;
				formatter << "z" << i << " = (1 / " << b.theData[i] << ") * ((" << b.theData[i + 3] << "*x) + " << b.theData[i + 6] << ")";
				engEvalString(ep, formatter.str().c_str());
			}
		}
		engEvalString(ep, "hold all");    //plot!
		engEvalString(ep, "plot(x,z0)");
		engEvalString(ep, "plot(x,z1)");
		engEvalString(ep, "plot(x,z2)");


		string s;
		cout << "Hit return to continue..." << endl;
		getline(cin, s);                                // pause long enough to be able to see the plot
		mxDestroyArray(I);                              // return memory
		engEvalString(ep, "close;");               // close MATLAB figure.
	}
}



// Description:			
//				Ouputs a sin wave if is unit, otherwise draws unity alongside the input using
//				compareMatrixMATLAB()
//
void checkUnityMATLAB(Matrix input)
{
	double data[] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	Matrix unity = Create3x3(data);

	if (unity.theData == input.theData)
	{
		Engine *ep;
		mxArray *I = NULL;
		cout << "Starting MATLAB... May take up to 2 minutes... " << endl;
	

		if (!(ep = engOpen("\0")))
		{
			cout << "Can't start MATLAB engine" << endl;
		}
		else
		{
			engEvalString(ep, "title('Unity Vector Test');");
			engEvalString(ep, "xlabel('The application successfully created the decrypt matrix!')");
			//engEvalString(ep, "ylabel('Velocity(volts)');");

			engEvalString(ep, "x = 0:0.1:10;");
			engEvalString(ep, "y = sin(x);");

			engEvalString(ep, "hold all");
			engEvalString(ep, "plot(x,y)");

			string s;
			cout << "Hit return to continue..." << endl;
			getline(cin, s);                                // pause long enough to be able to see the plot
			mxDestroyArray(I);                              // return memory
			engEvalString(ep, "close;");               // close MATLAB figure.
		}
	}
	else
	{
		compareMatrixMATLAB(unity, input, "Unity Vector Test - FAILED");
	}
	
}