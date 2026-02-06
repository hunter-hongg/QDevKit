#include <header.h>
    
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
            },
            GlobalWindow());
        return route;
    }
}