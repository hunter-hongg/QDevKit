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
  // 存储工厂函数而不是页面实例
  std::unordered_map<std::string, std::function<QWidget *(QMainWindow *)>> routeFactories;
  QMainWindow *window;
};
} // namespace util