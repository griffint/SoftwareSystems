/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
	if (strstr(tracks[i], search_for)) {
	    printf("Track %i: '%s'\n", i, tracks[i]);
	}
    }
}

// Finds all tracks that match the given pattern.
//
// Prints track number and title.
void find_track_regex(char pattern[])
{
    printf("in regex finder for pattern: %s",pattern);
    int    status;
    regex_t    re;
    regmatch_t matches[5];

    regcomp(&re, pattern, REG_EXTENDED);
   
    int x;
    for (x=0; x<5; x++)
    {
        char* string = tracks[x];
        status = regexec(&re, tracks[x], 5, matches, 0); 
      
        if (status != 0) 
        {
            printf("regex - no track found\n");      /* Report error. */
        }
        else
        {
            printf("found our track\n");
        }
    }

    regfree(&re);
    
    printf("\ndone with the for loop\n");

    //Example of how this should look
    /*
        int regcomp(regex_t *preg, const char *pattern, int cflags);
        int regexec(const regex_t *preg, const char *string,
            size_t nmatch, regmatch_t pmatch[], int eflags);
        size_t regerror(int errcode, const regex_t *preg,
            char *errbuf, size_t errbuf_size);
        void regfree(regex_t *preg);
    */
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
	*ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);
    printf("not even in regex yet\n");
    //find_track(search_for);
    find_track_regex(search_for);

    return 0;
}
