//������� 1
//�������� ��������� IOutput.� �� ������ ���� ���
//������ :
//? void Show() � ���������� ����������;
//? void Show(string info) � ���������� ���������� �
//�������������� ���������, ������� ���� �������
//� ��������� info.
//�������� ����� Array(������ ������ ����) � ������������ ��������.���� ����� ������ ����������������
//��������� IOutput.
//����� Show() � ���������� �� ����� �������� �������.
//����� Show(string info) � ���������� �� ����� �������� ������� � �������������� ���������, ���������
//� ��������� info.
//�������� ��� ��� ������������ ���������� ����������������.

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
        cout << "�������� �������: ";
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

    
    myArray.Show("�������������� ���������: ������ ����� �����");

    return 0;
}