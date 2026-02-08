#include "global.h"
#include "logical/git.h"
#include "pages.h"
    
namespace global {
    MainWindow *GlobalWindow()
    {
        static MainWindow window;
        return &window;
    }

    util::Router GlobalRouter()
    {
        static util::Router route(
            {
                {"/", main_page},
                {"/git", git_page},
            },
            GlobalWindow());
        return route;
    }

    std::string GlobalPath = "";
    logical::GitHelper GlobalGit("");
}