#ifndef MINMAX_HH
#define MINMAX_HH
#include "WinCondition.hh"

pair< int, pair<int, int> > MinMax(Board gameBoard, Player player1, Player player2, bool minOrMax, WinCondition condition);

#endif
