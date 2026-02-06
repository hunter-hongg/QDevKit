#include "pages.h"
#include "simple.h"
#include <header.h>

QWidget *git_page(QMainWindow *window) {

  QWidget *centralWidget = new QWidget(window);

  QVBoxLayout *layout = new QVBoxLayout(centralWidget);

  Simple::title("版本管理", centralWidget, layout);

  layout -> addStretch();

  Simple::back("/", centralWidget, layout);

  layout -> addStretch();

  return centralWidget;
}