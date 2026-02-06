#pragma once
#include <QMainWindow>
#include <QWidget>
#include <functional>
#include <string>
#include <unordered_map>

namespace util {
class Router {
public:
  Router() = delete;
  Router(std::unordered_map<std::string, QWidget *>, QMainWindow *);
  Router(
      std::unordered_map<std::string, std::function<QWidget *(QMainWindow *)>>,
      QMainWindow *);
  std::unordered_map<std::string, QWidget *> GetRoutes() noexcept;
  void Navigate(std::string route) noexcept(false);

protected:
  std::unordered_map<std::string, QWidget *> routes;
  QMainWindow *window;
};
} // namespace util