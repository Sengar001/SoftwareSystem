/*
================================================================================================================
Name: 26a.c
Author: Abhishek Singh Sengar
Description:Write a program to execute an executable program.
		a. use some executable program
Date: 29 Aug 2024
================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
int main(){
	execl("/bin/ls","ls",NULL);
	return 0;
}

/*
================================================
Output: ./a.out
10.c   14.c   18a.c  1c.c  25.c   27d.c  3.c  9.c	File1		soft.txt
11a.c  15.c   18b.c  20.c  26a.c  27e.c  4.c  a.out	filedescriptor	t2.txt
11b.c  16a.c  18c.c  21.c  26b.c  28.c	 5.c  dup.txt	hardlink	temp.txt
11c.c  16b.c  19.c   22.c  27a.c  29.c	 6.c  f1.txt	line.txt	ticket.txt
12.c   17a.c  1a.c   23.c  27b.c  2.c	 7.c  f2.txt	new.txt
13.c   17b.c  1b.c   24.c  27c.c  30.c	 8.c  fifo.txt	softlink

================================================
*/

