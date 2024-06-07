#include <iostream>
#include <fstream>
#include <string>

#define ERROR 1
#define SUCCESS 0

int print_err(std::string msg)
{
    std::cout << msg << std::endl;
    return (ERROR);
}

int init_s1s2(std::string &s1, std::string &s2, char *argv[])
{
    s1 = argv[2];
    s2 = argv[3];

    if (s1.empty() || s2.empty())
        return (print_err("The string is empty."));
    return (SUCCESS);
}

int init_ifstream(std::ifstream &ifs, char *filename)
{
    ifs.open(filename);
    if (ifs.fail())
        return (print_err("Cannot open file."));
    return (SUCCESS);
}

int init_ofstream(std::ofstream &ofs, char *filename)
{
    std::string ofilename = filename;
    ofilename.append(".replace");
    ofs.open(ofilename.c_str());
    if (ofs.fail())
        return (print_err("Cannot open file."));
    return (SUCCESS);
}

void replace_s1_to_s2(std::ifstream &ifs, std::ofstream &ofs, std::string &s1, std::string &s2)
{
    std::string line;

        size_t pos = 0;
        std::getline(ifs, line, '\0');
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
}

int main(int argc, char *argv[])
{
    std::string s1;
    std::string s2;
    std::ifstream ifs;
    std::ofstream ofs;

    if (argc != 4)
    {
        print_err("Wrong arguments");
        return (1);
    }
    if (init_s1s2(s1, s2, argv) == ERROR ||
    init_ifstream(ifs, argv[1]) == ERROR ||
    init_ofstream(ofs, argv[1]) == ERROR)
        return (1);
    replace_s1_to_s2(ifs, ofs, s1, s2);
    ifs.close();
    ofs.close();
    return (0);
}