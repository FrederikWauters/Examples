#include <stdio.h>
#include <string.h>
#include "midas.h"





int main()
{
   const char* database_filename = "databasename";
   printf("Name of db = %s\n",database_filename);
   
   char msg[256] = "Cannot open ";
   printf("msg = %s\n",msg);
   
   strcat(msg,database_filename);
   
   printf("combined string = %s\n",msg);
   cm_msg(MERROR, "sql_analysis_init", "%s",msg); 
}
