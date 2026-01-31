#include <stdio.h>
#include <string.h>
  
int main (){
 printf("                                       Wellcome to NOTEPAD          \n\n\n"); //just the welcome text
 char user_choice[20];
 printf("Enter 'NEW' for a new text file\nEnter 'OLD_FILE' for existing file\nEnter 'EXIT' to exit the function\n\n\n"); //asking for user input
 printf("Enter you choice: ");
 scanf("%s", &user_choice); 
 char filename [100];  //you may ask why is this here instead of inside the if statement. the answer is that, just so I can store user input of filename for both new file and exististing file.
          FILE *pfile;
 if(strcmp(user_choice, "NEW")==0){   //comparing the existing data with the use input to know what the user wants
                  //declaring an array to store the string user will input 
     printf("\nEnter new file name: ");
     scanf("%s", filename);
     
     pfile = fopen (filename,"w");        
     if(pfile == NULL){            //checking if the the file creating procedure has any error in it 
         printf("ERROR!!!");
         return 1;   
     }else {
         char text[1024];   //taking the user text that user wants to store
         printf("\nAfter writing the text tap enter to save and exit\nType your text here: ");
         getchar(); 
         fgets(text, sizeof text, stdin);
         fputs(text,pfile);
     }
     fclose(pfile);
 }else if(strcmp(user_choice, "OLD_FILE")==0){
     printf("\nEnter the name of the file you want to open: ");
     scanf("%s", filename);
     pfile = fopen (filename, "r");
     if(pfile == NULL){
         printf("The file doesn't exist");
         return 1;
     }
     char truck [1024] = {0};
     while(fgets(truck, sizeof (truck), pfile) != NULL){
        printf("%s", truck);
     }
     fclose(pfile);
 }else if(strcmp(user_choice, "EXIT")==0){ //donno why I kept this but anyways. no one mind having an additional button or option, right? it's just an escape sequence btw
     return 0;
 }else{
     printf("Your input doesn't exit\nRun the program again");    //just in case user inputs garbage value as input instead of proper instructions that are already stored in the code
 }
        
    return 0;
}