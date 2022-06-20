#ifndef CLASSES_SCREEN_H
#define CLASSES_SCREEN_H

#include <string>
#include <iostream>
#include "window_mgr.h"

using std::string;
using std::ostream;

class Screen {
    friend void Window_mgr::clear(ScreenIndex);
    
   public:
    using pos =  string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' '){}
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c){}

    char get() const {return contents[cursor];}
    char get(pos ht, pos wd) const;

    Screen &move(pos, pos);

    Screen &set(char);
    Screen &set(pos, pos, char);

    Screen &display(ostream &);
    const Screen &display(ostream &) const;

   private:
    pos cursor{0};
    pos height{0}, width{0};
    string contents;

    void do_display(ostream &os) const {os << contents;}
};

inline
Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline 
char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

inline 
Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline
Screen &Screen::set(pos row, pos col, char c) {
    contents[row * width + col] = c;
    return *this;
}

inline
Screen &Screen::display(ostream &os) {
    do_display(os);
    return *this;
}

inline
const Screen &Screen::display(ostream &os) const {
    do_display(os);
    return *this;
}

#endif