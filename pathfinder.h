#pragma once

#include <vector>
#include <utility>


class Pathfinder {
    public:
    std::vector<std::pair<int, int>> find_path(const std::vector<std::vector<int>>& grid, 
                                                std::pair<int, int> start, 
                                                std::pair<int, int> goal);

};

void display_map(std::vector<std::vector<int>>& grid, const std::vector<std::pair<int, int>>& path);

