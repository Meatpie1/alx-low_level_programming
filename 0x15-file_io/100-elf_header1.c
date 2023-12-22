#include <stdio.h>
#include <elf.h>

/**
 * print_magic - Print the magic numbers of the ELF header
 * @e_ident: ELF identification array
 */
void print_magic(unsigned char *e_ident)
{
    int i;

    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
        printf(" %02x", e_ident[i]);
    printf("\n");
}

/**
 * print_class - Print the class of the ELF file
 * @e_ident: ELF identification array
 */
void print_class(unsigned char *e_ident)
{
    printf("  Class:                             ");
    switch (e_ident[EI_CLASS])
    {
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

/**
 * print_data - Print the data encoding of the ELF file
 * @e_ident: ELF identification array
 */
void print_data(unsigned char *e_ident)
{
    printf("  Data:                              ");
    switch (e_ident[EI_DATA])
    {
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_DATA]);
    }
}

/**
 * main - Entry point of the program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
    FILE *file;
    Elf64_Ehdr elf_header;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <ELF-file>\n", argv[0]);
        return (1);
    }

    file = fopen(argv[1], "rb");
    if (file == NULL)
    {
        perror("fopen");
        return (1);
    }

    fread(&elf_header, sizeof(elf_header), 1, file);

    printf("ELF Header:\n");

    print_magic(elf_header.e_ident);
    print_class(elf_header.e_ident);
    print_data(elf_header.e_ident);

    fclose(file);
    return (0);
}

