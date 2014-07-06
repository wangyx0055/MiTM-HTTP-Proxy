#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <regex.h>
#include "utils.h"

#ifndef REGEX_H_
#define REGEX_H_

typedef struct{
    int start;
    int end;
} Range;

typedef struct{
    regex_t r;
    const char * search;
    Range o;
} Regex;

struct __TAGS__{
     Regex* a,
          * link,
          * iframe,
          * script;
} HTML_TAGS;

struct __ATTRIBUTES__{
    Regex* href,
         * src;
} HTML_ATTR;

void generateRegexes();

int matchRegex (const char* string, Range* range, Regex* reg);

Regex* compileRegex(const char* reg);


void freeRegex(Regex* r);

void freeRegexes();

int findLink(const char* string, Range* r);


#endif