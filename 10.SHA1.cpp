#include <stdio.h>
#include <stdint.h>

#define ROTLEFT(a, b) ((a << b) | (a >> (32 - b)))

void sha1(uint8_t *message, uint64_t len, uint32_t hash[5]) {
    uint64_t bitlen = len * 8;
    uint32_t w[80];
    uint32_t a, b, c, d, e, temp, i, j;


    hash[0] = 0x67452301;
    hash[1] = 0xEFCDAB89;
    hash[2] = 0x98BADCFE;
    hash[3] = 0x10325476;
    hash[4] = 0xC3D2E1F0;

    
    uint64_t newlen = len + 1;
    while (newlen % 64 != 56) {
        newlen++;
    }
    uint8_t padded_message[64]; 
    for (i = 0; i < len; i++) {
        padded_message[i] = message[i];
    }
    padded_message[len] = 0x80;
    for (i = len + 1; i < newlen; i++) {
        padded_message[i] = 0;
    }
    for (i = 0; i < 8; i++) {
        padded_message[newlen + i] = (bitlen >> (56 - 8 * i)) & 0xFF;
    }

   
}

int main() {
    uint8_t message[] = "Hello, SHA-1!";
    uint32_t hash[5];
    sha1(message, sizeof(message) - 1, hash);

    printf("SHA-1 Hash: ");
    for (int i = 0; i < 5; i++) {
        printf("%08x", hash[i]);
    }
    printf("\n");

    return 0;
}
