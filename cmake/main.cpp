//Template C++ program with root libraries
//set root outputfile data manager class



#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;


const int nArgc =3;
std::string fout_name; 

int analyze_command_line (int argc, char **argv);

int main(int argc, char* argv[])
{
  std::cout << "Running cmake example ... " << std::endl;
  
  int ret = analyze_command_line(argc, argv);
  if(ret) { return 1; }
  
  return 0;
}
  
  
  
  
  
int analyze_command_line(int argc, char **argv)
{
  if(argc==nArgc)
  {
    for(int i=1; i<argc; /*increment in loop*/)
    {
      if(argv[i][0] != '-'){ printf("ERROR: Wrong argument %s\n",argv[i]); }
      else
      {
        if(strlen(&argv[i][1]) == 1)
        {
	  switch(argv[i][1])
          {
	    case 'o':
	      if(i+1 < argc)
              {
	        fout_name = argv[i+1];
	        i+=2;
	      }
              else
              {
	        printf("ERROR:  output file not specified\n");
	      }
              break;

             default:
	     printf("Argument %s not recognized\n",argv[i]);
             return 1;
          }
        }
      }
    }
    std::cout << "Outputfile is set as '" << fout_name << "'"<< std::endl;
  }
  else
  {
    cout << " use as ./Program -o outputfile" << endl;
    return 1;
  }
  return 0;
}
