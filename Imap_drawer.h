#pragma once

#include <vector>

class IMapDrawer{
public:
    virtual void draw(std::vector<std::vector<int>>& grid, 
                        const std::vector<std::pair<int, int>>& path) = 0;
};