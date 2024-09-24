#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define W_MAX 100
#define W_MIN 16
#define W_DEFAULT 40

void writeline(char *s, char *e)
{
	do
	{
		if( *s=='\0' )
			return;
		putchar(*s);
		s++;
	}
	while(s<=e);
}

int main(int argc, char *argv[])
{
	static char *text = "Shall I compare thee to a summer's day? \
Thou art more lovely and more temperate:\n\
Rough winds do shake the darling buds of May, \
And summer's lease hath all too short a date;\n\
Sometime too hot the eye of heaven shines, \
And often is his gold complexion dimm'd;\n\
And every fair from fair sometime declines, \
By chance or nature's changing course untrimm'd;\n\
But thy eternal summer shall not fade, \
Nor lose possession of that fair thou ow'st;\n\
Nor shall death brag thou wander'st in his shade, \
When in eternal lines to time thou grow'st:\n\
So long as men can breathe or eyes can see, \
So long lives this, and this gives life to thee.";
	char *start,*end;
	int width;

	width = W_DEFAULT;
	if( argc>1 )
	{
		width = strtol(argv[1],NULL,10);
		if( width<W_MIN || width>W_MAX )
			width=W_DEFAULT;
	}

	start = end = text;
	while( *end )
	{
		if( *end=='\n')
		{
			writeline(start,end);
			end++;
			start = end;
		}
		else
		{
			end++;
			if( end==start+width )
			{
				while( !isspace(*end) )
				{
					end--;
					if( start==end )
					{
						end+=width;
						break;
					}
				}
				writeline(start,end);
				if( *end != '\n')
					putchar('\n');
				end++;
				start = end;
			}
		}
	}
	writeline(start,end);
	if( *end != '\n')
		putchar('\n');

	return(0);
}
