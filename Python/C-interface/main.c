#include <stdio.h>
#include "functions.h"

int main( int argc, const char* argv[] )
{
  if(argc > 1)
  {
	  for( int i = 1; i < argc; i++ )
	  {
	  	Print(i, argv[i] );
	  }
  }
  
  printf("MY_VALUE is %d\n",MY_VALUE);
  
  return 1;
}
