#pragma once
#ifndef KASUMI_H
#define KASUMI_H

#include <iostream>
#include <cstdint>
#include <string>

#define ROL16(a, b) (u16)(((a) << b) | ((a) >> (16 - b))) // Циклический сдвиг для 16 бит

using namespace std;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef union
{
	u32 b32;
	u16 b16[2];
	u8 b8[4];
}WORD32;

typedef union
{
	u16 b16;
	u8 b8[2];
}WORD16;

class Kasumi
{
public:
	Kasumi();

	void setKey(u8* key_external);
	void encryptBlock(u8* data);
	void decryptBlock(u8* data);
	void encrypt(string& data);
	void decrypt(string& data);

private:
	u16 FI(u16 input, u16 subkey);
	u32 FL(u32 input, int key_index);
	u32 FO(u32 input, int key_index);

	u16 KL_1[8], KL_2[8],
		KO_1[8], KO_2[8], KO_3[8],
		KI_1[8], KI_2[8], KI_3[8];
};

#endif KASUMI_H
