#include "Tree.h"

TreeNode* new_node(std::string name)
{
    TreeNode* temp = new TreeNode();
    temp->parent = name;
    return temp;
}

void print_node(TreeNode* tree)
{
    std::cout << std::endl << "имя: " << tree->parent << std::endl;
    std::cout << "дети: ";

    if (tree->child.size() > 0)
        for (TreeNode* node : tree->child)
            std::cout << node->parent << " ";
    else
        std::cout << "-";

    if (tree->father != NULL)
        std::cout << std::endl << "отец: " << tree->father->parent;

    if (tree->father->father != NULL)
        std::cout << std::endl << "дедушка: " << tree->father->father->parent;

    std::cout << std::endl << std::endl;
}

TreeNode* search_node(TreeNode* root, std::string name)
{
    TreeNode* element = new TreeNode;
    if (!root)
        return NULL;

    if (root->parent == name)
        print_tree(root);

    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int n = (int)q.size();
        while (n > 0)
        {
            TreeNode* p = q.front();
            q.pop();

            if (p->parent == name)
                print_tree(p);

            for (int i = 0; i < p->child.size(); i++)
                q.push(p->child[i]);

            n--;
        }
    }

    return element;
}

void print_tree(TreeNode* tree)
{
    if (tree == NULL)
        return;

    print_node(tree);

    for (int i = 0; i < tree->child.size(); i++)
        print_tree(tree->child[i]);
}