#ifndef CLASSES_WINDOW_MGR_H
#define CLASSES_WINDOW_MGR_H

#include <vector>
#include "screen.h"

using std::vector;

class Window_mgr {
   private:
    vector<Screen> screens{Screen(24, 80, ' ')};

   public:
    using ScreenIndex = vector<Screen>::size_type;

    void clear(ScreenIndex);
};

inline
void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

#endif