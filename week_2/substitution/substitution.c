#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool checkstring(string text);
void cipher(string key, string text);
bool handle_duplicate(string key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {

        if (strlen(argv[1]) != 26 || !checkstring(argv[1]))
        {
            printf("Key must contain 26 characters\n");
            return 1;
        }
        if (handle_duplicate(argv[1]))
        {
            printf("Key must not contain duplicates\n");
            return 1;
        }
        string text = get_string("plaintext: ");
        cipher(argv[1], text);
        return 0;
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
}

bool checkstring(string text)
{
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (!isalpha(text[i]))
        {
            return false;
        }
    }
    return true;
}

bool handle_duplicate(string key)
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = 1 + i; j < 26; j++)
        {
            if (key[i] == key[j])
            {
                return true;
            }
        }
    }
    return false;
}

void cipher(string key, string text)
{
    printf("ciphertext: ");

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                printf("%c", toupper(key[text[i] - 65]));
            }
            else
            {
                printf("%c", tolower(key[text[i] - 97]));
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
