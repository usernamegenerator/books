// 5.2 Given a (decimal - e.g. 3.72) number that is passed in as a string,
// print the binary representation. If the number can not be represented accurately in binary, print “ERROR”
#include <iostream>
#include <string>
using namespace std;

void printBinary(const char *s)
{
    double num = stod(s);
    cout << num << endl;

    int integer = stoi(s);
    cout << integer << endl;

    double fract = num - integer;
    cout << fract << endl;

    // convert the integer part
    int integerArray[32] = {0};
    int integerTemp = integer;
    int i = 0;
    while (integerTemp)
    {
        integerArray[i++] = integerTemp % 2;
        integerTemp = integerTemp / 2;
    }
    for (int j = 31; j >= 0; j--)
    {
        cout << integerArray[j];
    }
    cout << ".";
    // cout << endl;

    // convert the fraction part
    double fractTemp = fract;
    int fractArray[32] = {0};
    i = 0;
    while (fractTemp)
    {
        double res = fractTemp * 2;
        int integerPart = fractTemp * 2;
        fractArray[i++] = integerPart;
        fractTemp = res - integerPart;
        //cout << res << " " << integerPart << " " << fractTemp << endl;
    }
    
    for (int j = 0; j <32; j++)
    {
        cout << fractArray[j];
    }
    
}

int main()
{
    // const char *s = "3.72"; //11.10111000010
    const char* s = "4.53"; // 100.10000111101
    printBinary(s);
}