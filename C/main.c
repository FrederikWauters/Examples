/* test stdarg in midas context
 see https://en.wikipedia.org/wiki/Stdarg.h for some general info
*/

#include <stdio.h>
#include <midas.h>
#include <stdarg.h>

INT command_interpreter(INT cmd, ...);

int main()
{

  printf("Executing Midas driver command test program ... \n");
  
  //test basic functionality
  float value = 4.45;
  command_interpreter(CMD_SET,1,value);
  
  command_interpreter(CMD_GET,1,&value);
  printf("After CMD_GET, value = %f\n",value);
  
  //setting a DWORD
  DWORD word = 0x00000002;
  printf("value of 32 bit word = 0x%08x\n", word);
  printf("setting without casting\n");
  command_interpreter(CMD_SET_CHSTATE,1,word);
  printf("setting after casting\n");
  command_interpreter(CMD_SET_CHSTATE,1,(float)word);
  
  //getting a DWORD
  DWORD status = 0x0F0F0F0F;
  command_interpreter(CMD_GET_CHSTATE,1,&status);
  printf("value of 32 bit status word set to = 0x%08x (float print: %f)\n", (DWORD)status,status);

  return 1;
}

INT command_interpreter(INT cmd, ...)
{
   va_list argptr; //type for iterating arguments

   INT channel, status;
   float value;
   float *pvalue;
   DWORD *pstate;


   va_start(argptr, cmd); //cmd is the named parameter preceeding the first variable parameter
   status = FE_SUCCESS;

   switch (cmd) {

     case CMD_SET:
        channel = va_arg(argptr, INT); //va_arg yield the next parameter, first argument is the va_list, the second is the type of the next argument
        value = (float) va_arg(argptr, double);
        printf("CMD_SET called, value = %f \n",value);
        break;
        
     case CMD_SET_CHSTATE:
        channel = va_arg(argptr, INT); 
        value = (float) va_arg(argptr, double);
        printf("CMD_SET_CHSTATE called, value = %f , casting back to DWORD: 0x%08x \n",value,(DWORD)value);
        break;

     case CMD_GET_CHSTATE:
       channel = va_arg(argptr, INT);
       pstate = (DWORD *) va_arg (argptr, DWORD *);
       printf("pvalue arriving with value 0x%08x\n",(DWORD)*pstate);
       *pstate = 0x000000FF;

       
       break;
        
     case CMD_GET:
       channel = va_arg(argptr, INT);
       pvalue = va_arg(argptr, float *);
       *pvalue = 9.3;
       break;
       
  
     default:
        break;
     }

   va_end(argptr);

   return status;
}
