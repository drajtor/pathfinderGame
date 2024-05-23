#include <iostream>
#include <utility>
#include <cstdlib>
#include "pathfinder.h"
#include "map_generator.h"
#include "Imap_drawer.h"
#include "map_text_drawer.h"
#include <memory>
#include <csignal>
#include <sys/wait.h>

void handle_signal(int sig){
    if (sig == SIGTSTP){
        exit(0);
    }
}

void run_gui(){


    std::cout << "run_gui" << std::endl;

    while(1){
        sleep(1);
    }

}

void run_algo(int map_index){
    
    std::vector<std::vector<std::vector<int>>> maps;
    generate_maps(maps);

    std::pair<int, int> start (0, 0);
    std::pair<int, int> goal(maps[map_index].size()-1, maps[map_index][0].size()-1);

    Pathfinder pathfinder;

    std::vector<std::pair<int, int>> path = pathfinder.find_path(maps[map_index], start, goal);
    
    std::unique_ptr<IMapDrawer> mapDrawer = std::make_unique<MapTextDrawer>(MapTextDrawer());

    mapDrawer->draw(maps[map_index], path);

    while(1){
        sleep(1);
    }
}

int main(int argc, char** argv) {
    const int mapCount (5);
    const int mapMaxIndex = mapCount - 1;
    const char* guiProcessString = "gui";
    const char* algorithmProcessString = "algo";

    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGTSTP, &sa, NULL);

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " map_index (0-" << mapMaxIndex << ")" << std::endl;
        return 1;
    }
    

    if (std::string(argv[1]) == guiProcessString ){
        run_gui();
    }

    if (std::string(argv[1]) == algorithmProcessString ){
        run_algo(mapMaxIndex);
    }

    int map_index = std::atoi(argv[1]);
    if (map_index < 0 || map_index > mapCount) {
        std::cout << "Invalid map index. Please enter a value between 0 and " << mapMaxIndex << std::endl;
        exit (1);
    }

    pid_t pid_0 = fork();
    if (pid_0 == 0){
        //child process
        std::cout << "run child process gui" << std::endl;
        //TODO dont use distro specific terminal...
        execlp("gnome-terminal", "gnome-terminal", "--", "./pathfinder", "gui", (char *)nullptr);
    }

    pid_t pid_1 = fork();
    if (pid_1 == 0){
        //child process
        std::cout << "run child process algo" << std::endl;
        run_algo(map_index);
    }

    waitpid(pid_0, nullptr, 0);
    waitpid(pid_1, nullptr, 0);

    return 0;
}
