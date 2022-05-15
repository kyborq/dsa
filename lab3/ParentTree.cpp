// 5. Имеется дерево, корень которого соответствует основателю
//    рода. Сыновья  каждой  вершины  задают  сыновей   и   дочерей
//    соответствующего    человека.Указывается   имя   некоторого
//    человека.Требуется выдать имена его детей, внуков, сестер и
//    братьев, одного из родителей, дедушки или бабушки (9).
// Подыганов Константин Эдуардович ПС-22
// Visual Studio 2022

#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <fstream>
#include <locale>
#include <Windows.h>

#include "Tree.h"
#include "Utils.h"

using namespace std;

ifstream open_file(string file_name)
{
    ifstream file;
    file.open(file_name);

    if (!file.is_open())
        cout << endl << "Ошибка при открытии файла: " << file_name << "!" << endl;

    return file;
}

void search_driver(TreeNode * root)
{
    bool flag_input = true;

    cout << "Добро пожаловать в программу поиска. Для выхода введите 'выход'" << endl << endl;
    while (flag_input)
    {
        string name;
        cout << "Введите имя: ";
        cin >> name;

        if (name == "выход")
            flag_input = false;
        if (name != "")
            search_node(root, name);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream input;
    string line;
    TreeNode* root;

    input = open_file("input.txt");

    getline(input, line);
    root = new_node(line);    

    vector<TreeNode*> nodes;
    nodes.push_back(root);

    while (getline(input, line))
    {
        int level = get_depth(line);
        string name = get_name(line);
        TreeNode* node = new_node(name);

        if (level == nodes.size())
        {
            nodes.push_back(node);
        }

        if (level < nodes.size())
        {
            node->father = nodes[level - 1];
            nodes[level - 1]->child.push_back(node);
            nodes.erase(nodes.begin() + level, nodes.end());
            nodes.push_back(node);
        }
    }

    search_driver(root);
}

