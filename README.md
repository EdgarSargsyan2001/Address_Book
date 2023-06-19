# Address_Book

***!compile only main.cpp***

+ When running the program, you will receive a warning if you do not have an input file, but this will not cause the program to crash.
  
+ At the end of the program, you will be given a file named "addressData" where the saved data will be,
and after that, every time you run the program, it will be considered an input file.

+ If the data in the input file is not valid, the program will give you the opportunity to edit or remove that data

+ After that, the program will be completely ready for work and a list will be given in the console with which you can:

0. exit
      > this command will terminate the program and save the data in the file. Always verify the 
       data before using this command so that incorrect information is not saved.
      
1. see all contact information
      > displays all addresses by their id.
        
2. search in contact information
      > you can search by both first name and last name and you can consider that field 
      > by setting "#" after which all found contacts will be displayed.
       
3. add new contact information
      > by entering the appropriate dashes, you can add a new contact: if a field is entered incorrectly, it will require re-entering.
    
     
4. select contact with id
      > you can select the contact by its id after which you will be given a list in which you can:
     **0: go back**
            +return to the main menu
     **1: change name**
            +If the input is not valid, it will ask for input again
     **2: change surname**
            +If the input is not valid, it will ask for input again
     **3: change number**
            +If the input is not valid, it will ask for input again
     **4: change email**
            +If the input is not valid, it will ask for input again
     **5. delete**
            +will remove the contact and return to the main menu.

**5. save data in file:**
     >will save the entire contents of the file.
     ***!it is important to note that after each operation the data is not saved to the file and you have to do it with this command***
