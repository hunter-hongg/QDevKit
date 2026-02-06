#include <router.h>

util::Router::Router(std::unordered_map<std::string, QWidget *> route,
                     QMainWindow *MainWindow)
    : routes(route), window(MainWindow) {}

util::Router::Router(
    std::unordered_map<std::string, std::function<QWidget *(QMainWindow *)>>
        route,
    QMainWindow *MainWindow)
    : window(MainWindow) {
  for (auto &route : route) {
    routes.insert({route.first, route.second(window)});
  }
}

std::unordered_map<std::string, QWidget *> util::Router::GetRoutes() noexcept {
  return routes;
}

void util::Router::Navigate(std::string route) noexcept(false) {
  if (routes.find(route) == routes.end()) {
    throw std::runtime_error("Route not found");
  }
  if (window->centralWidget()) {
    delete window->centralWidget();
  }
  window->setCentralWidget(routes[route]);
}