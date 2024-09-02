#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>

struct Node
{
    int value;
    Node* next; 
    
    Node(): value(0), next(nullptr)
    {}
    
    Node(int value_i): value(value_i), next(nullptr)
    {}
    
    Node(int value_i, Node* next_i): value(value_i), next(next_i)
    {}
};

Node* MakeList(std::vector<int> V)
{
    
    Node* new_node_ref = new Node();
    Node* new_node_ref_copy = new_node_ref;
    int n = V.size();
    for (int i = 0; i < n - 1; ++i)
    {
        new_node_ref_copy->value = V[i];
        Node* next_ref = new Node();
        new_node_ref_copy->next = next_ref;
        new_node_ref_copy = new_node_ref_copy->next;
    }
    new_node_ref_copy->value = V[n - 1];
    new_node_ref_copy->next = nullptr;
    return new_node_ref;
}

void print(Node* node)
{
    while (node != nullptr)
    {
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

Node* deep_copy(Node* node)
{
    Node* new_node_ref = new Node();
    Node* new_node_ref_copy = new_node_ref;
    while (node->next != nullptr)
    {
        int v = node->value;
        new_node_ref_copy->value = v;
        Node* ref = new Node();
        new_node_ref_copy->next = ref;
        new_node_ref_copy = new_node_ref_copy->next;
        node = node->next;
    }
    int v = node->value;
    new_node_ref_copy->value = v;
    return new_node_ref;
}

void Insert(Node* node, int res, int index=1)
{
    Node* node_copy = node;
    if (index == 0)
    {
        Node* node_next = new Node(node->value, node->next);
        node->next = node_next;
        node->value = res;
        return;
    }
    for (int i = 0; i < index - 1; ++i)
    {
        node_copy = node_copy->next;
    }
    Node* node_memory = node_copy->next;
    Node* node_new = new Node(res, node_memory);
    node_copy->next = node_new;
}

void Delete(Node* node, int index=1)
{
    if (index == 0)
    {
        node->value = (node->next)->value;
        node->next = (node->next)->next;
        return;
    }
    for (int i = 0; i < index - 1; ++i)
    {
        node = node->next;
    }
    node->next = (node->next)->next;
}

Node* reverse(Node* node)
{
    Node* rev_node = new Node(node->value);
    while (node->next != nullptr)
    {
        node = node->next;
        int res = node->value;
        Insert(rev_node, res, 0);
    }
    return rev_node;
}


#endif
