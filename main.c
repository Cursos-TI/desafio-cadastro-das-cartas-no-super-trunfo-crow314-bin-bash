#include <stdio.h>
#include <string.h>

/** Estrutura que armazena informações sobre uma carta:
    - estado: Sigla do estado
    - cidade: Nome da cidade
    - idCarta: Código identificador interno da carta
    - populacao: Número de habitantes
    - pontoTuristico: Quantidade de pontos turísticos
    - area: Área em km²
    - pib: Produto interno bruto */
struct Carta {
    char estado[3];
    char cidade[21];
    char idCarta[5];
    int populacao;
    int pontoTuristico;
    float area;
    float pib;
};

int main(void) {
    struct Carta c1;
    struct Carta c2;
    char buffer[40];
    int numeroId1;
    int numeroId2;

    printf("Para a Primeira Carta digite o estado com duas letras: \n");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Limpa quebra de linha no buffer e retorna terminador da string
    strncpy(c1.estado, buffer, sizeof(c1.estado) -1); // n-1 evitando overflow
    c1.estado[sizeof(c1.estado)-1] = '\0'; // Sempre retorna um terminador de string no final do array


    printf("Para a Primeira Carta digite o nome da cidade com no máximo de 20 caracteres: \n");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(c1.cidade, buffer, sizeof(c1.cidade) -1);
    c1.cidade[sizeof(c1.cidade)-1] = '\0';

    printf("Para a Primeira Carta digite um código de 1 a 4, a sigla do Estado será adicionada automaticamente: \n");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    sscanf(buffer, "%d", &numeroId1);

    // Monta o código único Estado + número
    snprintf(c1.idCarta, sizeof(c1.idCarta), "%s%d", c1.estado, numeroId1);

    printf("O código gerado para a Primeira Carta é: %s\n", c1.idCarta, "\n");
    printf("\n");

    // Segunda Carta

    printf("Para a Segunda Carta digite o estado com duas letras: \n");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Limpa quebra de linha no buffer e retorna terminador da string
    strncpy(c2.estado, buffer, sizeof(c2.estado) -1); // n-1 evitando overflow
    c2.estado[sizeof(c2.estado)-1] = '\0'; // Sempre retorna um terminador de string no final do array

    printf("Para a Segunda Carta digite o nome da cidade com no máximo de 20 caracteres: \n");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(c2.cidade, buffer, sizeof(c2.cidade) -1);
    c2.cidade[sizeof(c2.cidade)-1] = '\0';

    printf("Para a Segunda Carta digite um código de 1 a 4, a sigla do Estado será adicionada automaticamente: \n");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    sscanf(buffer, "%d", &numeroId2);

    snprintf(c2.idCarta, sizeof(c2.idCarta), "%s%d", c2.estado, numeroId2);

    printf("O código gerado para a Segunda Carta é: %s\n", c2.idCarta, "\n");

    return 0;
}