//
// Qt.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/Qt.hpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:40 2017 Loïc Lopez
// Last update jeu. mars 16 15:07:40 2017 Loïc Lopez
//

#ifndef QTCONTROLLER_HPP__
# define QTCONTROLLER_HPP__

#include "../interface/ILibraryViewController.hpp"

class QtViewController : public ILibraryViewController
{
  virtual ~QtViewController();

  // Methods
  virtual void drawMap(std::map<int, int> &);
  virtual void drawCharacter(std::array<int, 2> &position);
  virtual void drawMenu();
};

#endif /* QTCONTROLLER_HPP__ */