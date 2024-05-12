#include <iostream>
#include <cstdlib>  // Dla std::atoi
#include "pathfinding.h"
#include "map_generator.h"

int main(int argc, char** argv) {
    const int mapCount (4);
    const int mapMaxIndex = mapCount - 1;

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " map_index (0-" << mapMaxIndex << ")" << std::endl;
        return 1;
    }

    int map_index = std::atoi(argv[1]);
    if (map_index < 0 || mapCount > 9) {
        std::cout << "Invalid map index. Please enter a value between 0 and " << mapMaxIndex << std::endl;
        return 1;
    }

    std::vector<std::vector<std::vector<int>>> maps;
    generate_maps(maps);

    Node start(0, 0);
    Node goal(maps[map_index].size()-1, maps[map_index][0].size()-1);

    std::vector<std::pair<int, int>> path = find_path(maps[map_index], start, goal);
    display_map(maps[map_index], path);

    return 0;
}
