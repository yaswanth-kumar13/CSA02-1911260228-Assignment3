
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int word_count_manual(const char s[])
{
    int count = 0, inside = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
        {
            if (!inside)
                count++;
            inside = 1;
        }
        else
            inside = 0;
    }

    return count;
}

int palindrome_manual(const char s[])
{
    int left = 0, right = 0;

    while (s[right] != '\0')
        right++;

    right--;

    while (left < right)
    {
        while (left < right && !isalpha((unsigned char)s[left]))
            left++;

        while (left < right && !isalpha((unsigned char)s[right]))
            right--;

        if (tolower((unsigned char)s[left]) != tolower((unsigned char)s[right]))
            return 0;

        left++;
        right--;
    }

    return 1;
}

void uppercase_manual(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] -= 32;
}

void reverse_manual(char s[])
{
    int i = 0, j = 0;

    while (s[j] != '\0')
        j++;

    j--;

    while (i < j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int main(void)
{
    char message[] = "Meet at the library at 5 PM";
    char upper[100], reversed[100];
    char tab_message[] = "Hello\tWorld";

    snprintf(upper, sizeof upper, "%s", message);
    snprintf(reversed, sizeof reversed, "%s", message);

    printf("MANUAL STRING FUNCTIONS\n");
    printf("Words: %d\n", word_count_manual(" Meet at the library at 5 PM "));
    printf("Madam palindrome: %d\n", palindrome_manual("Madam, I'm Adam"));
    printf("Hello palindrome: %d\n", palindrome_manual("Hello"));

    uppercase_manual(upper);
    reverse_manual(reversed);

    printf("Uppercase: %s\n", upper);
    printf("Reversed: %s\n", reversed);
    printf("Tab-separated words: %d\n", word_count_manual(tab_message));

    printf("\nLIBRARY STRING FUNCTIONS\n");
    printf("Length: %zu\n", strlen(message));

    char library_upper[100];
    char library_reverse[100];

    snprintf(library_upper, sizeof library_upper, "%s", message);
    snprintf(library_reverse, sizeof library_reverse, "%s", message);

    for (int i = 0; library_upper[i] != '\0'; i++)
        library_upper[i] = (char)toupper((unsigned char)library_upper[i]);

    for (int i = 0, j = (int)strlen(library_reverse) - 1; i < j; i++, j--)
    {
        char temp = library_reverse[i];
        library_reverse[i] = library_reverse[j];
        library_reverse[j] = temp;
    }

    printf("Uppercase: %s\n", library_upper);
    printf("Reversed: %s\n", library_reverse);
    printf("Palindrome comparison: %d\n",
           strcmp("MADAM", "MADAM") == 0);

    char small[5];
    snprintf(small, sizeof small, "%s", "FEEDBACK");
    printf("Safe truncated copy: %s\n", small);

    return 0;
}
