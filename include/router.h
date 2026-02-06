#pragma once
#include <QMainWindow>
#include <QWidget>
#include <unordered_map>
#include <string>
#include <functional>

namespace util
{
    class Router
    {
    public:
        Router() = delete;
        Router(
            std::unordered_map<std::string, QWidget*> route,
            QMainWindow *MainWindow) : routes(route), window(MainWindow) {}

        Router(
            std::unordered_map<std::string, std::function<QWidget*(QMainWindow*)>> route, 
            QMainWindow *MainWindow) : window(MainWindow) {
                for(auto &route : route) {
                    routes.insert({route.first, route.second(window)});
                }
        }
        std::unordered_map<std::string, QWidget*> GetRoutes() noexcept {
            return routes;
        }

        void Navigate(std::string route) noexcept(false) {
            if(routes.find(route) == routes.end()) {
                throw std::runtime_error("Route not found");
            }
            if (window->centralWidget()) {
                delete window->centralWidget();
            }
            window->setCentralWidget(routes[route]);
        }

    protected:
        std::unordered_map<std::string, QWidget*> routes;
        QMainWindow *window;
    };
}