#include <iostream>
#include <utility>
#include <cstdlib>  // Dla std::atoi
#include "pathfinder.h"
#include "map_generator.h"

int main(int argc, char** argv) {
    const int mapCount (5);
    const int mapMaxIndex = mapCount - 1;

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " map_index (0-" << mapMaxIndex << ")" << std::endl;
        return 1;
    }

    int map_index = std::atoi(argv[1]);
    if (map_index < 0 || map_index > mapCount) {
        std::cout << "Invalid map index. Please enter a value between 0 and " << mapMaxIndex << std::endl;
        return 1;
    }

    std::vector<std::vector<std::vector<int>>> maps;
    generate_maps(maps);

    std::pair<int, int> start (0, 0);
    std::pair<int, int> goal(maps[map_index].size()-1, maps[map_index][0].size()-1);

    Pathfinder pathfinder;

    std::vector<std::pair<int, int>> path = pathfinder.find_path(maps[map_index], start, goal);
    display_map(maps[map_index], path);

    return 0;
}
