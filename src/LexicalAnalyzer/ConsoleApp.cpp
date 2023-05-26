// ConsoleApp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <queue>
#include "Analyzers/Lexer.h"
#include "Analyzers/Analyzer.h"

std::string ReadAllFile(std::string fileName)
{
    std::string result;
    std::ifstream file;
    file.open(fileName);
    while (!file.eof())
    {
        std::string temp;
        std::getline(file, temp);
        result += temp + "\n";
    }
    return result;
}
void ShowTokens(std::list<Token*> tokens)
{
    std::cout << "__________________Tokens__________________" << std::endl;
    for (Token* token : tokens)
        std::cout << token << std::endl;
}

void ShowNamesTabel(NamesTabel* namesTabel)
{
    std::cout << "__________________NamesTabel__________________" << std::endl;
    std::queue<Scope*> scopes;
    scopes.push(namesTabel->GetGlobalScope());
    int numeber = 0;
    while (!scopes.empty())
    {  
        Scope* scope = scopes.front();
        scopes.pop();
        std::map<std::string, IdentifierInfo*> identifiers = scope->GetIdentifiers();
        
        if (identifiers.size() > 0)
            std::cout << "InverstmentLevel: " << scope->GetInverstmentLevel() << std::endl;
        for (auto identifier : identifiers)
        {
            std::cout << identifier.first << "\t"
                << identifier.second << std::endl;
        }
        
        for (Scope* child : scope->GetChilds())
        {
            scopes.push(child);
        }
    }
}

int main()
{
    std::string inputString = ReadAllFile("input.txt");
    Analyzer* analyzer = new Analyzer(inputString.c_str(), inputString.size());
    Token* token = nullptr;
    try
    {
        analyzer->Parse();
    }
    catch(BaseException* exception)
    {
        std::cout << exception;
        return -1;
    }
    catch (...)
    {
        std::cout << "Unknown exception";
        return -1;
    }
    ShowTokens(analyzer->GetTokens());
    ShowNamesTabel(analyzer->GetNamesTabel());

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
