#include <iostream>
#include <iomanip>

#include "map_text_drawer.h"


void MapTextDrawer::draw(std::vector<std::vector<int>>& grid, 
                        const std::vector<std::pair<int, int>>& path){

    //TODO remove magic numbers
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