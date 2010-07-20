#include "lucidacalligraphy14.h"
#include <nds.h>

using namespace WoopsiUI;

static const u16 LucidaCalligraphy14_glyphdata[671] = {
/* '!' */	0x04B4,0x9090,0x0000,
/* '"' */	0x16D0,0x0000,0x0000,
/* '#' */	0x0014,0x50A7,0xE53F,0x2891,0x4000,0x0000,0x0000,
/* '$' */	0x0000,0x27B5,0x86F7,0x1000,0x0000,
/* '%' */	0x001C,0x5249,0x4740,0x405C,0x5249,0x4700,0x0000,0x0000,0x0000,
/* '&' */	0x001C,0x2424,0x3857,0x929C,0x8C77,0x0000,0x0000,0x0000,
/* ''' */	0x7000,
/* '(' */	0x1244,0x4888,0x8884,0x0000,
/* ')' */	0x2211,0x1112,0x2448,0x0000,
/* '*' */	0x014D,0xF650,0x0000,0x0000,0x0000,
/* '+' */	0x0000,0x0410,0x8FC8,0x2080,0x0000,0x0000,
/* ',' */	0x0000,0x006C,0xE000,
/* '-' */	0x0000,0x3800,0x0000,
/* '.' */	0x0000,0xF000,
/* '/' */	0x0102,0x0404,0x0808,0x1020,0x2040,0x4080,0x0000,0x0000,
/* '0' */	0x0000,0x0039,0x1861,0x89C0,0x0000,0x0000,
/* '1' */	0x0000,0x7322,0x2F00,0x0000,
/* '2' */	0x0000,0x003D,0x1084,0x63E0,0x0000,0x0000,
/* '3' */	0x0000,0x003D,0x108C,0x0828,0x9C00,0x0000,
/* '4' */	0x0000,0x0000,0x4185,0x12C9,0xFC20,0xE000,0x0000,
/* '5' */	0x0000,0x0003,0xE810,0x1C04,0x0A23,0x8000,0x0000,
/* '6' */	0x0001,0xD942,0xECA2,0x99C0,0x0000,0x0000,
/* '7' */	0x0000,0x0007,0xE082,0x0820,0xC106,0x0000,0x0000,
/* '8' */	0x0003,0xD148,0xCDA2,0x89C0,0x0000,0x0000,
/* '9' */	0x0000,0x0039,0x1453,0x7429,0xB800,0x0000,
/* ':' */	0x0006,0xC0D8,0x0000,
/* ';' */	0x0000,0x3300,0x662C,0x0000,
/* '<' */	0x0000,0x0004,0xEC20,0x6060,0x0000,0x0000,
/* '=' */	0x0000,0x0000,0x1FC0,0x7F00,0x0000,0x0000,0x0000,
/* '>' */	0x0000,0x0040,0xC0C3,0x3300,0x0000,0x0000,
/* '?' */	0x03A2,0x1111,0x0806,0x0000,0x0000,
/* '@' */	0x000F,0x0849,0xD94D,0x26B5,0x6E40,0x1C00,0x0000,0x0000,0x0000,
/* 'A' */	0x0000,0x7835,0x04A0,0x2408,0x81F0,0x4288,0x5E0C,0x0000,0x0000,0x0000,0x0000,
/* 'B' */	0x003E,0x4989,0x1A1C,0x1311,0x21FE,0x0000,0x0000,0x0000,
/* 'C' */	0x001E,0x2140,0xC080,0x8080,0xC478,0x0000,0x0000,0x0000,
/* 'D' */	0x000F,0xE48E,0x6198,0x4411,0x0442,0x213F,0x8000,0x0000,0x0000,0x0000,
/* 'E' */	0x001F,0xD231,0x0180,0xF040,0x2021,0x7F00,0x0000,0x0000,0x0000,
/* 'F' */	0x0001,0xFC48,0x9100,0x200F,0x0100,0x2004,0x0182,0x2038,0x0000,0x0000,0x0000,
/* 'G' */	0x001E,0x2140,0x808E,0x9282,0xC67C,0x0478,0x0000,0x0000,
/* 'H' */	0x001C,0x7082,0x4213,0x1808,0x407F,0x0084,0x0630,0x1083,0x8300,0x0000,0x0000,0x0000,0x0000,0x0000,
/* 'I' */	0x003C,0x2041,0x8204,0x0821,0xE000,0x0000,0x0000,
/* 'J' */	0x000F,0x0404,0x0C08,0x0808,0x1810,0x10E0,0x0000,0x0000,
/* 'K' */	0x0000,0xE334,0x4258,0x0600,0x600F,0x0090,0x088F,0x0E00,0x0000,0x0000,0x0000,0x0000,
/* 'L' */	0x0007,0x0918,0x1810,0x1010,0x21FE,0x0000,0x0000,0x0000,
/* 'M' */	0x0000,0x70CD,0x864C,0x7075,0x02A8,0x2641,0x2291,0x3301,0xC000,0x0000,0x0000,0x0000,0x0000,
/* 'N' */	0x0000,0x1C1C,0x4841,0x3880,0x5100,0xB201,0x2804,0x3088,0x60E0,0x4000,0x0000,0x0000,0x0000,0x0000,0x0000,
/* 'O' */	0x001E,0x2341,0xC181,0x8382,0xC478,0x0000,0x0000,0x0000,
/* 'P' */	0x001F,0x9231,0x1890,0xF840,0x2020,0x7800,0x0000,0x0000,0x0000,
/* 'Q' */	0x000F,0x0CC4,0x2412,0x0988,0x6808,0x780F,0x00F0,0x0000,0x0000,
/* 'R' */	0x000F,0x8492,0x4412,0x0701,0x60C8,0x233C,0x7000,0x0000,0x0000,0x0000,
/* 'S' */	0x0038,0x8903,0x0303,0x02C4,0xF000,0x0000,0x0000,
/* 'T' */	0x0027,0xF910,0x4208,0xC010,0x0200,0x4010,0x0700,0x0000,0x0000,0x0000,0x0000,
/* 'U' */	0x000E,0x1486,0x2110,0x8421,0x0846,0x1383,0x3000,0x0000,0x0000,0x0000,
/* 'V' */	0x7013,0x0C21,0x0220,0x480A,0x0140,0x3004,0x0080,0x0000,0x0000,0x0000,0x0000,
/* 'W' */	0x7001,0x109C,0x3110,0x2620,0x5480,0xA901,0x9403,0x3804,0x6008,0xC000,0x0000,0x0000,0x0000,0x0000,0x0000,
/* 'X' */	0x0003,0x0CA2,0x0680,0x6008,0x0380,0x9023,0x9830,0x0000,0x0000,0x0000,0x0000,
/* 'Y' */	0x0030,0x6864,0x2211,0x1888,0x4C1A,0x0213,0x0F00,0x0000,0x0000,
/* 'Z' */	0x003F,0x0306,0x0C10,0x2040,0xF28E,0x0000,0x0000,0x0000,
/* '[' */	0x3908,0x4421,0x0844,0x21C0,0x0000,
/* '\' */	0x9248,0x9248,0x9000,
/* ']' */	0x3842,0x2108,0x4221,0x09C0,0x0000,
/* '^' */	0x0020,0x8E29,0x2461,0x0000,0x0000,0x0000,
/* '_' */	0x0000,0x0000,0x0000,0x3E00,0x0000,
/* '`' */	0x9000,0x0000,
/* 'a' */	0x0000,0x0000,0x1E62,0x448C,0x95E6,0x0000,0x0000,0x0000,
/* 'b' */	0x0E20,0x8306,0xEA58,0xA2C5,0xF000,0x0000,0x0000,
/* 'c' */	0x0000,0x03A6,0x308F,0x8000,0x0000,
/* 'd' */	0x00E0,0x6008,0x0303,0xC088,0x1104,0x40B8,0x19C0,0x0000,0x0000,0x0000,0x0000,
/* 'e' */	0x0000,0x03A6,0x7C8B,0x8000,0x0000,
/* 'f' */	0x0718,0x2020,0x7C20,0x2040,0x4040,0x4080,0x8000,0x0000,
/* 'g' */	0x0000,0x0000,0x0F12,0x2242,0x4E74,0x4484,0x88F0,0x0000,
/* 'h' */	0x0E32,0x4040,0x4E52,0x62C4,0x8586,0x0000,0x0000,0x0000,
/* 'i' */	0x1200,0x2E44,0x5600,0x0000,
/* 'j' */	0x0044,0x0318,0x8421,0x1888,0x0000,
/* 'k' */	0x0C60,0x8304,0xCE92,0x38D1,0x1C00,0x0000,0x0000,
/* 'l' */	0x1C84,0x1041,0x0820,0xA300,0x0000,0x0000,
/* 'm' */	0x0000,0x0000,0x0000,0x666A,0xAA33,0x2224,0x4454,0x4600,0x0000,0x0000,0x0000,0x0000,
/* 'n' */	0x0000,0x0000,0x0675,0x48C4,0x4442,0xA180,0x0000,0x0000,0x0000,
/* 'o' */	0x0000,0x0039,0x1861,0x89C0,0x0000,0x0000,
/* 'p' */	0x0000,0x0000,0x1779,0x3122,0x223C,0x4040,0x8000,0x0000,
/* 'q' */	0x0000,0x003D,0x18E6,0xAB20,0x841C,0x4000,
/* 'r' */	0x0000,0x0006,0x750C,0x1040,0x8000,0x0000,0x0000,
/* 's' */	0x0000,0x03A5,0x0697,0x0000,0x0000,
/* 't' */	0x0008,0x8FA1,0x10A6,0x0000,0x0000,
/* 'u' */	0x0000,0x0000,0x62A2,0x244C,0x5566,0x0000,0x0000,0x0000,
/* 'v' */	0x0000,0x0000,0x61B1,0x1214,0x1810,0x0000,0x0000,0x0000,
/* 'w' */	0x0000,0x0000,0x0006,0x2326,0x4550,0xAC19,0x8220,0x0000,0x0000,0x0000,0x0000,
/* 'x' */	0x0000,0x0000,0x2354,0x1818,0x28C6,0x0000,0x0000,0x0000,
/* 'y' */	0x0000,0x0000,0x61A3,0x2226,0x2A34,0x0404,0x0870,0x0000,
/* 'z' */	0x0000,0x003D,0x2108,0xC7E0,0x0000,0x0000,
/* '{' */	0x3222,0x4C44,0x488C,0x0000,
/* '|' */	0x04A4,0x9292,0x4000,
/* '}' */	0x3112,0x2124,0x4448,0x0000,
/* '~' */	0x0000,0x0000,0x0018,0xCE00,0x0000,0x0000,0x0000,
/* 0x7F */	0xFE18,0x6186,0x1861,0x861F,0xC000,0x0000,
};

static const u16 LucidaCalligraphy14_offset[95] = {
    0,    3,    6,   13,   18,   27,   35,   36,   40,   44,   49,   55,   58,   61,   63,   71,
   77,   81,   87,   93,  100,  107,  113,  120,  126,  132,  135,  139,  145,  152,  158,  163,
  172,  183,  191,  199,  209,  218,  229,  237,  251,  258,  266,  278,  286,  299,  314,  322,
  331,  340,  350,  357,  368,  378,  389,  404,  415,  424,  432,  437,  440,  445,  451,  456,
  458,  466,  473,  478,  489,  494,  502,  510,  518,  522,  527,  534,  540,  552,  561,  567,
  575,  581,  588,  593,  598,  606,  614,  625,  633,  641,  647,  651,  654,  658,  665
};

static const u8 LucidaCalligraphy14_width[95] = {
 3, 3, 7, 5, 9, 8, 1, 4, 4, 5, 6, 3, 3, 2, 8, 6,
 4, 6, 6, 7, 7, 6, 7, 6, 6, 3, 4, 6, 7, 6, 5, 9,
11, 8, 8,10, 9,11, 8,14, 7, 8,12, 8,13,15, 8, 9,
 9,10, 7,11,10,11,15,11, 9, 8, 5, 3, 5, 6, 5, 2,
 8, 7, 5,11, 5, 8, 8, 8, 4, 5, 7, 6,12, 9, 6, 8,
 6, 7, 5, 5, 8, 8,11, 8, 8, 6, 4, 3, 4, 7, 6
};

LucidaCalligraphy14::LucidaCalligraphy14(u8 fixedWidth) : PackedFont1 (
	33,
	127,
	LucidaCalligraphy14_glyphdata,
	LucidaCalligraphy14_offset,
	LucidaCalligraphy14_width,
	16,
	4,
	15) {
	if (fixedWidth) setFontWidth(fixedWidth);
};
