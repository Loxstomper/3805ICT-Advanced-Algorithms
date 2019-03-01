#include "./headers/Reader.hpp"

Reader::Reader()
{

}

void Reader::read(std::string path)
{
    std::cout << path << std::endl;

    std::string str;
    std::ifstream file;
    file.open(path);

    std::string a, b, c;

    // while(!file.eof) 
    // {
    //     file.getline(file, str);
    //     std::cout << str;
    // }

    while (file >> a >> b >> c)
    {
        std::cout << a << b << c << std::endl;
    }

    file.close();
}