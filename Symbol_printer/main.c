
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <stdio.h>
#include <time.h>

struct SymbolPrinter
{
    char symbol;
    clock_t intervalTime;
    clock_t lastPrintTime;
};

int main()
{
  struct SymbolPrinter plus = {'+', 3000000, 0}; // display a '+' symbol every 3 seconds
  struct SymbolPrinter star = {'*', 7e6, 0};     // display a '*' symbol every 7 seconds
  struct SymbolPrinter hastag = {'#', 15e6, 0};// display a '#' symbol every 15 seconds
  clock_t currentTime = clock();    // clock ticks in micro-seconds from program start
                                    // we get 1 million clock ticks per second
  while(1){      
    currentTime = clock();
    if (currentTime - plus.lastPrintTime > plus.intervalTime){
        printf("%c\n", plus.symbol);
        plus.lastPrintTime = clock();
    }
    // add code to print star on schedule  
    if(currentTime - star.lastPrintTime > star.intervalTime){
    printf("%c\n",star.symbol);
    star.lastPrintTime = clock();
    }
    
    
  }
  return 0;
}


