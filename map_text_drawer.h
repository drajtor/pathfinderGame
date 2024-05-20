#pragma once

#include "Imap_drawer.h"

class MapTextDrawer : public IMapDrawer {
public:
    void draw(std::vector<std::vector<int>>& grid, 
                        const std::vector<std::pair<int, int>>& path);
};