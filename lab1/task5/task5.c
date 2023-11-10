#include<stdio.h>

/// @brief 
/// @param argc 
/// @param argv 
/// @return 
int main(int argc, char *argv[]){
   if(argc < 2){
      printf("Error, try again\n");
      return 1;
   }

   FILE *file = fopen(argv[1], "r");
   if (file==NULL){
      printf("Error, file is empty... Try again!\n");
      return 1;
   }

   char ch;
   while ((ch = fgetc(file)) != EOF){
      putchar(ch);
<<<<<<< HEAD
      
   }fclose(file);
=======
     
   } fclose(file);
>>>>>>> 652f1542a95b91c4a6e3bda5fd0dffd02832895d
}