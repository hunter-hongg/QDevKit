#pragma once
#include "logical/git.h"
#include <router.h>
#include <window.h>
#include <pages.h>

namespace global
{
    MainWindow *GlobalWindow();
    util::Router GlobalRouter();
    extern std::string GlobalPath;
    extern logical::GitHelper GlobalGit;
}