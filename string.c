#include <stddef.h>

/**
 * Concatène la chaîne src à la fin de dest.
 * @param dest Destination pour la concaténation
 * @param src La chaîne de caractère qui ira à la fin de dest
 */
void strcat(char *dest, const char *src) {
    while (*dest != '\0') {
        dest++;
    }

    while (*src != '\0') {
        *(dest++) = *(src++);
    }

    *dest = '\0';
}

/**
 * Concatène au plus n caractères de src à la fin de dest.
 * @param dest Destination pour la concaténation
 * @param src La chaîne de caractère qui ira à la fin de dest
 * @param n Le nombre maximal de caractères à concaténer
 */
void strncat(char *dest, const char *src, size_t n) {
    while (*dest != '\0') {
        dest++;
    }

    while (n > 0 && *src != '\0') {
        *(dest++) = *(src++);
        n--;
    }

    *dest = '\0';
}

/**
 * Recherche la première occurrence du caractère cha dans str.
 * @param str La chaîne dans laquelle rechercher
 * @param cha Le caractère à rechercher
 * @return Un pointeur vers la première occurrence de cha dans str, ou NULL si non trouvé
 */
const char* strchr(const char *str, int cha) {
    while (*str != '\0' && *str != cha) {
        str++;
    }

    return (*str == cha) ? str : NULL;
}

/**
 * Recherche la dernière occurrence du caractère cha dans str.
 * @param str La chaîne dans laquelle rechercher
 * @param cha Le caractère à rechercher
 * @return Un pointeur vers la dernière occurrence de cha dans str, ou NULL si non trouvé
 */
const char* strrchr(const char *str, int cha) {
    const char *last_occurrence = NULL;

    while (*str != '\0') {
        if (*str == cha) {
            last_occurrence = str;
        }
        str++;
    }

    if (cha == '\0') {
        return str;
    }

    return last_occurrence;
}

/**
 * Compare les chaînes s1 et s2.
 * @param str1 La première chaîne à comparer
 * @param str2 La deuxième chaîne à comparer
 * @return 0 si les chaînes sont égales, un nombre négatif si str1 < str2, un nombre positif si str1 > str2
 */
int strcmp(const char* str1, const char* str2) {
    if (str1 == NULL || str2 == NULL) {
        return 0;
    }

    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }

    if (*str1 == *str2) {
        return 0;
    }

    return (*str1 < *str2) ? -1 : 1;
}

/**
 * Compare les n premiers caractères de s1 et s2.
 * @param str1 La première chaîne à comparer
 * @param str2 La deuxième chaîne à comparer
 * @param n Le nombre de caractères à comparer
 * @return 0 si les chaînes sont égales, un nombre négatif si str1 < str2, un nombre positif si str1 > str2
 */
int strncmp(const char* str1, const char* str2, size_t n) {
    if (str1 == NULL || str2 == NULL) {
        return 0;
    }

    while (n > 0) {
        if (*str1 != *str2) {
            return (*str1 < *str2) ? -1 : 1;
        }

        if (*str1 == '\0') {
            return 0;
        }

        str1++;
        str2++;
        n--;
    }

    return 0;
}

/**
 * Copie la chaîne src dans dest, y compris le caractère nul de fin.
 * @param dest Le tableau de destination
 * @param src La chaîne source à copier
 */
void strcpy(char* dest, const char* src) {
    if (dest == NULL || src == NULL) {
        return;
    }

    while (*src != '\0') {
        *(dest++) = *(src++);
    }

    *dest = '\0';
}

/**
 * Copie au plus n caractères de src dans dest.
 * @param dest Le tableau de destination
 * @param src La chaîne source à copier
 * @param n Le nombre maximal de caractères à copier
 */
void strncpy(char* dest, const char* src, size_t n) {
    if (dest == NULL || src == NULL) {
        return;
    }

    while (n > 0 && *src != '\0') {
        *dest = *src;

        dest++;
        src++;
        n--;
    }

    *dest = '\0';
}

/**
 * Renvoie la longueur de la chaîne str.
 * @param str La chaîne dont la longueur doit être calculée
 * @return La longueur de la chaîne
 */
size_t strlen(const char *str) {
    const char *end = str;

    while (*end) {
        end++;
    }

    return end - str;
}

/**
 * Compare les n premiers octets des zones mémoire s1 et s2.
 * @param str1 Le premier bloc de mémoire à comparer
 * @param str2 Le deuxième bloc de mémoire à comparer
 * @param n Le nombre d'octets à comparer
 * @return 0 si les blocs sont égaux, un nombre négatif si str1 < str2, un nombre positif si str1 > str2
 */
int memcmp(const void* str1, const void* str2, size_t n) {
    if (str1 == NULL || str2 == NULL) {
        return 0;
    }

    const unsigned char *p1 = str1;
    const unsigned char *p2 = str2;

    for (size_t i = 0; i < n; i++) {
        int diff = p1[i] - p2[i];
        if (diff != 0) {
            return (diff < 0) ? -1 : 1;
        }
    }

    return 0;
}

/**
 * Copie n octets de la zone mémoire src vers la zone mémoire dest.
 * @param dest Le bloc de mémoire de destination
 * @param src Le bloc de mémoire source
 * @param n Le nombre d'octets à copier
 * @return Un pointeur vers dest
 */
void* memcpy(void *dest, const void *src, size_t n) {
    if (dest == NULL || src == NULL || n == 0) {
        return NULL;
    }

    unsigned char *p_dest = dest;
    const unsigned char *p_src = src;

    while (n--) {
        *p_dest++ = *p_src++;
    }

    return dest;
}

/**
 * Copie n octets de la zone mémoire src vers la zone mémoire dest (les zones peuvent se chevaucher).
 * @param dest Le bloc de mémoire de destination
 * @param src Le bloc de mémoire source
 * @param n Le nombre d'octets à copier
 * @return Un pointeur vers dest
 */
void* memmove(void *dest, const void *src, size_t n) {
    if (dest == NULL || src == NULL || n == 0) {
        return NULL;
    }

    unsigned char *p_dest = dest;
    const unsigned char *p_src = src;

    if (p_dest <= p_src || p_dest >= p_src + n) {
        while (n--) {
            *p_dest++ = *p_src++;
        }
    } else {
        p_dest += n - 1;
        p_src += n - 1;

        while (n--) {
            *p_dest-- = *p_src--;
        }
    }

    return dest;
}