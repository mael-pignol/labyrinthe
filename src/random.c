#include <stdio.h>
#include <unistd.h>
#include "labyrinthes.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
  srand(time(0));
  // Variables for starting position
  int startX = 2;
  int startY = 3;

  // Variables for goal
  int arrivalX = 6;
  int arrivalY = 2;

  // Variables de position
  int x = startX;
  int y = startY;

  // Load the labyrinth and set the starting and goal positions
  load_lab("/labyrinthe/lab/lab.fodaly");
  set_start(startX, startY);
  set_arrival(arrivalX, arrivalY);
  set_display_mode(1);
  exists_solution();

  // Display the lab
  display_lab();

  if(exists_solution() == 0 ){
    sleep(1);
    close_lab();
      return 0;
  }
  while((x!=arrivalX || y!=arrivalY))
  {
    int random = rand() %4;
        if(random==0 && is_valid_move(x,y-1))
        {
            move(x,y-1);
            y=y-1;
        }
        if(random==1 && is_valid_move(x+1,y))
        {
            move(x+1,y);
            x=x+1;
        }
        if(random==2 && is_valid_move(x,y+1))
        {
           move(x,y+1);
           y=y+1;
        }
        if(random==3 && is_valid_move(x-1,y))
        {
           move(x-1,y);
           x=x-1;
        }
          display_lab();
          //sleep(1);
          int c = 1, d = 1;
           for ( c = 1 ; c <= 3 ; c++ )
                 for ( d = 1 ; d <= 3 ; d++ )
                    {}
  }
  // Wait until enter is pressed
  getchar();
  close_lab();
  return 0;

}
