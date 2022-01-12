// 15 �������   �����   ���������,  ���������  ��  ����������
//    ����������.  ������ �������� ���������� � ��������� �  �������
//    ������  �������  ��  ����������� ���������.  ����� �������� ��
//    ��������.  ����� �������� ���������� � �� ������ �  �������  �
//    �����  ������  ������  '-'.  ������������  ����  � �����������
//    ��������� (7).
// ��������� ���������� ��-22
// Code::Blocks 20.03 MinGW GCC

#include <iostream>
#include <fstream>
#include <locale>

using namespace std;

string get_number(string line);

int main(int argc, char* argv[])
{
    ifstream file;
    ofstream output;
    string line;

    int counter = 0;
    bool new_line = false;
    bool page_number = false;
    bool paragraph_header = false;

    string output_name = "output.txt";
    string input_name = "input.txt";

    setlocale(LC_ALL, ".1251");

    if (argc > 1)
    {
        input_name = argv[1];
        output_name = argv[2];
    }
    else
    {
        cout << "��� ����������. ������� ������� � �������� ���� �������" << endl;
        cout << "������� ����: ";
        cin >> input_name;
        cout << "�������� ����: ";
        cin >> output_name;
    }

    file.open(input_name);
    output.open(output_name);
    if (!file) return -1;
    if (!output) return -1;

    while (getline(file, line))
    {
        new_line = line[0] == '\0';
        page_number = line[0] == '-';

        if (page_number)
        {
            paragraph_header = false;
            output << get_number(line) << " ";
        }

        if (new_line)
        {
            paragraph_header = false;
            counter++;
        }


        if (!new_line && !page_number && !paragraph_header)
        {
            string head = line;

            if (isalpha(line[0]))
            {
                paragraph_header = true;
                getline(file, line);
                counter++;
            }

            output << head<< endl;

            counter++;
        }

        counter++;
    }

    cout << "���������� �� " << input_name << " ��������� � ���� " << output_name << endl;

    return 0;
}

string get_number(string line)
{
    string number = "";

    bool flag_start = false;
    bool flag_end = false;

    int len = line.length();
    int counter = 1;

    flag_start = line[0] == '-';

    while (flag_start && !flag_end)
    {
        flag_end = line[counter] == '-';

        if (!flag_end)
            number += line[counter];

        counter++;
    }

    return number;
}
