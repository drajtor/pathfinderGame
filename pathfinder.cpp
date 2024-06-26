// pathfinder.cpp
#include "pathfinder.h"
#include <iostream>
#include <queue>
#include <cmath>
#include <iomanip>

class Node {
public:
    int y, x;
    int g_cost, h_cost, f_cost;
    Node* parent;


    Node(int y, int x, Node* p = nullptr) : y(y), x(x), g_cost(0), h_cost(0), f_cost(0), parent(p) {

    }

    void update_costs(const Node& goal){
        if (parent) g_cost = parent->g_cost + 1;
        h_cost = std::abs(goal.x - x) + std::abs(goal.y - y);
        f_cost = g_cost + h_cost;
    }
};

class CompareNode {
public:
    bool operator()(const Node* a, const Node* b);
};


bool CompareNode::operator()(const Node* a, const Node* b) {
    return a->f_cost > b->f_cost;
}

std::vector<std::pair<int, int>> Pathfinder::find_path(const std::vector<std::vector<int>>& grid, 
                                                        std::pair<int,int> s, 
                                                        std::pair<int,int> g) {
    Node start(s.first, s.second), goal(g.first, g.second);

    
    std::priority_queue<Node*, std::vector<Node*>, CompareNode> open_set;
    std::vector<std::vector<bool>> closed_set(grid.size(), std::vector<bool>(grid[0].size(), false));
    start.update_costs(goal);
    open_set.push(new Node(start.y, start.x));
    Node* current = nullptr;

    while (!open_set.empty()) {
        current = open_set.top();
        open_set.pop();

        if (current->y == goal.y && current->x == goal.x) {
            break;
        }

        closed_set[current->y][current->x] = true;

        for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                int ny = current->y + dy;
                int nx = current->x + dx;
                if (ny < 0 || nx < 0 || ny >= (int)grid.size() || nx >= (int)grid[0].size() || grid[ny][nx] == 1 || closed_set[ny][nx])
                    continue;

                Node* neighbor = new Node(ny, nx, current);
                neighbor->update_costs(goal);
                open_set.push(neighbor);
            }
        }
    }

    std::vector<std::pair<int, int>> path;
    while (current != nullptr) {
        path.push_back({current->y, current->x});
        current = current->parent;
    }

    return path;
}

void display_map(std::vector<std::vector<int>>& grid, const std::vector<std::pair<int, int>>& path) {
    for (auto& p : path) {
        grid[p.first][p.second] = 2; // 2 oznacza ścieżkę
    }
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 1) std::cout << std::setw(2) << "#";
            else if (grid[i][j] == 2) std::cout << std::setw(2) << ".";
            else std::cout << std::setw(2) << " ";
        }
        std::cout << "\n";
    }
}

