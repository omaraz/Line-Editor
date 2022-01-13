/**Line Editor code 
 * using the keyboard Buffer
*/

#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
	char str[100]; // limit of input is 99 chars and 1 Byte resurvied to NULL char
	int x=1,y=1,flag=1,i=0; //x and y are indexes of gotoxy() 
							// flag is used in do while loop
							// i is used as index for the str
	clrscr();

	gotoxy(x,y); //function gotoxy() used to let the program access the line  and columnin the counsle
	cout<<"Enter Any words you want:"<<endl;
	y=2; // seting the y value line
      do{
	flushall();


	char test; //the input from the keyboard
	test = getche();

	if(isalnum(test)){//if it is a letter or number put it in the array of char
	    str[i]=test;
	    i++;}

	else if(test == 0){ //if it is an extended key then check which one
		test = getch();
		if(int(test) == 77){ //left arrow ->
		x++;
		}
		else if (int(test) == 75){//right arrow ->
		x--;
		if (x<1){
		x=1;}
	
		gotoxy(x,y);}
			
		else if (int(test) == 71){//if it is home then move to the start of the line

		  gotoxy(1,y);}
		else if(int(test) == 79){//if it is End then move to the end of the line
                  x=i;
		  gotoxy(x,y); }
                  }
	else{//if it is a normal key 

	        if(int(test) == 13){//if it is enter print the array of char in the next line
	       //	clrscr();
		  y++;
		  str[i]=0;
		  cout<<endl<<str;
		  }
		else if(int(test) == 27){//if it is Esc print 2 seconds left then close
		clrscr();
		cout<<endl<<"program will exit in 2 Seconds!";
	       sleep(2);
	       flag =0; // change the flag to exit while loop
		}
	}
	//clrscr();
	 }while(flag);


return 0;}