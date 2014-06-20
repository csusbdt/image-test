#include <stdio.h>
#define STB_TRUETYPE_IMPLEMENTATION
#include "stb_truetype.h"

char ttf_buffer[1<<25];

const char * ttf_file = "../CaviarDreams.ttf";

int main(int argc, char **argv)
{
	stbtt_fontinfo font;
	unsigned char * bitmap;
	int w, h, i, j;
	int c = 'w';
	int s = 30;

	fread(ttf_buffer, 1, 1<<25, fopen(ttf_file, "rb"));

	stbtt_InitFont(&font, ttf_buffer, stbtt_GetFontOffsetForIndex(ttf_buffer, 0));
	bitmap = stbtt_GetCodepointBitmap(&font, 0, stbtt_ScaleForPixelHeight(&font, s), c, &w, &h, 0, 0);

	for (j = 0; j < h; ++j) {
		for (i = 0; i < w; ++i) {
			putchar(" .:ioVM@"[bitmap[j * w + i] >> 5]);
		}
		putchar('\n');
	}
	return 0;
}
