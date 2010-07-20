#include "courier12b.h"
#include <nds.h>

using namespace WoopsiUI;

static const u16 Courier12b_glyphdata[496] = {
/* '!' */	0xFFFC,0xC000,
/* '"' */	0xFFF0,0x0000,0x0000,
/* '#' */	0x1E1E,0x7F3C,0x3C3C,0xFE78,0x7800,0x0000,
/* '$' */	0x31EC,0xF078,0x3CDE,0x3000,0x0000,
/* '%' */	0x60F3,0x660C,0x1830,0x66CF,0x0600,0x0000,
/* '&' */	0x3860,0x6030,0x70DB,0xDECC,0x7F00,0x0000,
/* ''' */	0xFC00,0x0000,
/* '(' */	0x366C,0xCCCC,0x6630,
/* ')' */	0xC663,0x3333,0x66C0,
/* '*' */	0x0000,0x7E3C,0xFF3C,0x7E00,0x0000,0x0000,
/* '+' */	0x0000,0x1818,0x18FF,0x1818,0x1800,0x0000,
/* ',' */	0x0000,0x0078,0x0000,
/* '-' */	0x0000,0x0000,0x00FF,0x0000,0x0000,0x0000,
/* '.' */	0x0000,0xC000,
/* '/' */	0x0003,0x060C,0x1830,0x60C0,0x0000,0x0000,
/* '0' */	0x7B3C,0xF3CF,0x3CF3,0x7800,0x0000,
/* '1' */	0x33C3,0x0C30,0xC30C,0xFC00,0x0000,
/* '2' */	0x7B30,0xC318,0xC630,0xFC00,0x0000,
/* '3' */	0x7B30,0xC338,0x30F3,0x7800,0x0000,
/* '4' */	0x18E3,0x9E7B,0x6FC6,0x3C00,0x0000,
/* '5' */	0xFF0C,0x30F8,0x30F3,0x7800,0x0000,
/* '6' */	0x398C,0x30FB,0x3CF3,0x7800,0x0000,
/* '7' */	0xFF30,0xC618,0xC318,0x6000,0x0000,
/* '8' */	0x7B3C,0xF37B,0x3CF3,0x7800,0x0000,
/* '9' */	0x7B3C,0xF37C,0x30C6,0x7000,0x0000,
/* ':' */	0x0300,0xC000,
/* ';' */	0x0030,0x0078,0x0000,
/* '<' */	0x0006,0x6661,0x8618,0x0000,
/* '=' */	0x0000,0x3F03,0xF000,0x0000,0x0000,
/* '>' */	0x0030,0xC30C,0xCCC0,0x0000,
/* '?' */	0x7B30,0xC318,0xC300,0x3000,0x0000,
/* '@' */	0x3E63,0xDFFF,0xFFFF,0xDE60,0x3C00,0x0000,
/* 'A' */	0x3818,0x183C,0x3C66,0x7E66,0xFF00,0x0000,
/* 'B' */	0xFE63,0x6363,0x7E63,0x6363,0xFE00,0x0000,
/* 'C' */	0x3E63,0xC0C0,0xC0C0,0xC063,0x3E00,0x0000,
/* 'D' */	0xFC66,0x6363,0x6363,0x6366,0xFC00,0x0000,
/* 'E' */	0xFF63,0x606C,0x7C6C,0x6063,0xFF00,0x0000,
/* 'F' */	0xFF63,0x606C,0x7C6C,0x6060,0xF800,0x0000,
/* 'G' */	0x3E63,0xC0C0,0xC0CF,0xC363,0x3E00,0x0000,
/* 'H' */	0xFF66,0x6666,0x7E66,0x6666,0xFF00,0x0000,
/* 'I' */	0xFCC3,0x0C30,0xC30C,0xFC00,0x0000,
/* 'J' */	0x3E18,0x3060,0xC1B3,0x6678,0x0000,0x0000,
/* 'K' */	0xF766,0x6C6C,0x7878,0x6C66,0xF700,0x0000,
/* 'L' */	0xFC30,0x3030,0x3030,0x3033,0xFF00,0x0000,
/* 'M' */	0xE766,0x7E7E,0x7E7E,0x6666,0xFF00,0x0000,
/* 'N' */	0xEF66,0x7676,0x7E6E,0x6E66,0xF600,0x0000,
/* 'O' */	0x3C66,0xC3C3,0xC3C3,0xC366,0x3C00,0x0000,
/* 'P' */	0xFE63,0x6363,0x7E60,0x6060,0xF800,0x0000,
/* 'Q' */	0x3C66,0xC3C3,0xC3C3,0xC366,0x3C3F,0x0000,
/* 'R' */	0xFE63,0x6363,0x7E6C,0x6C66,0xF700,0x0000,
/* 'S' */	0x7EC3,0xC0C0,0x7E03,0x03C3,0x7E00,0x0000,
/* 'T' */	0xFFDB,0x1818,0x1818,0x1818,0x3C00,0x0000,
/* 'U' */	0xFF66,0x6666,0x6666,0x6666,0x3C00,0x0000,
/* 'V' */	0xFF66,0x6666,0x3C3C,0x3C18,0x1800,0x0000,
/* 'W' */	0xFF66,0x6666,0x7E7E,0x7E3C,0x3C00,0x0000,
/* 'X' */	0xFF66,0x3C3C,0x183C,0x3C66,0xFF00,0x0000,
/* 'Y' */	0xFF66,0x663C,0x3C18,0x1818,0x3C00,0x0000,
/* 'Z' */	0xFFC6,0x0C0C,0x1830,0x3063,0xFF00,0x0000,
/* '[' */	0xFCCC,0xCCCC,0xCCF0,
/* '\' */	0x00C0,0x6030,0x180C,0x0603,0x0000,0x0000,
/* ']' */	0xF333,0x3333,0x33F0,
/* '^' */	0x31EC,0xC000,0x0000,0x0000,0x0000,
/* '_' */	0x0000,0x0000,0x0000,0x0000,0x0000,0x003F,0xE000,
/* '`' */	0xCC00,0x0000,0x0000,
/* 'a' */	0x0000,0x007C,0x067E,0xC6C6,0x7F00,0x0000,
/* 'b' */	0xE060,0x607E,0x6363,0x6363,0xFE00,0x0000,
/* 'c' */	0x0000,0x007E,0xC3C0,0xC0C3,0x7E00,0x0000,
/* 'd' */	0x0E06,0x067E,0xC6C6,0xC6C6,0x7F00,0x0000,
/* 'e' */	0x0000,0x007E,0xC3FF,0xC0C3,0x7E00,0x0000,
/* 'f' */	0x3B19,0xF631,0x8CF8,0x0000,
/* 'g' */	0x0000,0x007F,0xC6C6,0xC67E,0x0606,0x7C00,
/* 'h' */	0xE060,0x607C,0x7666,0x6666,0xFF00,0x0000,
/* 'i' */	0x3000,0x3C30,0xC30C,0xFC00,0x0000,
/* 'j' */	0x1801,0xF18C,0x6318,0xFC00,
/* 'k' */	0xE060,0x606E,0x6C78,0x786C,0xE700,0x0000,
/* 'l' */	0x70C3,0x0C30,0xC30C,0xFC00,0x0000,
/* 'm' */	0x0000,0x00FC,0x7E7E,0x7E7E,0xFF00,0x0000,
/* 'n' */	0x0000,0x00FC,0x7666,0x6666,0xFF00,0x0000,
/* 'o' */	0x0000,0x007E,0xC3C3,0xC3C3,0x7E00,0x0000,
/* 'p' */	0x0000,0x00FE,0x6363,0x6363,0x7E60,0xF000,
/* 'q' */	0x0000,0x007F,0xC6C6,0xC6C6,0x7E06,0x0F00,
/* 'r' */	0x0000,0x00FE,0x3B30,0x3030,0xFC00,0x0000,
/* 's' */	0x0000,0x007E,0xC378,0x0EC3,0x7E00,0x0000,
/* 't' */	0x0186,0x3E61,0x861B,0x3800,0x0000,
/* 'u' */	0x0000,0x00EE,0x6666,0x666E,0x3F00,0x0000,
/* 'v' */	0x0000,0x00FF,0x6666,0x3C3C,0x1800,0x0000,
/* 'w' */	0x0000,0x00FF,0x667E,0x7E3C,0x3C00,0x0000,
/* 'x' */	0x0000,0x00FF,0x663C,0x3C66,0xFF00,0x0000,
/* 'y' */	0x0000,0x00FF,0x6666,0x3C3C,0x1818,0x7000,
/* 'z' */	0x0000,0x07FC,0xC30C,0x33FE,0x0000,0x0000,
/* '{' */	0x1CC3,0x0C33,0x830C,0x30C1,0xC000,
/* '|' */	0xFFFF,0xFF00,
/* '}' */	0xE0C3,0x0C30,0x730C,0x30CE,0x0000,
/* '~' */	0x0073,0xDBCE,0x0000,0x0000,0x0000,0x0000,
/* 0x7F */	0x0FFF,0xFFFF,0xFF00,
};

static const u16 Courier12b_offset[95] = {
    0,    2,    5,   11,   16,   22,   28,   30,   33,   36,   42,   48,   51,   57,   59,   65,
   70,   75,   80,   85,   90,   95,  100,  105,  110,  115,  117,  120,  124,  129,  133,  138,
  144,  150,  156,  162,  168,  174,  180,  186,  192,  197,  203,  209,  215,  221,  227,  233,
  239,  245,  251,  257,  263,  269,  275,  281,  287,  293,  299,  302,  308,  311,  316,  323,
  326,  332,  338,  344,  350,  356,  360,  366,  372,  377,  381,  387,  392,  398,  404,  410,
  416,  422,  428,  434,  439,  445,  451,  457,  463,  469,  475,  480,  482,  487,  493
};

static const u8 Courier12b_width[95] = {
 2, 4, 8, 6, 8, 8, 2, 4, 4, 8, 8, 3, 8, 2, 8, 6,
 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 3, 5, 6, 5, 6, 8,
 8, 8, 8, 8, 8, 8, 8, 8, 6, 7, 8, 8, 8, 8, 8, 8,
 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 8, 4, 6, 9, 3,
 8, 8, 8, 8, 8, 5, 8, 8, 6, 5, 8, 6, 8, 8, 8, 8,
 8, 8, 8, 6, 8, 8, 8, 8, 8, 7, 6, 2, 6, 8, 4
};

Courier12b::Courier12b(u8 fixedWidth) : PackedFont1 (
	33,
	127,
	Courier12b_glyphdata,
	Courier12b_offset,
	Courier12b_width,
	12,
	3,
	9) {
	if (fixedWidth) setFontWidth(fixedWidth);
};
