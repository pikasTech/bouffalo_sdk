#include "bflb_mtimer.h"
#include "bflb_sec_aes.h"
#include "board.h"

const uint8_t aes_ecb_128bit_key[2][16] = {
    { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6,
      0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c },
    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
      0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f },
};

const uint8_t aes_ecb_128bit_iv[2][16] = {
    { 0 },
    { 0 },
};

const uint8_t aes_ecb_128bit_pt[2][16] = {
    { 0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d,
      0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34 },
    { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
      0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff },
};

const uint8_t aes_ecb_128bit_ct[2][16] = {
    { 0x39, 0x25, 0x84, 0x1d, 0x02, 0xDc, 0x09, 0xfb,
      0xdc, 0x11, 0x85, 0x97, 0x19, 0x6a, 0x0b, 0x32 },
    { 0x69, 0xc4, 0xe0, 0xd8, 0x6a, 0x7b, 0x04, 0x30,
      0xd8, 0xcd, 0xb7, 0x80, 0x70, 0xb4, 0xc5, 0x5a },
};

const uint8_t aes_ecb_128bit_len[2] = {
    16, 16
};

const uint8_t aes_ecb_192bit_key[1][24] = {
    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
      0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
      0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17 },
};

const uint8_t aes_ecb_192bit_iv[1][16] = {
    { 0 },
};

const uint8_t aes_ecb_192bit_pt[1][16] = {
    { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
      0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff },
};

const uint8_t aes_ecb_192bit_ct[1][16] = {
    { 0xdd, 0xa9, 0x7c, 0xa4, 0x86, 0x4c, 0xdf, 0xe0,
      0x6e, 0xaf, 0x70, 0xa0, 0xec, 0x0d, 0x71, 0x91 }
};

const uint8_t aes_ecb_192bit_len[1] = {
    16
};

const uint8_t aes_ecb_256bit_key[1][32] = {
    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
      0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
      0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
      0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f },
};

const uint8_t aes_ecb_256bit_iv[1][16] = {
    { 0 },
};

const uint8_t aes_ecb_256bit_pt[1][16] = {
    { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
      0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff },
};

const uint8_t aes_ecb_256bit_ct[1][16] = {
    { 0x8e, 0xa2, 0xb7, 0xca, 0x51, 0x67, 0x45, 0xbf,
      0xea, 0xfc, 0x49, 0x90, 0x4b, 0x49, 0x60, 0x89 },
};

const uint8_t aes_ecb_256bit_len[1] = {
    16
};

const uint8_t aes_cbc_128bit_key[1][16] = {
    { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6,
      0xAB, 0xF7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c },
};

const uint8_t aes_cbc_128bit_iv[1][16] = {
    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
      0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F },
};

const uint8_t aes_cbc_128bit_pt[1][48] = {
    { 0x6B, 0xC1, 0xBE, 0xE2, 0x2E, 0x40, 0x9F, 0x96, 0xE9, 0x3D, 0x7E, 0x11, 0x73, 0x93, 0x17, 0x2A,
      0xAE, 0x2D, 0x8A, 0x57, 0x1E, 0x03, 0xAC, 0x9C, 0x9E, 0xB7, 0x6F, 0xAC, 0x45, 0xAF, 0x8E, 0x51,
      0x30, 0xC8, 0x1C, 0x46, 0xA3, 0x5C, 0xE4, 0x11, 0xE5, 0xFB, 0xC1, 0x19, 0x1A, 0x0A, 0x52, 0xEF },
};

const uint8_t aes_cbc_128bit_ct[1][48] = {
    { 0x76, 0x49, 0xAB, 0xAC, 0x81, 0x19, 0xB2, 0x46, 0xCE, 0xE9, 0x8E, 0x9B, 0x12, 0xE9, 0x19, 0x7D,
      0x50, 0x86, 0xCB, 0x9B, 0x50, 0x72, 0x19, 0xEE, 0x95, 0xDB, 0x11, 0x3A, 0x91, 0x76, 0x78, 0xB2,
      0x73, 0xBE, 0xD6, 0xB8, 0xE3, 0xC1, 0x74, 0x3B, 0x71, 0x16, 0xE6, 0x9E, 0x22, 0x22, 0x95, 0x16 },
};

const uint8_t aes_cbc_128bit_len[1] = { 48 };

const uint8_t aes_cbc_192bit_key[1][24] = {
    { 0x8E, 0x73, 0xB0, 0xF7, 0xDA, 0x0E, 0x64, 0x52,
      0xC8, 0x10, 0xF3, 0x2B, 0x80, 0x90, 0x79, 0xE5,
      0x62, 0xF8, 0xEA, 0xD2, 0x52, 0x2C, 0x6B, 0x7B },
};

const uint8_t aes_cbc_192bit_iv[1][16] = {
    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
      0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F },
};

const uint8_t aes_cbc_192bit_pt[1][48] = {
    { 0x6B, 0xC1, 0xBE, 0xE2, 0x2E, 0x40, 0x9F, 0x96, 0xE9, 0x3D, 0x7E, 0x11, 0x73, 0x93, 0x17, 0x2A,
      0xAE, 0x2D, 0x8A, 0x57, 0x1E, 0x03, 0xAC, 0x9C, 0x9E, 0xB7, 0x6F, 0xAC, 0x45, 0xAF, 0x8E, 0x51,
      0x30, 0xC8, 0x1C, 0x46, 0xA3, 0x5C, 0xE4, 0x11, 0xE5, 0xFB, 0xC1, 0x19, 0x1A, 0x0A, 0x52, 0xEF },
};

const uint8_t aes_cbc_192bit_ct[1][48] = {
    { 0x4F, 0x02, 0x1D, 0xB2, 0x43, 0xBC, 0x63, 0x3D, 0x71, 0x78, 0x18, 0x3A, 0x9F, 0xA0, 0x71, 0xE8,
      0xB4, 0xD9, 0xAD, 0xA9, 0xAD, 0x7D, 0xED, 0xF4, 0xE5, 0xE7, 0x38, 0x76, 0x3F, 0x69, 0x14, 0x5A,
      0x57, 0x1B, 0x24, 0x20, 0x12, 0xFB, 0x7A, 0xE0, 0x7F, 0xA9, 0xBA, 0xAC, 0x3D, 0xF1, 0x02, 0xE0 },
};

const uint8_t aes_cbc_192bit_len[1] = { 48 };

const uint8_t aes_cbc_256bit_key[1][32] = {
    { 0x60, 0x3D, 0xEB, 0x10, 0x15, 0xCA, 0x71, 0xBE,
      0x2B, 0x73, 0xAE, 0xF0, 0x85, 0x7D, 0x77, 0x81,
      0x1F, 0x35, 0x2C, 0x07, 0x3B, 0x61, 0x08, 0xD7,
      0x2D, 0x98, 0x10, 0xA3, 0x09, 0x14, 0xDF, 0xF4 },
};

const uint8_t aes_cbc_256bit_iv[1][16] = {
    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
      0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F },
};

const uint8_t aes_cbc_256bit_pt[1][48] = {
    { 0x6B, 0xC1, 0xBE, 0xE2, 0x2E, 0x40, 0x9F, 0x96, 0xE9, 0x3D, 0x7E, 0x11, 0x73, 0x93, 0x17, 0x2A,
      0xAE, 0x2D, 0x8A, 0x57, 0x1E, 0x03, 0xAC, 0x9C, 0x9E, 0xB7, 0x6F, 0xAC, 0x45, 0xAF, 0x8E, 0x51,
      0x30, 0xC8, 0x1C, 0x46, 0xA3, 0x5C, 0xE4, 0x11, 0xE5, 0xFB, 0xC1, 0x19, 0x1A, 0x0A, 0x52, 0xEF },
};

const uint8_t aes_cbc_256bit_ct[1][48] = {
    { 0xF5, 0x8C, 0x4C, 0x04, 0xD6, 0xE5, 0xF1, 0xBA, 0x77, 0x9E, 0xAB, 0xFB, 0x5F, 0x7B, 0xFB, 0xD6,
      0x9C, 0xFC, 0x4E, 0x96, 0x7E, 0xDB, 0x80, 0x8D, 0x67, 0x9F, 0x77, 0x7B, 0xC6, 0x70, 0x2C, 0x7D,
      0x39, 0xF2, 0x33, 0x69, 0xA9, 0xD9, 0xBA, 0xCF, 0xA5, 0x30, 0xE2, 0x63, 0x04, 0x23, 0x14, 0x61 },
};

const uint8_t aes_cbc_256bit_len[1] = { 48 };

const uint8_t aes_ctr_128bit_key[3][16] = {
    { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6,
      0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c },
    { 0x7E, 0x24, 0x06, 0x78, 0x17, 0xFA, 0xE0, 0xD7,
      0x43, 0xD6, 0xCE, 0x1F, 0x32, 0x53, 0x91, 0x63 },
    { 0x76, 0x91, 0xBE, 0x03, 0x5E, 0x50, 0x20, 0xA8,
      0xAC, 0x6E, 0x61, 0x85, 0x29, 0xF9, 0xA0, 0xDC }
};

const uint8_t aes_ctr_128bit_iv[3][16] = {
    { 0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7,
      0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff },
    { 0x00, 0x6C, 0xB6, 0xDB, 0xC0, 0x54, 0x3B, 0x59,
      0xDA, 0x48, 0xD9, 0x0B, 0x00, 0x00, 0x00, 0x01 },
    { 0x00, 0xE0, 0x01, 0x7B, 0x27, 0x77, 0x7F, 0x3F,
      0x4A, 0x17, 0x86, 0xF0, 0x00, 0x00, 0x00, 0x01 }
};

const uint8_t aes_ctr_128bit_pt[3][48] = {
    { 0x6B, 0xC1, 0xBE, 0xE2, 0x2E, 0x40, 0x9F, 0x96,
      0xE9, 0x3D, 0x7E, 0x11, 0x73, 0x93, 0x17, 0x2A },

    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
      0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
      0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
      0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F },

    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
      0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
      0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
      0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
      0x20, 0x21, 0x22, 0x23, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
};

const uint8_t aes_ctr_128bit_ct[3][48] = {
    { 0x87, 0x4D, 0x61, 0x91, 0xB6, 0x20, 0xE3, 0x26,
      0x1B, 0xEF, 0x68, 0x64, 0x99, 0x0D, 0xB6, 0xCE },

    { 0x51, 0x04, 0xA1, 0x06, 0x16, 0x8A, 0x72, 0xD9,
      0x79, 0x0D, 0x41, 0xEE, 0x8E, 0xDA, 0xD3, 0x88,
      0xEB, 0x2E, 0x1E, 0xFC, 0x46, 0xDA, 0x57, 0xC8,
      0xFC, 0xE6, 0x30, 0xDF, 0x91, 0x41, 0xBE, 0x28 },

    { 0xC1, 0xCF, 0x48, 0xA8, 0x9F, 0x2F, 0xFD, 0xD9,
      0xCF, 0x46, 0x52, 0xE9, 0xEF, 0xDB, 0x72, 0xD7,
      0x45, 0x40, 0xA4, 0x2B, 0xDE, 0x6D, 0x78, 0x36,
      0xD5, 0x9A, 0x5C, 0xEA, 0xAE, 0xF3, 0x10, 0x53,
      0x25, 0xB2, 0x07, 0x2F, 0x17, 0x55, 0x36, 0x00,
      0xa6, 0x3d, 0xfe, 0xcf, 0x56, 0x23, 0x87, 0xe9 }
};

const uint8_t aes_ctr_128bit_len[3] = { 16, 32, 48 };

const uint8_t aes_ctr_192bit_key[1][32] = {
    { 0x8E, 0x73, 0xB0, 0xF7, 0xDA, 0x0E, 0x64, 0x52,
      0xC8, 0x10, 0xF3, 0x2B, 0x80, 0x90, 0x79, 0xE5,
      0x62, 0xF8, 0xEA, 0xD2, 0x52, 0x2C, 0x6B, 0x7B },
};

const uint8_t aes_ctr_192bit_iv[1][16] = {
    { 0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7,
      0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff },
};

const uint8_t aes_ctr_192bit_pt[1][48] = {
    { 0x6B, 0xC1, 0xBE, 0xE2, 0x2E, 0x40, 0x9F, 0x96, 0xE9, 0x3D, 0x7E, 0x11, 0x73, 0x93, 0x17, 0x2A,
      0xAE, 0x2D, 0x8A, 0x57, 0x1E, 0x03, 0xAC, 0x9C, 0x9E, 0xB7, 0x6F, 0xAC, 0x45, 0xAF, 0x8E, 0x51,
      0x30, 0xC8, 0x1C, 0x46, 0xA3, 0x5C, 0xE4, 0x11, 0xE5, 0xFB, 0xC1, 0x19, 0x1A, 0x0A, 0x52, 0xEF },
};

const uint8_t aes_ctr_192bit_ct[1][48] = {
    { 0x1A, 0xBC, 0x93, 0x24, 0x17, 0x52, 0x1C, 0xA2, 0x4F, 0x2B, 0x04, 0x59, 0xFE, 0x7E, 0x6E, 0x0B,
      0x09, 0x03, 0x39, 0xEC, 0x0A, 0xA6, 0xFA, 0xEF, 0xD5, 0xCC, 0xC2, 0xC6, 0xF4, 0xCE, 0x8E, 0x94,
      0x1E, 0x36, 0xB2, 0x6B, 0xD1, 0xEB, 0xC6, 0x70, 0xD1, 0xBD, 0x1D, 0x66, 0x56, 0x20, 0xAB, 0xF7 },
};

const uint8_t aes_ctr_192bit_len[1] = { 48 };

const uint8_t aes_ctr_256bit_key[1][32] = {
    { 0x60, 0x3D, 0xEB, 0x10, 0x15, 0xCA, 0x71, 0xBE,
      0x2B, 0x73, 0xAE, 0xF0, 0x85, 0x7D, 0x77, 0x81,
      0x1F, 0x35, 0x2C, 0x07, 0x3B, 0x61, 0x08, 0xD7,
      0x2D, 0x98, 0x10, 0xA3, 0x09, 0x14, 0xDF, 0xF4 },
};

const uint8_t aes_ctr_256bit_iv[1][16] = {
    { 0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7,
      0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff },
};

const uint8_t aes_ctr_256bit_pt[1][48] = {
    { 0x6B, 0xC1, 0xBE, 0xE2, 0x2E, 0x40, 0x9F, 0x96, 0xE9, 0x3D, 0x7E, 0x11, 0x73, 0x93, 0x17, 0x2A,
      0xAE, 0x2D, 0x8A, 0x57, 0x1E, 0x03, 0xAC, 0x9C, 0x9E, 0xB7, 0x6F, 0xAC, 0x45, 0xAF, 0x8E, 0x51,
      0x30, 0xC8, 0x1C, 0x46, 0xA3, 0x5C, 0xE4, 0x11, 0xE5, 0xFB, 0xC1, 0x19, 0x1A, 0x0A, 0x52, 0xEF },
};

const uint8_t aes_ctr_256bit_ct[1][48] = {
    { 0x60, 0x1E, 0xC3, 0x13, 0x77, 0x57, 0x89, 0xA5, 0xB7, 0xA7, 0xF5, 0x04, 0xBB, 0xF3, 0xD2, 0x28,
      0xF4, 0x43, 0xE3, 0xCA, 0x4D, 0x62, 0xB5, 0x9A, 0xCA, 0x84, 0xE9, 0x90, 0xCA, 0xCA, 0xF5, 0xC5,
      0x2B, 0x09, 0x30, 0xDA, 0xA2, 0x3D, 0xE9, 0x4C, 0xE8, 0x70, 0x17, 0xBA, 0x2D, 0x84, 0x98, 0x8D },
};

const uint8_t aes_ctr_256bit_len[1] = { 48 };

/* test for key1 != key2, 32 bytes == unit number + 1 */
uint8_t aes_xts_128bit_key[3][32] = {
    /*key 1*/
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      /*key 2*/
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

    /*key 1*/
    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
      0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
      /*key 2*/
      0xff, 0xfe, 0xfd, 0xfc, 0xfb, 0xfa, 0xf9, 0xf8,
      0xf7, 0xf6, 0xf5, 0xf4, 0xf3, 0xf2, 0xf1, 0xf0 },

    /*key 1*/
    { 0xff, 0xfe, 0xfd, 0xfc, 0xfb, 0xfa, 0xf9, 0xf8,
      0xf7, 0xf6, 0xf5, 0xf4, 0xf3, 0xf2, 0xf1, 0xf0,
      /*key 2*/
      0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
      0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f }
};

uint8_t aes_xts_128bit_iv[3][16] = {
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
};

const uint8_t aes_xts_128bit_pt[3][64] = {
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
      0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
      0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
      0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f }
};

const uint8_t aes_xts_128bit_ct[3][64] = {
    { 0x91, 0x7c, 0xf6, 0x9e, 0xbd, 0x68, 0xb2, 0xec, 0x9b, 0x9f, 0xe9, 0xa3, 0xea, 0xdd, 0xa6, 0x92,
      0xcd, 0x43, 0xd2, 0xf5, 0x95, 0x98, 0xed, 0x85, 0x8c, 0x02, 0xc2, 0x65, 0x2f, 0xbf, 0x92, 0x2e,
      0xc4, 0xcf, 0xc5, 0xa3, 0x8b, 0x75, 0x84, 0x30, 0xd5, 0x16, 0x51, 0x18, 0x7f, 0x65, 0xbb, 0xe6,
      0x16, 0x6b, 0xc3, 0x60, 0xd7, 0xbb, 0x56, 0xe9, 0xbb, 0xe4, 0x54, 0x10, 0x72, 0x2e, 0x46, 0x75 },

    { 0x5a, 0xbd, 0x58, 0x95, 0xd6, 0x09, 0x8c, 0x25, 0x64, 0x7f, 0x6b, 0xfe, 0xfd, 0x03, 0xef, 0x81,
      0x9e, 0x1f, 0xc4, 0xab, 0x14, 0xd8, 0x84, 0x84, 0x49, 0x2b, 0x4f, 0xa3, 0xa1, 0x0a, 0xe3, 0x32,
      0x8a, 0x5e, 0x96, 0x47, 0xab, 0x35, 0x7d, 0x23, 0x5c, 0x2f, 0x4c, 0x83, 0xd1, 0x0f, 0x69, 0x26,
      0xf1, 0xbe, 0x32, 0xcb, 0x07, 0x97, 0xc3, 0xde, 0x84, 0x80, 0x24, 0x5a, 0x92, 0x94, 0xad, 0x0a },

    { 0x7c, 0x01, 0xeb, 0xa3, 0xeb, 0xa9, 0x89, 0x26, 0xe2, 0x05, 0x6b, 0x9a, 0xd9, 0x28, 0x96, 0x7e,
      0xb4, 0x94, 0x04, 0x1e, 0x15, 0xeb, 0x53, 0x65, 0x50, 0x6a, 0x3b, 0xf9, 0x52, 0x64, 0x00, 0x05,
      0xc9, 0xd0, 0x7b, 0xcb, 0xd0, 0xfa, 0x05, 0x28, 0x0e, 0x5a, 0x52, 0x53, 0xfc, 0x2a, 0x86, 0x3e,
      0xc5, 0xef, 0xdb, 0x7c, 0xba, 0x1f, 0x14, 0x64, 0xec, 0x4f, 0xbc, 0xf5, 0x99, 0xb7, 0x31, 0x10 }
};

const uint8_t aes_xts_128bit_len[3] = { 64, 64, 64 };

/* xts192 mode need key1 == key2,each key = 24 bytes, 32 bytes == unit number + 1 */
const uint8_t aes_xts_192bit_key[3][32] = {
    /* key 1 == key 2*/
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
      0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
      0xff, 0xfe, 0xfd, 0xfc, 0xfb, 0xfa, 0xf9, 0xf8,
      0xf7, 0xf6, 0xf5, 0xf4, 0xf3, 0xf2, 0xf1, 0xf0 },

    { 0xff, 0xfe, 0xfd, 0xfc, 0xfb, 0xfa, 0xf9, 0xf8,
      0xf7, 0xf6, 0xf5, 0xf4, 0xf3, 0xf2, 0xf1, 0xf0,
      0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
      0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f }
};

const uint8_t aes_xts_192bit_iv[3][16] = {
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
};

const uint8_t aes_xts_192bit_pt[3][64] = {
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
      0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
      0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
      0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f }

};

const uint8_t aes_xts_192bit_ct[3][64] = {
    { 0xf8, 0x16, 0x1d, 0x25, 0x15, 0xbc, 0x5d, 0x79, 0x59, 0xc9, 0xb1, 0xb2, 0xe8, 0x7e, 0xb8, 0xe6,
      0x33, 0xcd, 0x7a, 0xf3, 0x2c, 0xd1, 0x69, 0x45, 0x32, 0xa8, 0xe3, 0x63, 0xca, 0x0f, 0xd8, 0x19,
      0x36, 0x73, 0x9a, 0xe7, 0x76, 0x73, 0x69, 0x1c, 0x9c, 0xc1, 0xfe, 0x80, 0x46, 0x6f, 0xb8, 0x17,
      0xce, 0x40, 0xca, 0xf4, 0x84, 0xfd, 0x21, 0x06, 0xb6, 0xd0, 0x54, 0xab, 0x3f, 0x22, 0x9a, 0x62 },

    { 0x82, 0xba, 0x63, 0x7a, 0xd6, 0xfb, 0x48, 0xe1, 0x5c, 0xc2, 0x3e, 0x8e, 0x36, 0xf9, 0x63, 0x53,
      0x0c, 0xd8, 0xda, 0x20, 0x87, 0x90, 0xdf, 0x03, 0x82, 0x97, 0xe5, 0x65, 0xee, 0xe2, 0x54, 0xa5,
      0xe8, 0x3d, 0x20, 0xa1, 0x23, 0xd2, 0xcc, 0x22, 0xe1, 0x6e, 0xc2, 0x14, 0x49, 0x19, 0xdc, 0x09,
      0x4c, 0x1c, 0xdb, 0xe1, 0xbd, 0xc1, 0x5b, 0xa6, 0xdf, 0x7a, 0x71, 0xc7, 0x9e, 0x11, 0x62, 0xdb },

    { 0x9f, 0x22, 0x16, 0xaf, 0x4b, 0xa8, 0xb1, 0xa2, 0x93, 0x74, 0x06, 0x5d, 0xa2, 0x90, 0xc4, 0x8b,
      0xfc, 0x2e, 0x10, 0x11, 0x9e, 0x30, 0x50, 0x19, 0x84, 0xa9, 0x19, 0x0e, 0xc9, 0xeb, 0x5f, 0xac,
      0x8c, 0x75, 0x11, 0x5f, 0xcd, 0x8a, 0xb7, 0x75, 0x96, 0xdc, 0x36, 0x95, 0x63, 0x95, 0x78, 0x62,
      0x03, 0x95, 0xbe, 0x8b, 0x8d, 0x9f, 0x5c, 0x73, 0x2b, 0x81, 0xcd, 0x74, 0x07, 0x97, 0x18, 0x15 }
};

const uint8_t aes_xts_192bit_len[3] = { 64, 64, 64 };

/* xts256 mode need key1 == key2,each key = 32 bytes, 32 bytes == unit number + 1 */
const uint8_t aes_xts_256bit_key[3][32] = {
    /* key 1 == key 2*/
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
      0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
      0xff, 0xfe, 0xfd, 0xfc, 0xfb, 0xfa, 0xf9, 0xf8,
      0xf7, 0xf6, 0xf5, 0xf4, 0xf3, 0xf2, 0xf1, 0xf0 },

    { 0xff, 0xfe, 0xfd, 0xfc, 0xfb, 0xfa, 0xf9, 0xf8,
      0xf7, 0xf6, 0xf5, 0xf4, 0xf3, 0xf2, 0xf1, 0xf0,
      0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
      0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f }
};

const uint8_t aes_xts_256bit_iv[3][16] = {
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
};

const uint8_t aes_xts_256bit_pt[3][64] = {
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
      0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
      0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
      0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f }
};

const uint8_t aes_xts_256bit_ct[3][64] = {
    { 0xd4, 0x56, 0xb4, 0xfc, 0x2e, 0x62, 0x0b, 0xba, 0x6f, 0xfb, 0xed, 0x27, 0xb9, 0x56, 0xc9, 0x54,
      0x34, 0x54, 0xdd, 0x49, 0xeb, 0xd8, 0xd8, 0xee, 0x6f, 0x94, 0xb6, 0x5c, 0xbe, 0x15, 0x8f, 0x73,
      0x9f, 0x18, 0xac, 0x6c, 0x7f, 0x5a, 0x7a, 0x61, 0x2f, 0xb9, 0x06, 0xb8, 0x4a, 0xdd, 0x10, 0xa8,
      0xc8, 0xe0, 0x5a, 0xf9, 0x03, 0x32, 0x65, 0x10, 0x2b, 0x97, 0x8b, 0xfc, 0x99, 0xe9, 0x94, 0x5e },

    { 0xb5, 0xe0, 0x20, 0x4e, 0xce, 0x33, 0xcd, 0xc0, 0x49, 0x74, 0xa6, 0xeb, 0x78, 0xd1, 0xcb, 0xad,
      0x9c, 0x5e, 0xbc, 0x0a, 0x6d, 0xf2, 0x54, 0x86, 0x8b, 0xb8, 0x00, 0x85, 0x69, 0x1b, 0x2f, 0x17,
      0xc0, 0xfa, 0x26, 0xfe, 0x00, 0x54, 0x33, 0x33, 0x56, 0x36, 0xa6, 0x92, 0xe5, 0x65, 0x68, 0x24,
      0x74, 0x81, 0x71, 0xb6, 0x8e, 0xdb, 0xaa, 0x0d, 0x7a, 0x4c, 0x31, 0x0f, 0xdc, 0x2c, 0x71, 0xa4 },

    { 0x4b, 0xeb, 0x2b, 0x8d, 0xa5, 0x70, 0x97, 0xca, 0x36, 0x7a, 0x88, 0x9b, 0xf7, 0x8e, 0xfe, 0xe4,
      0x7d, 0x4e, 0xfd, 0x95, 0x1d, 0xfd, 0xcb, 0x2a, 0xfc, 0x09, 0x95, 0x6c, 0xef, 0xe6, 0xba, 0x89,
      0xc0, 0xc7, 0xb7, 0x3c, 0x4a, 0xf3, 0xa6, 0xec, 0x10, 0xf0, 0xff, 0xae, 0x41, 0x17, 0x57, 0xb0,
      0x0f, 0xf2, 0x6b, 0x98, 0x36, 0x63, 0x34, 0xd5, 0x21, 0xe0, 0xbd, 0x09, 0x4e, 0x43, 0xb9, 0xfc }
};

const uint8_t aes_xts_256bit_len[3] = { 64, 64, 64 };

ATTR_NOCACHE_NOINIT_RAM_SECTION uint8_t aes_enc_buf[512];
ATTR_NOCACHE_NOINIT_RAM_SECTION uint8_t aes_dec_buf[512];

static uint32_t bflb_data_compare(const uint8_t *expected, uint8_t *input, uint32_t len)
{
    int i = 0;
    for (i = 0; i < len; i++) {
        if (input[i] != expected[i]) {
            printf("Compare fail at %d,input %02x, but expect %02x\r\n", i, input[i], expected[i]);
            while (1) {
            }
        }
    }

    return 0;
}

int main(void)
{
    board_init();

    struct bflb_device_s *aes;

    aes = bflb_device_get_by_name("aes");

    bflb_group0_request_aes_access(aes);

    bflb_aes_init(aes);

    bflb_aes_set_mode(aes, AES_MODE_ECB);
    bflb_aes_setkey(aes, aes_ecb_128bit_key[0], 128);
    bflb_aes_encrypt(aes, aes_ecb_128bit_pt[0], aes_ecb_128bit_iv[0], aes_enc_buf, aes_ecb_128bit_len[0]);
    bflb_data_compare(aes_ecb_128bit_ct[0], aes_enc_buf, aes_ecb_128bit_len[0]);
    bflb_aes_decrypt(aes, aes_enc_buf, aes_ecb_128bit_iv[0], aes_dec_buf, aes_ecb_128bit_len[0]);
    bflb_data_compare(aes_ecb_128bit_pt[0], aes_dec_buf, aes_ecb_128bit_len[0]);
    printf("aes ecb 128 success\r\n");

    bflb_aes_set_mode(aes, AES_MODE_ECB);
    bflb_aes_setkey(aes, aes_ecb_192bit_key[0], 192);
    bflb_aes_encrypt(aes, aes_ecb_192bit_pt[0], aes_ecb_192bit_iv[0], aes_enc_buf, aes_ecb_192bit_len[0]);
    bflb_data_compare(aes_ecb_192bit_ct[0], aes_enc_buf, aes_ecb_192bit_len[0]);
    bflb_aes_decrypt(aes, aes_enc_buf, aes_ecb_192bit_iv[0], aes_dec_buf, aes_ecb_192bit_len[0]);
    bflb_data_compare(aes_ecb_192bit_pt[0], aes_dec_buf, aes_ecb_192bit_len[0]);
    printf("aes ecb 192 success\r\n");

    bflb_aes_set_mode(aes, AES_MODE_ECB);
    bflb_aes_setkey(aes, aes_ecb_256bit_key[0], 256);
    bflb_aes_encrypt(aes, aes_ecb_256bit_pt[0], aes_ecb_256bit_iv[0], aes_enc_buf, aes_ecb_256bit_len[0]);
    bflb_data_compare(aes_ecb_256bit_ct[0], aes_enc_buf, aes_ecb_256bit_len[0]);
    bflb_aes_decrypt(aes, aes_enc_buf, aes_ecb_256bit_iv[0], aes_dec_buf, aes_ecb_256bit_len[0]);
    bflb_data_compare(aes_ecb_256bit_pt[0], aes_dec_buf, aes_ecb_256bit_len[0]);
    printf("aes ecb 256 success\r\n");

    bflb_aes_set_mode(aes, AES_MODE_CBC);
    bflb_aes_setkey(aes, aes_cbc_128bit_key[0], 128);
    bflb_aes_encrypt(aes, aes_cbc_128bit_pt[0], aes_cbc_128bit_iv[0], aes_enc_buf, aes_cbc_128bit_len[0]);
    bflb_data_compare(aes_cbc_128bit_ct[0], aes_enc_buf, aes_cbc_128bit_len[0]);
    bflb_aes_decrypt(aes, aes_enc_buf, aes_cbc_128bit_iv[0], aes_dec_buf, aes_cbc_128bit_len[0]);
    bflb_data_compare(aes_cbc_128bit_pt[0], aes_dec_buf, aes_cbc_128bit_len[0]);
    printf("aes cbc 128 success\r\n");

    bflb_aes_set_mode(aes, AES_MODE_CBC);
    bflb_aes_setkey(aes, aes_cbc_192bit_key[0], 192);
    bflb_aes_encrypt(aes, aes_cbc_192bit_pt[0], aes_cbc_192bit_iv[0], aes_enc_buf, aes_cbc_192bit_len[0]);
    bflb_data_compare(aes_cbc_192bit_ct[0], aes_enc_buf, aes_cbc_192bit_len[0]);
    bflb_aes_decrypt(aes, aes_enc_buf, aes_cbc_192bit_iv[0], aes_dec_buf, aes_cbc_192bit_len[0]);
    bflb_data_compare(aes_cbc_192bit_pt[0], aes_dec_buf, aes_cbc_192bit_len[0]);
    printf("aes cbc 192 success\r\n");

    bflb_aes_set_mode(aes, AES_MODE_CBC);
    bflb_aes_setkey(aes, aes_cbc_256bit_key[0], 256);
    bflb_aes_encrypt(aes, aes_cbc_256bit_pt[0], aes_cbc_256bit_iv[0], aes_enc_buf, aes_cbc_256bit_len[0]);
    bflb_data_compare(aes_cbc_256bit_ct[0], aes_enc_buf, aes_cbc_256bit_len[0]);
    bflb_aes_decrypt(aes, aes_enc_buf, aes_cbc_256bit_iv[0], aes_dec_buf, aes_cbc_256bit_len[0]);
    bflb_data_compare(aes_cbc_256bit_pt[0], aes_dec_buf, aes_cbc_256bit_len[0]);
    printf("aes cbc 256 success\r\n");

    bflb_aes_set_mode(aes, AES_MODE_CTR);
    bflb_aes_setkey(aes, aes_ctr_128bit_key[0], 128);
    bflb_aes_encrypt(aes, aes_ctr_128bit_pt[0], aes_ctr_128bit_iv[0], aes_enc_buf, aes_ctr_128bit_len[0]);
    bflb_data_compare(aes_ctr_128bit_ct[0], aes_enc_buf, aes_ctr_128bit_len[0]);
    bflb_aes_decrypt(aes, aes_enc_buf, aes_ctr_128bit_iv[0], aes_dec_buf, aes_ctr_128bit_len[0]);
    bflb_data_compare(aes_ctr_128bit_pt[0], aes_dec_buf, aes_ctr_128bit_len[0]);
    printf("aes ctr 128 success\r\n");

    bflb_aes_set_mode(aes, AES_MODE_CTR);
    bflb_aes_setkey(aes, aes_ctr_192bit_key[0], 192);
    bflb_aes_encrypt(aes, aes_ctr_192bit_pt[0], aes_ctr_192bit_iv[0], aes_enc_buf, aes_ctr_192bit_len[0]);
    bflb_data_compare(aes_ctr_192bit_ct[0], aes_enc_buf, aes_ctr_192bit_len[0]);
    bflb_aes_decrypt(aes, aes_enc_buf, aes_ctr_192bit_iv[0], aes_dec_buf, aes_ctr_192bit_len[0]);
    bflb_data_compare(aes_ctr_192bit_pt[0], aes_dec_buf, aes_ctr_192bit_len[0]);
    printf("aes ctr 192 success\r\n");

    bflb_aes_set_mode(aes, AES_MODE_CTR);
    bflb_aes_setkey(aes, aes_ctr_256bit_key[0], 256);
    bflb_aes_encrypt(aes, aes_ctr_256bit_pt[0], aes_ctr_256bit_iv[0], aes_enc_buf, aes_ctr_256bit_len[0]);
    bflb_data_compare(aes_ctr_256bit_ct[0], aes_enc_buf, aes_ctr_256bit_len[0]);
    bflb_aes_decrypt(aes, aes_enc_buf, aes_ctr_256bit_iv[0], aes_dec_buf, aes_ctr_256bit_len[0]);
    bflb_data_compare(aes_ctr_256bit_pt[0], aes_dec_buf, aes_ctr_256bit_len[0]);
    printf("aes ctr 256 success\r\n");

    bflb_aes_set_mode(aes, AES_MODE_XTS);
    bflb_aes_setkey(aes, aes_xts_128bit_key[0], 128);
    bflb_aes_encrypt(aes, aes_xts_128bit_pt[0], aes_xts_128bit_iv[0], aes_enc_buf, aes_xts_128bit_len[0]);
    bflb_data_compare(aes_xts_128bit_ct[0], aes_enc_buf, aes_xts_128bit_len[0]);
    bflb_aes_decrypt(aes, aes_enc_buf, aes_xts_128bit_iv[0], aes_dec_buf, aes_xts_128bit_len[0]);
    bflb_data_compare(aes_xts_128bit_pt[0], aes_dec_buf, aes_xts_128bit_len[0]);
    printf("aes xts 128 success\r\n");

    bflb_aes_set_mode(aes, AES_MODE_XTS);
    bflb_aes_setkey(aes, aes_xts_192bit_key[0], 192);
    bflb_aes_encrypt(aes, aes_xts_192bit_pt[0], aes_xts_192bit_iv[0], aes_enc_buf, aes_xts_192bit_len[0]);
    bflb_data_compare(aes_xts_192bit_ct[0], aes_enc_buf, aes_xts_192bit_len[0]);
    bflb_aes_decrypt(aes, aes_enc_buf, aes_xts_192bit_iv[0], aes_dec_buf, aes_xts_192bit_len[0]);
    bflb_data_compare(aes_xts_192bit_pt[0], aes_dec_buf, aes_xts_192bit_len[0]);
    printf("aes xts 192 success\r\n");

    bflb_aes_set_mode(aes, AES_MODE_XTS);
    bflb_aes_setkey(aes, aes_xts_256bit_key[0], 256);
    bflb_aes_encrypt(aes, aes_xts_256bit_pt[0], aes_xts_256bit_iv[0], aes_enc_buf, aes_xts_256bit_len[0]);
    bflb_data_compare(aes_xts_256bit_ct[0], aes_enc_buf, aes_xts_256bit_len[0]);
    bflb_aes_decrypt(aes, aes_enc_buf, aes_xts_256bit_iv[0], aes_dec_buf, aes_xts_256bit_len[0]);
    bflb_data_compare(aes_xts_256bit_pt[0], aes_dec_buf, aes_xts_256bit_len[0]);
    printf("aes xts 256 success\r\n");

    printf("aes success\r\n");
    bflb_group0_release_aes_access(aes);
    while (1) {
        bflb_mtimer_delay_ms(2000);
    }
}