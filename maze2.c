#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include "maze.h"

int main(int argc, char* argv[]){

  initscr();
  cbreak();
  noecho();
  noqiflush();
  keypad(stdscr, TRUE);

  Map map = {map1, NULL};

  Player* players = NULL;
  players->y = 4;
  players->x = 4;
  players->c = 'O';

  char c = '\0';
  int sy = 0;
  int sx = 0;
  do{
    clear();
    printw("%c", c);
    refresh();

    for (int i = 0; i < 9; i++){
      for (int j = 0; j < 9; j++){
        if(map.map[i] == 'S'){
          sy = i;
          sx = j;
        }
        mvprintw(i, j, "%c", map[i][j]);
      }
    }

    if (c == 'r'){ 
      players = (Player *)malloc(sizeof(Player));
      players->y = sy;
      players->x = sx;
      map[sy][sx] = players->c;
      mvprintw(sy, sx, "%c", () ?  : map[sy][sx]);
    }

    move(8, 8);
  }while ((c = getch()) != 'q');
  /*
     Player* p = NULL;
     char input = '\0';
     while((input = getch()) != 'q' || map[players->y][players->x] != 'E'){
     clear();
     if(map[players->y-1][players->x] == '.'){
     p = (Player*)malloc(sizeof(Player));
     players->next = p;
     }
     refresh();
     }

     Player* ptr = players;
     while(ptr->next){
     ptr = ptr->next;
     }
     ptr->next = p;

     free(players);
     */

  endwin();
  return 0;
}
