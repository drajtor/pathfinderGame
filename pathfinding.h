#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <vector>
#include <utility>

struct Node {
    int y, x;
    int g_cost, h_cost, f_cost;
    Node* parent;

    Node(int y, int x, Node* p = nullptr);
    void update_costs(const Node& goal);
};

struct CompareNode {
    bool operator()(const Node* a, const Node* b);
};

std::vector<std::pair<int, int>> find_path(const std::vector<std::vector<int>>& grid, Node start, Node goal);
void display_map(std::vector<std::vector<int>>& grid, const std::vector<std::pair<int, int>>& path);

#endif // PATHFINDING_H
