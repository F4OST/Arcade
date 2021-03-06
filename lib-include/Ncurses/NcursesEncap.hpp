//
// NcursesEncap.hpp for arcade in /home/prost_m/Rendu/Semestre_4/cpp_arcade/lib-include/Ncurses/
//
// Made by Matthias Prost
// Login   <matthias.prost@epitech.eu@epitech.eu>
//
// Started on  Mon Mar 20 10:24:02 2017 Matthias Prost
// Last update Fri Mar 24 08:41:55 2017 Yassir Jabbari
//

#ifndef _NcursesEncap_H__
#define _NcursesEncap_H__

#include <curses.h>

class   NcursesEncap
{
public:
  static void n_newterm(void);
  static int n_endwin(void);
  static int n_refresh(void);
  static void n_mvprintw(int, int, const char *);
  static int  n_box(WINDOW *win, chtype verch, chtype horch);
  static WINDOW *n_subwin(WINDOW *orig, int nlines, int ncols, int begin_y, int begin_x);
  static void n_mvwprintw(WINDOW *win, int y, int x, const char *fmt);
  static int n_wrefresh(WINDOW *);
  static int n_getch();
  static void n_curs_set();
  static void n_noecho();
  static void n_nodelay();
  static void n_keypad();
  static void n_start_color();
  static void n_init_pair(short, short, short);
  static int n_init_color(short color, short r, short g, short b);
  static int n_attron(int);
  static int n_attroff(int);
  static void n_getmaxyx(WINDOW *, int *, int *);
  static void n_clear(void);
  static int  n_cbreak(void);
  static int n_nocbreak(void);
};

#endif
