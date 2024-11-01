#ifndef COFRE_H
#define COFRE_H

#include <Keypad.h>
#include <MsgCofre.h>

#define TRUE 1
#define FALSE 0
#define SUCESSO 0
#define uint unsigned int
#define MAX_USERS 10
#define WORD_LENTH 5
#define OP_ACESSO 1
#define OP_CADASTRO 2
#define OP_REMOCAO 3

typedef struct _cadastro {
	char user[WORD_LENTH];
	char passw[WORD_LENTH];
	uint adm_access;
} cadastro;

typedef struct _listaUsuarios {
	cadastro usuarios[MAX_USERS];
	uint numero_usuarios = 0;
} listaUsuarios;

void iniciaLista (listaUsuarios *lista, char* adm_user, char* amd_passw);
uint insereUsuario (listaUsuarios *lista, char *user, char *passw, uint adm_access);
uint removeUsuario (listaUsuarios *lista, char *rem_user);
uint verificaAcesso (listaUsuarios *lista, char *user, char *passw);
void concatenaLeitura (char* str, char c, uint pos);

uint cadastrarUsuario (listaUsuarios *lista);
uint acessarCofre (listaUsuarios *lista);
uint removerUsuario (listaUsuarios *lista);

#endif
