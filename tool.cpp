
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

class SingleLineC
{
protected:
    string type;
    string name;

public:
    SingleLineC(string str1, string str2 = "EMPTY ") : type{str1}, name{str2} {}
    string get()
    {
        ostringstream ss;
        ss << type << " get";
        string temp = name;
        if (name[0] >= 'a' && name[0] <= 'z')
        {
            temp[0] -= 32;
        }
        temp.pop_back();
        ss << temp << "(){return " << name << " }\n";
        return ss.str();
    }
    string set()
    {
        ostringstream ss;
        ss << "void set";
        string temp = name;
        if (name[0] >= 'a' && name[0] <= 'z')
        {
            temp[0] -= 32;
        }
        temp.pop_back();
        ss << temp << "(" << type << " TEMPORARY){ ";
        temp = name;
        temp.pop_back();
        ss << temp << "= TEMPORARY;}\n";
        return ss.str();
    }

    string lastOutput()
    {
        ostringstream ss;
        ss << get();
        ss << set();
        return ss.str();
    }
};

class SingleLineJAVA : public SingleLineC
{
private:
    string access;

public:
    SingleLineJAVA(string str1, string str2 = "EMPTY ", string str3 = "EMPTY ") : SingleLineC(str2, str3), access{str1} {}
    string set()
    {
        ostringstream ss;
        ss << "public void set";
        string temp = name;
        if (name[0] >= 'a' && name[0] <= 'z')
        {
            temp[0] -= 32;
        }
        temp.pop_back();
        ss << temp << "(" << type << " TEMPORARY){ ";
        temp = name;
        temp.pop_back();
        ss << temp << "= TEMPORARY;}\n";
        return ss.str();
    }
    string get()
    {
        ostringstream ss;
        ss << "public " << type << " get";
        string temp = name;
        if (name[0] >= 'a' && name[0] <= 'z')
        {
            temp[0] -= 32;
        }
        temp.pop_back();
        ss << temp << "(){return " << name << " }\n";
        return ss.str();
    }
    string lastOutput()
    {
        ostringstream ss;
        ss << get();
        ss << set();
        return ss.str();
    }
};

int main()
{
    bool usingC = 0;
    cout << "Type 1 to create C++\t||\tType 2 to create Java\n";
    int num;
    cin >> num;
    if (num != 1 && num != 2)
        throw invalid_argument("MUST BE 1 or 2\n");

    string access;
    string type;
    string name;
    ifstream read("INPUT");

    ofstream write;

    write.open("OUTPUT");
    if (!write.is_open())
    {
        cout << "CANT OPEN FILE TO WRITE\n";
    }
    if (num == 1)
    {
        while (read >> type && read >> name)
        {
            if (name == ";")
                throw invalid_argument("MISSING NAME IN INPUT FILE\n");
            SingleLineC *ob = new SingleLineC(type, name);
            write << ob->lastOutput();
        }
    }
    else
    {
        while (read >> access && read >> type && read >> name)
        {
            if (name == ";")
                throw invalid_argument("MISSING NAME IN INPUT FILE\n");
            SingleLineJAVA *ob = new SingleLineJAVA(access, type, name);
            write << ob->lastOutput();
        }
    }
    write.close();
    cout << "DONE!\n";
    cout << "Check result at OUTPUT\n";
}