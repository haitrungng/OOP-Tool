#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

string get(string name)
{
    ostringstream ss;
    ss << "get " << name << "(){ return this._" << name << "}\n";
    return ss.str();
}
string set(string name)
{
    ostringstream ss;
    ss << "set " << name << "(TEMPORARY){\n";
    ss << "if(TEMPORARY > 0)    this._" << name << " = TEMPORARY\n"
       << "else console.error("
       << "`" << name << " must be a positive number`)}\n";
    return ss.str();
}

int main()
{
    cout << "THIS FILE IS USED FOR Java Script!!!\n";
    cout << "Running\n";
    ifstream read("INPUT");
    ofstream write;
    write.open("OUTPUT");
    if (!write.is_open())
    {
        cout << "CANT OPEN FILE TO WRITE\n";
    }
    while (read.ignore(256, ' '))
    {
        string name;
        read.ignore(256, ' ');

        read >> name;
        // cout << name << '\n';

        ostringstream ss;
        ss << get(name);
        ss << set(name);
        write << ss.str();
    }
    write.close();
    cout << "done";
}