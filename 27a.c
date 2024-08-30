/*
================================================================================================================
Name: 27a.c
Author: Abhishek Singh Sengar
Description: Write a program to execute ls -Rl by the following system calls
		a. execl	
Date: 29 Aug 2024
================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
int main(){
	execl("/bin/ls","ls"."-Rl",NULL);
	return 0;
}

/*
==================================================================================
Output: ./a.out
total 240
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1013 Aug 30 14:26 10.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1054 Aug 30 14:32 11a.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1037 Aug 30 14:35 11b.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1016 Aug 30 15:42 11c.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1047 Aug 30 15:01 12.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar   990 Aug 30 15:05 13.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1365 Aug 30 15:11 14.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  3984 Aug 30 15:26 15.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1063 Aug 30 15:39 16a.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1000 Aug 30 15:41 16b.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1012 Aug 30 16:33 17a.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1595 Aug 30 16:41 17b.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1154 Aug 30 16:45 18a.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1988 Aug 30 16:49 18b.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1620 Aug 30 16:54 18c.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar   908 Aug 30 16:58 19.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar   626 Aug 30 12:51 1a.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar   616 Aug 30 12:50 1b.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar   611 Aug 30 13:02 1c.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar   769 Aug 30 17:01 20.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar   688 Aug 30 17:04 21.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar   963 Aug 30 17:40 22.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar   847 Aug 30 17:45 23.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar   625 Aug 30 17:47 24.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1351 Aug 30 17:51 25.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1007 Aug 30 17:57 26a.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1267 Aug 30 18:03 26b.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1069 Aug 30 18:06 27a.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1071 Aug 30 18:08 27b.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1094 Aug 30 18:09 27c.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar   501 Aug 30 18:14 27d.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar   108 Aug 29 22:28 27e.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar   585 Aug 29 23:02 28.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1225 Aug 30 10:44 29.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar   641 Aug 30 13:07 2.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar   508 Aug 30 11:40 30.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar   659 Aug 30 13:14 3.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar   718 Aug 30 13:17 4.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar   761 Aug 30 14:02 5.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar   736 Aug 30 14:06 6.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar   912 Aug 30 14:11 7.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1042 Aug 30 14:16 8.c
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar  1900 Aug 30 14:20 9.c
-rwxrwxr-x 1 abhishek-singh-sengar abhishek-singh-sengar 16008 Aug 30 18:14 a.out
-rwxrwxr-x 1 abhishek-singh-sengar abhishek-singh-sengar 15960 Aug 30 18:01 b.out
-rwxrwxr-x 1 abhishek-singh-sengar abhishek-singh-sengar    50 Aug 14 19:43 dup.txt
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar    30 Aug 30 14:09 f1.txt
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar    45 Aug 30 14:09 f2.txt
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar     0 Aug 30 12:52 fifo.txt
---------- 1 abhishek-singh-sengar abhishek-singh-sengar     0 Aug 30 13:16 File1
-rwxr-xr-x 1 abhishek-singh-sengar abhishek-singh-sengar     0 Aug 30 13:11 filedescriptor
-rw-rw-r-- 2 abhishek-singh-sengar abhishek-singh-sengar    30 Aug 30 17:39 hardlink
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar    80 Aug 27 22:27 line.txt
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar    47 Aug 30 14:36 new.txt
lrwxrwxrwx 1 abhishek-singh-sengar abhishek-singh-sengar     8 Aug 30 12:28 softlink -> soft.txt
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar     0 Aug 30 12:25 soft.txt
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar    24 Aug 29 16:45 t2.txt
-rw-rw-r-- 2 abhishek-singh-sengar abhishek-singh-sengar    30 Aug 30 17:39 temp.txt
-rw-rw-r-- 1 abhishek-singh-sengar abhishek-singh-sengar    24 Aug 30 16:49 ticket.txt


==================================================================================
*/


