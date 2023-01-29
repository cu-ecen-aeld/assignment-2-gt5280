/**
*ECEN 5713, Spring 2023
*Description: writer.c function, assignment 2
*first argument of filepath
*second argument a string to write to file, and log using syslog
*Author: Nelson Rodriguez
*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include"unistd.h"
#include<syslog.h>
  
int main(int argc,char* argv[])
{
	    /*declare variable to hold file pointer*/
		int fd;
		/*initiate syslog to default user*/
		openlog("writer_log", 0, LOG_USER); 
  
    if(argc==3)
    {
		/*declare variable to hold return from syscall*/
		ssize_t nr;
		/*declare char pointer to hold string from argument 2*/
		const char *buf = argv[2]; 
		
		fd = open ( argv[1], O_WRONLY | O_CREAT, 0777 );
				
		if (fd == -1){
			syslog(LOG_ERR, "open");
			return 1;
		}
		else{
			nr = write (fd, buf, strlen(buf));
			syslog(LOG_DEBUG, "Writing %s to %s", buf, argv[1]);
		}
		if (nr == -1)
			syslog(LOG_ERR, "error while writing to file");
		
		if (close (fd) == -1)
			syslog(LOG_ERR, "close");
    }
	else{
			syslog(LOG_DEBUG, "incorrect number of arguments," 
					"expecting two arguments, filepath and string");
			return 1;
	}

		closelog();
		
    return 0;
}
