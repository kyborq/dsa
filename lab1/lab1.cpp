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
void print_line(string text, string number);

int main(int argc, char *argv[])
{
    ifstream file;
    string input_name = "input.txt";

    string line = "";
    string page = "";
    string header = "";

    bool is_skip_header = false;

    setlocale(LC_ALL, ".1251");

    file.open(input_name);
    if (!file)
        return -1;

    // line[0] == '-' �������� �� ����� ��������
    // line.empty()   �������� �� ������ ������
    while (getline(file, line))
    {

        // 1. ���� ������ �������
        if (line[0] == '-' && !is_skip_header)
        {
            page = get_number(line);

            // 2. ��������� ����� ���� ����� ����� ������ ��������
            getline(file, header);
            print_line(header, page);
        }

        // 3. ��������� ������ ������ ��� ���
        if (line.empty())
        {
            // is_empty_line = true;
            getline(file, line);
            if (line[0] != '-')
            {
                header = line;
            }

            if (line[0] == '-')
            {
                page = get_number(line);
                getline(file, header);
            }

            print_line(header, page);
        }

        // if (line.empty() && line[0] != '-')
        // {
        //     getline(file, line);
        //     if (!line.empty())
        //         header = line;
        //     getline(file, line);
        // }
    }

    // cout << "Last page is number " << page_number << endl;
    // cout << "Here is " << t_paragraph_counter << " paragraphs" << endl;
    // print_line("t_paragraph_counter", page_number);

    return 0;
}

string get_number(string line)
{
    int index = 1;
    int length = line.length();
    string number = "";

    while (index < length)
    {
        if (line[index] != '-')
            number += line[index];
        index++;
    }

    return number;
}

void print_line(string text, string number)
{
    string splitter = "";
    int text_len = text.length();
    int number_len = number.length();
    int width = 30 - text_len - number_len;

    int index = 0;
    while (index < width)
    {
        splitter += ".";
        index++;
    }

    cout << text << splitter << number << endl;
}