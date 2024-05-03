#include "map_generator.h"
#include "maps_data.h"

void generate_maps(std::vector<std::vector<std::vector<int>>>& maps) {
    maps.clear();
    for (const auto& template_map : map_templates) {
        maps.push_back(template_map);
    }
}
