#include "msgothic9.h"
#include <nds.h>

using namespace WoopsiUI;

static const u16 MSGothic9_glyphdata[273] = {
/* '!' */	0xAA8C,0x0000,
/* '"' */	0xB680,0x0000,
/* '#' */	0x57D4,0xAFA9,0x4000,0x0000,
/* '$' */	0x23AB,0x4716,0xAE20,0x0000,
/* '%' */	0xCEB4,0x45AE,0x6000,0x0000,
/* '&' */	0x2288,0xC9C9,0xA000,0x0000,
/* ''' */	0x5800,0x0000,
/* '(' */	0x2A49,0x2220,
/* ')' */	0x8892,0x4A80,
/* '*' */	0x255C,0xEA90,0x0000,0x0000,
/* '+' */	0x0974,0x8000,
/* ',' */	0x0036,0x0000,
/* '-' */	0x000F,0x0000,0x0000,
/* '.' */	0x000C,0x0000,
/* '/' */	0x1122,0x4488,0x0000,
/* '0' */	0x6999,0x9960,0x0000,
/* '1' */	0x7554,0x0000,
/* '2' */	0x6912,0x48F0,0x0000,
/* '3' */	0x6916,0x1960,0x0000,
/* '4' */	0x3194,0xA97C,0x4000,0x0000,
/* '5' */	0xF8E1,0x1960,0x0000,
/* '6' */	0x698E,0x9960,0x0000,
/* '7' */	0xF122,0x4440,0x0000,
/* '8' */	0x6996,0x9960,0x0000,
/* '9' */	0x6997,0x1960,0x0000,
/* ':' */	0x300C,0x0000,
/* ';' */	0x3036,0x0000,
/* '<' */	0x1248,0x4210,0x0000,
/* '=' */	0x00F0,0xF000,0x0000,
/* '>' */	0x8421,0x2480,0x0000,
/* '?' */	0x6912,0x2022,0x0000,
/* '@' */	0x746F,0x5BC1,0xC000,0x0000,
/* 'A' */	0x6699,0xF990,0x0000,
/* 'B' */	0xE99E,0x99E0,0x0000,
/* 'C' */	0x6988,0x8960,0x0000,
/* 'D' */	0xE999,0x99E0,0x0000,
/* 'E' */	0xF88E,0x88F0,0x0000,
/* 'F' */	0xF88E,0x8880,0x0000,
/* 'G' */	0x698B,0x9970,0x0000,
/* 'H' */	0x999F,0x9990,0x0000,
/* 'I' */	0xFE00,
/* 'J' */	0x1111,0x1960,0x0000,
/* 'K' */	0x99AC,0xA990,0x0000,
/* 'L' */	0x8888,0x88F0,0x0000,
/* 'M' */	0x8C77,0xBAD6,0xA000,0x0000,
/* 'N' */	0x99DD,0xBB90,0x0000,
/* 'O' */	0x6999,0x9960,0x0000,
/* 'P' */	0xE999,0xE880,0x0000,
/* 'Q' */	0x6999,0xDA50,0x0000,
/* 'R' */	0xE99E,0x9990,0x0000,
/* 'S' */	0x6986,0x1960,0x0000,
/* 'T' */	0xF444,0x4440,0x0000,
/* 'U' */	0x9999,0x9960,0x0000,
/* 'V' */	0x8C62,0xA510,0x8000,0x0000,
/* 'W' */	0xAD6B,0x5529,0x4000,0x0000,
/* 'X' */	0x9966,0x6990,0x0000,
/* 'Y' */	0x8C54,0x4210,0x8000,0x0000,
/* 'Z' */	0xF122,0x48F0,0x0000,
/* '[' */	0xEAAA,0xC000,
/* '\' */	0x8A89,0xE278,0x8000,0x0000,
/* ']' */	0xD555,0xC000,
/* '^' */	0x5400,0x0000,
/* '_' */	0x0000,0x0000,0x1F00,0x0000,
/* '`' */	0x9000,0x0000,
/* 'a' */	0x00E1,0x7970,0x0000,
/* 'b' */	0x88E9,0x99E0,0x0000,
/* 'c' */	0x0069,0x8960,0x0000,
/* 'd' */	0x1179,0x9970,0x0000,
/* 'e' */	0x0069,0xF870,0x0000,
/* 'f' */	0x64F4,0x4440,0x0000,
/* 'g' */	0x005A,0xA4B9,0x0000,
/* 'h' */	0x88E9,0x9990,0x0000,
/* 'i' */	0xBE00,
/* 'j' */	0x2092,0x4F00,
/* 'k' */	0x889A,0xE990,0x0000,
/* 'l' */	0xFE00,
/* 'm' */	0x0035,0x5AD6,0xA000,0x0000,
/* 'n' */	0x00E9,0x9990,0x0000,
/* 'o' */	0x0069,0x9960,0x0000,
/* 'p' */	0x00E9,0x9E88,0x0000,
/* 'q' */	0x0079,0x9711,0x0000,
/* 'r' */	0x02E9,0x2000,
/* 's' */	0x0078,0x61E0,0x0000,
/* 't' */	0x44F4,0x4460,0x0000,
/* 'u' */	0x0099,0x9960,0x0000,
/* 'v' */	0x0099,0x9660,0x0000,
/* 'w' */	0x002B,0x5AA9,0x4000,0x0000,
/* 'x' */	0x0096,0x6990,0x0000,
/* 'y' */	0x0099,0x5224,0x0000,
/* 'z' */	0x00F2,0x48F0,0x0000,
/* '{' */	0x6928,0x9260,
/* '|' */	0xFF80,
/* '}' */	0xC922,0x92C0,
/* '~' */	0x5A00,0x0000,0x0000,
/* 0x7F */	0xF999,0x9F00,0x0000,
};

static const u16 MSGothic9_offset[95] = {
    0,    2,    4,    8,   12,   16,   20,   22,   24,   26,   30,   32,   34,   37,   39,   42,
   45,   47,   50,   53,   57,   60,   63,   66,   69,   72,   74,   76,   79,   82,   85,   88,
   92,   95,   98,  101,  104,  107,  110,  113,  116,  117,  120,  123,  126,  130,  133,  136,
  139,  142,  145,  148,  151,  154,  158,  162,  165,  169,  172,  174,  178,  180,  182,  186,
  188,  191,  194,  197,  200,  203,  206,  209,  212,  213,  215,  218,  219,  223,  226,  229,
  232,  235,  237,  240,  243,  246,  249,  253,  256,  259,  262,  264,  265,  267,  270
};

static const u8 MSGothic9_width[95] = {
 2, 3, 5, 5, 5, 5, 2, 3, 3, 5, 3, 2, 4, 2, 4, 4,
 2, 4, 4, 5, 4, 4, 4, 4, 4, 2, 2, 4, 4, 4, 4, 5,
 4, 4, 4, 4, 4, 4, 4, 4, 1, 4, 4, 4, 5, 4, 4, 4,
 4, 4, 4, 4, 4, 5, 5, 4, 5, 4, 2, 5, 2, 3, 5, 2,
 4, 4, 4, 4, 4, 4, 4, 4, 1, 3, 4, 1, 5, 4, 4, 4,
 4, 3, 4, 4, 4, 4, 5, 4, 4, 4, 3, 1, 3, 4, 4
};

MSGothic9::MSGothic9(u8 fixedWidth) : PackedFont1 (
	33,
	127,
	MSGothic9_glyphdata,
	MSGothic9_offset,
	MSGothic9_width,
	10,
	3,
	5) {
	if (fixedWidth) setFontWidth(fixedWidth);
};
