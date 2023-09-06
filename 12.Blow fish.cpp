#include <stdio.h>
#include <string.h>
#include <openssl/blowfish.h>

int main() {
    BF_KEY key;
    unsigned char keyData[BF_KEY_LENGTH] = "MySecretKey"; // 64-bit key
    unsigned char ivData[BF_BLOCK] = "IVData123"; // 64-bit IV

    BF_set_key(&key, BF_KEY_LENGTH, keyData);
    unsigned char plaintext[] = "Hello, Blowfish!";
    int plaintextLen = strlen((char *)plaintext);
    unsigned char encrypted[plaintextLen];
    memset(encrypted, 0, sizeof(encrypted));
    unsigned char decrypted[plaintextLen];
    memset(decrypted, 0, sizeof(decrypted));
    BF_cbc_encrypt(plaintext, encrypted, plaintextLen, &key, ivData, BF_ENCRYPT);
    printf("Encrypted Text: ");
    for (int i = 0; i < plaintextLen; i++) {
        printf("%02X", encrypted[i]);
    }
    printf("\n");
    BF_cbc_encrypt(encrypted, decrypted, plaintextLen, &key, ivData, BF_DECRYPT);
    printf("Decrypted Text: %s\n", decrypted);
    return 0;
}

