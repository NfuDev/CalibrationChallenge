// CalibrationChallenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "String"
#include <cctype>
#include "vector"

using namespace std;


static string num_String[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };

int lineCallibration(string& line)
{
    string calebration;
    int numberOfDigits = 0;
    string AssumedlasDigit;

    bool bFoundFirst = false;
    string DigitString;

    auto GetNumberCharacter = [&](string& NumberString)
        { string _calebration;
         int _itr = 0;
            for (string& str : num_String)
            {
                size_t position = line.find(str);

                if (position != string::npos)
                {
                    _calebration += ('0' + _itr);
                }
                _itr++;
            }
            return _calebration;
        };

    auto IsValidNumberString = [&](string& NumberString)
        {
            for (string& str : num_String)
            {
                size_t position = line.find(str);

                if (position != string::npos)
                {
                    return true;
                }
                return false;
            }
        };

    int itr = 0;

    for (char& c : line)
    {
        if (isdigit(c))
        {
            DigitString.erase(DigitString.length());
          
            if (!bFoundFirst)
            {
                calebration += c;
                numberOfDigits++;
                bFoundFirst = true;
            }
            else
            {
                AssumedlasDigit = c;
                numberOfDigits = 2;
            }
        }

        else
        {
            DigitString += c;
       
            if (IsValidNumberString(DigitString))
            {
                if (!bFoundFirst)
                {
                    bFoundFirst = true;
                    calebration += GetNumberCharacter(DigitString);
                    numberOfDigits++;
                    DigitString.erase(DigitString.length());
                }
                else
                {
                    AssumedlasDigit = GetNumberCharacter(DigitString);
                    numberOfDigits = 2;
                }
            }
        }

        itr++;
    }

    calebration += AssumedlasDigit;

    if (!calebration.empty())
    {
        if (numberOfDigits == 1)
        {
            calebration += calebration;
        }

        return stoi(calebration);
    }
       
    else
        return -1;
}

int main()
{

    string filename = "C:\\Users\\Acer\\Documents\\Inputs.txt";
    vector<string> lines;
    int sum = 0;

    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line))
        {
            int lineCaleb = lineCallibration(line);
            sum += lineCaleb;
            cout << "found line : [ " << line << " ] with callibration of : " << lineCaleb << endl;
            lines.push_back(line);
        }
        file.close();
    }

    cout << " sum of all calibrations : " << sum << endl;

    return 0;
}