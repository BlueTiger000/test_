// 2Task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int main()
{
    setlocale(LC_ALL, "Russian");
    struct Athlete {
        std::string name;
        float r1;
        float r2;
        float r3;
    };
    std::ifstream in("DATA.csv");
    float x, y, z;
    std::string line;
    std::string name;

    std::vector <Athlete> athletes;


    if (in.is_open()) 
    {
        std::cout << "File is open";
    }
    while (getline(in, line)) {
        std::stringstream ss(line);
        std::string name;
        char comma;

        getline(ss, name, ',');
        ss >> x >> comma >> y >> comma >> z;

        athletes.push_back({ name, x, y, z });
    }
    std:: cout << std::endl << "Средний балл спортсмена:" << std::endl;
    for (const auto& athlete : athletes) {
        float srednee = (athlete.r1 + athlete.r2 + athlete.r3) / 3.0;
        if ((srednee > 10) && (srednee <= 35)) {
            std::cout << athlete.name << ": " << srednee << std::endl;
        }
    }
    float r1t{ 0 };
    float r2t = 0; 
    float r3t{ 0 };
    for (const auto& athlete : athletes) {
        if((athlete.r2>10)&&(athlete.r3>10)){
            r1t += athlete.r1;
            r2t += athlete.r2;
            r3t += athlete.r3;
        }
    }
    int number_athletes = athletes.size();
    std::cout << "Среднее число за первый раунд: " << r1t / number_athletes << std:: endl;
    std::cout << "Среднее число за второй раунд: " << r2t / number_athletes << std::endl;
    std::cout << "Среднее число за третий раунд: " << r3t / number_athletes << std::endl;
    in.close();
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
