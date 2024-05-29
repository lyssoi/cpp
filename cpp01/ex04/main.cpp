#include <iostream>
#include <fstream>
#include <string>

void print_err(std::string msg)
{
    std::cout << msg << std::endl;
    exit(1);
}

void init_s1s2(std::string &s1, std::string &s2, char *argv[])
{
    s1 = argv[2];
    s2 = argv[3];

    if (s1.empty() || s2.empty())
        print_err("The string is empty.");
}

void init_ifstream(std::ifstream &ifs, char *filename)
{
    ifs.open(filename);
    if (ifs.fail())
        print_err("Cannot open file.");
}

void init_ofstream(std::ofstream &ofs, char *filename)
{
    std::string ofilename = filename;
    ofilename.append(".replace");
    ofs.open(ofilename);
    if (ofs.fail())
        print_err("Cannot open file.");
}

void replace_s1_to_s2(std::ifstream &ifs, std::ofstream &ofs, std::string &s1, std::string &s2)
{
    std::string line;

    while(!ifs.eof())
    {
        size_t pos = 0;
        std::getline(ifs, line);
        while (true)
        {
            pos = line.find(s1, pos);
            if (pos == std::string::npos)
                break;
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        ofs << line;
        if (!ifs.eof())
            ofs << std::endl;
    }
}

int main(int argc, char *argv[])
{
    std::string s1;
    std::string s2;
    std::ifstream ifs;
    std::ofstream ofs;

    if (argc != 4)
        print_err("Wrong arguments");
    init_s1s2(s1, s2, argv);
    init_ifstream(ifs, argv[1]);
    init_ofstream(ofs, argv[1]);
     replace_s1_to_s2(ifs, ofs, s1, s2);
    ifs.close();
    ofs.close();
    return (0);
}