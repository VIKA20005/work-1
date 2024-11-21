//Задание 1
//Создайте интерфейс IOutput.В нём должно быть два
//метода :
//? void Show() — отображает информацию;
//? void Show(string info) — отображает информацию и
//информационное сообщение, которое было указано
//в параметре info.
//Создайте класс Array(массив целого типа) с необходимыми методами.Этот класс должен имплементировать
//интерфейс IOutput.
//Метод Show() — отображает на экран элементы массива.
//Метод Show(string info) — отображает на экран элементы массива и информационное сообщение, указанное
//в параметре info.
//Напишите код для тестирования полученной функциональности.

#include <iostream>
#include <vector>
#include <string>

using namespace std; 

class IOutput 
{
public:
    virtual void Show() = 0; 
    virtual void Show(const string& info) = 0; 
    virtual ~IOutput() = default;
};


class Array : public IOutput 
{
private:
    vector<int> arr; 

public:
    
    Array(const vector<int>& data) : arr(data) {}

    
    void Show() override 
    {
        cout << "Элементы массива: ";
        for (int num : arr) 
        {
            cout << num << " ";
        }
        cout << endl;
    }

    
    void Show(const string& info) override 
    {
        cout << info << endl;
        Show(); 
    }
};


int main() 
{
    
    vector<int> data = { 1, 2, 3, 4, 5 };
    Array myArray(data);

    
    myArray.Show();

    
    myArray.Show("Дополнительное сообщение: Массив целых чисел");

    return 0;
}