#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <queue>

struct TreeNode {
    std::string parent;
    std::vector<TreeNode*> child;
    TreeNode* father;
};

TreeNode* new_node(std::string);
void print_node(TreeNode* tree);
void print_tree(TreeNode*);
TreeNode* get_childrens(TreeNode*, std::string);
TreeNode* search_node(TreeNode*, std::string);