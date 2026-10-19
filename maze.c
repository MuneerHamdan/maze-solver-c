#include <stdlib.h>
#include <stdio.h>
#include "maze.h"

void printmap() {
  // print map
  printf("\n");
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n"); 
  }
  printf("\n");
}

Player* solve(Player* p) {

  printf("solving\n");

  if (map[p->y+1][p->x+0] == 'E') {
    map[p->y][p->x] = 'x';
    p->y+=1;
    p->x+=0;
    printf("moved down\n");
    map[p->y][p->x] = 'O';
    p->active = 'E';
    solved = 1;
  }
  else if (map[p->y-1][p->x+0] == 'E') {
    map[p->y][p->x] = 'x';
    p->y-=1;
    p->x+=0;
    printf("moved up\n");
    map[p->y][p->x] = 'O';
    p->active = 'E';
    solved = 1;
  }
  else if (map[p->y+0][p->x+1] == 'E') {
    map[p->y][p->x] = 'x';
    p->y+=0;
    p->x+=1;
    printf("moved right\n");
    map[p->y][p->x] = 'O';
    p->active = 'E';
    solved = 1;
  }
  else if (map[p->y+0][p->x-1] == 'E') {
    map[p->y][p->x] = 'x';
    p->y+=0;
    p->x-=1;
    printf("moved left\n");
    map[p->y][p->x] = 'O';
    p->active = 'E';
    solved = 1;
  }
  printf("no E: p.y: %d, p.x: %d\n", p->y, p->x);
  if (solved) return p;


  printf("traversing\n");

  int routes = 0;

  if (map[p->y+1][p->x+0] == '.') {
    printf("route down\n");
    routes++;
  }
  if (map[p->y-1][p->x+0] == '.') {
    printf("route up\n");
    routes++;
  }
  if (map[p->y+0][p->x+1] == '.') {
    printf("route right\n");
    routes++;
  }
  if (map[p->y+0][p->x-1] == '.') {
    printf("route left\n");
    routes++;
  }

//  cacheline** cache = (cacheline**)malloc(S * sizeof(cacheline*));
  Player** players = (Player**)malloc (1 * sizeof(Player*));
  if (routes > 1) {
    for (int i = 0; i < routes; i++) {
      Player* player = (Player*)malloc (1 * sizeof(Player));
      players[i] = player;
    }
  }
    for (int i = 0; i < routes; i++) {
      printf("%d\n", sizeof(players) / sizeof(Player**));
    }

  if (map[p->y+1][p->x+0] == '.') {
    map[p->y][p->x] = 'x';
    p->y+=1;
    p->x+=0;
    printf("moved up\n");
  }
  if (map[p->y-1][p->x+0] == '.') {
    map[p->y][p->x] = 'x';
    p->y-=1;
    p->x+=0;
    printf("moved down\n");
  }
  if (map[p->y+0][p->x+1] == '.') {
    map[p->y][p->x] = 'x';
    p->y+=0;
    p->x+=1;
    printf("moved right\n");
  }
  if (map[p->y+0][p->x-1] == '.') {
    map[p->y][p->x] = 'x';
    p->y+=0;
    p->x-=1;
    printf("moved left\n");
  }
  printf("routes: %d\n", routes);
  map[p->y][p->x] = 'O';
  return p;
}

Player* backtrack(Player* p) {

  printf("backtracking\n");

  if (map[p->y+1][p->x+0] == 'x') {
    map[p->y][p->x] = '-';
    p->y+=1;
    p->x+=0;
    printf("moved down\n");
    map[p->y][p->x] = 'O';
  }
  else if (map[p->y-1][p->x+0] == 'x') {
    map[p->y][p->x] = '-';
    p->y-=1;
    p->x+=0;
    printf("moved up\n");
    map[p->y][p->x] = 'O';
  }
  else if (map[p->y+0][p->x+1] == 'x') {
    map[p->y][p->x] = '-';
    p->y+=0;
    p->x+=1;
    printf("moved right\n");
    map[p->y][p->x] = 'O';
  }
  else if (map[p->y+0][p->x-1] == 'x') {
    map[p->y][p->x] = '-';
    p->y+=0;
    p->x-=1;
    printf("moved left\n");
    map[p->y][p->x] = 'O';
  }
}

int main() {
  Player players[10];

  // print initial map
  printmap();

  // initialize player on map at posititon 'S'
  Player p;
  players[0] = p;
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (map[i][j] == 'S') {
        p.y = i;
        p.x = j;
        map[i][j] = 'O';
        break;
      }
    }
  }

  // print map with player on it
  printmap();

  // run and count how many tries
  int tries = 1;
//  while (solved != 1) {
  for (int i = 0; i < MAXTRIES; i++) {
    printf("\n\n ----- Attempt %d ----- \n\n", tries);
    solve(&p);
    if (solved == 1) {
      printf("solved!!!!!!\n");
      printmap();
      break;
    }
    else if ((map[p.y+1][p.x+0] != '.') && (map[p.y-1][p.x+0] != '.') && (map[p.y+0][p.x+1] != '.') && (map[p.y+0][p.x-1] != '.')) {
    //  backtrack(&p);
    }


    tries++;
    printmap();
  }

    if (solved != 1) {
      printf("couldnt solve within %d attempts\n", MAXTRIES);
    }

  return 0;
}
