#include "kartika9.h"
#include <nds.h>

using namespace WoopsiUI;

static const u16 Kartika9_glyphdata[269] = {
/* '!' */	0xF400,
/* '"' */	0xB400,0x0000,
/* '#' */	0x51BE,0xEF70,0x0000,0x0000,
/* '$' */	0x27BA,0x7B72,0x0000,
/* '%' */	0xE953,0xC0F2,0xA5C0,0x0000,0x0000,
/* '&' */	0x7289,0xF9BC,0x0000,0x0000,
/* ''' */	0xC000,
/* '(' */	0x6AA9,0x0000,
/* ')' */	0xA55A,0x0000,
/* '*' */	0xF400,0x0000,
/* '+' */	0x0109,0xF210,0x0000,0x0000,
/* ',' */	0x0600,
/* '-' */	0x0300,0x0000,
/* '.' */	0x0400,
/* '/' */	0x16A0,0x0000,
/* '0' */	0x6999,0x9600,0x0000,
/* '1' */	0x7550,0x0000,
/* '2' */	0x6912,0x4F00,0x0000,
/* '3' */	0x7921,0x1E00,0x0000,
/* '4' */	0x1194,0xAF88,0x0000,0x0000,
/* '5' */	0xF8E1,0x1E00,0x0000,
/* '6' */	0x78E9,0x9600,0x0000,
/* '7' */	0xF122,0x4400,0x0000,
/* '8' */	0x6969,0x9600,0x0000,
/* '9' */	0x6997,0x1E00,0x0000,
/* ':' */	0x2400,
/* ';' */	0x2600,
/* '<' */	0x016C,0x3000,0x0000,
/* '=' */	0x00F0,0xF000,0x0000,
/* '>' */	0x0863,0xC000,0x0000,
/* '?' */	0x7912,0x0200,0x0000,
/* '@' */	0x1E63,0x9FA5,0xA5BE,0x403C,0x0000,
/* 'A' */	0x2294,0xE8C4,0x0000,0x0000,
/* 'B' */	0xE9E9,0x9E00,0x0000,
/* 'C' */	0x7461,0x08B8,0x0000,0x0000,
/* 'D' */	0xF463,0x18F8,0x0000,0x0000,
/* 'E' */	0xF8F8,0x8F00,0x0000,
/* 'F' */	0xF3C9,0x0000,
/* 'G' */	0x7461,0x38BC,0x0000,0x0000,
/* 'H' */	0x99F9,0x9900,0x0000,
/* 'I' */	0xFC00,
/* 'J' */	0x249B,0x8000,
/* 'K' */	0x9531,0x4944,0x0000,0x0000,
/* 'L' */	0x8888,0x8F00,0x0000,
/* 'M' */	0x8EF7,0x5AD4,0x0000,0x0000,
/* 'N' */	0x8E6B,0x59C4,0x0000,0x0000,
/* 'O' */	0x7463,0x18B8,0x0000,0x0000,
/* 'P' */	0xE99E,0x8800,0x0000,
/* 'Q' */	0x7463,0x19B8,0x2000,0x0000,
/* 'R' */	0xE4A5,0xC944,0x0000,0x0000,
/* 'S' */	0x6961,0x9600,0x0000,
/* 'T' */	0xF908,0x4210,0x0000,0x0000,
/* 'U' */	0x8C63,0x18B8,0x0000,0x0000,
/* 'V' */	0x8C94,0xA610,0x0000,0x0000,
/* 'W' */	0x9325,0xAB66,0xC480,0x0000,0x0000,
/* 'X' */	0x8A88,0x4544,0x0000,0x0000,
/* 'Y' */	0x8A94,0x4210,0x0000,0x0000,
/* 'Z' */	0xF888,0x887C,0x0000,0x0000,
/* '[' */	0xEAAB,0x0000,
/* '\' */	0xA940,0x0000,
/* ']' */	0xD557,0x0000,
/* '^' */	0x5400,0x0000,
/* '_' */	0x0000,0x0000,0x1F00,0x0000,
/* '`' */	0x9000,0x0000,
/* 'a' */	0x00E7,0x9700,0x0000,
/* 'b' */	0x88E9,0x9E00,0x0000,
/* 'c' */	0x03C9,0xC000,
/* 'd' */	0x1179,0x9700,0x0000,
/* 'e' */	0x006F,0x8700,0x0000,
/* 'f' */	0xEEA0,0x0000,
/* 'g' */	0x0079,0x971E,0x0000,
/* 'h' */	0x88E9,0x9900,0x0000,
/* 'i' */	0xBC00,
/* 'j' */	0xBF00,
/* 'k' */	0x88AC,0xA900,0x0000,
/* 'l' */	0xFC00,
/* 'm' */	0x0037,0x5AD4,0x0000,0x0000,
/* 'n' */	0x00E9,0x9900,0x0000,
/* 'o' */	0x0069,0x9600,0x0000,
/* 'p' */	0x00E9,0x9E88,0x0000,
/* 'q' */	0x0079,0x9711,0x0000,
/* 'r' */	0x0EA0,0x0000,
/* 's' */	0x03E3,0xC000,
/* 't' */	0x2EB0,0x0000,
/* 'u' */	0x0099,0x9700,0x0000,
/* 'v' */	0x02D4,0x8000,
/* 'w' */	0x002B,0x5728,0x0000,0x0000,
/* 'x' */	0x02AB,0x4000,
/* 'y' */	0x0095,0x622C,0x0000,
/* 'z' */	0x00F2,0x4F00,0x0000,
/* '{' */	0x5755,0x0000,
/* '|' */	0xFF00,
/* '}' */	0x4934,0x9600,
/* '~' */	0xC300,0x0000,0x0000,
/* 0x7F */	0xF999,0x9999,0xF000,
};

static const u16 Kartika9_offset[95] = {
    0,    1,    3,    7,   10,   15,   19,   20,   22,   24,   26,   30,   31,   33,   34,   36,
   39,   41,   44,   47,   51,   54,   57,   60,   63,   66,   67,   68,   71,   74,   77,   80,
   85,   89,   92,   96,  100,  103,  105,  109,  112,  113,  115,  119,  122,  126,  130,  134,
  137,  141,  145,  148,  152,  156,  160,  165,  169,  173,  177,  179,  181,  183,  185,  189,
  191,  194,  197,  199,  202,  205,  207,  210,  213,  214,  215,  218,  219,  223,  226,  229,
  232,  235,  237,  239,  241,  244,  246,  250,  252,  255,  258,  260,  261,  263,  266
};

static const u8 Kartika9_width[95] = {
 1, 3, 5, 4, 7, 5, 1, 2, 2, 3, 5, 1, 2, 1, 2, 4,
 2, 4, 4, 5, 4, 4, 4, 4, 4, 1, 1, 4, 4, 4, 4, 8,
 5, 4, 5, 5, 4, 3, 5, 4, 1, 3, 5, 4, 5, 5, 5, 4,
 5, 5, 4, 5, 5, 5, 7, 5, 5, 5, 2, 2, 2, 3, 5, 2,
 4, 4, 3, 4, 4, 2, 4, 4, 1, 1, 4, 1, 5, 4, 4, 4,
 4, 2, 3, 2, 4, 3, 5, 3, 4, 4, 2, 1, 3, 4, 4
};

Kartika9::Kartika9(u8 fixedWidth) : PackedFont1 (
	33,
	127,
	Kartika9_glyphdata,
	Kartika9_offset,
	Kartika9_width,
	10,
	3,
	8) {
	if (fixedWidth) setFontWidth(fixedWidth);
};
