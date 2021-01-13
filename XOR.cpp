#include <iostream> // cout
#include <fstream> // ofstream


using namespace std;
int XOR1(int a, int b); // Funkcijos
int XOR2(int a, int b);
int XOR3(int a, int b);
int XOR4(int a, int b);
long long convert(int n)
{
    long long binaryNumber = 0;
    int remainder, i = 1;

    while (n!=0)
    {
        remainder = n%2; // Renkama liekana
        n /= 2; // skaicius dalinamas is 2
        binaryNumber += remainder*i; // sumuojama rezultatas padaugintas is I , kuris dideja *10
        i *= 10;
    }
    return binaryNumber;
}
int main(int kiek, char* arg[]) // Duomenys paduodami kaip char , nes int nenusiskaito.
{
    ofstream out("rezultatas.csv"); // Isvedimas
    if (kiek==3) // 3 , nes pirmas skaicius buna lygus kiek argumentu yra+1
    {
        int a = atoi(arg[1]); // String pavertimas i integer
        int b = atoi(arg[2]);
        out << "Vardas:, Eimantas" << endl;
        out << "Pavarde:, Kucinskas" << endl;
        out << "Grupe:, ISF19/1" << endl;
        out << "Duom: ,A= " << a << " ,B= " << b << endl;
        out << "XOR(1),NOT AND OR," << XOR1(a, b) << endl;
        out << "XOR(2),NAND," << XOR2(a, b) << endl;
        out << "XOR(3),OR AND NOT," << XOR3(a, b) << endl;
        out << "XOR(4),NOT OR AND," << XOR4(a, b) << endl;
        cout << "Atlikta sekmingai , tikrinkite faila!" << endl;
        system("PAUSE");
        out.close();
        return 0;

    }
    else
    {
        cout << "Turi buti du argumentai!" << endl;
    }
    system("PAUSE");
    return 0;
}

int XOR1(int a, int b) // NOT AND OR
{
    return (~a & b) | (a & ~b);
}
int XOR2(int a, int b) // NAND
{
    return ~(~(a & ~(a & b)) & ~(~(a & b) & b));
}
int XOR3(int a, int b) // OR AND NOT
{
    return ~(a & b) & (a | b);
}
int XOR4(int a, int b) // NOT OR AND
{
    return (a | b) & (~a | ~b);
}


// https://en.wikipedia.org/wiki/XOR_gate

