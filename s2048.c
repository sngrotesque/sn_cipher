#include "S2048.h"

int main(int argc, char **argv)
{
    S2048_ctx *data = (S2048_ctx *)malloc(sizeof(S2048_ctx));
    const static uint32_t fileBlockSize = 4096;

    data->data = (u8 *)malloc(fileBlockSize);
    data->key = S2048_Round_key_obfuscation(S2048_Key_Padding(
        "hello, world.\nPower by C Programming Language.", 48));

    FILE *fp_read  = fopen("misc_file/bilibili_2233.jpg", "rb");
    FILE *fp_write = fopen("misc_file/bilibili_2233.jpg.enc", "wb");

    do {
        data->len = fread(data->data, 1, fileBlockSize, fp_read);
        S2048_ENCRYPT(data);
        fwrite(data->data, 1, data->len, fp_write);
    } while(!feof(fp_read));

    fclose(fp_read);
    fclose(fp_write);
    free(data);
    return 0;
    return 0;
}
