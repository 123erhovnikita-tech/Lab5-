#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printToScreen (const vector <string> &lines)
{
    if (lines.empty ())
    {
        wcout << L"Âåêòîð ïóñò. Íå÷åãî âûâîäèòü." << endl;
        return;
    }
    wcout << L"Âûâîä ñòðîê íà ýêðàí" << endl;
    for (size_t i = 0; i < lines.size (); i++)
    {
        cout << "[" << i + 1 << "] " << lines [i] << endl;
    }
    wcout << endl;
}

void writeToFile(const vector <string> &lines, const string &filename = "output.txt")
{
    ofstream outputFile(filename);
    if (!outputFile.is_open())
    {
        wcout << L"Îøèáêà: íå óäàëîñü ñîçäàòü ôàéë " << filename << endl;
        return;
    }
    for (const auto &line : lines)
    {
        outputFile << line << endl;
    }
    outputFile.close ();
    wcout << L"Çàïèñàíî " << lines.size () << L" ñòðîê â ôàéë " << filename << endl;
}

int main()
{
    setlocale (LC_ALL "RU")
    vector <string> lines;
    readFromFile (lines);
    printToScreen (lines);
    writeToFile (lines);
    return 0;
}